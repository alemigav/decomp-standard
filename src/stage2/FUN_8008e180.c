/* FUN_8008e180
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e180  body 0x8008e180..0x8008e1ab  size 44 B
 * body sha256 ae98063c6e14ab59e5bdbe9d4587a227596980ea1244e264faf7b490f8503ba5
 * provider record sha256 57af1f84edf0d746e36817e130c4107ec0a2b7af02e77f3592fd1a511433b2ef
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e180(void)

{
  int unaff_s0;
  
  if ((DAT_8010b294 & 0x80) == 0) {
    *(undefined1 *)(unaff_s0 + 2) = 4;
    *(undefined1 *)(unaff_s0 + 3) = 0;
  }
  return;
}
