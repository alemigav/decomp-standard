/* FUN_80054cf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054cf8  body 0x80054cf8..0x80054d47  size 80 B
 * body sha256 e36bf7822433f19581b9c6bb8f25a82bde89d3511fdcec348352ec46a078db18
 * provider record sha256 2ddd66de35f39802447fd7c9cd6a9a09c00cac6ca75e31980d6e987e7d51aeb4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054cf8(void)

{
  int unaff_s2;
  uint unaff_s3;
  
  DAT_80139bef = 4;
  FUN_800539a0(1,"|1This name is not in the]researcher data base.|0]",&DAT_8010da24);
  if ((DAT_8010da24 & DAT_8010da20) != 0) {
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
