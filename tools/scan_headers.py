#!/usr/bin/env python3
"""Header analysis for the RE2 cartridge container: compare, derive, chain.

Discovery tool, not an extractor. It answers three questions with numbers instead
of impressions:

  window   hexdump a bounded window around anchors (offsets printed, no guessing)
  compare  which bytes are constant across a set of block headers
  derive   which (offset, width, endian) field predicts block boundaries, scored
           against anchors whose boundaries are already known
  chain    walk a candidate format across a whole region and report where it breaks

The ROM is opened read-only and its sha256 is printed before and after every run,
so "the original cartridge image is immutable input" is demonstrated, not assumed.

Why anchors: the MJPEG region yielded 1 227 JPEG frames with exact boundaries by
carving ffd8ff..ffd9. Those are ground truth. A length field that predicts 1 226
consecutive transitions is a finding; one that predicts a few is a coincidence.
"""
import argparse, hashlib, json, struct, sys

def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()

def load(path):
    with open(path, "rb") as f:      # read-only, whole file, never written back
        return f.read()

def magic_anchors(d, lo, hi, magic):
    """Payload starts = every occurrence of `magic` in [lo,hi)."""
    pat = bytes.fromhex(magic) if isinstance(magic, str) else magic
    out, i = [], lo
    while True:
        i = d.find(pat, i, hi)
        if i < 0: break
        out.append((i, len(pat)))
        i += len(pat)
    return out

def jpeg_anchors(d, lo, hi):
    """Payload starts of JPEG members inside [lo,hi), by carving SOI..EOI."""
    out, i = [], lo
    while True:
        i = d.find(b"\xff\xd8\xff", i, hi)
        if i < 0: break
        j = d.find(b"\xff\xd9", i + 2, hi)
        if j < 0: break
        out.append((i, j + 2 - i))
        i = j + 2
    return out

def rd(d, pos, width, endian):
    if pos < 0 or pos + width > len(d): return None
    return int.from_bytes(d[pos:pos + width], "big" if endian == "be" else "little")

def cmd_window(d, at, before, after):
    for addr in at:
        lo, hi = max(0, addr - before), min(len(d), addr + after)
        print(f"\n@ {addr:#09x}  (window {lo:#x}..{hi:#x})")
        for row in range(lo, hi, 16):
            b = d[row:row + 16]
            mark = ""
            if row <= addr < row + 16: mark = "  <== anchor"
            print(f"  {row:#09x}  {b.hex(' '):<47}  {mark}")

def cmd_compare(d, at, before):
    """Byte-by-byte constancy across the `before` bytes preceding each anchor."""
    rows = [d[a - before:a] for a in at]
    if not rows or min(len(r) for r in rows) < before:
        sys.exit("anchor too close to the start of the file")
    print(f"\ncomparing {before} bytes before each of {len(at)} anchors")
    print(f"{'rel':>4} {'const?':>7}  values")
    for k in range(before):
        vals = {r[k] for r in rows}
        const = "CONST" if len(vals) == 1 else f"{len(vals):>4}var"
        show = f"{list(vals)[0]:#04x}" if len(vals) == 1 else \
               " ".join(f"{v:02x}" for v in sorted(vals)[:6]) + (" …" if len(vals) > 6 else "")
        print(f"  -{before-k:>2} {const:>7}  {show}")


def _equal_bytes(a, b):
    """Number of positions where two equal-length byte strings agree.

    Doing this per byte in Python is hopeless at 64 KB x 65 000 lags, so the two
    windows are XORed as big integers and the zero bytes counted — same answer,
    all of it in C.
    """
    x = int.from_bytes(a, "big") ^ int.from_bytes(b, "big")
    return x.to_bytes(len(a), "big").count(0)

