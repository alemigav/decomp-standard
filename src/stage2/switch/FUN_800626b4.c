/* FUN_800626b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800626b4  body 0x800626b4..0x800627df  size 300 B
 * body sha256 043b98086ab218a1f63bf40d093ebeb2ab7999b15ae2c2c098b250c85fb4a554
 * provider record sha256 0396a76ce14753e58306f6f44ac4c35ab89e2d0dc0a39aa38ea0ab32ece1f4e6
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void switchD_800625a4::caseD_2(void)

{
  char cVar1;
  int unaff_s0;
  uint unaff_s3;
  
  FUN_8005c308();
  DAT_800e112a = DAT_800e112a | 1;
  FUN_8005ab48();
  FUN_80089d54();
  (*(code *)(&PTR_FUN_80111078)[(*(ushort *)(unaff_s0 + 0x1aa) & 0xfff) - 1])();
  if ((unaff_s3 & 0x100) == 0) {
    *(undefined2 *)(unaff_s0 + 6) = 0x300;
    FUN_80077adc(0x10c0001,unaff_s0 + 0x28);
  }
  else if ((unaff_s3 & 0x40) == 0) {
    *(undefined1 *)(unaff_s0 + 7) = 3;
  }
  else {
    if (((*(short *)(unaff_s0 + 0x1a8) != 0) &&
        (*(short *)(unaff_s0 + 0x1a8) < *(short *)(unaff_s0 + 0x25e))) &&
       ((*(byte *)(unaff_s0 + 0x1e9) & 3) == 0)) {
      FUN_8005c3e8();
    }
    cVar1 = DAT_800df8c0;
    if (((unaff_s3 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
      *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -8;
    }
    if (((unaff_s3 & 2) != 0) || ('\x19' < cVar1)) {
      *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 8;
    }
  }
  return;
}
