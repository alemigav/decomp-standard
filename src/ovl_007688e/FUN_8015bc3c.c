/* FUN_8015bc3c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015bc3c  body 0x8015bc3c..0x8015be7b  size 576 B
 * body sha256 5b95421bfafe4316dc13403baf458f63e1282b5d8de69f430e2c150daa6d3915
 * provider record sha256 86bb98595760f7b1c5afc499dbee03757aa5904acf7c8de4b32bf4f5c02d97ab
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015bc3c(void)

{
  byte bVar1;
  
  _DAT_800e10ec = _DAT_800e10ec & 0xffffffdf;
  if (DAT_80160c1f == '\0') {
    DAT_80160c24 = '\x02';
    DAT_80160c25 = 0;
    DAT_80160c23 = '\0';
    DAT_80160c1f = '\x01';
  }
  else if (DAT_80160c1f != '\x01') {
    return;
  }
  if ((int)_DAT_800e10ec < 0) {
    if (((_DAT_800df90c & 0x4000) != 0) && (DAT_80160c22 < 2)) {
      DAT_80160c22 = DAT_80160c22 + 1;
      func_0x80077adc(0x4040000,0);
    }
    if (((_DAT_800df90c & 0x1000) != 0) && (DAT_80160c22 != 0)) {
      DAT_80160c22 = DAT_80160c22 - 1;
      func_0x80077adc(0x4040000,0);
    }
  }
  DAT_80160c23 = DAT_80160c23 + DAT_80160c24;
  if (0x2f < (byte)(DAT_80160c23 - 1U)) {
    DAT_80160c24 = -DAT_80160c24;
  }
  FUN_8015e384(DAT_80160c22,0,0,0);
  bVar1 = DAT_80160c22;
  if (((_DAT_800df918 & 0x1000) != 0) || ((_DAT_800df908 & 0x800) != 0)) {
    if (DAT_80160c22 == 1) {
      func_0x80077adc(0x4060000,0);
      DAT_80160c22 = 0;
      DAT_80160c1e = bVar1;
      DAT_80160c1f = '\0';
      DAT_80160c28 = 0;
    }
    else if (DAT_80160c22 < 2) {
      if (DAT_80160c22 == 0) {
        DAT_80160c21 = 0;
        DAT_80160c1e = 6;
        DAT_80160c1f = '\0';
        func_0x80052bd0(7,0);
        func_0x80052c6c(9,0xff,0);
        func_0x80052d10(4,0xff,0x3c,10);
      }
    }
    else if (DAT_80160c22 == 2) {
      DAT_80160c21 = DAT_80160c22;
      DAT_80160c1e = 6;
      DAT_80160c1f = '\0';
    }
  }
  return;
}
