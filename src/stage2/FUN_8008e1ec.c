/* FUN_8008e1ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e1ec  body 0x8008e1ec..0x8008e213  size 40 B
 * body sha256 10deac0e70ccdc9ab9b4913fb4c2fb74f98964b1035eacb1d67d696ae3e9254b
 * provider record sha256 8a1f070655e9aed7f820ec40431de1d3883d27cc9022409e463a4770e1568008
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e1ec(undefined4 param_1,int param_2)

{
  int unaff_s0;
  
  *(ushort *)(param_2 + 0x215cc) =
       (ushort)*(byte *)(param_2 + (uint)*(byte *)(unaff_s0 + 0xc) * 4 + 0x21818);
  *(undefined1 *)(unaff_s0 + 1) = 0;
  return;
}
