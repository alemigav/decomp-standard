/* FUN_8008f238
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f238  body 0x8008f238..0x8008f24f  size 24 B
 * body sha256 a166d4497f05ad5a0408713f051e7e7a6606b6e87248f4a98aa0ffca5b711c77
 * provider record sha256 dd8d8b8cda06b054a10fb02dd073d58b1989a3d6e01dd1d11af5832d9c9ae7e3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f238(void)

{
  byte bVar1;
  int unaff_s2;
  
  *(short *)(unaff_s2 + 0x4e) = *(short *)(unaff_s2 + 0x4e) + -0xf;
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + -0xc;
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
