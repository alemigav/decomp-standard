/* FUN_80162158
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80162158  body 0x80162158..0x80162183  size 44 B
 * body sha256 50032eb310a36360dd9634f65718fef3dfcbbd68fd948d7352ce641d1b1abfbe
 * provider record sha256 ce6bde8756303ffecb1c47e55b7686af784bd4fba44e6809ee31629c4fde14e4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162158(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
    FUN_8016ba54();
  }
  return;
}
