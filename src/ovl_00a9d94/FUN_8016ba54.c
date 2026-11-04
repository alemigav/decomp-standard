/* FUN_8016ba54
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016ba54  body 0x8016ba54..0x8016ba9f  size 76 B
 * body sha256 a1d981291b609edbcb79538c1b541888ed29a711fa0139d428ca0024844de40b
 * provider record sha256 f3b7a423517e471935032ee43f483f9260450bc32f0654813b8d52dfbcefc45c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016ba54(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x2630;
  func_0x80036290(param_1,iVar1,&DAT_8016c680);
  func_0x80036734(param_1,iVar1);
  return;
}
