/* FUN_80083cec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083cec  body 0x80083cec..0x80083d2b  size 64 B
 * body sha256 9843afba22d784ed3dea57312a2589afbf27c17c622bf447b083cc531f31b86c
 * provider record sha256 4b5a5c4a7547a589847713d744a85f618d7d8014b2e21a25b778c8bc791b51cf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80083cec(uint param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(*(int *)(DAT_800df92c + 0x28) + 2);
  iVar2 = *(int *)(DAT_800df92c + 0x28);
  while (bVar1 != param_1) {
    bVar1 = *(byte *)(iVar2 + 0x16);
    iVar2 = iVar2 + 0x14;
  }
  return iVar2;
}
