# M287 — `0x800704e0` byte-exact at 123: the accessor family is now three of three

The last sized member of the arm-shaped family comes out **123 of 123 words byte-exact** with its **44-word table
44 of 44**, on the first corrected attempt. With it, the whole accessor trio is reproduced: **read** (`0x800701d8`,
141 words), **write** (`0x8006ff48`, 98) and **address-of** (`0x800704e0`, 123) — same 44 indices, same field offsets,
three different arm shapes.

## 1. What it is

```c
u8 *FUN_800704e0(u8 *p, u32 idx)
{
    switch (idx) {
    case 1: return p;                        /* addu v0,a2,zero                  */
    case 0: return p + 2;                    /* addiu v0,a2,2                    */
    case 2: D_80115120++; return p + 4;      /* lhu / addiu / sh on 0x80115120   */
    ...
    }
}
```

Each arm is `addiu v0,a2,N` and returns the *address* of the field, not its value; the head's first act is
`addu a2,a0,zero`, because `a0` is needed as the base of the counter global in ten of the arms. Those ten — indices
**2, 3, 4, 5, 6, 8, 9, 27, 31, 43** — also do `D_80115120++` on a `u16` at `0x80115120`, and gcc **shares one increment
tail** across the first nine of them through a `j` to `0x80070524` (`addiu r3,r3,1; jr ra; sh`), while index 43 lands
adjacent to the epilogue and inlines it. That shared tail is visible in the table as nine entries whose arms begin
`lui r4,0x8011` and end in a jump.

The offsets are the **same 44** as the other two members — `2`, `0`, `4`, `5`, `6`, `7`, `8`, `10`, `11`, `16`, `40`,
`44`, `48`, `100`, `102`, `104`, `418`, `426`, `480` (twice: indices 27 and 28 differ only in that 27 counts),
`482`, `484`, `490`, `496`, `606`, `608`, `610`, `616`, `623`, `624`, `626`, `628`, `630`, `634`, `304`, `308`, `306`,
`310`, `314`, `312`, `436`, `438`, `692`, `694`. Three functions, 132 arms, no contradiction in any offset — which is
now the third independent check on the field map.

## 2. The one thing that was wrong was in my *extraction*, not in the C

The first generated source scored 69 of 123 with the offsets shifted by one index. The generator picked the **last**
`addiu v0,a2,N` in a five-word window per arm instead of the first, so each arm inherited its neighbour's offset —
visible immediately in the diff as a chain of `addiu` mismatches that all looked like a one-step displacement. Reading
each arm's own first offset fixed it, and with the arms in the image's order (**case 1 before case 0**, then
ascending — the same transposition the other two members need; ascending scores 121) the function is exact:

| source | score |
|---|---|
| offsets from the last match, case 1 then 0 | 69 / 123 |
| offsets from the first match, ascending | 121 / 123 |
| **offsets from the first match, case 1 then 0** | **123 / 123** |

That is worth recording as a process fact: on a 44-arm function the extraction script is part of the reconstruction, and
a one-index displacement looks exactly like a codegen disagreement. The tell was that the *displacement* was uniform.

## 3. Coverage

`0x800704e0` enters the probe as two **exact** pins (the 123-word function and its 44-word table), so the corpus is
**43 cases, all passing**, the suite **72 suites / 1012 cases** with **732** needing the cartridge.

Recovered functions are **fourteen**, of which **eleven are byte-exact**: 41, 46, 53, 53, 84, 98, 98, 123, 141, 167,
206 words. The three partials are unchanged and pinned: `0x80024558` at `136 of 139`, `0x8007e590` at `226 of 229`, and
`0x8006e574` at `17 of 23`. **The arm-shaped family has no sized target left** — the five dispatch sites the M284 scan
found are all either recovered (`0x800701d8`, `0x8006fc5c`, `0x8006ff48`, `0x800704e0`) or identified and recovered
(`0x8006e68c`, and `0x8006e574` at 17 of 23), and the only remaining work of this kind is whatever a new scan finds.

The next task is the one M286 filed: **regenerating `manifests/code_index.json`**, which still lists dispatch arms as
functions and omits the leaves that enclose them.
