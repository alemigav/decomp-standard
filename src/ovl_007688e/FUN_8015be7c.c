/* FUN_8015be7c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015be7c  body 0x8015be7c..0x8015c23b  size 960 B
 * body sha256 fbf1c1ea2a13106996d2494e46d3d211c1fba9eab1084fde4af5bc74e3f7a255
 * provider record sha256 a913106b04095e719a47c9d1b304751bd49e59258fb3622fa33afa6399f77a4b
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015be7c(void)

{
  if (DAT_80160c1f != 1) {
    if (1 < DAT_80160c1f) {
      if (DAT_80160c1f != 2) {
        if (DAT_80160c1f == 3) {
          DAT_801614e0 = 1;
          DAT_80160c23 = '\0';
          DAT_80160c26 = DAT_80160c26 + '\x10';
          DAT_80160c27 = DAT_80160c27 + -0x10;
          DAT_80160c25 = DAT_80160c25 + -1;
          if (DAT_80160c25 == '\0') {
            DAT_80160c26 = -0x80;
            DAT_80160c27 = '\0';
            DAT_80160c22 = '\x01';
            DAT_80160c1e = 0;
            DAT_80160c1f = 0;
          }
        }
        goto LAB_8015c204;
      }
      if (((_DAT_800df90e & 0x4000) != 0) && (DAT_80160c22 == '\0')) {
        DAT_80160c22 = '\x01';
        func_0x80077adc(0x4040000,0);
      }
      if ((_DAT_800df90e & 0x1000) == 0) {
LAB_8015bfe8:
        if (DAT_80160c22 == '\0') goto LAB_8015bff8;
      }
      else {
        if (DAT_80160c22 != '\0') {
          DAT_80160c22 = DAT_80160c22 + -1;
          func_0x80077adc(0x4040000,0);
          goto LAB_8015bfe8;
        }
LAB_8015bff8:
        if (((_DAT_800df90e & 0x8000) != 0) && (DAT_80160c29 == 1)) {
          DAT_80160c29 = 0;
          func_0x80077adc(0x4040000,0);
        }
        if (((_DAT_800df90e & 0x2000) != 0) && (DAT_80160c29 == 0)) {
          DAT_80160c29 = 1;
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
        DAT_80160c29 = (byte)DAT_801614e4;
      }
      if (((_DAT_800df918 & 0x1000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
        if (DAT_80160c22 == '\x01') {
          func_0x80077adc(0x4050000,0);
          DAT_80160c1f = 3;
          DAT_80160c29 = 0;
        }
        else {
          if (DAT_80160c29 == 1) {
            _DAT_800e10ec = _DAT_800e10ec | 0x20;
          }
          DAT_80160c21 = 1;
          DAT_80160c1e = 3;
          func_0x80077adc(0x4060000,0);
          func_0x80052bd0(7,0);
          func_0x80052c6c(9,0xff,0);
          func_0x80052d10(4,0xff,0x3c,10);
        }
      }
      goto LAB_8015c204;
    }
    if (DAT_80160c1f != 0) goto LAB_8015c204;
    DAT_80160c26 = -0x80;
    DAT_80160c24 = '\x02';
    DAT_80160c25 = '\0';
    DAT_80160c27 = '\0';
    DAT_80160c23 = '\0';
    DAT_801614e0 = 0;
    DAT_801614e4 = (uint)DAT_80160c29;
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
LAB_8015c204:
  FUN_8015e670(DAT_80160c22);
  FUN_8015e384(1,1,0x1b,DAT_801614e0);
  return;
}
