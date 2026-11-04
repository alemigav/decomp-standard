/* FUN_800478b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478b8  body 0x800478b8..0x800478c3  size 12 B
 * body sha256 467792955f882a109123db96dd0cab173ce70f85789383063b28490dee64df38
 * provider record sha256 debfc8ae299c207d78f0f2acd9dd57992af891bf6e7d5cbce5f4c6d92e026dc9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478b8(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  return;
}
