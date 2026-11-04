/* FUN_8006eb80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eb80  body 0x8006eb80..0x8006ebeb  size 108 B
 * body sha256 6a160839ef36e3ef545c1fdd326355c8050a2c80e43184c2e4c41b111fdb4af6
 * provider record sha256 01da96a6c018c45a40e65a2596547b0a5b47ede9e43fd15a3c1de5e16051eabd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006eb80(int param_1)

{
  FUN_8006ebec(DAT_80114f35);
  DAT_800e110c = DAT_800e110c & 0xfffffeff | 0x100000;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}
