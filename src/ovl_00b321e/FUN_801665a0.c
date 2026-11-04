/* FUN_801665a0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801665a0  body 0x801665a0..0x801665e3  size 68 B
 * body sha256 63b93d0ff8a9d8b15996a31cec5d35e4561713908d618501d0f1934f95bb905f
 * provider record sha256 eab5c8198b3c65b6803b9d4ff7a992ca2e873ad476fe6f04fc0989caad4a1899
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801665a0(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0x134) = 0xfce0;
    *(undefined2 *)(param_1 + 0x13a) = 1000;
    *(undefined2 *)(param_1 + 300) = 800;
    *(undefined2 *)(param_1 + 0x12e) = 0x578;
    return;
  }
  *(undefined2 *)(param_1 + 0x13a) = 2000;
  *(undefined2 *)(param_1 + 0x134) = 0;
  *(undefined2 *)(param_1 + 300) = 4;
  *(undefined2 *)(param_1 + 0x12e) = 4;
  return;
}
