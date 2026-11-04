/* FUN_80039d6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039d6c  body 0x80039d6c..0x80039da3  size 56 B
 * body sha256 9b64717b344992f25a36a7010c38ca9a3fb1f75b0ce79c99e6ee665f1d2852e1
 * provider record sha256 701ab8e1eacc19f3c8d7abe4610abdb379878630dd99aea0038df3ddadce43df
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039d6c(void)

{
  if (*(char *)(DAT_800ebb94 + 3) == '\0') {
    FUN_80039ba8();
  }
  else {
    *(char *)(DAT_800ebb94 + 3) = *(char *)(DAT_800ebb94 + 3) + -1;
  }
  return;
}
