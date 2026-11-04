/* FUN_800545f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800545f4  body 0x800545f4..0x8005464b  size 88 B
 * body sha256 0097d185ebf245fbc13516eb989665cd41566b36e00cf1332b7f13f53f6de0f8
 * provider record sha256 0e7bd6befd84c978893048d9f652fd6f09b90f3889bdcf1b26789e2f066ebb0a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800545f4(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  _DAT_80139be8 = &DAT_8010d9d6;
  FUN_800539a0(1,"]Checking up ID CARD[025.[025.[025.[025.",&DAT_8010da18);
  if (DAT_8010da18 != 0) {
    DAT_800e8609 = 7;
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
