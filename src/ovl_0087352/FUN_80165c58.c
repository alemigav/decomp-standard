/* FUN_80165c58
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165c58  body 0x80165c58..0x80165c67  size 16 B
 * body sha256 ddaaa25f7ea771bc9b708992054a793800fb6ad3aa4ec2e8878f971787633e19
 * provider record sha256 4793e562255e409e58eed8ec9f572cee1e8cfde0b1054ef644e6528cad400369
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c58(int param_1,undefined1 param_2,undefined1 param_3)

{
  *(undefined1 *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 5) = param_3;
  *(undefined2 *)(param_1 + 6) = 0;
  return;
}
