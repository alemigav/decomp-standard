/* FUN_8003765c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003765c  body 0x8003765c..0x8003777f  size 292 B
 * body sha256 e17c8a907de212a24bc3b72cc09a2326219518e3f1369fdf2b1b1ba71f03276a
 * provider record sha256 e1f8bf3265345df5797fe862309e293aa6151c1de9d75d3d3a88f2bc6592bd85
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003765c(void)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  short *psVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar6 = &DAT_800ebb98;
  do {
    if ((&UNK_800ebb9f < pbVar6) && (*pbVar6 == 0xff)) {
      return;
    }
    psVar4 = *(short **)(&DAT_800ebba8 + (uint)*pbVar6 * 4);
    uVar5 = 0x7fffffff;
    iVar1 = FUN_800844cc((int)*psVar4);
    iVar1 = (int)psVar4 + ((iVar1 << 0x10) >> 0xd) + 8;
    uVar2 = FUN_800844e4(*(undefined4 *)psVar4);
    uVar2 = uVar2 >> 0x10;
    do {
      uVar2 = uVar2 - 1;
      if (*(byte *)(iVar1 + 1) < uVar5) {
        uVar5 = (uint)*(byte *)(iVar1 + 1);
      }
      iVar1 = iVar1 + 4;
    } while (uVar2 != 0);
    iVar1 = FUN_800844cc((int)*psVar4);
    uVar2 = FUN_800844e4(*(undefined4 *)psVar4);
    uVar2 = uVar2 >> 0x10;
    pcVar3 = (char *)((int)psVar4 + ((iVar1 << 0x10) >> 0xd) + 9);
    do {
      uVar2 = uVar2 - 1;
      *pcVar3 = *pcVar3 - (char)uVar5;
      pcVar3 = pcVar3 + 4;
    } while (uVar2 != 0);
    pbVar6 = pbVar6 + 1;
  } while (pbVar6 < &DAT_800ebba8);
  return;
}
