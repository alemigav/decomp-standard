/* FUN_8009f668
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f668  body 0x8009f668..0x8009f6d7  size 112 B
 * body sha256 5653d462610d5a3ded3641bcf60e08c347b3195088279e7d339bd581f0788d32
 * provider record sha256 4a9df1cd5cca119bc121ff013f777e43ec056d572f405643548696a3832e962b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009f668(void)

{
  do {
  } while (DAT_801344f4 != 0);
  FUN_8009eee0(*(undefined4 *)((DAT_80184b38 ^ 1) * 4 + -0x7fe7b4d0),
               *(undefined4 *)((uint)DAT_80184b38 * 4 + -0x7fe7b4d0));
  DAT_801344cc = 0;
  DAT_801344c8 = 2;
  DAT_801344d4 = DAT_801344d4 + 1;
  DAT_801344f8 = DAT_801344f8 + 1;
  return;
}
