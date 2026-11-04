/* FUN_8008f190
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f190  body 0x8008f190..0x8008f19b  size 12 B
 * body sha256 1f1d4b7b076cfe29ee95cb65f57c7b9d170851ec9c8b7b4adffdaa09ea5b7ab4
 * provider record sha256 839a013c9951ca1400564fa6eed2bb86d65496f7cd0ac5852612d1046e479a7e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f190(void)

{
  byte bVar1;
  int unaff_s2;
  
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + -0xc;
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (4 < bVar1) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + 6;
  *(short *)(unaff_s2 + 0x3a) = *(short *)(unaff_s2 + 0x3a) + 8;
  *(short *)(unaff_s2 + 0x48) = *(short *)(unaff_s2 + 0x48) + 8;
  *(short *)(unaff_s2 + 0x40) = *(short *)(unaff_s2 + 0x40) + -6;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
