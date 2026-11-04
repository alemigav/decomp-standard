/* FUN_80075c9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075c9c  body 0x80075c9c..0x80075d9f  size 260 B
 * body sha256 7dd6b7a0b43547f76dee64f1d384f6c18a4cc8f558aaae0ee975b169e9d17565
 * provider record sha256 0231e0371df140fe72aa54e0a4710e546d3cbbc109c06d5d0eaca1ed11aaacba
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80075c9c(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  
  FUN_800b202c(0x7f,0,0xff);
  pcVar4 = &DAT_80119ee4;
  DAT_8011a290 = 0;
  DAT_80119e78 = 0;
  DAT_8011a28e = 0;
  do {
    if (*pcVar4 != '\0') {
      sVar1 = FUN_80079418((int)pcVar4[2],0);
      if (sVar1 == 0) {
        *pcVar4 = '\0';
      }
      else {
        FUN_800790a4((int)pcVar4[2]);
        *pcVar4 = '\0';
      }
    }
    if (-1 < pcVar4[2]) {
      FUN_80078b5c();
      pcVar4[2] = -1;
    }
    pcVar4 = pcVar4 + 8;
  } while (pcVar4 < "");
  FUN_80078b40(0);
  pcVar4 = &DAT_80119ea8;
  uVar2 = 0;
  do {
    if (-1 < *pcVar4) {
      *pcVar4 = -1;
    }
    uVar3 = uVar2 + 1;
    pcVar4 = &DAT_80119ea9 + uVar2;
    uVar2 = uVar3;
  } while (uVar3 < 8);
  FUN_800755c0();
  return;
}
