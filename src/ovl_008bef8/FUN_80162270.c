/* FUN_80162270
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162270  body 0x80162270..0x801622ff  size 144 B
 * body sha256 ae9e6f492cf0ccc991ab313601a2ecd774d0e86634655eb8122d58ee81f5a4ff
 * provider record sha256 a32b422eee7bc3c5f1b1cf178e16372b39250c292557617526d403fea1aae2c7
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162270(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_LAB_801660d0)[*(byte *)(param_1 + 5)])();
  func_0x80036c44(param_1,*(undefined4 *)(param_1 + 700));
  *(undefined4 *)(param_1 + 700) = *(undefined4 *)(param_1 + 4);
  (*(code *)(&PTR_FUN_801660f0)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
