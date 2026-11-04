/* FUN_80166634
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166634  body 0x80166634..0x801666bf  size 140 B
 * body sha256 3533cd71b29e76c1e5c79813737e8b3b38da9d3679b7baa7015ebd019c0106b4
 * provider record sha256 193870e3ee93d4bb0537daf26c00cb81bbf0f9345fa64124a1146a70a295cc5a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166634(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 0x2c0) == '\0') {
    FUN_801679c8(param_1,0x3f3f3f);
    *(undefined1 *)(param_1 + 0x2d7) = 0x1e;
    FUN_8016703c(param_1,0x13,10);
    FUN_8016703c(param_1,0,10);
  }
  *(undefined1 *)(param_1 + 5) = 2;
  FUN_8016577c(param_1,param_2,param_3);
  return;
}
