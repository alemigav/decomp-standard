/* FUN_800547b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800547b4  body 0x800547b4..0x8005480f  size 92 B
 * body sha256 aadf18232250cb581ae51ec9274768a913eacdd178ecee050467030be20f43c8
 * provider record sha256 26504ff98cfb1a959bc6613c68f66c4be1c2d2e8e150b4dcfc965de4439792f1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800547b4(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  _DAT_80139be8 = &DAT_8010d9eb;
  FUN_800539a0(1,"]OK!]Hall side doors lock released.",&DAT_8010da18);
  if ((DAT_8010da18 & DAT_8010da14) != 0) {
    DAT_800e8609 = 0xb;
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
