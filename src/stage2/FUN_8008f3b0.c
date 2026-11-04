/* FUN_8008f3b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f3b0  body 0x8008f3b0..0x8008f3c7  size 24 B
 * body sha256 2c9f7d5b5429210e3faa378f5c31433038950af4fc3a3ea60f474f17e17a28e5
 * provider record sha256 286ea5059ec83880cb0610a32daeede5ee543dd3d1008955b15540ebbed02843
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f3b0(void)

{
  byte bVar1;
  int unaff_s2;
  
  *(short *)(unaff_s2 + 0x4e) = *(short *)(unaff_s2 + 0x4e) + 0xf;
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + -0xc;
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (4 < bVar1) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + 6;
  *(short *)(unaff_s2 + 0x40) = *(short *)(unaff_s2 + 0x40) + 6;
  *(short *)(unaff_s2 + 0x3a) = *(short *)(unaff_s2 + 0x3a) + -8;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
