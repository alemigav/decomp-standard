/* FUN_800969a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800969a4  body 0x800969a4..0x80096c8b  size 744 B
 * body sha256 28605257a04c024c55bd08629a4b0d37c278f5a02f412d47c3e5a6461c0d96a4
 * provider record sha256 f8f444eaad4477bdb67533064bcf6fd331a31aa09ba0af5eb1281445cc6f8a1e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800969a4(void)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  short sVar10;
  short sVar11;
  
  uVar8 = 0xd;
  uVar9 = 10;
  iVar6 = DAT_800c52dc + 0x3bb2c;
  sVar11 = DAT_8012bfd4 + -0x33;
  sVar2 = DAT_8012bfd8 + sVar11;
  sVar10 = DAT_8012bfd6 + -0xd;
  sVar1 = DAT_8012bfda + sVar10 + 6;
  psVar3 = &DAT_801311e8;
  iVar5 = DAT_800c52dc + 0x3ba28;
  while( true ) {
    uVar8 = uVar8 - 1;
    FUN_800478b8(iVar5,*psVar3 + sVar11,psVar3[1] + sVar10);
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar5,0,0);
    if (uVar8 < 4) break;
    psVar3 = psVar3 + -2;
    iVar5 = iVar5 + 0x14;
  }
  if ((DAT_8012bfa8 == '\0') && ((DAT_800e110c & 0x10000000) != 0)) {
    psVar3 = &DAT_80131210;
    iVar7 = iVar6;
    do {
      uVar9 = uVar9 - 1;
      FUN_800478b8(iVar7,*psVar3 + sVar2,psVar3[1] + sVar1);
      iVar6 = iVar7 + 0x14;
      DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar7,0,0);
      psVar3 = psVar3 + -2;
      iVar7 = iVar6;
    } while (2 < uVar9);
  }
  puVar4 = (undefined2 *)(iVar5 + 0x1e);
  psVar3 = (short *)(&UNK_801311b8 + uVar8 * 4);
  iVar5 = iVar5 + 0x14;
  do {
    uVar8 = uVar8 - 1;
    FUN_800478b8(iVar5,psVar3[-2] + sVar11,psVar3[-1] + sVar10);
    *(undefined **)(puVar4 + 1) = &DAT_8012f530;
    *puVar4 = 0x400;
    puVar4 = puVar4 + 10;
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar5,0,0);
    psVar3 = psVar3 + -2;
    iVar5 = iVar5 + 0x14;
  } while (uVar8 != 0);
  if ((DAT_8012bfa8 == '\0') && ((DAT_800e110c & 0x10000000) != 0)) {
    puVar4 = (undefined2 *)(iVar6 + 10);
    psVar3 = (short *)(&UNK_801311ec + uVar9 * 4);
    do {
      uVar9 = uVar9 - 1;
      FUN_800478b8(iVar6,psVar3[-2] + sVar2,psVar3[-1] + sVar1);
      *(undefined **)(puVar4 + 1) = &DAT_8012f530;
      *puVar4 = 0x400;
      puVar4 = puVar4 + 10;
      DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar6,0,0);
      psVar3 = psVar3 + -2;
      iVar6 = iVar6 + 0x14;
    } while (uVar9 != 0);
  }
  return;
}
