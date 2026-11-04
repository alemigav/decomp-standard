/* FUN_800a3264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a3264  body 0x800a3264..0x800a3373  size 272 B
 * body sha256 c99182c919f7662465e4b8fb08beaddb2d646699ad8e0f1ad30c77ba655f7bb7
 * provider record sha256 7a287d874765088285c721e85cfd620b08f7df4be7b5341ec8ddbb578eead51b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a3264(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  _DAT_80143f78 = (int *)(*_DAT_80144008)(param_1 * 0x14,0);
  _DAT_80143f7c = (*_DAT_80144008)(param_1 << 8,0);
  func_0x80007320(_DAT_80143f7c,param_1 << 8);
  iVar6 = _DAT_80143f7c;
  piVar1 = _DAT_80143f78;
  iVar5 = 1;
  _DAT_80143f84 = 0;
  _DAT_80143f88 = _DAT_80143f78;
  _DAT_80143f78[2] = _DAT_80143f7c;
  piVar1[1] = 0;
  if (1 < param_1) {
    iVar4 = 0;
    piVar3 = piVar1;
    do {
      iVar6 = iVar6 + 0x100;
      piVar3[7] = iVar6;
      iVar2 = (int)piVar1 + iVar4;
      iVar4 = iVar4 + 0x14;
      piVar3[6] = iVar2;
      *piVar3 = (int)(piVar3 + 5);
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 5;
    } while (iVar5 < param_1);
  }
  _DAT_80143f80 = 0;
  _DAT_80143f78[iVar5 * 5 + -5] = 0;
  return;
}
