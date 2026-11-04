/* FUN_80054c9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054c9c  body 0x80054c9c..0x80054cf7  size 92 B
 * body sha256 fbd7e049a591dfdfe84f3d2879492b2ba3b21aa6922078f8ef94f768857932bc
 * provider record sha256 81d495dea597fc9223cfdc74139e130743d7c879ef4ac4d295316b3a007f667d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054c9c(void)

{
  int iVar1;
  int unaff_s2;
  uint unaff_s3;
  
  iVar1 = FUN_80052ffc(8,0);
  if (iVar1 != 0) {
    DAT_800e860a = 2;
    iVar1 = FUN_80082308(unaff_s2 + 0x2e4,"NEMESIS");
    if (iVar1 == 0) {
      DAT_800e8609 = 7;
      FUN_80053d38();
    }
    else {
      DAT_800e8609 = 6;
    }
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
