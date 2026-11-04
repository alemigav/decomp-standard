/* FUN_80054e0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054e0c  body 0x80054e0c..0x80054e5f  size 84 B
 * body sha256 73a2dd7c7746eb600f99e355d9cb66d358bad16c55857d01b6d1c88e4af8861f
 * provider record sha256 46db9eabd9eef978df2642293143338e7e4630470a9fa0acac579d9263205a9a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054e0c(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bef = 9;
  FUN_800539a0(1,"Registration complete.]]",&DAT_8010da24);
  if ((DAT_8010da24 & DAT_8010da20) != 0) {
    DAT_800e8609 = 10;
  }
  if (*(char *)(unaff_s2 + 0x2d9) == '\x01') {
    *(undefined1 *)(unaff_s2 + 0x2d9) = 0;
    DAT_800e8609 = 0xb;
  }
  if (((DAT_8010da20 & DAT_8010da24) != 0) || (unaff_s3 != DAT_800e8609)) {
    DAT_80139bef = 0;
    DAT_8010da24 = 0;
    DAT_8010da20 = 0;
    DAT_80139bee = 0;
  }
  FUN_80053d7c(1);
  FUN_80053eb8(0x16c);
  return;
}
