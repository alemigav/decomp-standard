/* FUN_8008eff8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008eff8  body 0x8008eff8..0x8008f0a7  size 176 B
 * body sha256 a408a6bb948d1a6ce15c5ad93518245e1643094e2670972feeef2ba50b8407b5
 * provider record sha256 426f3e24952b799e81be2a8087478789a04b581e0549e898c7f673dc05cb0a45
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008eff8(void)

{
  int unaff_s2;
  int unaff_s3;
  
  if (*(char *)(unaff_s2 + 5) == '\0') {
    FUN_8004ac04(0xaf0010,0xe400,0xb,0);
    *(char *)(unaff_s2 + 5) = *(char *)(unaff_s2 + 5) + '\x01';
  }
  else if ((DAT_8010b294 & 0x80) == 0) {
    if ((DAT_8010b294 & 1) == 0) {
      *(undefined1 *)(unaff_s2 + 4) = 4;
    }
    else {
      *(undefined1 *)(unaff_s2 + 6) = 0;
      *(undefined1 *)(unaff_s2 + 5) = 0;
      *(undefined1 *)(unaff_s2 + 4) = 0;
    }
  }
  FUN_800965e4(*(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x2181a));
  return;
}
