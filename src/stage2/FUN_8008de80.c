/* FUN_8008de80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008de80  body 0x8008de80..0x8008def3  size 116 B
 * body sha256 70724bbfa0163120950c8c20a9a85dde5e3df189243500e0821b40ee87e91399
 * provider record sha256 a6d0cd7373dc2edb9b49b7543a0151571a249fc8cfc8a38f316a2a914e5f27ff
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008de80(void)

{
  byte bVar1;
  undefined1 uVar2;
  int unaff_s1;
  int unaff_s2;
  
  bVar1 = *(byte *)(unaff_s1 + 3);
  *(byte *)(unaff_s1 + 3) = bVar1 + 1;
  if (3 < bVar1) {
    *(undefined1 *)(unaff_s1 + 2) = 0;
    *(undefined1 *)(unaff_s1 + 3) = 0;
  }
  uVar2 = DAT_8013a380;
  *(short *)(unaff_s1 + 0x48) = *(short *)(unaff_s1 + 0x48) + 0xd;
  FUN_80097578(uVar2);
  FUN_800962fc(*(undefined1 *)(unaff_s2 + (uint)*(byte *)(unaff_s1 + 0xc) * 4 + 0x2181a));
  return;
}
