# M217 — TYRANT is a codename, and what each layer may claim

The reconstructed script execution model now has a name in this project's vocabulary: **TYRANT**. `tools/scd_vm.py`
keeps its path and its behaviour; the name is how documentation, reports and future tooling refer to the thing.

**What the name is not.** It is this project's codename. Nothing in the cartridge names it — no string, no table, no
handler — and Capcom or Angel Studios may well have called it something else or nothing at all. The handover and any
report state that caveat at first mention, because the project's standard is that a name without evidence is a
claim, and a codename is only honest when it is labelled as one.

## 1. Why the name is worth having

Three documents and eleven tools now talk about "the decoder", "the reference VM", "the script VM" and "the walk"
interchangeably, and one of them (`walk_stream.py`) is not a VM at all — it is a linear length walker. A codename
collapses that ambiguity at no evidentiary cost, as long as it is never used as evidence.

## 2. The three layers, and the rule that protects them

A reviewer proposed splitting the model into decoder / semantic interpreter / host simulation. That split is
adopted, because it protects the property this milestone series has spent the most effort on — **the decoder that
refuses must not become an interpreter that improvises**.

| layer | may claim | may not claim | status |
|---|---|---|---|
| **1 decoder** (`tools/scd_vm.py`) | instructions, boundaries, successors, scheduler state, and explicit refusal | that a jump target is valid code; any gameplay effect | **built — 33 cases** |
| **2 semantic interpreter** | what an *understood* instruction does to a small, explicit game-state model | that its game-state model is the original's memory layout | next milestone |
| **3 host / simulation** | rooms, entities, audio, animation, collision | anything about the original's implementation | out of scope |

## 3. The two rules carried forward

**`UnimplementedEffect` is not `UnresolvedAdvance`.** An instruction can have a fully established length, operand
layout and control flow, and an entirely unknown gameplay effect. Layer 2 must raise the first and not the second,
and must never treat an unknown effect as a no-op — a silent no-op is exactly the defect this project has caught
in its own tooling more than once (M141's phantom advance family, M213's skipped byte).

**Python first, C later — and only after behaviour is verified.** The research interpreter stays Python, where the
traces, fixtures and differential harnesses already live. A production runtime is a separate decision with its own
evidence bar; the review's suggestion of C17 matches what this repository already anticipates (`tools/` counts
`.c` files, and `t64info.c` is the precedent), but nothing about it is scheduled here.

## 4. What changed in the tree

`docs/handover.md` gained a short section naming the codename with the caveat; the plan records the layers and the
two rules. No code, no artefact, no count changed — which is why this landed with the audio work package instead of
carrying a cycle of its own.
