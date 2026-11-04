/* FUN_800543f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800543f0  body 0x800543f0..0x8005448b  size 156 B
 * body sha256 1047fa6dabe47d224e4985c45e913a21aba8a10046af15dd30ee1e68ea2d72e3
 * provider record sha256 4466e7263f167c361337001930415d6862f4d873ae724e0c11acafd86f590ced
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800543f0(void)

{
  int iVar1;
  int unaff_s2;
  uint unaff_s3;
  
  _DAT_80139be4 = &DAT_8010d9b3;
  _DAT_80139be8 = &DAT_8010d9c2;
  FUN_800539a0(1,"]The doors can be unlocked]by a |2CARD KEY|0.]",&DAT_8010da18);
  if ((DAT_8010da18 & DAT_8010da14) != 0) {
    iVar1 = FUN_800837ac(&DAT_800e8ce0,0x46);
    if (iVar1 == 0) {
      DAT_800e8609 = 4;
    }
    else {
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
