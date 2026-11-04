/* FUN_80054ba4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054ba4  body 0x80054ba4..0x80054bf7  size 84 B
 * body sha256 234987bd5f544a4b1e70f14d5373dfe47c1ba6b07a491dac709c9b330f668e71
 * provider record sha256 b09072c75a5166683b878cf400e6ea45f99a4328b15b163cd8052e302d7bdd16
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054ba4(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bef = 0xc;
  FUN_800539a0(1,"Culture Experiment Room Staff Registry.]]",&DAT_8010da24);
  if ((DAT_8010da24 & DAT_8010da20) != 0) {
    DAT_800e8609 = 3;
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
