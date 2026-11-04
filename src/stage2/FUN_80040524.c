/* FUN_80040524
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040524  body 0x80040524..0x80040583  size 96 B
 * body sha256 5c78f608e5c125187378c4fb43edd03289af3d751fde5fe3decc841bd93aa5e5
 * provider record sha256 47c9c44ff0b8e74383466bb8e1b50281a7d1a0b4416886a391cb65db038bfa7a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040524(void)

{
  if ((*(ushort *)(DAT_800ebb94 + 0x12) & 3) == 0) {
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x1c020000,(int)*(short *)(DAT_800ebb94 + 0x22),
                 &DAT_800e9028,DAT_800ebb94 + 0x2c);
  }
  *(short *)(DAT_800ebb94 + 0x12) = *(short *)(DAT_800ebb94 + 0x12) + 1;
  return;
}
