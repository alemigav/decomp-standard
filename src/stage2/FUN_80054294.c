/* FUN_80054294
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054294  body 0x80054294..0x800542f7  size 100 B
 * body sha256 3b61e334b4a9547d233d00bb46b90980ff50a3a71527e927b7ee6214c32589dc
 * provider record sha256 93409e4b9d7219f075a004997520be9cc60befe965ca0e5505c1edf2f0d19e8b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80054294(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  _DAT_80139be8 = &DAT_8010d960;
  FUN_800539a0(1,"DOOR LOCK SERVICE]------------------------------",&DAT_8010da18);
  if ((DAT_8010da18 & DAT_8010da14) != 0) {
    DAT_800e8609 = 2;
  }
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
