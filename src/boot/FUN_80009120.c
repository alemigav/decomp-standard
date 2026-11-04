/* FUN_80009120
 * image   boot (boot), base 0x80000480
 * address 0x80009120  body 0x80009120..0x8000916f  size 80 B
 * body sha256 6c6dfcea30509bcdd74d7a431da95dd84233c7ddfb80cbac9b27be820dc339bf
 * provider record sha256 125e0b6c67b6a79cc1feadce8799b9915dd26ae79cda89748e287d82b0262bf5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80009120(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 0;
  puVar4 = param_1;
  do {
    iVar1 = 0;
    puVar2 = param_1;
    do {
      if (iVar3 == iVar1) {
        *puVar4 = 0x3f800000;
      }
      else {
        *puVar2 = 0;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < 4);
    puVar4 = puVar4 + 5;
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 4;
  } while (iVar3 < 4);
  return;
}
