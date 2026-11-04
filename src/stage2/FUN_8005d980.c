/* FUN_8005d980
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d980  body 0x8005d980..0x8005d9a3  size 36 B
 * body sha256 2e546e559f05493cfa6d3dedcc672580b6505890b5b12b1b41d06a601cb55d32
 * provider record sha256 6814ca3bde7a54ab63a2ad46b06aa2af8d52614073a1e73e68e1a173dc0bb81c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d980(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
