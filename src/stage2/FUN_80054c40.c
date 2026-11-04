/* FUN_80054c40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054c40  body 0x80054c40..0x80054c9b  size 92 B
 * body sha256 8e7fe6a1434f42242577c307da2f6aefb054a64c031490f876e2843290aea580
 * provider record sha256 c5884191ef71c24358257037f7f3d60ea46e054eb1f71c898432e7df8b8f8623
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054c40(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bef = 3;
  FUN_800539a0(1,"Enter your user name.]>",&DAT_8010da24);
  if ((DAT_8010da24 & DAT_8010da20) != 0) {
    DAT_800e8609 = 5;
    DAT_800e860a = 1;
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
