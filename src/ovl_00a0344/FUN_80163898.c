/* FUN_80163898
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163898  body 0x80163898..0x80163a2f  size 408 B
 * body sha256 d28d5fe345c868b0e4dda865e0372ee061dd588185d0d63cd5cbf046458421a8
 * provider record sha256 4a2e94126b58cabbce7005602c007b9428e270adaa3e6693fe235011ca2bec0a
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80163898(int param_1,int param_2,short param_3)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == 0) {
    iVar3 = -0x7ff1eed0;
  }
  else {
    iVar3 = _DAT_800e13ec;
  }
  iVar5 = 1;
  iVar4 = 0x178;
  while (((*(short *)(iVar3 + 0x1f2) < 0 ||
          (iVar1 = func_0x80033024(iVar3 + 0x28,*(int *)(param_1 + 0x234) + iVar4 + 0x4c,700),
          iVar1 == 0)) || (*(char *)(param_1 + 0x1a2) != *(char *)(iVar3 + 0x1a2)))) {
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x178;
    if (2 < iVar5) {
      return 0;
    }
  }
  if ((*(byte *)(iVar3 + 0x26f) & 0x80) != 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    iVar4 = func_0x80059e00((int)param_3,1);
  }
  else {
    iVar4 = func_0x80080e00(param_1,(int)param_3,1);
  }
  if (iVar4 == 1) {
    _DAT_800e1128 = _DAT_800e1128 | 0x20;
  }
  else {
    if (1 < iVar4) {
      if (iVar4 == 2) {
        FUN_80163b0c(iVar3);
      }
      goto LAB_801639e4;
    }
    if (iVar4 != 0) goto LAB_801639e4;
  }
  uVar2 = func_0x80033144(param_1,iVar3);
  FUN_80163ab8(iVar3,uVar2);
LAB_801639e4:
  func_0x80077d18(0,param_1);
  return 1;
}
