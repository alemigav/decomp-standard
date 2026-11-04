/* FUN_80054810
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054810  body 0x80054810..0x8005488b  size 124 B
 * body sha256 797f87fba67d00c3883fd1d15151960d4420cb73f6140870c7e146eb499e18a5
 * provider record sha256 9cf6a528584b726a5971b85bd9d7a90a64599eaf8ae77eb2347c7522f250c032
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80054810(void)

{
  bool bVar1;
  int unaff_s2;
  uint unaff_s3;
  
  _DAT_80139be8 = &DAT_8010d960;
  FUN_800539a0(1,"press any key]>",&DAT_8010da18);
  bVar1 = (DAT_8010da18 & DAT_8010da14) != 0;
  DAT_8010da1c = 1;
  if (bVar1) {
    FUN_80053d38();
    DAT_800e8609 = 0xb;
  }
  DAT_8010da1c = !bVar1;
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da14 & DAT_8010da18) != 0) || (unaff_s3 != DAT_800e8609)) {
    _DAT_80139be8 = (undefined *)0x0;
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    _DAT_80139be4 = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
