/* FUN_800755c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800755c0  body 0x800755c0..0x80075607  size 72 B
 * body sha256 7c6cb65c6c56c481d9b37cfcb647bd7e1b5c6ec4df1b8e7d2026eacea7d27a82
 * provider record sha256 de5ce80bac01e9c5c6504be93a41b611af5c7ec267a7ee91003c03d21b01ee40
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800755c0(void)

{
  while (_DAT_8013a168 != 0) {
    _DAT_8013a168 = _DAT_8013a168 + -1;
    FUN_800a8a04();
  }
  return;
}
