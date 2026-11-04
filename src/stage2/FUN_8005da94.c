/* FUN_8005da94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005da94  body 0x8005da94..0x8005dab7  size 36 B
 * body sha256 3b3210e1d08cee0fd04eddcb93db1dad29b9e88879703473af6672c12beca549
 * provider record sha256 8752260a7e8ebbc2db1ca49cd498ef60cdc3abe171c0d780a0fdb4b54a7535a4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005da94(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