def stride_null(d, starts, window, lags, shuffles, seed=20261030):
    """Empirical null for the stride probe: shuffle each window's bytes and re-measure.

    Shuffling keeps the byte histogram (so a value-skewed region stays skewed) and
    destroys only order, which is exactly the property the probe tests. Without
    this, a 2x-over-median spike proves nothing: the negative control below shows
    2x spikes arise in data with no block structure at all.
    """
    import random
    rnd = random.Random(seed)
    per_lag = {S: [] for S in lags}
    for _ in range(shuffles):
        for st in starts:
            for S in lags:
                # shuffle a buffer long enough that both sides are `window` bytes,
                # so the null uses the same comparison length as the measurement
                base = bytearray(d[st:st + window + S])
                rnd.shuffle(base)
                b = bytes(base)
                per_lag[S].append(_equal_bytes(b[:window], b[S:S + window]) / window)
    return per_lag



def run_lengths(buf, stride):
    """Runs of consecutive positions where buf[i] == buf[i+stride].

    Run length is the discriminator a phase sweep cannot provide:
      * whole-record repetition -> multi-byte runs (a repeated field, a repeated
        constant stretch), and their starts cluster at one phase mod stride
      * byte-level skew (e.g. the high byte of 16-bit samples) -> runs of length 1
    Both produce the same per-phase *rate*, so only the run structure tells them apart.
    """
    n = len(buf) - stride
    runs = []
    i = 0
    while i < n:
        if buf[i] == buf[i + stride]:
            j = i
            while j < n and buf[j] == buf[j + stride]:
                j += 1
            runs.append((j - i, i))
            i = j
        else:
            i += 1
    return runs

