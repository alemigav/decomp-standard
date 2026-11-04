/* FUN_80089230
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089230  body 0x80089230..0x8008940b  size 476 B
 * body sha256 5e1ea9422b9a578c97d8289a30846b1f41fd4a61b0e3eea7987d5729b05eaf2a
 * provider record sha256 417743b59306ab7edff1ebe41162ff76d3430d084e4210f1fddd76983577413e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80089230(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  short *psVar10;
  undefined2 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  
  uVar15 = 0;
  puVar14 = *(undefined4 **)(param_1 + 0x234);
  iVar4 = *(int *)(param_1 + 0x1a4);
  iVar16 = *(byte *)(param_1 + 0x1a3) - 1;
  puVar14[0x19] = param_1 + 0x14;
  puVar14[0x4b] = param_1;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined2 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0x10000000;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0x10000000;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0x10000000;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(int *)(param_1 + 0x70) = param_1 + 0x1b8;
  iVar4 = iVar4 + 8;
  if (iVar16 != -1) {
    psVar10 = (short *)(puVar14 + 0xb);
    do {
      psVar10[6] = 0x1000;
      psVar10[7] = 0;
      psVar10[8] = 0;
      psVar10[9] = 0;
      psVar10[10] = 0x1000;
      psVar10[0xb] = 0;
      psVar10[0xc] = 0;
      psVar10[0xd] = 0;
      psVar10[0xe] = 0x1000;
      psVar10[0xf] = 0;
      psVar10[0x10] = 0;
      psVar10[0x11] = 0;
      psVar10[0x12] = 0;
      psVar10[0x13] = 0;
      psVar10[0x14] = 0;
      psVar10[0x15] = 0;
      puVar13 = puVar14 + 2;
      iVar12 = 2;
      puVar11 = &DAT_800e9048;
      do {
        iVar7 = 2;
        puVar5 = puVar11;
        puVar9 = puVar13;
        do {
          uVar2 = *puVar5;
          puVar5 = puVar5 + 1;
          iVar7 = iVar7 + -1;
          *(undefined2 *)puVar9 = uVar2;
          puVar9 = (undefined4 *)((int)puVar9 + 2);
        } while (iVar7 != -1);
        puVar13 = (undefined4 *)((int)puVar13 + 6);
        iVar12 = iVar12 + -1;
        puVar11 = puVar11 + 3;
      } while (iVar12 != -1);
      psVar10[0x1a] = 0x80;
      psVar10[0x1b] = -0x7f80;
      psVar10[-0xffffffff00000014] = 0;
      psVar10[-0xffffffff00000013] = 0;
      psVar10[0x16] = 0;
      psVar10[0x17] = 0;
      psVar10[0x18] = 0;
      *puVar14 = 1;
      uVar3 = uVar15 ^ 1;
      uVar6 = uVar15 + 1;
      uVar8 = uVar15 + 2;
      uVar15 = uVar15 + 3;
      puVar14 = puVar14 + 0x5e;
      psVar10[0x10] = 0;
      psVar10[0x82] = 0;
      psVar10[0x83] = 0;
      psVar10[0x84] = 0;
      psVar10[0x85] = 0;
      psVar10[0x86] = 0;
      psVar10[0x87] = 0;
      sVar1 = *(short *)(uVar3 * 2 + iVar4);
      *(int *)(psVar10 + -8) = (int)sVar1;
      psVar10[-2] = sVar1;
      sVar1 = *(short *)((uVar6 ^ 1) * 2 + iVar4);
      *(int *)(psVar10 + -6) = (int)sVar1;
      psVar10[-1] = sVar1;
      sVar1 = *(short *)((uVar8 ^ 1) * 2 + iVar4);
      iVar16 = iVar16 + -1;
      *(int *)(psVar10 + -4) = (int)sVar1;
      *psVar10 = sVar1;
      psVar10 = psVar10 + 0xbc;
    } while (iVar16 != -1);
  }
  return;
}
