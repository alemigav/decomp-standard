/* FUN_8015ce7c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015ce7c  body 0x8015ce7c..0x8015d267  size 1004 B
 * body sha256 99f8150655d277a27e7492e1f4c90b5a999b640819f2ebbeaabdae16d30b1ff3
 * provider record sha256 7028eac3d5c25dd4c631afa5ecbbbb5bb159bd121d8fe76d32ff03f7c669c852
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015ce7c(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_80160c1f != 1) {
    if (1 < DAT_80160c1f) {
      if (DAT_80160c1f != 2) {
        if (DAT_80160c1f == 3) {
          DAT_80161500 = 1;
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
        goto LAB_8015d228;
      }
      if (((_DAT_800df90e & 0x4000) != 0) && (DAT_80160c22 == '\0')) {
        DAT_80160c22 = '\x01';
        func_0x80077adc(0x4040000,0);
      }
      if ((_DAT_800df90e & 0x1000) == 0) {
LAB_8015d000:
        if (DAT_80160c22 == '\0') goto LAB_8015d010;
      }
      else {
        if (DAT_80160c22 != '\0') {
          DAT_80160c22 = DAT_80160c22 + -1;
          func_0x80077adc(0x4040000,0);
          goto LAB_8015d000;
        }
LAB_8015d010:
        if ((_DAT_800df90e & 0x8000) != 0) {
          if ((DAT_800e9012 & 3) != 0) {
            DAT_800e9012 = DAT_800e9012 & 0xfc | (DAT_800e9012 & 3) - 1;
            func_0x80077adc(0x4040000,0);
          }
        }
        if ((_DAT_800df90e & 0x2000) != 0) {
          if ((DAT_800e9012 & 3) < 2) {
            DAT_800e9012 = DAT_800e9012 & 0xfc | (DAT_800e9012 & 3) + 1;
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
          DAT_80160c29 = '\0';
        }
        else {
          uVar1 = _DAT_800e10ec | 0x20000;
          if (DAT_80160c29 == '\x01') {
            uVar1 = _DAT_800e10ec | 0x20020;
          }
          _DAT_800e10ec = uVar1;
          DAT_80160c21 = 1;
          DAT_80160c1e = 6;
          iVar2 = (DAT_800e9012 & 3) * 4;
          _DAT_800c76b0 = *(undefined4 *)(&DAT_80160870 + iVar2);
          _DAT_800c76b4 = *(undefined4 *)(&DAT_8016087c + iVar2);
        }
      }
      goto LAB_8015d228;
    }
    if (DAT_80160c1f != 0) goto LAB_8015d228;
    DAT_80160c26 = -0x80;
    DAT_80160c24 = '\x02';
    DAT_80160c25 = '\0';
    DAT_80160c27 = '\0';
    DAT_80160c23 = '\0';
    DAT_80161500 = 0;
    DAT_80160c1f = 1;
    DAT_800e9012 = DAT_800e9012 & 0xfc;
  }
  DAT_80160c26 = DAT_80160c26 + -0x10;
  DAT_80160c25 = DAT_80160c25 + '\x01';
  DAT_80160c27 = DAT_80160c27 + '\x10';
  if (DAT_80160c25 == '\b') {
    DAT_80160c26 = '\0';
    DAT_80160c27 = -0x80;
    DAT_80160c1f = DAT_80160c1f + 1;
  }
LAB_8015d228:
  FUN_8015f298(DAT_80160c22);
  FUN_8015e384(1,1,0x1b,DAT_80161500);
  return;
}
