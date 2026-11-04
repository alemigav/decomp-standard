/* FUN_8008e1ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e1ac  body 0x8008e1ac..0x8008e1eb  size 64 B
 * body sha256 946ab37533c994b59a6a75e791be3aef1852d36c2907ed175a08e2ed2b43bb08
 * provider record sha256 02af662e3dcc77333ef730e30bfc49fd4dcd7df2c3a5fd15e1ba32c82a576532
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e1ac(void)

{
  int unaff_s0;
  
  FUN_8008c314(*(undefined1 *)(unaff_s0 + 0xc),0,0,0);
  FUN_8008cc1c((uint)(*(byte *)(unaff_s0 + 0xc) >> 1) + (uint)*(byte *)(unaff_s0 + 0xc));
  *(undefined1 *)(unaff_s0 + 3) = 1;
  *(undefined1 *)(unaff_s0 + 4) = 2;
  *(undefined1 *)(unaff_s0 + 6) = 0;
  *(undefined1 *)(unaff_s0 + 5) = 0;
  return;
}
