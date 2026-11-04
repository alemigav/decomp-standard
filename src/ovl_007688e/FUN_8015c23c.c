/* FUN_8015c23c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015c23c  body 0x8015c23c..0x8015c60b  size 976 B
 * body sha256 155616c9c9e19a79929d465f2c50c29629d03e30ae883f120c8bd30b52708b2e
 * provider record sha256 ed26a0185914ca3e90289508ce8177e8994715f1450f6ae58b914a1babb577e3
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015c23c(void)

{
  uint uVar1;
  
  if (DAT_80160c1f != 1) {
    if (1 < DAT_80160c1f) {
      if (DAT_80160c1f != 2) {
        if (DAT_80160c1f == 3) {
          DAT_801614e8 = 1;
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
        goto LAB_8015c5d4;
      }
      if (((_DAT_800df90e & 0x4000) != 0) && (DAT_80160c22 == '\0')) {
        DAT_80160c22 = '\x01';
        func_0x80077adc(0x4040000,0);
      }
      if ((_DAT_800df90e & 0x1000) == 0) {
LAB_8015c3a4:
        if (DAT_80160c22 == '\0') goto LAB_8015c3b4;
      }
      else {
        if (DAT_80160c22 != '\0') {
          DAT_80160c22 = DAT_80160c22 + -1;
          func_0x80077adc(0x4040000,0);
          goto LAB_8015c3a4;
        }
LAB_8015c3b4:
        if (((_DAT_800df90e & 0x8000) != 0) && (DAT_8016150c != 0)) {
          DAT_8016150c = DAT_8016150c - 1;
          func_0x80077adc(0x4040000,0);
        }
        if (((_DAT_800df90e & 0x2000) != 0) && (DAT_8016150c == 0)) {
          DAT_8016150c = 1;
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
      }
      if (((_DAT_800df918 & 0x1000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
        if (DAT_80160c22 == '\x01') {
          func_0x80077adc(0x4050000,0);
          DAT_80160c1f = 3;
          DAT_80160c29 = 0;
        }
        else {
          DAT_80160c21 = 1;
          uVar1 = func_0x8009bea0(_DAT_8010b6f8);
          DAT_80160c1e = 7;
          if ((uVar1 & 1) == 0) {
            DAT_80160c1e = 4;
          }
          if ((DAT_8016150c & 1) == 0) {
            _DAT_800e110c = _DAT_800e110c & 0x7fffffff;
          }
          else {
            _DAT_800e110c = _DAT_800e110c | 0x80000000;
          }
          func_0x80077adc(0x4060000,0);
        }
      }
      goto LAB_8015c5d4;
    }
    if (DAT_80160c1f != 0) goto LAB_8015c5d4;
    DAT_8016150c = 0;
    DAT_80160c26 = -0x80;
    DAT_80160c24 = '\x02';
    DAT_80160c25 = '\0';
    DAT_80160c27 = '\0';
    DAT_80160c23 = '\0';
    DAT_801614e8 = 0;
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
LAB_8015c5d4:
  FUN_8015e934(DAT_80160c22);
  FUN_8015e384(1,1,0x1b,DAT_801614e8);
  return;
}
