/* FUN_80054e60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054e60  body 0x80054e60..0x80054f7b  size 252 B
 * body sha256 dc57a571bf50e20936aca7ecdce7d8cd24e9c27e48a5287c9ee32f4e0a2e6e0a
 * provider record sha256 0bad75b8fcc0332546dbd376e4370a152e97aebb9117b5f7513aca77f3012dd8
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054e60(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bee = 10;
  DAT_80139bef = 0xb;
  FUN_800539a0(1,"Guest registration is valid]for 24 hours.]",&DAT_8010da24);
  if ((DAT_8010da24 & DAT_8010da20) == 0) {
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
  }
  else {
    DAT_800e110c = DAT_800e110c & 0xfffffdff;
    FUN_800550ec(1);
  }
  return;
}
