/* FUN_801676cc
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801676cc  body 0x801676cc..0x801677af  size 228 B
 * body sha256 31debe60f3ef95b9ba0ef3305bfd80676d83bd884bcdb97017752eda0a6f1d6a
 * provider record sha256 59ed9ba9ddefb99cb51f0de24d22c7882a1dd256fba6d64e362a8069a93b38c1
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801676cc(int param_1)

{
  int iVar1;
  undefined1 uVar3;
  undefined4 uVar2;
  
  iVar1 = FUN_8016760c();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = func_0x80059e00(0x14,0);
    if (iVar1 == 2) {
      FUN_801675ec();
      uVar2 = 0xffffffff;
    }
    else {
      _DAT_800e1324 =
           func_0x80032d14((int)*(short *)(*(int *)(param_1 + 0x234) + 0x4b6),
                           (int)*(short *)(*(int *)(param_1 + 0x234) + 0x4be),(int)_DAT_800e115a,
                           (int)_DAT_800e1162);
      if (*(char *)(param_1 + 0x2bd) == '\0') {
        uVar3 = func_0x80033144(param_1,&DAT_800e1130);
        FUN_801675bc(param_1,0,uVar3);
      }
      else {
        uVar3 = func_0x80033144(param_1,&DAT_800e1130);
        FUN_80167598(uVar3);
      }
      func_0x80052bd0(8,0);
      func_0x80052c6c(8,0xfa,4);
      uVar2 = 1;
    }
  }
  return uVar2;
}
