/* FUN_8007f9b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f9b0  body 0x8007f9b0..0x8007fa53  size 164 B
 * body sha256 d29b98f780b58710059b8790d07e74468b8031ac199a09a63fede62f3f8d8253
 * provider record sha256 f8780ea2d1c56769640c17a07c6db5489e445e8f2324c44d58fc45e106f6b28c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007f9a8::caseD_0(void)

{
  ushort uVar1;
  int unaff_s0;
  undefined4 uStack00000010;
  
  uVar1 = *(ushort *)((int)&uStack00000010 + *(char *)(unaff_s0 + 0x1ed) * 2);
  *(undefined1 *)(unaff_s0 + 6) = 1;
  *(byte *)(unaff_s0 + 0x25c) = *(byte *)(unaff_s0 + 0x25c) & 0xed;
  *(uint *)(unaff_s0 + 0x1e8) = (uint)uVar1 * 0x1000000 + 0x700;
  if ((*(ushort *)(unaff_s0 + 0x2b8) & 0x2000) == 0) {
    FUN_80089d54();
  }
  else {
    *(undefined4 *)(unaff_s0 + 0x1e8) = 0x6000700;
    *(undefined1 *)(unaff_s0 + 6) = 4;
    *(undefined4 *)(unaff_s0 + 0x1e0) = 0;
    *(byte *)(unaff_s0 + 0x25c) = *(byte *)(unaff_s0 + 0x25c) | 0x12;
    if ((*(short *)(unaff_s0 + 0x1a8) != 0) &&
       ((int)*(short *)(unaff_s0 + 0x1a8) < *(short *)(unaff_s0 + 0x25e) + -500)) {
      uVar1 = *(ushort *)((int)&uStack00000010 + *(char *)(unaff_s0 + 0x1ed) * 2);
      *(undefined1 *)(unaff_s0 + 6) = 1;
      *(uint *)(unaff_s0 + 0x1e8) = (uint)uVar1 * 0x1000000 + 0x700;
    }
  }
  return;
}
