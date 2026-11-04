/* FUN_8005d938
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d938  body 0x8005d938..0x8005d95b  size 36 B
 * body sha256 177849fc27865fb0ff55dc5b29f270be2632ae7444010fdad97b0f252e6ae9c5
 * provider record sha256 f4963bc00f83f430fd2689d471135948cc22db75d88f4f476b66ee9da464ab57
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d938(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
