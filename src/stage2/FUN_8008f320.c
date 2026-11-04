/* FUN_8008f320
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f320  body 0x8008f320..0x8008f32b  size 12 B
 * body sha256 8bb61f6e926e41c693001f58e6bcff10f261f4ea001c7d1e84b086c3fe8632c0
 * provider record sha256 4ed5eedbcfdb02f2102c9a27d67339627d5412564a55c1e0417ab0c33963c02e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f320(void)

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
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
