/* FUN_80164384
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164384  body 0x80164384..0x801643cf  size 76 B
 * body sha256 ed7d128124d6481e5307b7fdb8b1a9e247ab7e67be0f6ccbf5e5f15a88cb7dda
 * provider record sha256 dd9ec082c8765ccb632e732b79ae57dd3c02fff4f0c06279e7d6f2c6f1ac64ab
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164384(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_801643d0();
  }
  else {
    FUN_80164530(param_1);
  }
  FUN_801664d8(param_1);
  return;
}
