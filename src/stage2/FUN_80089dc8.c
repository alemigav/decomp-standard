/* FUN_80089dc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089dc8  body 0x80089dc8..0x8008a347  size 1408 B
 * body sha256 07ba00fc42b5cb28d3f49967f388adbbfc0c8047d589073ff98df3676a2d6c29
 * provider record sha256 c553c1cb5b5ec00d91179af5b2bad1dd3725383f5c4dad05ebe149b937908c2a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80089dc8(ushort *param_1,int param_2,uint *param_3,uint param_4)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  byte bVar8;
  int iVar9;
  short *psVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  uint uVar20;
  
  iVar4 = DAT_800df938;
  puVar18 = *(uint **)(DAT_800df938 + 0x234);
  uVar1 = *(ushort *)((uint)*(byte *)(DAT_800df938 + 0x1e8) * 4 + param_2 + 2);
  psVar10 = (short *)((int)param_1 +
                     (*(uint *)(param_1 + 2) >> 0x12) * (*param_3 & 0xfff) * 4 + (uint)*param_1);
  puVar18[7] = (int)psVar10[1];
  iVar16 = (int)*psVar10 * (int)*(short *)(iVar4 + 0x27a);
  puVar18[8] = iVar16 >> 0xc;
  puVar18[9] = (int)psVar10[3];
  uVar19 = (uint)param_1[3];
  uVar17 = (uint)*(byte *)(iVar4 + 0x1ea);
  if (uVar17 != 0) {
    DAT_8012bd70 = (int)*(short *)(puVar18 + 10);
    iVar16 = (param_4 & 0xffff) * uVar17;
    DAT_8012bd74 = (int)*(short *)((int)puVar18 + 0x2a);
    DAT_8012bd78 = (int)*(short *)(puVar18 + 0xb);
    iVar9 = 0x1000 - iVar16;
    puVar18[7] = (int)(puVar18[7] * iVar9 + DAT_8012bd70 * iVar16) >> 0xc;
    puVar18[8] = (int)(puVar18[8] * iVar9 + DAT_8012bd74 * iVar16) >> 0xc;
    puVar18[9] = (int)(puVar18[9] * iVar9 + DAT_8012bd78 * iVar16) >> 0xc;
  }
  puVar11 = (uint *)(psVar10 + 6);
  *(undefined2 *)(puVar18 + 10) = *(undefined2 *)((int)puVar18 + 0x1e);
  *(undefined2 *)((int)puVar18 + 0x2a) = *(undefined2 *)((int)puVar18 + 0x22);
  *(undefined2 *)(puVar18 + 0xb) = *(undefined2 *)((int)puVar18 + 0x26);
  puVar15 = puVar18;
  uVar20 = uVar19;
  do {
    puVar15[0x45] = (*puVar11 & 0xfff) << 0x10 | (*puVar11 & 0xfff000) >> 0xc;
    *(ushort *)(puVar15 + 0x46) =
         (ushort)*(byte *)puVar11 | (*(ushort *)((int)puVar11 + 6) & 0xf) << 8;
    if (uVar20 == 1) break;
    uVar5 = puVar11[1];
    puVar15[0xa3] = (uVar5 & 0xfff0) << 0xc | (uVar5 & 0xfff0000) >> 0x10;
    *(ushort *)(puVar15 + 0xa4) =
         (ushort)(puVar11[1] >> 0x1c) | (ushort)*(byte *)((int)puVar11 + 0xb) << 4;
    if (uVar20 == 2) break;
    puVar15[0x101] = (puVar11[2] & 0xfff00) << 8 | puVar11[2] >> 0x14;
    *(ushort *)(puVar15 + 0x102) = *(ushort *)((int)puVar11 + 0xe) & 0xfff;
    if (uVar20 == 3) break;
    puVar12 = puVar11 + 4;
    puVar15[0x15f] = (puVar11[3] & 0xfff000) << 4 | puVar11[3] >> 0x18 | (*puVar12 & 0xf) << 8;
    *(short *)(puVar15 + 0x160) = (short)((*puVar12 & 0xfff0) >> 4);
    if (uVar20 == 4) break;
    puVar15[0x1bd] =
         *puVar12 & 0xfff0000 | *puVar12 >> 0x1c | (uint)*(byte *)((int)puVar11 + 0x17) << 4;
    *(ushort *)(puVar15 + 0x1be) = (ushort)(puVar11[5] >> 8) & 0xfff;
    if (uVar20 == 5) break;
    puVar12 = puVar11 + 6;
    puVar15[0x21b] = puVar11[5] >> 4 & 0xfff0000 | *puVar12 & 0xfff;
    *(short *)(puVar15 + 0x21c) = (short)((*puVar12 & 0xfff000) >> 0xc);
    if (uVar20 == 6) break;
    puVar13 = puVar11 + 7;
    puVar15[0x279] = *puVar12 >> 8 & 0xfff0000 | (*puVar13 & 0xf) << 0x18 | (*puVar13 & 0xfff0) >> 4
    ;
    *(ushort *)(puVar15 + 0x27a) = (ushort)(*puVar13 >> 0x10) & 0xfff;
    if (uVar20 == 7) break;
    puVar12 = puVar11 + 8;
    uVar20 = uVar20 - 8;
    uVar5 = *puVar12;
    puVar15[0x2d7] = *puVar13 >> 0xc & 0xfff0000 | (uVar5 & 0xff) << 0x14 | (uVar5 & 0xfff00) >> 8;
    puVar11 = puVar11 + 9;
    *(ushort *)(puVar15 + 0x2d8) = (ushort)(*puVar12 >> 0x14);
    puVar15 = puVar15 + 0x2f0;
  } while (uVar20 != 0);
  puVar15 = puVar18;
  uVar20 = uVar19;
  if (uVar17 == 0) {
    do {
      uVar20 = uVar20 - 1;
      puVar15[0x16] = puVar15[0x45];
      *(undefined2 *)(puVar15 + 0x17) = *(undefined2 *)(puVar15 + 0x46);
      puVar15 = puVar15 + 0x5e;
    } while (uVar20 != 0);
  }
  else {
    *(char *)(iVar4 + 0x1ea) = *(char *)(iVar4 + 0x1ea) + -1;
    uVar17 = uVar19;
    do {
      uVar2 = *(ushort *)(puVar15 + 0x17);
      sVar7 = *(short *)(puVar15 + 0x45);
      puVar15[0x16] = puVar15[0x16] & 0xfff0fff;
      *(short *)(puVar15 + 0x17) = (short)(uVar2 & 0xfff);
      uVar14 = ((int)sVar7 - (int)*(short *)(puVar15 + 0x16)) + 0x800;
      uVar5 = ((int)*(short *)(puVar15 + 0x46) - (uVar2 & 0xfff)) + 0x800;
      uVar20 = ((int)*(short *)((int)puVar15 + 0x116) - (int)*(short *)((int)puVar15 + 0x5a)) +
               0x800;
      if (0x1000 < uVar14) {
        sVar6 = sVar7 + 0x1000;
        if ((uVar14 & 0x8000) == 0) {
          sVar6 = sVar7 + -0x1000;
        }
        *(short *)(puVar15 + 0x45) = sVar6;
      }
      if (0x1000 < uVar20) {
        sVar7 = *(short *)((int)puVar15 + 0x116) + 0x1000;
        if ((uVar20 & 0x8000) == 0) {
          sVar7 = *(short *)((int)puVar15 + 0x116) + -0x1000;
        }
        *(short *)((int)puVar15 + 0x116) = sVar7;
      }
      if (0x1000 < uVar5) {
        sVar7 = *(short *)(puVar15 + 0x46) + 0x1000;
        if ((uVar5 & 0x8000) == 0) {
          sVar7 = *(short *)(puVar15 + 0x46) + -0x1000;
        }
        *(short *)(puVar15 + 0x46) = sVar7;
      }
      iVar9 = 0x1000 - iVar16;
      uVar17 = uVar17 - 1;
      *(short *)(puVar15 + 0x16) =
           (short)(*(short *)(puVar15 + 0x16) * iVar16 + *(short *)(puVar15 + 0x45) * iVar9 >> 0xc);
      *(short *)((int)puVar15 + 0x5a) =
           (short)(*(short *)((int)puVar15 + 0x5a) * iVar16 +
                   *(short *)((int)puVar15 + 0x116) * iVar9 >> 0xc);
      *(short *)(puVar15 + 0x17) =
           (short)(*(short *)(puVar15 + 0x17) * iVar16 + *(short *)(puVar15 + 0x46) * iVar9 >> 0xc);
      puVar15 = puVar15 + 0x5e;
    } while (uVar17 != 0);
  }
  do {
    if ((*puVar18 & 0x200) == 0) {
      FUN_80040e58(puVar18 + 0x16,puVar18 + 2);
    }
    uVar19 = uVar19 - 1;
    puVar18 = puVar18 + 0x5e;
  } while (uVar19 != 0);
  bVar8 = *(char *)(iVar4 + 0x1e9) + 1;
  *(byte *)(iVar4 + 0x1e9) = bVar8;
  bVar3 = uVar1 <= bVar8;
  if (bVar3) {
    *(undefined1 *)(iVar4 + 0x1e9) = 0;
  }
  return bVar3;
}
