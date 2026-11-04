/* FUN_8009d828
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d828  body 0x8009d828..0x8009d877  size 80 B
 * body sha256 7ac25107ad77153cc325159b3c4180d8afe96c4a64bb693e75029748125a6d80
 * provider record sha256 44c40c530da12c2f0909568a41f6eef4e2d9cc3c88a23f78a0632ddb3c25930f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d828(void)

{
  if (DAT_8013273a == 10) {
    DAT_8013272a = 3;
    DAT_8013273c = 4;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
