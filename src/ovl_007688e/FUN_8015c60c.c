/* FUN_8015c60c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015c60c  body 0x8015c60c..0x8015cadf  size 1236 B
 * body sha256 4f5568237587b84f2c1806258c77d4c21d2d78fb7a96ec786a6a3192ff5fc387
 * provider record sha256 9becc3c63df388dd4485b87219e65497172e2ad0cc04172ed2d90e0dd46fbe34
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015c60c(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  if (DAT_80160c1f != 1) {
    if (1 < DAT_80160c1f) {
      if (DAT_80160c1f != 2) {
        if (DAT_80160c1f == 3) {
          DAT_801614f0 = 1;
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
        goto LAB_8015caa4;
      }
      if (((_DAT_800df90e & 0x4000) != 0) && (DAT_80160c22 == '\0')) {
        DAT_80160c22 = '\x01';
        func_0x80077adc(0x4040000,0);
      }
      if ((_DAT_800df90e & 0x1000) == 0) {
LAB_8015c778:
        if (DAT_80160c22 == '\0') goto LAB_8015c788;
      }
      else {
        if (DAT_80160c22 != '\0') {
          DAT_80160c22 = DAT_80160c22 + -1;
          func_0x80077adc(0x4040000,0);
          goto LAB_8015c778;
        }
LAB_8015c788:
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
          DAT_80160c1e = 4;
          DAT_800e9012 = DAT_800e9012 & 0xf;
          if ((DAT_8016150c & 1) != 0) {
            iVar1 = func_0x80007000();
            _DAT_800f9e30 = iVar1 * 0x41c64e6d + 0x3039;
            fVar2 = ((float)((_DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / 32767.0) * 14.0 + 1.0;
            fVar3 = fVar2;
            if (fVar2 < 0.0) {
              fVar3 = -fVar2;
            }
            fVar3 = fVar3 - (float)(int)fVar3;
            if (0.5 < fVar3) {
              if (0.0 < fVar2) {
                fVar2 = fVar2 + (1.0 - fVar3);
              }
              else {
                fVar2 = fVar2 - fVar3;
              }
            }
            else if (0.0 <= fVar2) {
              fVar2 = fVar2 - fVar3;
            }
            else {
              fVar2 = fVar2 - (1.0 - fVar3);
            }
            DAT_800e9012 = DAT_800e9012 | (byte)((int)fVar2 << 4);
          }
          func_0x80077adc(0x4060000,0);
        }
      }
      goto LAB_8015caa4;
    }
    if (DAT_80160c1f != 0) goto LAB_8015caa4;
    DAT_8016150c = 0;
    DAT_80160c26 = -0x80;
    DAT_80160c24 = '\x02';
    DAT_80160c25 = '\0';
    DAT_80160c27 = '\0';
    DAT_80160c23 = '\0';
    DAT_801614f0 = 0;
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
LAB_8015caa4:
  FUN_8015ec40(DAT_80160c22);
  FUN_8015e384(1,1,0x1b,DAT_801614f0);
  return;
}
