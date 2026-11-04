/* FUN_80166b60
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166b60  body 0x80166b60..0x80166b9f  size 64 B
 * body sha256 2c69e3893f6698d40282fb2b189954d9a28e2acef7e6af1f8a767c8c8e9343ba
 * provider record sha256 8ea8cb5528423dc6611c902d69aac516265f5b325fbf1f05dd711755a14a0023
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166b60(int param_1)

{
  if (DAT_800e12d2 != *(char *)(param_1 + 0x1a2)) {
    *(undefined1 *)(param_1 + 5) = 9;
    *(undefined2 *)(param_1 + 6) = 0;
    _DAT_800e1128 = _DAT_800e1128 & 0xffdf;
  }
  return;
}
