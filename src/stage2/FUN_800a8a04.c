/* FUN_800a8a04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8a04  body 0x800a8a04..0x800a8bbf  size 444 B
 * body sha256 e9e441045894f4edcf8c896076162777c9970386bb944228def38f6a1c268164
 * provider record sha256 fa49677a6e93b0077a8e704125cf055f005fd756c9b68839566ecde09dd15228
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a8a04(void)

{
  short sVar1;
  undefined4 uVar2;
  short *psVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  
  if ((DAT_80136310 == '\0') || (_DAT_80147fd0 == 0)) {
    uVar2 = 0;
  }
  else {
    _DAT_80147fd0 = _DAT_80147fd0 - 1;
    iVar6 = *(int *)(&DAT_80147fe0 + ((int)((uint)_DAT_80147fd0 << 0x10) >> 0xe));
    psVar3 = (short *)(*(int *)(iVar6 + 8) + iVar6 + 8);
    sVar1 = *psVar3;
    while (sVar1 != -1) {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
      FUN_800ad818(sVar1);
      sVar1 = *psVar3;
    }
    iVar4 = *(int *)(iVar6 + 0xc) + iVar6;
    psVar5 = (short *)(iVar4 + 8);
    psVar3 = psVar5;
    if (*psVar5 != -1) {
      for (psVar3 = (short *)(iVar4 + 10); *psVar3 != -1; psVar3 = psVar3 + 1) {
      }
    }
    while (psVar3 = psVar3 + -1, psVar5 <= psVar3) {
      FUN_800ad458(*psVar3);
    }
    psVar3 = (short *)(*(int *)(iVar6 + 0x10) + iVar6 + 8);
    sVar1 = *psVar3;
    while (sVar1 != -1) {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
      FUN_800ad230(sVar1);
      sVar1 = *psVar3;
    }
    psVar3 = (short *)(*(int *)(iVar6 + 0x14) + iVar6 + 8);
    sVar1 = *psVar3;
    while (sVar1 != -1) {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
      FUN_800acd1c(sVar1);
      sVar1 = *psVar3;
    }
    psVar3 = (short *)(*(int *)(iVar6 + 0x18) + iVar6 + 8);
    sVar1 = *psVar3;
    while (sVar1 != -1) {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
      FUN_800acfa8(sVar1);
      sVar1 = *psVar3;
    }
    uVar2 = 1;
    if (*(short *)(iVar6 + 6) == 1) {
      FUN_800adc44(*(undefined2 *)(iVar6 + 4));
      uVar2 = 1;
    }
  }
  return uVar2;
}
