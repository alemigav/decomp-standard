/* FUN_8015cae0
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015cae0  body 0x8015cae0..0x8015ce7b  size 924 B
 * body sha256 74a73c3ef4f39321ddec539bbb999bf6ee07721bdf829221b615878570ac5ba3
 * provider record sha256 77562e2a38aa118cac9cb85b42e01e1a133cc34f3688e83e0e70e386a1acab68
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015cae0(void)

{
  uint uVar1;
  
  if (DAT_80160c1f != 1) {
    if (1 < DAT_80160c1f) {
      if (DAT_80160c1f != 2) {
        if (DAT_80160c1f == 3) {
          DAT_801614f8 = 1;
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
        goto LAB_8015ce44;
      }
      if (((_DAT_800df90e & 0x4000) != 0) && (DAT_80160c22 == '\0')) {
        DAT_80160c22 = '\x01';
        func_0x80077adc(0x4040000,0);
      }
      if ((_DAT_800df90e & 0x1000) == 0) {
LAB_8015cc5c:
        if (DAT_80160c22 == '\0') goto LAB_8015cc6c;
      }
      else {
        if (DAT_80160c22 != '\0') {
          DAT_80160c22 = DAT_80160c22 + -1;
          func_0x80077adc(0x4040000,0);
          goto LAB_8015cc5c;
        }
LAB_8015cc6c:
        if ((_DAT_800df90e & 0x8000) != 0) {
          if ((DAT_800e9012 & 0xc) != 0) {
            DAT_800e9012 = DAT_800e9012 & 0xf3 | (DAT_800e9012 & 0xc) - 4;
            func_0x80077adc(0x4040000,0);
          }
        }
        if ((_DAT_800df90e & 0x2000) != 0) {
          uVar1 = (DAT_800e9012 & 0xc) >> 2;
          if (uVar1 < 2) {
            DAT_800e9012 = DAT_800e9012 & 0xf3 | ((char)uVar1 + '\x01') * '\x04';
            func_0x80077adc(0x4040000,0);
          }
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
          DAT_80160c1e = 5;
          func_0x80077adc(0x4060000,0);
        }
      }
      goto LAB_8015ce44;
    }
    if (DAT_80160c1f != 0) goto LAB_8015ce44;
    DAT_80160c26 = -0x80;
    DAT_80160c24 = '\x02';
    DAT_80160c25 = '\0';
    DAT_80160c27 = '\0';
    DAT_80160c23 = '\0';
    DAT_801614f8 = 0;
    DAT_80160c1f = 1;
    DAT_800e9012 = DAT_800e9012 & 0xf3;
  }
  DAT_80160c26 = DAT_80160c26 + -0x10;
  DAT_80160c25 = DAT_80160c25 + '\x01';
  DAT_80160c27 = DAT_80160c27 + '\x10';
  if (DAT_80160c25 == '\b') {
    DAT_80160c26 = '\0';
    DAT_80160c27 = -0x80;
    DAT_80160c1f = DAT_80160c1f + 1;
  }
LAB_8015ce44:
  FUN_8015ef4c(DAT_80160c22);
  FUN_8015e384(1,1,0x1b,DAT_801614f8);
  return;
}
