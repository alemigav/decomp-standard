/* FUN_80039020
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039020  body 0x80039020..0x800390b7  size 152 B
 * body sha256 1edcedfb04e5cad75566d5e34528e2b0716dfd7be5a28697f3f8f23153fce662
 * provider record sha256 929926d89951e27948bf609d9b09075ea3f0dbb52966d875f12f2ca68e5a6764
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80039020(char param_1,char param_2,undefined1 param_3,int param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_4 == 0) {
    puVar1 = &DAT_800ebda8;
    do {
      if ((puVar1[0x1c] == param_1) && (puVar1[0x1e] == param_2)) {
        *puVar1 = param_3;
      }
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 0x7c;
    } while (uVar2 < 0x60);
    return 0;
  }
  puVar1 = &DAT_800ebda8;
  do {
    if (((puVar1[0x1c] == param_1) && (puVar1[0x1e] == param_2)) &&
       (*(int *)(puVar1 + 0x6c) == param_4)) {
      *puVar1 = param_3;
    }
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 0x7c;
  } while (uVar2 < 0x60);
  return 0;
}
