/* FUN_80059e00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059e00  body 0x80059e00..0x80059ed7  size 216 B
 * body sha256 ead5cc8992fef012f3be1cff9c5ebfba73a64a192478e543153bbf7e1728e3cd
 * provider record sha256 c47e0e8b647a4271ecadf43f1e3adbd53e66f11df3b2a52c679ad1b075f46c89
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80059e00(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 0x29) {
    param_1 = param_1 + (param_1 >> 1);
  }
  param_1 = (uint)DAT_800e1322 - param_1;
  uVar1 = 1;
  DAT_800e1322 = (short)param_1;
  if (param_2 == 1) {
    if (param_1 * 0x10000 < 0) {
      DAT_800e1322 = 0;
      DAT_800e1320 = DAT_800e1320 | 0x1000;
      return 1;
    }
    return 0;
  }
  if (param_2 == 0) {
    iVar2 = param_1 * 0x10000 >> 0x10;
    if (iVar2 < 0) {
      if ((iVar2 < -0xe) || ((DAT_800e1320 & 0x1000) != 0)) {
        DAT_800e139f = DAT_800e139f | 0x80;
        DAT_800e10ec = DAT_800e10ec | 0x4000000;
        return 2;
      }
      DAT_800e1322 = 0;
      DAT_800e1320 = DAT_800e1320 | 0x1000;
      return 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}
