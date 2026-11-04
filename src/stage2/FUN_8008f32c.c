/* FUN_8008f32c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f32c  body 0x8008f32c..0x8008f373  size 72 B
 * body sha256 e1413aad8ad03c8f858b6665addd680fba389a1dd9824cd1d0b8c55dd9448299
 * provider record sha256 0d7b6e7e56a32e26103c5fe116db7d18e891721f396f1b331e3a1bac2564d16c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f32c(void)

{
  byte bVar1;
  int unaff_s2;
  
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (4 < bVar1) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + 6;
  *(short *)(unaff_s2 + 0x3a) = *(short *)(unaff_s2 + 0x3a) + 8;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
