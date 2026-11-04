/* FUN_8004ce90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ce90  body 0x8004ce90..0x8004cec3  size 52 B
 * body sha256 02452f84bac46f1131b9e213505e8aa9ccf3732e69e276c62162539313d89da2
 * provider record sha256 8c25907f577c7d89f0123d6f6aaeafa1accd1400a85a9d6eeee145ffa0f3a3e8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ce90(int param_1)

{
  (&DAT_8010b328)[param_1 * 0xe4] = (&DAT_8010b328)[param_1 * 0xe4] | 0x40;
  return;
}
