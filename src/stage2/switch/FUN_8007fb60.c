/* FUN_8007fb60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fb60  body 0x8007fb60..0x8007fb7f  size 32 B
 * body sha256 f518b1ed2d7ea6f3c0b0c355319796de11f9a021152650a0905994ae6b00c1d4
 * provider record sha256 2bad1a186582b39ac5bda461dae05e3328421f0766131e67f46bbdf4a9e42806
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007f9a8::caseD_7(void)

{
  int unaff_s0;
  
  *(undefined1 *)(unaff_s0 + 6) = 0;
  *(ushort *)(unaff_s0 + 0x2b8) = *(ushort *)(unaff_s0 + 0x2b8) & 0xdfff;
  return;
}