def runs_report(d, lo, hi, stride, window, nwin, shuffles, top):
    import random
    from collections import Counter
    span = hi - lo
    starts = [lo + (span - window) * i // max(1, nwin - 1) for i in range(nwin)] \
             if nwin > 1 else [lo + (span - window) // 2]
    starts = [max(lo, min(st, hi - window - stride)) for st in starts]
    obs = Counter(); phases = Counter(); longest = (0, 0); notable = []
    total_match = total_cmp = 0
    for st in starts:
        buf = d[st:st + window]
        rs = run_lengths(buf, stride)
        for L, at in rs:
            obs[min(L, 6)] += 1
            if L >= 3:
                phases[at % stride] += 1
                # a long run is either repeated records or a constant fill; the
                # distinct-value count over the run span tells them apart
                span = buf[at:at + L + stride]
                notable.append((L, st + at, len(set(span)), bytes(span[:8]).hex()))
            if L > longest[0]: longest = (L, st + at)
        total_match += sum(L for L, _ in rs)
        total_cmp += window - stride
    null = Counter(); null_match = 0
    rnd = random.Random(20261030)
    for _ in range(shuffles):
        for st in starts:
            b = bytearray(d[st:st + window]); rnd.shuffle(b)
            rs = run_lengths(bytes(b), stride)
            for L, _ in rs: null[min(L, 6)] += 1
            null_match += sum(L for L, _ in rs)
    scale = shuffles
    return (obs, null, scale, phases, longest, notable,
            total_match / total_cmp, null_match / (total_cmp * shuffles))

def phase_sweep(d, lo, hi, stride, window, nwin):
    """Per-byte-position agreement within a period: which bytes actually repeat?

    For phase p the series is every stride-th byte starting at p. Consecutive
    elements of that series are the same position in adjacent records, so the
    agreement rate measures how often *that* byte repeats record-to-record. A
    single lag agreement rate hides this: 40 positions averaged together turn one
    constant byte into a 1/40 signal.

    Two reference points are reported per phase:
      null_p2   sum of squared byte frequencies in the analysed window — the chance
                that two bytes drawn from this region's own histogram match
      top value / distinct — a constant byte (padding) and a field that merely
                changes slowly look identical in the agreement rate but not here
    """
    from collections import Counter
    span = hi - lo
    if span < window + stride: window = max(1024, span // 2)
    starts = [lo + (span - window) * i // max(1, nwin - 1) for i in range(nwin)] \
             if nwin > 1 else [lo + (span - window) // 2]
    starts = [max(lo, min(st, hi - window)) for st in starts]

    hist = Counter()
    for st in starts: hist.update(d[st:st + window])
    total = sum(hist.values())
    null_p2 = sum((c / total) ** 2 for c in hist.values())

    rows = []
    for p in range(stride):
        eq = n = 0
        vals = Counter()
        for st in starts:
            series = d[st + p:st + window:stride]
            vals.update(series)
            eq += sum(1 for i in range(len(series) - 1) if series[i] == series[i + 1])
            n += max(0, len(series) - 1)
        if not n: continue
        top_v, top_c = vals.most_common(1)[0]
        # per-phase null: this phase's OWN marginal distribution. Using the global
        # null would let a merely skewed position (e.g. the high byte of 16-bit
        # samples) look periodic — it reproduces its own values by chance often
        # enough to clear a global floor.
        np2 = sum((c / n) ** 2 for c in vals.values())
        rows.append((eq / n, p, np2, top_v, top_c / max(1, sum(vals.values())),
                     len(vals)))
    return rows, null_p2, starts

def stride_probe(d, lo, hi, window, nwin, min_s, max_s, step, top, lags=None):
    """Score lags by byte agreement across several spread windows of a region.

    A fixed-size container repeats something every `stride` bytes, so byte
    agreement spikes at that lag (and at its multiples) above the ~1/256 floor
    that random data gives. Averaging over several windows spread through the
    region keeps one lucky match from becoming a conclusion.
    """
    span = hi - lo
    if span < window + max_s: window = min(window, max(1024, span // 2))
    starts = [lo + (span - window - max_s) * i // max(1, nwin - 1) for i in range(nwin)] \
             if nwin > 1 else [lo + (span - window - max_s) // 2]
    starts = [max(lo, min(st, hi - window - max_s)) for st in starts]
    scores = {}
    lags = lags or list(range(min_s, max_s + 1, step))
    for S in lags:
        tot = 0
        for st in starts:
            a = d[st:st + window]
            b = d[st + S:st + S + window]
            tot += _equal_bytes(a, b)
        scores[S] = tot / (window * len(starts))
    ordered = sorted(scores.items(), key=lambda kv: -kv[1])
    floor = sorted(scores.values())[len(scores) // 2]
    return ordered, floor, starts

def cmd_derive(d, anchors, max_before=40, max_after=16):
    """Find which field explains anchor-to-anchor spacing, using residual distributions.

    Anchors are payload starts. For a candidate field read in either the current
    anchor's window or the *next* anchor's window, compute the residual

        r_k = (A[k+1] - A[k]) - value_k

    With positive rel the field is read after the anchor, which is what makes a
    trailer *type word* usable as an anchor: anchor spacing is then the whole block
    (payload + trailer + pad) and the size sits at anchor+4.

    A real length field makes the residual nearly constant: 0 for an unpadded
    length, 8 or 9 for a big-endian trailer plus parity padding, and so on. Scoring
    by residual constancy finds a field whose block framing differs from the
    anchor spacing by a fixed overhead — which exact-match scoring cannot see, and
    which is exactly the shape this container turned out to have.

    Reading the field in the NEXT anchor's window is what discovers a trailer:
    a size stored after its payload sits before the following payload.
    """
    from collections import Counter
    A = [a for a, _ in anchors]
    if len(A) < 8: sys.exit("need at least 8 anchors")
    trans = len(A) - 1
    cands = []
    for frame in ("cur", "next"):
        for endian in ("be", "le"):
            for width in (1, 2, 3, 4):
                for rel in range(-max_before, max_after + 1):
                    vals = []
                    for k in range(trans):
                        base = A[k] if frame == "cur" else A[k + 1]
                        vals.append(rd(d, base + rel, width, endian))
                    if any(v is None for v in vals): continue
                    res = Counter(A[k + 1] - A[k] - vals[k] for k in range(trans))
                    mode, cnt = res.most_common(1)[0]
                    # parity model: residual == C + (value & 1), the shape a trailer
                    # plus one odd-size pad byte produces. A model that ignores parity
                    # splits 52/48 across two residuals and looks like a 52 % failure.
                    par = sum(1 for k in range(trans)
                              if A[k+1] - A[k] - vals[k] == mode + (vals[k] & 1))
                    cands.append((par / trans, frame, endian, width, rel, mode,
                                  res.most_common(3), cnt / trans))
    cands.sort(reverse=True)
    print(f"\nderive: {trans} transitions from {len(A)} anchors")
    print(f"  {'parity':>6} {'modal':>6}  {'window':>4} {'width':>5} {'endian':>6} {'rel':>5} "
          f"{'C':>5}  other residuals")
    for share, frame, endian, width, rel, mode, top, modal in cands[:8]:
        print(f"  {share*100:5.1f}% {modal*100:5.1f}%  {frame:>4} {width:>5} {endian:>6} {rel:>5} "
              f"{mode:>5}  {[(r, c) for r, c in top[1:3]]}")
    best = cands[0]
    if best[0] < 0.9:
        print("  NO candidate reaches 90 % under the parity model — do not extract")
        return None
    spec = {"window": best[1], "endian": best[2], "width": best[3], "rel": best[4],
            "residual_C": best[5], "parity_model": True, "score": best[0]}
    print("\nbest spec:", json.dumps(spec))
    return spec

def a_ok(a, b, c, extra):
    return a + b + extra == c

def cmd_chain(d, lo, hi, hlen, rel, width, endian, meaning, expect_type=None, verbose=False):
    """Walk a forward hypothesis and report where it stops.

    meaning="payload"  block = [hlen bytes][value bytes]        -> next = pos + hlen + value
    meaning="total"    block = [hlen bytes, value includes it]  -> next = pos + value
    A run that lands exactly on `hi` is evidence; one that stops early is not.
    """
    p, n, stuck = lo, 0, 0
    stops = []
    while p + hlen <= hi:
        v = rd(d, p + rel, width, endian)
        if v is None: break
        if expect_type is not None:
            got = rd(d, p, len(expect_type) // 2, "be")
            if got != int(expect_type, 16):
                stops.append(f"type {got:#010x} != {expect_type} at {p:#09x}")
                break
        nxt = p + (v if meaning == "total" else hlen + v)
        if nxt <= p or nxt > hi:
            stops.append(f"length {v:#x} at {p:#09x} overruns")
            break
        n += 1; p = nxt
    tail = (f"EXACT at region end" if p == hi else f"{hi - p:#x} bytes short")
    print(f"    chain hlen={hlen} rel={rel} w={width} {endian} {meaning}: "
          f"{n} blocks, stopped {p:#09x} ({tail})")
    for st in stops[:2]:
        print(f"      {st}")
    return n, p

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    sub = ap.add_subparsers(dest="cmd", required=True)

    w = sub.add_parser("window"); w.add_argument("--at", required=True)
    w.add_argument("--before", type=int, default=24); w.add_argument("--after", type=int, default=8)

    c = sub.add_parser("compare"); c.add_argument("--at", required=True)
    c.add_argument("--before", type=int, default=16)

    dv = sub.add_parser("derive")
    dv.add_argument("--jpeg-region", help="carve JPEG members as anchors")
    dv.add_argument("--region", help="S:E region for --magic anchors")
    dv.add_argument("--magic", help="hex byte pattern used as anchors, e.g. 000001b3")
    dv.add_argument("--max-before", type=int, default=40)
    dv.add_argument("--max-after", type=int, default=16,
                    help="also read fields up to N bytes AFTER an anchor (trailer-type anchors)")

    ch = sub.add_parser("chain"); ch.add_argument("--region", required=True)
    ch.add_argument("--header-len", type=int, required=True)
    ch.add_argument("--rel", type=int, required=True)
    ch.add_argument("--width", type=int, required=True)
    ch.add_argument("--endian", default="be")
    ch.add_argument("--meaning", default="length_covers_header")
    ch.add_argument("--expect-type")

    st = sub.add_parser("stride")
    st.add_argument("--region", required=True)
    st.add_argument("--window", type=lambda v: int(v, 0), default=0x10000)
    st.add_argument("--windows", type=int, default=3)
    st.add_argument("--min-stride", type=lambda v: int(v, 0), default=16)
    st.add_argument("--max-stride", type=lambda v: int(v, 0), default=0x10000)
    st.add_argument("--step", type=int, default=4)
    st.add_argument("--top", type=int, default=12)
    st.add_argument("--lags", help="comma-separated lags to probe instead of a range")
    st.add_argument("--null", type=int, default=0, metavar="N",
                    help="N shuffles per lag for an empirical null (strongly recommended)")

    ph = sub.add_parser("phase")
    ph.add_argument("--region", required=True)
    ph.add_argument("--stride", type=lambda v: int(v, 0), required=True)
    ph.add_argument("--window", type=lambda v: int(v, 0), default=0x10000)
    ph.add_argument("--windows", type=int, default=3)
    ph.add_argument("--top", type=int, default=12)

    rn = sub.add_parser("runs")
    rn.add_argument("--region", required=True)
    rn.add_argument("--stride", type=lambda v: int(v, 0), required=True)
    rn.add_argument("--window", type=lambda v: int(v, 0), default=0x10000)
    rn.add_argument("--windows", type=int, default=3)
    rn.add_argument("--null", type=int, default=4)
    rn.add_argument("--top", type=int, default=8)

    a = ap.parse_args()
    before = sha256(a.rom)
    d = load(a.rom)

    if a.cmd == "window":
        cmd_window(d, [int(x, 0) for x in a.at.split(",")], a.before, a.after)
    elif a.cmd == "compare":
        cmd_compare(d, [int(x, 0) for x in a.at.split(",")], a.before)
    elif a.cmd == "derive":
        if a.jpeg_region:
            lo, hi = (int(x, 0) for x in a.jpeg_region.split(":"))
            anchors = jpeg_anchors(d, lo, hi)
            print(f"anchors: {len(anchors)} JPEG members in {lo:#x}..{hi:#x}")
        else:
            if not (a.region and a.magic):
                sys.exit("derive needs --jpeg-region, or --region with --magic")
            lo, hi = (int(x, 0) for x in a.region.split(":"))
            anchors = magic_anchors(d, lo, hi, a.magic)
            print(f"anchors: {len(anchors)} x '{a.magic}' in {lo:#x}..{hi:#x}")
            if len(anchors) > 1:
                gaps = [anchors[k+1][0] - anchors[k][0] for k in range(len(anchors)-1)]
                print(f"  anchor spacing: min {min(gaps):#x} max {max(gaps):#x} "
                      f"distinct {len(set(gaps))} values, first {[hex(g) for g in gaps[:6]]}")
        spec = cmd_derive(d, anchors, a.max_before, a.max_after)
        if spec: print("\nbest spec:", json.dumps(spec))
    elif a.cmd == "chain":
        lo, hi = (int(x, 0) for x in a.region.split(":"))
        cmd_chain(d, lo, hi, a.header_len, a.rel, a.width, a.endian, a.meaning, a.expect_type, True)

    elif a.cmd == "stride":
        lo, hi = (int(x, 0) for x in a.region.split(":"))
        only = [int(x, 0) for x in a.lags.split(",")] if a.lags else None
        ordered, floor, starts = stride_probe(d, lo, hi, a.window, a.windows,
                                              a.min_stride, a.max_stride, a.step, a.top, only)
        print(f"region {lo:#09x}..{hi:#09x}  {a.windows} window(s) of {a.window:#x}  "
              f"lags {a.min_stride:#x}..{a.max_stride:#x} step {a.step}")
        print(f"  chance floor (median agreement): {floor*100:.3f}%")
        print(f"  {'lag':>8} {'agree':>8} {'x floor':>8}   harmonics")
        null = None
        if a.null:
            null = stride_null(d, starts, a.window,
                               [S for S, _ in ordered[:a.top]], a.null)
        for S, sc in ordered[:a.top]:
            mult = [f"{S//k}={k}x" for k in (2, 3, 4, 8) if S % k == 0 and S//k >= a.min_stride]
            z = ""
            if null:
                vals = null[S]
                mu = sum(vals) / len(vals)
                sd = (sum((v - mu) ** 2 for v in vals) / len(vals)) ** 0.5 or 1e-9
                z = f"   null {mu*100:6.3f}% +-{sd*100:5.3f}  z={(sc-mu)/sd:+6.1f}"
            print(f"  {S:>8} {sc*100:7.3f}% {sc/floor:7.1f}x{('' if not z else z)}   {','.join(mult[:4])}")
    elif a.cmd == "phase":
        lo, hi = (int(x, 0) for x in a.region.split(":"))
        rows, null_p2, starts = phase_sweep(d, lo, hi, a.stride, a.window, a.windows)
        print(f"region {lo:#09x}..{hi:#09x}  stride {a.stride}  "
              f"{len(starts)} window(s) of {a.window:#x}")
        print(f"  per-phase null (sum of squared frequencies): {null_p2*100:.3f}%")
        print(f"  {'phase':>5} {'agree':>8} {'x null':>7} {'top byte':>9} {'share':>7} {'distinct':>8}")
        print(f"  ratio uses each phase's own null, so skew alone cannot pass")
        for rate, p, np2, tv, tc, nd in sorted(rows, key=lambda r: -r[0] / r[2])[:a.top]:
            print(f"  {p:>5} {rate*100:7.3f}% {rate/np2:6.2f}x "
                  f"{format(tv, '#04x'):>9} {tc*100:6.1f}% {nd:>8}  (own null {np2*100:.2f}%)")
        ratios = [r[0] / r[2] for r in rows]
        print(f"  mean ratio across all {len(rows)} phases: {sum(ratios)/len(ratios):.2f}x")
        print(f"  phases at or below their own null: {sum(1 for r in ratios if r <= 1.0)}")
    elif a.cmd == "runs":
        lo, hi = (int(x, 0) for x in a.region.split(":"))
        obs, null, scale, phases, longest, notable, mr, nmr = runs_report(
            d, lo, hi, a.stride, a.window, a.windows, a.null, a.top)
        print(f"region {lo:#09x}..{hi:#09x}  stride {a.stride}  "
              f"{a.windows} window(s) of {a.window:#x}  null = {a.null} shuffle(s)")
        print(f"  match rate {mr*100:.3f}%  (shuffled null {nmr*100:.3f}%, "
              f"{mr/nmr:.2f}x)")
        print(f"  {'run len':>7} {'observed':>9} {'null mean':>10} {'ratio':>6}")
        for L in (1, 2, 3, 4, 5, 6):
            o = obs.get(L, 0); n = null.get(L, 0) / scale
            label = f"{L}+" if L == 6 else str(L)
            print(f"  {label:>7} {o:>9} {n:>10.1f} "
                  f"{(o/n if n else float('inf')):>6.1f}x")
        print(f"  longest run: {longest[0]} bytes at {longest[1]:#09x}")
        if notable:
            fills = sum(1 for _L, _a, nd, _h in notable if nd <= 2)
            print(f"  runs >=3: {len(notable)}, of which constant-fill (<=2 distinct "
                  f"values over the span): {fills} ({fills/len(notable)*100:.0f}%)")
            print(f"  longest 6 runs: len  offset      distinct  head")
            for L, at, nd, head in sorted(notable, reverse=True)[:6]:
                kind = "CONSTANT FILL" if nd <= 2 else f"{nd} values"
                print(f"    {L:>4} {at:#010x}  {kind:>13}  {head}")
        if phases:
            print(f"  starts of runs >=3, by phase mod {a.stride}: "
                  f"{phases.most_common(a.top)}")
        else:
            print("  no run of length >= 3 anywhere")
    after = sha256(a.rom)
    print(f"\nROM sha256 before {before[:16]}…  after {after[:16]}…  "
          f"{'UNCHANGED' if before == after else 'MODIFIED — INVESTIGATE'}")

if __name__ == "__main__":
    main()
