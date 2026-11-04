/* FUN_8009acec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009acec  body 0x8009acec..0x8009ad3b  size 80 B
 * body sha256 f1eba965f3866bfda2c61bcc5f7e086af15dac4cae415ed10368383215b5c8f4
 * provider record sha256 34643e928b91bc9b8a3dc6c7c8f25c160bf505af840082f8b61c2bf470d61e76
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009acec(void)

{
  while (DAT_800e9241 == '\0') {
    FUN_8004cd88(1);
  }
  DAT_800e9241 = 0;
  FUN_8004cdd4();
  return;
}
