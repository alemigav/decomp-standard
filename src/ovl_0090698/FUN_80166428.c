/* FUN_80166428
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166428  body 0x80166428..0x80166563  size 316 B
 * body sha256 15438df44a7f0e8b03c1bb3968347bd790a3a18c1082a4add783965909b90377
 * provider record sha256 40399ec499e2660385ba06fbf9accc6753f4da47926901fc62261cc1f60296e7
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166428(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((*(char *)(param_1 + 6) == '\0') && (*(char *)(param_1 + 0x2c0) == '\0')) {
    uVar4 = 4;
    if (*(short *)(param_1 + 0x1a8) != 0) {
      uVar4 = 5;
    }
    FUN_8016703c(param_1,0,uVar4);
    uVar3 = 0;
    do {
      uVar1 = func_0x80033604();
      iVar2 = (uVar1 & 0xf) + 3;
      uVar1 = *(uint *)(*(int *)(param_1 + 0x234) + iVar2 * 0x178);
      if (((uVar1 & 1) != 0) && (((DAT_800e9012 & 8) == 0 || ((uVar1 & 0x4a) == 0)))) {
        FUN_8016703c(param_1,iVar2,uVar4);
        FUN_8016703c(param_1,iVar2,5);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
    FUN_801679c8(param_1,0x202f2f);
  }
  FUN_8016577c(param_1,param_2,param_3);
  return;
}
