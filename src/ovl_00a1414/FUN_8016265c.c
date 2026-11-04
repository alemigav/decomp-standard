/* FUN_8016265c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016265c  body 0x8016265c..0x801626d7  size 124 B
 * body sha256 1ba65134ec6ef438945aaa5c56211887a096f45efbde17a18d988e4ef1b4eb63
 * provider record sha256 a97db85c8c3b390fa162cafc9aadf5cb2b826c9669d2650fda66fcf420bc3e8a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016265c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80168f68)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80168fa0)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
