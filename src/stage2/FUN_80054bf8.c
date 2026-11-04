/* FUN_80054bf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054bf8  body 0x80054bf8..0x80054c3f  size 72 B
 * body sha256 526dbf09cd7c41b228db729091adf55def2c3dfe31eb3541304f59058260ef3a
 * provider record sha256 f80550b1987f12bd3169734caf4bec1d55646d16308a83e27682b72a428ec2ec
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054bf8(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bef = 2;
  FUN_800539a0(1,"Accessing[020.[020.[020.[020.[020.]]",&DAT_8010da24);
  if (DAT_8010da24 != 0) {
    DAT_800e8609 = 4;
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
