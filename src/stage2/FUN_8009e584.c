/* FUN_8009e584
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e584  body 0x8009e584..0x8009e8d3  size 848 B
 * body sha256 bca4fdc89384cf677cfcf753b2c7c6a77fe1fca8decd26bb0d8c94dea680ce18
 * provider record sha256 68f96b4967f92f3dd4e59eeb66bff7c8ccf4bb8314b37aa7a7afb907df8c1d8e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e584(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  undefined1 uVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  short sVar14;
  short sVar15;
  undefined *puVar16;
  byte *pbVar17;
  byte *pbVar18;
  int *piVar19;
  int iVar20;
  
  FUN_80043620();
  bVar1 = DAT_80132730 == 0;
  DAT_80132730 = DAT_80132730 + -1;
  if (bVar1) {
    DAT_80132730 = 10;
    DAT_80132732 = 0xffff;
  }
  else {
    DAT_80132732 = 0;
  }
  bVar1 = DAT_80132734 == 0;
  DAT_80132734 = DAT_80132734 + -1;
  if (bVar1) {
    DAT_80132734 = 3;
    DAT_80132736 = 0xffff;
  }
  else {
    DAT_80132736 = 0;
  }
  iVar20 = (int)DAT_80132738;
  piVar19 = (int *)(&DAT_8013274c + (uint)DAT_800dfbe8 * 0x500);
  pbVar17 = DAT_80132748 + 8;
  puVar16 = &DAT_8013274f + (uint)DAT_800dfbe8 * 0x500;
  pbVar18 = DAT_80132748;
  do {
    iVar20 = iVar20 + -1;
    if ((pbVar17[-7] & 0x10) != 0) {
      *pbVar18 = 0;
    }
    if (((*pbVar18 & 1) != 0) && (pbVar17[-7] >> 4 == 2)) {
      iVar13 = (uint)pbVar17[-5] * 10;
      if (((*pbVar18 & 4) != 0) &&
         (iVar12 = *(int *)pbVar17, *(int *)pbVar17 = iVar12 + 0x20202, 0x60605f < iVar12 + 0x20202)
         ) {
        pbVar17[0] = 0;
        pbVar17[1] = 0x60;
        pbVar17[2] = 0x60;
        pbVar17[3] = 0x60;
        *pbVar18 = *pbVar18 & 0xf9;
      }
      if (((*pbVar18 & 8) != 0) &&
         (iVar12 = *(int *)pbVar17, *(int *)pbVar17 = iVar12 + -0x10101, iVar12 + -0x10101 < 1)) {
        pbVar17[0] = 0;
        pbVar17[1] = 0;
        pbVar17[2] = 0;
        pbVar17[3] = 0;
        *pbVar18 = *pbVar18 & 0xf7;
      }
      iVar12 = *(int *)pbVar17;
      if ((*pbVar18 & 0x20) != 0) {
        (&DAT_801321fc)[iVar13] = (&DAT_801321fc)[iVar13] + (char)DAT_80132736 * -2;
        (&DAT_801321fd)[iVar13] = (&DAT_801321fd)[iVar13] + (char)DAT_80132736 * -2;
      }
      if ((*pbVar18 & 0x40) != 0) {
        (&DAT_801321fc)[iVar13] = (&DAT_801321fc)[iVar13] + (char)DAT_80132736 * '\x02';
        (&DAT_801321fd)[iVar13] = (&DAT_801321fd)[iVar13] + (char)DAT_80132736 * '\x02';
      }
      bVar2 = (&DAT_801321fc)[iVar13];
      bVar3 = (&DAT_801321fd)[iVar13];
      bVar4 = (&DAT_801321fc)[iVar13];
      bVar5 = (&DAT_801321fd)[iVar13];
      cVar6 = (&DAT_801321f8)[iVar13];
      cVar7 = (&DAT_801321fa)[iVar13];
      cVar8 = (&DAT_801321f9)[iVar13];
      cVar9 = (&DAT_801321fb)[iVar13];
      *piVar19 = iVar12 + 0x2e000000;
      sVar15 = (short)((int)(0x140 - (uint)bVar2) / 2);
      *(short *)(puVar16 + 1) = sVar15;
      sVar14 = (short)((int)(0xf0 - (uint)bVar3) / 2);
      *(short *)(puVar16 + 3) = sVar14;
      puVar16[5] = (&DAT_801321f8)[iVar13];
      uVar10 = (&DAT_801321f9)[iVar13];
      *(undefined2 *)(puVar16 + 7) = 0;
      *(ushort *)(puVar16 + 9) = sVar15 + (ushort)bVar4;
      *(short *)(puVar16 + 0xb) = sVar14;
      puVar16[0xd] = cVar6 + cVar7;
      puVar16[6] = uVar10;
      puVar16[0xe] = (&DAT_801321f9)[iVar13];
      sVar11 = *(short *)(&DAT_801321f4 + iVar13);
      *(short *)(puVar16 + 0x11) = sVar15;
      *(ushort *)(puVar16 + 0x13) = sVar14 + (ushort)bVar5;
      *(short *)(puVar16 + 0xf) = sVar11 + 0xa0;
      uVar10 = (&DAT_801321f8)[iVar13];
      puVar16[0x16] = cVar8 + cVar9;
      puVar16[0x1e] = cVar8 + cVar9;
      *(ushort *)(puVar16 + 0x19) = sVar15 + (ushort)bVar4;
      *(ushort *)(puVar16 + 0x1b) = sVar14 + (ushort)bVar5;
      puVar16[0x1d] = cVar6 + cVar7;
      *(undefined4 **)(puVar16 + 0x21) = &DAT_80132708;
      puVar16[0x15] = uVar10;
      *puVar16 = 4;
      puVar16 = puVar16 + 0x28;
      DAT_800df8b4 = FUN_80044fdc(DAT_800df8b4,piVar19,0);
      piVar19 = piVar19 + 10;
    }
    pbVar17 = pbVar17 + 0xc;
    pbVar18 = pbVar18 + 0xc;
  } while (iVar20 != 0);
  return;
}
