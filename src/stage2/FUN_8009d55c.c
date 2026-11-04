/* FUN_8009d55c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d55c  body 0x8009d55c..0x8009d707  size 428 B
 * body sha256 104db05f09814c982d9a0415c11d051c4411ffc08ac69864be23139a35e3214f
 * provider record sha256 ca707c960e003f11f473773d52b87d9f2fe890ab4d489816d5d2917ff6f24333
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d55c(void)

{
  int iVar1;
  
  if (DAT_8013273a == 0x60) {
    FUN_80025f78(1,2,&DAT_801326b4);
    DAT_8013272b = 3;
    DAT_80132728 = 0;
    FUN_8009ce40();
    DAT_80132740 = 0xf00000;
    FUN_8009e8d4(7,0);
    func_0x80004a6c(1,5);
  }
  if (DAT_8013273a == 0x6a) {
    DAT_80132740 = 0x3000000;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0xc9) {
    DAT_80132740 = 0x3000000;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0xd3) {
    DAT_80132740 = 0xc000000;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x105) {
    DAT_80132740 = 0x80000;
    FUN_8009e8d4(0x2b,0);
  }
  if (DAT_8013273a == 0x145) {
    DAT_80132740 = 0xc000000;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x1bd) {
    FUN_80077430(0x5a,0x18);
    DAT_80132728 = 8;
    DAT_80132729 = 0;
    DAT_8013272c = 2;
    FUN_8009ced8();
  }
  if ((0x1bd < DAT_8013273a) && (iVar1 = FUN_8002767c(DAT_8013272b), iVar1 != 0)) {
    DAT_80132729 = 1;
    DAT_80132740 = 0;
    FUN_8009e8d4(0);
    DAT_8013272e = 6;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
