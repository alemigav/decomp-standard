# M176 — the secret holds access, not bytes: CI fetches the cartridge

Asked to "wire the ROM through a repo secret". A secret cannot carry it — GitHub's own docs say *"Secrets are
limited to 48 KB in size"* — so the question became *what can a secret carry?* The answer is a URL. The bytes
stay in the owner's storage and are fetched when a run needs them, which means the full 23 suites / 240 cases
run on a **GitHub-hosted** runner with nothing committed and nothing stored on GitHub.

## 1. Why the literal request is impossible, measured

| quantity | value |
|---|---|
| per-secret limit (documented) | **48 KB** |
| cartridge | **67 108 864 B** |
| the same, base64 | **89 478 489 B** |
| secrets needed at the cap | **≈ 1 870** |

The documented workaround for "secrets larger than 48 KB" is to *encrypt the file and commit it to the
repository*, keeping only the passphrase as the secret. That works mechanically and is the one thing this
project refuses: 67 MB of copyrighted ROM in git history, forever.

## 2. Two scripts, so both tiers cannot drift

* **`tools/cart_fetch.sh`** — `RE2_CART_URL` (+ optional `RE2_CART_TOKEN`), download to a temporary name,
  verify, then unpack and build. The token is passed to `curl` through a config file, not the command line,
  because `ps` shows arguments on a runner.
* **`tools/ci_full.sh`** — the full tier: require the cartridge, `build/elfs` and `assets/unpacked`, run
  `tools/ci.sh`, then **fail if any suite reported SKIP**. Both the self-hosted job and the fetching job call
  it, which is why the guard is one implementation instead of two YAML snippets.

Verification is by SHA-256 against `rom_sha256` in the **committed** `manifests/manifest.json` — a runner has
no `build/elfs`, so the expected value had to come from a tracked file. A wrong or truncated download is
refused *before* anything unpacks it, so a bad secret fails as `FAIL sha256 …` rather than as a corrupt game.

## 3. Both guards were shown to fire, in both directions

```
cart_fetch.sh --self-test                     4/4   (intact accepted; one byte changed; truncated; manifest)
ci_full.sh --self-test                        3/3   (coverage accepted; SKIP refused; no-coverage-line refused)

RE2_CART_URL=file:///…/cart.z64  → fetch, verify, unpack 4 761 members, build 36 ELFs   11 s   exit 0
RE2_CART_URL=file:///…/truncated → FAIL sha256 4d493a7e…, nothing written to rom/      exit 1
sh tools/ci_full.sh in a tree with no cartridge                                         exit 1
sh tools/ci_full.sh in a tree that fetched its own cartridge   23 suites / 240 cases    exit 0
```

End to end that is **~11 s to materialise + ~61 s for the suites**, on a hosted runner, with no runner to keep
awake and no secret larger than a URL.

## 4. The audit harness was wrong for shell, and that is the interesting defect

Both new gates are shell, and `audit_gates.py` ran **every** tool with `sys.executable`. So the mutated copies
"failed" with `SyntaxError: invalid syntax` — detected, per the audit's rule, and reported as **PASS**:

```
PASS  ci_full: the skip guard never fires      (exit 1; SyntaxError: invalid syntax)
PASS  cart_fetch: the digest comparison always passes  (exit 1; SyntaxError: invalid syntax)
```

An audit that cannot distinguish "the check failed" from "the interpreter could not read the file" is exactly
the vacuous check this tool exists to catch. The audit entry now takes an `interp` (default Python), and both
shell gates pass `interp="sh"`. With that, they fail for the intended reason:

```
PASS  ci_full: the skip guard never fires      (exit 1; FAIL a log with skipped suites is refused)
PASS  cart_fetch: the digest comparison always passes  (exit 1; FAIL a single changed byte is detected)
```

This is the **fourth** time in this arc that an audit ran in the wrong environment — after `build/elfs`, `src`
and `.github/` were missing from it. The pattern is now explicit: an audit environment must supply everything
the tool reads *and* the interpreter that reads it.

## 5. State

| where | suites | cases |
|---|---|---|
| local, cartridge present | **23 / 23** | **240 / 240** |
| runner, no cartridge (`ci`) | 12 / 23 | 135 / 240, 11 suites / 105 cases SKIP |
| runner, fetched (`full-url`) | **23 / 23** | **240 / 240** |
| runner, self-hosted (`full`) | **23 / 23** | **240 / 240** |

`full-url` and `full` are both gated by a repository variable (`CARTRIDGE_URL`, `SELF_HOSTED_RUNNER`), so
neither queues while its prerequisite is absent; enabling either is documented in `docs/handover.md`. The
fetched job has not run yet — it needs `RE2_CART_URL` set — but everything it depends on was executed here:
the same two scripts, against a real 64 MiB cartridge, with the failure paths exercised.

```
python3 tools/acceptance.py    # 23 suites, 240 cases
python3 tools/audit_gates.py   # 22/22, 0 vacuous
python3 tools/workflow_lint.py # 14/14
sh tools/ci_full.sh            # ci_full: ok — every suite ran, none skipped
```
