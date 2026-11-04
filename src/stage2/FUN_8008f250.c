/* FUN_8008f250
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f250  body 0x8008f250..0x8008f28f  size 64 B
 * body sha256 54614f0ef9708d547f577975a4b0ac5c1b620f5a541f1f779c255e82726da5cb
 * provider record sha256 549cbca1f06d5c4c4591daf0ae9652210a28e52aa2d1d3cca5caebdc6fd962b4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f250(void)

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
  *(short *)(unaff_s2 + 0x3a) = *(short *)(unaff_s2 + 0x3a) + -8;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
