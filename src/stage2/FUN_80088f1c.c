/* FUN_80088f1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088f1c  body 0x80088f1c..0x8008922f  size 788 B
 * body sha256 acffa1e56c7ee5f2af3257f067f0efe55a6df72fde8b1c8baf807c492cb1210c
 * provider record sha256 d33e121a69be240211da6094e2bd19411ba97ea56405cb6ca2de56189cea0a43
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80088f1c(int param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  char cVar19;
  uint *puVar20;
  uint *puVar21;
  
  cVar19 = '\0';
  uVar15 = 0;
  puVar13 = *(undefined4 **)(param_1 + 0x234);
  uVar18 = (uint)*(ushort *)(param_3 + 6);
  puVar20 = (uint *)(param_3 + (*(ushort *)(param_3 + 2) & 0xfffc));
  iVar16 = *(byte *)(param_1 + 0x1a3) - 1;
  param_3 = param_3 + 8;
  iVar17 = *(int *)(*(int *)(param_1 + 0xc4) + 8);
  puVar13[0x19] = param_1 + 0x14;
  puVar13[0x4b] = param_1;
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
  if (iVar16 != -1) {
    puVar8 = puVar13 + 0x4b;
    puVar14 = puVar13;
    puVar21 = puVar20;
    do {
      puVar8[-0x3d] = 0x10000000;
      puVar8[-0x3c] = 0;
      puVar8[-0x3b] = 0x10000000;
      puVar8[-0x3a] = 0;
      puVar8[-0x39] = 0x10000000;
      puVar8[-0x38] = 0;
      puVar8[-0x37] = 0;
      puVar8[-0x36] = 0;
      puVar12 = puVar14 + 2;
      iVar11 = 2;
      puVar9 = &DAT_800e9048;
      do {
        iVar5 = 2;
        puVar4 = puVar9;
        puVar7 = puVar12;
        do {
          uVar2 = *puVar4;
          puVar4 = puVar4 + 1;
          iVar5 = iVar5 + -1;
          *(undefined2 *)puVar7 = uVar2;
          puVar7 = (undefined4 *)((int)puVar7 + 2);
        } while (iVar5 != -1);
        puVar12 = (undefined4 *)((int)puVar12 + 6);
        iVar11 = iVar11 + -1;
        puVar9 = puVar9 + 3;
      } while (iVar11 != -1);
      puVar8[-0x33] = 0x808080;
      puVar8[-0x4a] = 0;
      puVar8[-0x35] = 0;
      *(undefined2 *)(puVar8 + -0x34) = 0;
      *(undefined2 *)(puVar8 + 1) = 0;
      *(undefined2 *)((int)puVar8 + 6) = 0;
      *(undefined2 *)(puVar8 + 2) = 0;
      *(undefined2 *)((int)puVar8 + 10) = 0;
      *(undefined2 *)(puVar8 + 3) = 0;
      *(undefined2 *)((int)puVar8 + 0xe) = 0;
      *puVar14 = 1;
      *(undefined2 *)(puVar8 + -0x38) = 0;
      *(char *)(puVar8 + -7) = cVar19;
      puVar8[-0x21] = *(undefined4 *)(param_1 + 0xb8);
      puVar8[-0x20] = *(undefined4 *)(param_1 + 0xbc);
      puVar8[-0x1f] = *(undefined4 *)(param_1 + 0xc0);
      puVar8[-0x1e] = *(undefined4 *)(param_1 + 0xc4);
      *(undefined2 *)(puVar8 + -0x1a) = *(undefined2 *)(param_1 + 0xd4);
      *(undefined2 *)((int)puVar8 + -0x66) = *(undefined2 *)(param_1 + 0xd6);
      uVar3 = *(undefined4 *)(param_1 + 0xdc);
      puVar8[-0x19] = iVar17;
      puVar8[-0x1e] = 0;
      puVar8[-0x1c] = 0;
      puVar8[-0x18] = uVar3;
      sVar1 = *(short *)((uVar15 ^ 1) * 2 + param_3);
      puVar8[-0x44] = (int)sVar1;
      *(short *)(puVar8 + -0x41) = sVar1;
      sVar1 = *(short *)((uVar15 + 1 ^ 1) * 2 + param_3);
      iVar17 = iVar17 + 0x10;
      puVar8[-0x43] = (int)sVar1;
      *(short *)((int)puVar8 + -0x102) = sVar1;
      sVar1 = *(short *)((uVar15 + 2 ^ 1) * 2 + param_3);
      uVar15 = uVar15 + 3;
      puVar8[-0x42] = (int)sVar1;
      *(short *)(puVar8 + -0x40) = sVar1;
      if (uVar18 == 0) {
        puVar8[-0x32] = &DAT_800e9028;
        *puVar8 = 0;
      }
      else {
        iVar11 = (*puVar21 & 0xffff) - 1;
        uVar10 = (int)puVar20 + (*puVar21 >> 0x10);
        if (iVar11 != -1) {
          do {
            pbVar6 = (byte *)(uVar10 ^ 3);
            uVar10 = uVar10 + 1;
            puVar13[(uint)*pbVar6 * 0x5e + 0x19] = puVar14 + 0xe;
            iVar11 = iVar11 + -1;
            puVar13[(uint)*pbVar6 * 0x5e + 0x4b] = puVar14;
          } while (iVar11 != -1);
        }
        puVar21 = puVar21 + 1;
        uVar18 = uVar18 - 1;
      }
      puVar8 = puVar8 + 0x5e;
      puVar14 = puVar14 + 0x5e;
      iVar16 = iVar16 + -1;
      cVar19 = cVar19 + '\x01';
    } while (iVar16 != -1);
  }
  return param_2;
}
