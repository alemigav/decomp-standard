/* FUN_80164108
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164108  body 0x80164108..0x8016413f  size 56 B
 * body sha256 d3aab243ee0ef88f3dc56e9f46b0e1d8149982434ea43532ba208655e167f100
 * provider record sha256 e58019e2811366d5083e16cdce2ad3d7f3f11b5d5f76827c56688308fd03095e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164108(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80164140();
  }
  else {
    FUN_80163604();
  }
  return;
}
