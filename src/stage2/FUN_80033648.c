/* FUN_80033648
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033648  body 0x80033648..0x8003367f  size 56 B
 * body sha256 dc39a3359ee84a02c84017fba8d4f09fddaa1e058c70ccb5adeb2688f5c8204c
 * provider record sha256 09579ab3d73e8f39654f1f897d937beb11adf0250afb5ff1e0b6f4ceea38a22d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80033648(int param_1)

{
  if ((**(uint **)(param_1 + 0x214) & 0x8000000) != 0) {
    FUN_80077d18(**(uint **)(param_1 + 0x214) >> 0x1c);
  }
  return;
}
