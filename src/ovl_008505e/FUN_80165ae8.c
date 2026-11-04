/* FUN_80165ae8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165ae8  body 0x80165ae8..0x80165b37  size 80 B
 * body sha256 4991d8fcd6849934e161a4028f394f8007837fa9c221d21fb4058f9026e690d7
 * provider record sha256 a3589f62098aa69392ac67b452e4ba996025d763749dd1a2f09ecf205cabcb4c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ae8(int param_1)

{
  undefined **ppuVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    ppuVar1 = &PTR_FUN_80166eec;
    uVar2 = *(byte *)(param_1 + 5) - 1;
  }
  else {
    uVar2 = (uint)*(byte *)(param_1 + 6);
    ppuVar1 = &PTR_FUN_80166f38;
  }
  (*(code *)ppuVar1[uVar2])();
  return;
}
