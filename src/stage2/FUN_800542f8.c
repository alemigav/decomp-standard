/* FUN_800542f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800542f8  body 0x800542f8..0x800543ef  size 248 B
 * body sha256 97576a70dd1ff10cda0ee0c389e6e0e6d7faa1774b7033be064d62ce1ce1aa69
 * provider record sha256 9e165b727dd95dceb88205a6a851506f79bd81263b1ae818e7fd6a0fe0e25ae0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800542f8(void)

{
  int iVar1;
  int unaff_s2;
  uint unaff_s3;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0x46);
  if (iVar1 == 0) {
    _DAT_80139be4 = &DAT_8010d993;
    _DAT_80139be8 = &DAT_8010d99d;
    FUN_800539a0(1,"Hall side doors:      |2LOCKED|0]",&DAT_8010da18);
    if ((DAT_8010da18 & DAT_8010da14) != 0) {
      DAT_800e8609 = 3;
    }
  }
  else {
    _DAT_80139be4 = &DAT_8010d972;
    _DAT_80139be8 = &DAT_8010d97c;
    FUN_800539a0(1,"Hall side doors:      |2RELEASED|0]",&DAT_8010da18);
    if ((DAT_8010da18 & DAT_8010da14) != 0) {
      DAT_800e8609 = 0xb;
    }
  }
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da14 & DAT_8010da18) != 0) || (unaff_s3 != DAT_800e8609)) {
    _DAT_80139be8 = (undefined *)0x0;
    DAT_8010da18 = 0;
    DAT_8010da14 = 0;
    _DAT_80139be4 = (undefined *)0x0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
