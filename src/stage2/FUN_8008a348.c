/* FUN_8008a348
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008a348  body 0x8008a348..0x8008a993  size 1612 B
 * body sha256 6040152c3906bd3d89872939dd3b896b3b0fef0da916eaa6e7bb575a7a287f0c
 * provider record sha256 2483398d047afaf2597644259f8d3eb6565ced1af6c1f85eb30f3404591f5aac
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8008a348(byte *param_1,ushort *param_2,int param_3,uint param_4)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  uint *puVar11;
  int iVar12;
  ushort *puVar13;
  int iVar14;
  short *psVar15;
  uint uVar16;
  int iVar17;
  uint local_2c;
  
  uVar8 = *(uint *)(param_3 + (uint)*param_1 * 4);
  if ((param_4 & 0xffff0000) == 0) {
    uVar4 = (uint)param_1[1];
  }
  else {
    uVar4 = ((uVar8 & 0xffff) - (uint)param_1[1]) - 1;
  }
  bVar1 = param_1[2];
  local_2c = (uint)param_1[3];
  uVar16 = *(uint *)(param_1 + 4);
  iVar17 = *(int *)(DAT_800df938 + 0x234);
  puVar13 = (ushort *)(iVar17 + 0x118);
  psVar10 = (short *)((int)param_2 +
                     (*(uint *)(param_2 + 2) >> 0x12) *
                     (*(uint *)(param_3 + (uVar8 >> 0x10) + uVar4 * 4) & 0xfff) * 4 + (uint)*param_2
                     );
  puVar11 = (uint *)(psVar10 + 6);
  uVar2 = *(ushort *)((uint)*param_1 * 4 + param_3 + 2);
  psVar15 = psVar10 + 4;
  *(int *)(param_1 + 0x20) = (int)*psVar10 * (int)*(short *)(DAT_800df938 + 0x27a) >> 0xc;
  uVar4 = (uint)param_2[3];
  param_4 = param_4 & 0xffff;
  uVar8 = uVar4;
  do {
    if ((uVar16 & 1) != 0) {
      *(uint *)(puVar13 + -2) = (*puVar11 & 0xfff) << 0x10 | (*puVar11 & 0xfff000) >> 0xc;
      *puVar13 = (ushort)*(byte *)puVar11 | (psVar15[5] & 0xfU) << 8;
    }
    if (local_2c == 0) {
      *(uint *)(param_1 + 0x28) = (*puVar11 & 0xfff) << 0x10 | (*puVar11 & 0xfff000) >> 0xc;
      *(ushort *)(param_1 + 0x2c) = (ushort)*(byte *)puVar11 | (psVar15[5] & 0xfU) << 8;
      local_2c = 0xffffffff;
      FUN_80040e58(param_1 + 0x28,param_1 + 8);
    }
    if (uVar8 == 1) break;
    if ((uVar16 >> 1 & 1) != 0) {
      uVar5 = puVar11[1];
      *(uint *)(puVar13 + 0xba) = (uVar5 & 0xfff0) << 0xc | (uVar5 & 0xfff0000) >> 0x10;
      puVar13[0xbc] = (ushort)(puVar11[1] >> 0x1c) | (ushort)*(byte *)((int)psVar15 + 0xf) << 4;
    }
    if (uVar8 == 2) break;
    if ((uVar16 >> 2 & 1) != 0) {
      *(uint *)(puVar13 + 0x176) = (puVar11[2] & 0xfff00) << 8 | puVar11[2] >> 0x14;
      puVar13[0x178] = psVar15[9] & 0xfff;
    }
    if (uVar8 == 3) break;
    if ((uVar16 >> 3 & 1) != 0) {
      *(uint *)(puVar13 + 0x232) =
           (puVar11[3] & 0xfff000) << 4 | puVar11[3] >> 0x18 | (*(uint *)(psVar15 + 10) & 0xf) << 8;
      puVar13[0x234] = (ushort)((*(uint *)(psVar15 + 10) & 0xfff0) >> 4);
    }
    if (uVar8 == 4) break;
    if ((uVar16 >> 4 & 1) != 0) {
      *(uint *)(puVar13 + 0x2ee) =
           puVar11[4] & 0xfff0000 | puVar11[4] >> 0x1c | (uint)*(byte *)((int)psVar15 + 0x1b) << 4;
      puVar13[0x2f0] = (ushort)((uint)*(undefined4 *)(psVar15 + 0xc) >> 8) & 0xfff;
    }
    if (uVar8 == 5) break;
    if ((uVar16 >> 5 & 1) != 0) {
      *(uint *)(puVar13 + 0x3aa) = puVar11[5] >> 4 & 0xfff0000 | *(uint *)(psVar15 + 0xe) & 0xfff;
      puVar13[0x3ac] = (ushort)((*(uint *)(psVar15 + 0xe) & 0xfff000) >> 0xc);
    }
    if (uVar8 == 6) break;
    if ((uVar16 >> 6 & 1) != 0) {
      uVar5 = puVar11[7];
      *(uint *)(puVar13 + 0x466) =
           *(uint *)(psVar15 + 0xe) >> 8 & 0xfff0000 | (uVar5 & 0xf) << 0x18 | (uVar5 & 0xfff0) >> 4
      ;
      puVar13[0x468] = (ushort)(puVar11[7] >> 0x10) & 0xfff;
    }
    if (uVar8 == 7) break;
    if ((uVar16 >> 7 & 1) != 0) {
      uVar5 = puVar11[8];
      *(uint *)(puVar13 + 0x522) =
           *(uint *)(psVar15 + 0x10) >> 0xc & 0xf0000 | (uVar5 & 0xff) << 0x14 |
           (uVar5 & 0xfff00) >> 8;
      puVar13[0x524] = (ushort)(puVar11[8] >> 0x14);
    }
    uVar16 = uVar16 >> 8;
    psVar15 = psVar15 + 0x12;
    puVar11 = puVar11 + 9;
    uVar8 = uVar8 - 8;
    puVar13 = puVar13 + 0x5e0;
  } while (uVar8 != 0);
  uVar8 = *(uint *)(param_1 + 4);
  if (bVar1 == 0) {
    iVar12 = iVar17 + 8;
    do {
      if ((uVar8 & 1) != 0) {
        *(undefined4 *)(iVar12 + 0x50) = *(undefined4 *)(iVar12 + 0x10c);
        *(undefined2 *)(iVar12 + 0x54) = *(undefined2 *)(iVar12 + 0x110);
        FUN_80040e58(iVar17 + 0x114,iVar12);
      }
      uVar8 = uVar8 >> 1;
      iVar12 = iVar12 + 0x178;
      uVar4 = uVar4 - 1;
      iVar17 = iVar17 + 0x178;
    } while (uVar4 != 0);
  }
  else {
    iVar14 = 0x1000 - param_4;
    iVar12 = iVar17 + 8;
    do {
      if ((uVar8 & 1) != 0) {
        sVar7 = *(short *)(iVar12 + 0x10c);
        *(uint *)(iVar12 + 0x50) = *(uint *)(iVar12 + 0x50) & 0xfff0fff;
        uVar16 = *(ushort *)(iVar12 + 0x54) & 0xfff;
        *(short *)(iVar12 + 0x54) = (short)uVar16;
        uVar9 = ((int)sVar7 - (int)*(short *)(iVar12 + 0x50)) + 0x800;
        uVar5 = ((int)*(short *)(iVar12 + 0x110) - uVar16) + 0x800;
        uVar16 = ((int)*(short *)(iVar12 + 0x10e) - (int)*(short *)(iVar12 + 0x52)) + 0x800;
        if (0x1000 < uVar9) {
          sVar6 = sVar7 + 0x1000;
          if ((uVar9 & 0x8000) == 0) {
            sVar6 = sVar7 + -0x1000;
          }
          *(short *)(iVar12 + 0x10c) = sVar6;
        }
        if (0x1000 < uVar16) {
          sVar7 = *(short *)(iVar12 + 0x10e) + 0x1000;
          if ((uVar16 & 0x8000) == 0) {
            sVar7 = *(short *)(iVar12 + 0x10e) + -0x1000;
          }
          *(short *)(iVar12 + 0x10e) = sVar7;
        }
        if (0x1000 < uVar5) {
          sVar7 = *(short *)(iVar12 + 0x110) + 0x1000;
          if ((uVar5 & 0x8000) == 0) {
            sVar7 = *(short *)(iVar12 + 0x110) + -0x1000;
          }
          *(short *)(iVar12 + 0x110) = sVar7;
        }
        *(short *)(iVar12 + 0x50) =
             (short)((int)((int)*(short *)(iVar12 + 0x50) * param_4 +
                          *(short *)(iVar12 + 0x10c) * iVar14) >> 0xc);
        *(short *)(iVar12 + 0x52) =
             (short)((int)((int)*(short *)(iVar12 + 0x52) * param_4 +
                          *(short *)(iVar12 + 0x10e) * iVar14) >> 0xc);
        *(short *)(iVar12 + 0x54) =
             (short)((int)((int)*(short *)(iVar12 + 0x54) * param_4 +
                          *(short *)(iVar12 + 0x110) * iVar14) >> 0xc);
        FUN_80040e58(iVar17 + 0x58,iVar12);
      }
      uVar8 = uVar8 >> 1;
      iVar12 = iVar12 + 0x178;
      iVar17 = iVar17 + 0x178;
      uVar4 = uVar4 - 1;
      param_1[2] = param_1[2] - 1;
    } while (uVar4 != 0);
  }
  bVar1 = param_1[1];
  param_1[1] = bVar1 + 1;
  bVar3 = uVar2 <= (byte)(bVar1 + 1);
  if (bVar3) {
    param_1[1] = 0;
  }
  return bVar3;
}
