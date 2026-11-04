/* FUN_8017bdb0
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017bdb0  body 0x8017bdb0..0x8017be6b  size 188 B
 * body sha256 42a1400c458974415047ce38aa9c7c2b6ca461f9a285df8831ae00aab96b7e0f
 * provider record sha256 f2963bd6ebb9413accf5c85b219abc81456220e900d4e25ad88da4ae61f9f56f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017bdb0(void)

{
  DAT_8017e728 = 3000;
  DAT_8017e704 = 0;
  DAT_8017e730 = 0;
  DAT_8017e700 = 8;
  DAT_8017e736 = 1;
  DAT_8017e72e = 0x10;
  DAT_8017e73c = &DAT_8017e530;
  DAT_8017e72c = _DAT_800e1196;
  DAT_8017e710 = *(int *)(_DAT_800e1364 + 0x50) + -1000;
  DAT_8017e718 = *(undefined4 *)(_DAT_800e1364 + 0x4c);
  DAT_8017e720 = *(undefined4 *)(_DAT_800e1364 + 0x54);
  DAT_8017e71c = *(int *)(_DAT_800e1364 + 0x50) + -300;
  FUN_8017c234();
  FUN_8017be6c();
  FUN_8017c168();
  FUN_8017c664();
  return;
}
