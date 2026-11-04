/* FUN_8015d268
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015d268  body 0x8015d268..0x8015d5ab  size 836 B
 * body sha256 f3ce3c054d6e560f122cb8c453ee59d46060a3f38abd546456d3b94904a83407
 * provider record sha256 2ec2ec5454c4bd60be705787f3cbf73c6973e6f818367508bd64e254918e7cc3
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015d268(void)

{
  undefined4 uVar1;
  
  if (DAT_80160c1f != 1) {
    if (1 < DAT_80160c1f) {
      if (DAT_80160c1f != 2) {
        if (DAT_80160c1f == 3) {
          DAT_80160c23 = '\0';
          DAT_80161508 = 1;
          DAT_80160c26 = DAT_80160c26 + '\x10';
          DAT_80160c25 = DAT_80160c25 + -1;
          DAT_80160c27 = DAT_80160c27 + -0x10;
          if (DAT_80160c25 == '\0') {
            DAT_80160c26 = -0x80;
            DAT_80160c27 = '\0';
            DAT_80160c22 = '\x02';
            DAT_80160c1e = 0;
            DAT_80160c1f = 0;
          }
        }
        goto LAB_8015d574;
      }
      if (((_DAT_800df90e & 0x4000) != 0) && (DAT_80160c22 == '\0')) {
        DAT_80160c22 = '\x01';
        func_0x80077adc(0x4040000,0);
      }
      if ((_DAT_800df90e & 0x1000) == 0) {
LAB_8015d3c8:
        if (DAT_80160c22 == '\0') goto LAB_8015d3d8;
      }
      else {
        if (DAT_80160c22 != '\0') {
          DAT_80160c22 = DAT_80160c22 + -1;
          func_0x80077adc(0x4040000,0);
          goto LAB_8015d3c8;
        }
LAB_8015d3d8:
        if (((_DAT_800df90e & 0x8000) != 0) && (DAT_800dfbe9 != '\0')) {
          DAT_800dfbe9 = '\0';
          func_0x80077adc(0x4040000,0);
        }
        if (((_DAT_800df90e & 0x2000) != 0) && (DAT_800dfbe9 == '\0')) {
          DAT_800dfbe9 = '\x01';
          func_0x80077adc(0x4040000,0);
        }
      }
      DAT_80160c23 = DAT_80160c23 + DAT_80160c24;
      if (0x2f < (byte)(DAT_80160c23 - 1U)) {
        DAT_80160c24 = -DAT_80160c24;
      }
      if ((_DAT_800df918 & 0x2000) != 0) {
        func_0x80077adc(0x4050000,0);
        DAT_80160c1f = 3;
        DAT_800dfbe9 = DAT_80160c20;
      }
      if (((_DAT_800df918 & 0x1000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
        func_0x8007604c(DAT_800dfbe9);
        uVar1 = 0x4050000;
        if (DAT_80160c22 == '\0') {
          uVar1 = 0x4060000;
        }
        func_0x80077adc(uVar1,0);
        DAT_80160c1f = 3;
      }
      goto LAB_8015d574;
    }
    if (DAT_80160c1f != 0) goto LAB_8015d574;
    DAT_80160c26 = -0x80;
    DAT_80160c24 = '\x02';
    DAT_80160c25 = '\0';
    DAT_80160c27 = '\0';
    DAT_80160c23 = '\0';
    DAT_80161508 = 0;
    DAT_80160c1f = 1;
  }
  DAT_80160c26 = DAT_80160c26 + -0x10;
  DAT_80160c25 = DAT_80160c25 + '\x01';
  DAT_80160c27 = DAT_80160c27 + '\x10';
  if (DAT_80160c25 == '\b') {
    DAT_80160c26 = '\0';
    DAT_80160c27 = -0x80;
    DAT_80160c1f = DAT_80160c1f + 1;
  }
LAB_8015d574:
  FUN_8015f550(DAT_80160c22);
  FUN_8015e384(2,2,0x2f,DAT_80161508);
  return;
}
