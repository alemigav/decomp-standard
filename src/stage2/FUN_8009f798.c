/* FUN_8009f798
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f798  body 0x8009f798..0x8009f833  size 156 B
 * body sha256 871707d0e1eb29b2ede4236f2eb86ce833b5b9f344714a075a7e46ed379ed3f6
 * provider record sha256 2eb9dca69e276dc250c42e3d1488963eb8887b431031c6000cb5946c568f3e0f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009f798(void)

{
  DAT_801344cc = DAT_801344cc + 1;
  if (DAT_801344d0 != 0) {
    DAT_801344d0 = 0;
    DAT_801344fc = DAT_80184b38 ^ 1;
    FUN_8009ec1c(0x80184b3c,*(undefined4 *)((DAT_80184b38 ^ 1) * 4 + -0x7fe7b4d0));
    DAT_801344d4 = DAT_801344d4 + 1;
    DAT_801344c8 = 1;
  }
  DAT_801344f8 = DAT_801344f8 + 1;
  return;
}
