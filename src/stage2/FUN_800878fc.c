/* FUN_800878fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800878fc  body 0x800878fc..0x8008794b  size 80 B
 * body sha256 26e2c7ae887a09c7c3cc8822249c29051e1d12c72d183aa18e0d6f82f0b3ff49
 * provider record sha256 a1bf683f2c3938d6da69b12719a7d6c345864ccf192f59a5bbf2003e4e74fba3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800878fc(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0x5e)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0x40) + param_3 * *(short *)(param_1 + 0x5c) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0x44) + param_3 * *(short *)(param_1 + 0x5c) * 4;
  }
  return;
}
