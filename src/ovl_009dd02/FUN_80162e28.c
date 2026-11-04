/* FUN_80162e28
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162e28  body 0x80162e28..0x80162e5f  size 56 B
 * body sha256 4c74570c69b5ab2c47abe2aeedf64ac76a63e9b189f7e37257565f3c1e6b1d7c
 * provider record sha256 4776c02677196bc26b5d764ac29b9a96e27c0a523563722a64163cb39e866283
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162e28(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80162e60();
  }
  else {
    FUN_80163094();
  }
  return;
}
