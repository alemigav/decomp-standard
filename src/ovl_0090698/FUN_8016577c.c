/* FUN_8016577c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016577c  body 0x8016577c..0x801657c7  size 76 B
 * body sha256 81a1f98780da72a0e1311a63944a61387546c5514ae96e3ffcf2262626155be9
 * provider record sha256 b4baf143fc4ed91d8a5509c7916733155d016aeac05b850a6661024c5ec71239
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016577c(int param_1)

{
  if (*(char *)(param_1 + 0x2c0) == '\0') {
    (*(code *)(&PTR_FUN_80167f68)[*(byte *)(param_1 + 0x2be)])();
  }
  else {
    FUN_80165e40();
  }
  return;
}
