/* FUN_80166b04
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166b04  body 0x80166b04..0x80166b93  size 144 B
 * body sha256 0513fbdd625be32ef7a1f696dbefcf20ea557ce6ec74093a7b0e977a1befa5b8
 * provider record sha256 ba250caf3e61dbddd04575f7e240d385409ce74a72767fb36990492e8d9ac279
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166b04(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    iVar2 = -0x7ff1eed0;
  }
  else {
    iVar2 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 0x2be) == '\0') {
    iVar1 = *(int *)(iVar2 + 0x28);
    iVar2 = *(int *)(iVar2 + 0x30);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x28) * 2 - *(int *)(iVar2 + 0x28);
    iVar2 = *(int *)(param_1 + 0x30) * 2 - *(int *)(iVar2 + 0x30);
  }
  func_0x80032e74(param_1,iVar1,iVar2,(int)param_2);
  return;
}
