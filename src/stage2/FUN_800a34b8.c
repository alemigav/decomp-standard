/* FUN_800a34b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a34b8  body 0x800a34b8..0x800a35c7  size 272 B
 * body sha256 5395afc4dbb647ea385b4a241b33d36559446689f2a355053af032a7318d0a8d
 * provider record sha256 418a569738918c294739436782d2b19a32dbd9587127d55272c5c329b9d38d52
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a34b8(uint param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  param_1 = param_1 & 0xffff;
  _DAT_80143f8c = (*_DAT_80144008)(param_1 * 0x600,0);
  func_0x80007320(_DAT_80143f8c,param_1 * 0x600);
  piVar2 = (int *)(*_DAT_80144008)(param_1 * 0x18,0);
  iVar5 = _DAT_80143f8c;
  iVar6 = 1;
  _DAT_80143f94 = 0;
  _DAT_80143f98 = 0;
  _DAT_80143f90 = piVar2;
  _DAT_80143f9c = piVar2;
  piVar2[1] = 0;
  piVar2[5] = iVar5;
  if (1 < param_1) {
    iVar4 = 0;
    piVar1 = piVar2;
    do {
      iVar5 = iVar5 + 0x600;
      piVar1[0xb] = iVar5;
      iVar3 = (int)piVar2 + iVar4;
      iVar4 = iVar4 + 0x18;
      *piVar1 = (int)(piVar1 + 6);
      piVar1[7] = iVar3;
      iVar6 = iVar6 + 1;
      piVar1 = piVar1 + 6;
    } while (iVar6 < (int)param_1);
  }
  _DAT_80143f90[iVar6 * 6 + -6] = 0;
  return;
}
