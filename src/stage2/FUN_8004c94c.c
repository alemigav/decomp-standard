/* FUN_8004c94c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c94c  body 0x8004c94c..0x8004c9d3  size 136 B
 * body sha256 1037e4548aff844ee4d183e59044e8d19c16af4dc86d3faddd2127ad965a7e95
 * provider record sha256 e62a83fb762013095c3c9b1ff389ae3136f41241eb25781b7a4cff4625c5c8ef
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004c94c(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
  }
  puVar2 = &DAT_800fe288;
  puVar3 = &DAT_80100a88;
  iVar1 = 0x200;
  iVar4 = 0x800;
  do {
    *puVar2 = 0x4000000;
    puVar2[1] = 0x64808080;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 5;
  } while (iVar1 != 0);
  do {
    *puVar3 = 0x3000000;
    puVar3[1] = 0x74808080;
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + 4;
  } while (iVar4 != 0);
  FUN_8004c910();
  FUN_8004c9d4();
  return;
}
