/* FUN_800478c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478c4  body 0x800478c4..0x800478db  size 24 B
 * body sha256 dae26f0701f0616f9ed5d1d1a953cd147573a249d16467a5dcb06217ee595543
 * provider record sha256 c9218fcfae4ad40a6b8e77c3809d95f01cc2b856ba3a047f23adfc7b48a607c6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478c4(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  *(undefined2 *)(param_1 + 8) = param_4;
  *(undefined2 *)(param_1 + 10) = param_5;
  return;
}
