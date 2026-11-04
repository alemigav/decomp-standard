/* FUN_8007ad14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ad14  body 0x8007ad14..0x8007ad67  size 84 B
 * body sha256 253a2b2c7be27103f42d87db5b3b0e212d8137b2ccf5e2f0b2a0a9e4360918ec
 * provider record sha256 4b1b48013eca392874216f2d8b6afdd772dede0bf1a70947ba180ed941e21f6c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ad14(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x200) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfdff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
