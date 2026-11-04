/* FUN_80163f10
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163f10  body 0x80163f10..0x80163f8f  size 128 B
 * body sha256 056a9390a93e7686d2439b8085223b1bea4dd08fbe49c073eadfa91190b4804b
 * provider record sha256 26525b21c2bd2780957290e0a8a4a72bdc3ef2575da67ff8d9cbbeaef072b061
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163f10(int param_1)

{
  FUN_801621a0();
  if ((DAT_800e12d2 == *(char *)(param_1 + 0x1a2)) &&
     (((*(uint *)(param_1 + 0x28c) < 4000 || ((_DAT_800e1128 & 0x20) != 0)) ||
      ((_DAT_800e112a & 1) != 0)))) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
