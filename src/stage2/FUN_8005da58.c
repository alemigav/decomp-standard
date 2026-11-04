/* FUN_8005da58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005da58  body 0x8005da58..0x8005da7b  size 36 B
 * body sha256 95f552d81d31f0330ee040e63aea21b981f95ffa4782f033e29fa295c943d659
 * provider record sha256 8d7b3ba6e9aa5ba93edea8ad3e0dbfcaeb7c2a070327ed4aba420c87e312361d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005da58(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
