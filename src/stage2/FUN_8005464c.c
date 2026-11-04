/* FUN_8005464c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005464c  body 0x8005464c..0x800547b3  size 360 B
 * body sha256 4c00f63ffc8dc1f24c7eb187142561ff6df30329ef04b13f674d479ce65a7770
 * provider record sha256 fdf97f605e2fe43ea758ba8183d9ab5b049f326f24cbef0e9e02153eb20276f6
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005464c(void)

{
  int iVar1;
  int iVar2;
  int unaff_s2;
  uint unaff_s3;
  
  iVar2 = (int)DAT_800e8cac;
  if (((DAT_800e110c & 0x40000000) == 0) || (iVar1 = FUN_800837ac(&DAT_800e8ec0,0x11), iVar1 == 0))
  {
    FUN_80027148(9);
    iVar1 = 0;
    do {
      FUN_8004cd88(1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3c);
    FUN_80077adc(0x2120000,0);
    iVar1 = 0;
    do {
      FUN_8004cd88(1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3c);
  }
  FUN_80027148(2);
  iVar1 = 0;
  do {
    FUN_8004cd88(1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x3c);
  FUN_80077adc(0x2120000,0);
  iVar1 = 0;
  do {
    FUN_8004cd88(1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x3c);
  if ((DAT_800e110c & 0x40000000) != 0) {
    FUN_80027148(0xc);
    iVar1 = 0;
    do {
      FUN_8004cd88(1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3c);
    FUN_80077adc(0x2120000,0);
    iVar1 = 0;
    do {
      FUN_8004cd88(1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x3c);
  }
  FUN_80027148(iVar2);
  DAT_800e8609 = 8;
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da14 & DAT_8010da18) != 0) || (unaff_s3 != DAT_800e8609)) {
    _DAT_80139be8 = 0;
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    _DAT_80139be4 = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
