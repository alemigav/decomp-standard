/* FUN_80054d48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054d48  body 0x80054d48..0x80054dc3  size 124 B
 * body sha256 36a0c24d2c2e9e0d27ca2db90028280093adb810db339066d9abb69ccba548a9
 * provider record sha256 516be7719aa8e0d9ac61c9eb66063bbd992516a1f437c8b4602b967825617d6a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054d48(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bef = 6;
  FUN_800539a0(1,"Register your fingerprint.",&DAT_8010da24);
  if ((DAT_8010da24 & DAT_8010da20) != 0) {
    DAT_800e110c = DAT_800e110c | 0x200;
    FUN_80083758(&DAT_800e8ce0,0x5b);
    DAT_800e8609 = 0xc;
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
