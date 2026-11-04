/* FUN_8008f2cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f2cc  body 0x8008f2cc..0x8008f31f  size 84 B
 * body sha256 f3bde739c63cc0f8993d6b0f9dd3293f0c06df46fb73a15bc5753ffb05114b56
 * provider record sha256 3a70d526547d8f48d1ca63f7fa0f18aa0858a982e60ebf1dbece8bb46f8ae2b8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f2cc(void)

{
  int unaff_s2;
  int unaff_s3;
  
  if ((DAT_8010b294 & 0x80) == 0) {
    FUN_80077adc(0x4050000,0);
    FUN_80083758(&DAT_800e8d78,(&DAT_8012ffa9)[unaff_s3 * 8]);
    *(undefined1 *)(unaff_s2 + 4) = 8;
    *(undefined1 *)(unaff_s2 + 5) = 0;
  }
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
