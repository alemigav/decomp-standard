/* FUN_8008de48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008de48  body 0x8008de48..0x8008de7f  size 56 B
 * body sha256 b080add3929eeeeecd7aafa1cd8d7c6825505620cc1dee2af026b5832a33d065
 * provider record sha256 f30397d5e4d2d7e7702468d33c585ba170b0b37f452626c46e2bdc0f5f29400f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008de48(void)

{
  byte bVar1;
  undefined1 uVar2;
  int unaff_s1;
  int unaff_s2;
  
  bVar1 = *(byte *)(unaff_s1 + 3);
  *(byte *)(unaff_s1 + 3) = bVar1 + 1;
  if (3 < bVar1) {
    *(undefined1 *)(unaff_s1 + 2) = 1;
    *(undefined1 *)(unaff_s1 + 3) = 0;
  }
  uVar2 = DAT_8013a380;
  *(short *)(unaff_s1 + 0x48) = *(short *)(unaff_s1 + 0x48) + -0xd;
  FUN_80097578(uVar2);
  FUN_800962fc(*(undefined1 *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x2181a));
  return;
}
