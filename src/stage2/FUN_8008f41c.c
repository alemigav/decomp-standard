/* FUN_8008f41c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f41c  body 0x8008f41c..0x8008f457  size 60 B
 * body sha256 a961df7ba81715213a5231e998e63df12ce00754214bcc7f9681190c2c91d68c
 * provider record sha256 6e9bace1cf440f6a76ec08383d5b318469b6f490e54619ca650db2ec6b5db02e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f41c(void)

{
  int unaff_s2;
  
  *(undefined1 *)(unaff_s2 + 4) = 0;
  *(undefined1 *)(unaff_s2 + 3) = 0;
  *(undefined1 *)(unaff_s2 + 2) = 0;
  *(undefined1 *)(unaff_s2 + 5) = 0;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
