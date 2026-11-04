/* FUN_80090828
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090828  body 0x80090828..0x80090883  size 92 B
 * body sha256 57876c0ff47c8a1e8b0fd12b244b0ffe324679d9452bba309bfca32064a5b347
 * provider record sha256 44022f5e5f0307163c2d098341e5d0a35d43a13439673967b5edeadfa77a94a0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80090828(void)

{
  byte bVar1;
  int unaff_s0;
  
  bVar1 = *(byte *)(unaff_s0 + 3);
  *(byte *)(unaff_s0 + 3) = bVar1 + 1;
  if (0xc < bVar1) {
    *(undefined1 *)(unaff_s0 + 2) = 3;
    *(undefined1 *)(unaff_s0 + 3) = 0;
    FUN_80077adc(0x4090000,0);
  }
  *(short *)(unaff_s0 + 0x3c) = *(short *)(unaff_s0 + 0x3c) + -0x16;
  *(short *)(unaff_s0 + 0x46) = *(short *)(unaff_s0 + 0x46) + -0x13;
  *(short *)(unaff_s0 + 0x34) = *(short *)(unaff_s0 + 0x34) + 0x15;
  *(short *)(unaff_s0 + 0x3a) = *(short *)(unaff_s0 + 0x3a) + 0x15;
  FUN_80097fd0();
  return;
}
