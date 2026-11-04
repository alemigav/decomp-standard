/* FUN_8016273c
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x8016273c  body 0x8016273c..0x801627bf  size 132 B
 * body sha256 231f5a7bf733230ba5a920b582d454c18515dbb019c4c77a9e3fc4e5eceb6c20
 * provider record sha256 691ba6fed409f7d49d1034b0fc04aee393625500962de2211059c4c28c52ff4e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016273c(int param_1)

{
  FUN_80162d84();
  if ((*(char *)(param_1 + 0x2b6) == '\x01') && (_DAT_800e1c90 - *(int *)(param_1 + 0x30) < 0x251c))
  {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  if (*(uint *)(param_1 + 0x28c) < 0x5a) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  if (*(char *)(param_1 + 0x2d4) != '\0') {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
