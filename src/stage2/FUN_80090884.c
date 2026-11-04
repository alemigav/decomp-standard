/* FUN_80090884
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090884  body 0x80090884..0x800908df  size 92 B
 * body sha256 a03df9c7236e0a407d328f835bff800956221f6267c311e19a2667a924a352cf
 * provider record sha256 6c54d1f1e029006c8b8cf0296449a32021fe7f2b4e1e65345dd818308d1e949d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80090884(void)

{
  byte bVar1;
  int unaff_s0;
  
  bVar1 = *(byte *)(unaff_s0 + 3);
  *(byte *)(unaff_s0 + 3) = bVar1 + 1;
  if (0xc < bVar1) {
    *(undefined1 *)(unaff_s0 + 1) = 2;
    *(undefined1 *)(unaff_s0 + 2) = 0;
    *(undefined1 *)(unaff_s0 + 3) = 0;
  }
  *(short *)(unaff_s0 + 0x3c) = *(short *)(unaff_s0 + 0x3c) + 0x16;
  *(short *)(unaff_s0 + 0x46) = *(short *)(unaff_s0 + 0x46) + 0x13;
  *(short *)(unaff_s0 + 0x34) = *(short *)(unaff_s0 + 0x34) + -0x15;
  *(short *)(unaff_s0 + 0x3a) = *(short *)(unaff_s0 + 0x3a) + -0x15;
  FUN_80097fd0();
  return;
}
