/* FUN_8007fb0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fb0c  body 0x8007fb0c..0x8007fb3b  size 48 B
 * body sha256 1f865ad9555559a48d1d5c36c693e7fa41a974dd67bdab3864bdf862490d1535
 * provider record sha256 4560a104a5a0ecba0daa1dd0297f7e7a9b633855080945e398d3284c14163022
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007f9a8::caseD_5(void)

{
  byte bVar1;
  int unaff_s0;
  
  bVar1 = *(byte *)(unaff_s0 + 0x25c) & 0xed;
  *(byte *)(unaff_s0 + 0x25c) = bVar1;
  if (6000 < *(ushort *)(unaff_s0 + 0x2ba)) {
    *(byte *)(unaff_s0 + 0x25c) = bVar1 | 0x12;
  }
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0x6000700;
  return;
}
