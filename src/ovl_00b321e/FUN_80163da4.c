/* FUN_80163da4
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163da4  body 0x80163da4..0x80163def  size 76 B
 * body sha256 55cac2aa8876791c198c1e659f8279404d60fd8d8b6e8c69c587053020821c55
 * provider record sha256 31aa3fc55fb9cf1ccac3ba46fe5d1afe9b8265de3acd9ae46420ad5ef2412bca
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163da4(int param_1)

{
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x2c3) = 0;
  }
  if ((*(short *)(param_1 + 0x270) != 0) || (*(char *)(param_1 + 0x2c3) != '\0')) {
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  func_0x80089d54();
  return;
}
