/* FUN_801707d8
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x801707d8  body 0x801707d8..0x801708a3  size 204 B
 * body sha256 4303f580f44bb6a63def8dccdedbc3a8a295d9e8b93d0b7eac0327a0598380a2
 * provider record sha256 c4f599a0233ce855459987548891cccec41e89f67da7c573402991ee757784ce
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_801707d8(char param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 10;
  while( true ) {
    cVar2 = (&UNK_80172218)[iVar3 * 4];
    if ((cVar2 == param_1) &&
       (((cVar2 != '\x11' && (cVar2 != '\x0f')) || ((&UNK_80172219)[iVar3 * 4] == -1)))) break;
    bVar1 = iVar3 == 0;
    iVar3 = iVar3 + -1;
    if (bVar1) {
      iVar3 = 0x3f;
      while( true ) {
        cVar2 = (&UNK_80172244)[iVar3 * 4];
        if ((cVar2 == param_1) &&
           (((cVar2 != '\x11' && (cVar2 != '\x0f')) || ((&UNK_80172245)[iVar3 * 4] == -1)))) break;
        bVar1 = iVar3 == 0;
        iVar3 = iVar3 + -1;
        if (bVar1) {
          return 0;
        }
      }
      return (iVar3 + 1) * 0x10000;
    }
  }
  return iVar3 + 1;
}
