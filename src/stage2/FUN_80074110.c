/* FUN_80074110
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074110  body 0x80074110..0x8007422f  size 288 B
 * body sha256 3ec828072217e4f94d221edca77fb193442fe549b178e6d084e3d6ecaa408613
 * provider record sha256 4aed06004e51b701ccb208934cc8fc3566269a1280fe5a5b556aba3189018f15
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80074110(void)

{
  int iVar1;
  
  if (DAT_800e861e == '\0') {
    iVar1 = FUN_8008c51c(0x1e);
    if (iVar1 < 0) {
      DAT_800e1110 = DAT_801317c4;
      FUN_8004ac04(0,0x100,0,0xff000000);
      DAT_800e8928 = 0;
      DAT_800e861e = '\0';
    }
    else {
      FUN_8004ac04(0,0x100,1,0xff000000);
      DAT_800e861e = '\x01';
    }
  }
  else if ((DAT_800e861e == '\x01') && ((DAT_8010b294 & 0x80) == 0)) {
    if ((DAT_8010b294 & 1) == 0) {
      DAT_80131780 = DAT_800e861e;
      DAT_800e10ec = DAT_800e10ec | 0x40000;
    }
    else {
      DAT_800e1110 = DAT_801317c4;
    }
    DAT_800e8928 = 0;
    DAT_800e861e = '\0';
  }
  return;
}
