/* FUN_8004ed84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ed84  body 0x8004ed84..0x8004f47b  size 1784 B
 * body sha256 d1361c7d4f86100b29a9f2fe4afce3a8cb6f5a6d875fe6e2b89ed00b22150cb9
 * provider record sha256 b10496516b50fcc41bd0977e7933ff1608dab0496b3da6ee150f17777dc98092
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ed84(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  ushort *puVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  byte bVar17;
  uint uVar18;
  
  if (((*param_1 & 0x40) == 0) && (puVar14 = param_1 + 0x48, (*param_2 & 2) == 0)) {
    puVar1 = (uint *)FUN_8004f54c(param_1,puVar14,param_3,param_4,
                                  (uint)(ushort)(*(short *)((int)param_1 + 0x136) + 200) << 0x10,0);
    param_1[0xa0] = (uint)puVar1;
    puVar13 = param_2 + 0x48;
    if (puVar1 == param_2) {
      iVar11 = -(uint)(*(ushort *)(param_1 + 0x4b) >> 1) + (uint)*(ushort *)(param_2 + 0x4b);
      iVar15 = -(uint)(*(ushort *)(param_1 + 0x4b) >> 1) + (uint)*(ushort *)((int)param_2 + 0x12e);
      uVar18 = param_2[0x48] - param_1[0x48];
      uVar16 = param_2[0x4a] - param_1[0x4a];
      bVar4 = (uint)(iVar11 * 2) < uVar18 + iVar11;
      if ((uint)(iVar15 * 2) < uVar16 + iVar15) {
        bVar4 = bVar4 | 2;
      }
      bVar17 = (uint)(iVar11 * 2) <
               (param_2[0x48] -
               ((int)*(short *)((int)param_1 + 0x3a) + (int)*(short *)(param_1 + 0x4c))) + iVar11;
      if ((uint)(iVar15 * 2) <
          (param_2[0x4a] -
          ((int)*(short *)((int)param_1 + 0x3e) + (int)*(short *)((int)param_1 + 0x132))) + iVar15)
      {
        bVar17 = bVar17 | 2;
      }
      if (((bVar4 & 1) != 0) && (puVar1 = &DAT_800e18f8, &DAT_800e18f8 < DAT_800e85f8)) {
        puVar12 = &DAT_800e1a24;
        do {
          if ((((puVar1 != param_2) && ((*puVar1 & 0x101) == 0x101)) && ((*puVar1 & 2) == 0)) &&
             (param_2[0x49] - (uint)*(ushort *)((int)param_2 + 0x13a) ==
              *(int *)(puVar12 + -4) - (uint)puVar12[7])) {
            uVar6 = (uint)puVar12[1];
            iVar9 = *(int *)(puVar12 + -2);
            uVar8 = param_2[0x4a];
            iVar5 = (*(ushort *)((int)param_2 + 0x12e) + uVar6) - (uint)*(ushort *)(param_1 + 0x4b);
            if ((iVar9 - uVar8) + iVar5 < (uint)(iVar5 * 2)) {
              uVar10 = param_1[0x4a];
              if ((((iVar9 - uVar10) + uVar6 <= uVar6 << 1) &&
                  (iVar5 = (uint)*(ushort *)(param_2 + 0x4b) + (uint)*puVar12 + 200,
                  (*(int *)(puVar12 + -6) - *puVar13) + iVar5 <= (uint)(iVar5 * 2))) &&
                 (0 < (int)(*puVar13 - *(int *)(puVar12 + -6) ^ uVar18))) {
                iVar5 = -(uint)(*(ushort *)((int)param_1 + 0x12e) >> 1);
                iVar2 = iVar5 + (uint)*(ushort *)((int)param_2 + 0x12e);
                iVar5 = iVar5 + uVar6;
                uVar6 = iVar2 * 2;
                uVar7 = iVar5 * 2;
                bVar3 = (uVar8 - uVar10) + iVar2 < uVar6;
                if ((iVar9 - uVar10) + iVar5 < uVar7) {
                  bVar3 = bVar3 | 2;
                }
                if (bVar3 == 3) {
                  iVar15 = (int)*(short *)((int)param_1 + 0x3e) +
                           (int)*(short *)((int)param_1 + 0x132);
                  bVar4 = uVar6 < (uVar8 - iVar15) + iVar2;
                  if (uVar7 < (uint)((iVar9 - iVar15) + iVar5)) {
                    bVar4 = bVar4 | 2;
                  }
                  if (bVar4 == 0) {
                    return;
                  }
                  goto LAB_8004f410;
                }
                if ((bVar17 == 0) && ((bVar3 & 1) != 0)) goto LAB_8004f410;
                bVar4 = 2;
                if (bVar3 == 1) {
                  FUN_8004f4e4(param_1,puVar1 + 0x48,puVar1[0x4a] - uVar10,iVar15);
                  return;
                }
                iVar9 = (int)*(short *)((int)param_1 + 0x3e) + (int)*(short *)((int)param_1 + 0x132)
                ;
                if (((uVar8 - iVar9) + iVar2 < uVar6) && ((puVar1[0x4a] - iVar9) + iVar5 < uVar7))
                goto LAB_8004f3d8;
                if ((int)(uVar16 ^ uVar8 - puVar1[0x4a]) < 0) {
                  FUN_8004f47c(param_1,puVar13,uVar18,iVar11);
                }
              }
            }
          }
          puVar1 = puVar1 + 0xda;
          puVar12 = puVar12 + 0x1b4;
        } while (puVar1 < DAT_800e85f8);
      }
      if (((bVar4 & 2) != 0) &&
         (puVar1 = &DAT_800e18f8, (uint *)((int)&DAT_800e18f8 + 1) <= DAT_800e85f8)) {
        puVar12 = &DAT_800e1a26;
        do {
          if ((((puVar1 != param_2) && ((*puVar1 & 0x101) == 0x101)) && ((*puVar1 & 2) == 0)) &&
             (param_2[0x49] - (uint)*(ushort *)((int)param_2 + 0x13a) ==
              *(int *)(puVar12 + -5) - (uint)puVar12[6])) {
            uVar6 = (uint)puVar12[-1];
            iVar9 = *(int *)(puVar12 + -7);
            uVar8 = *puVar13;
            iVar5 = (*(ushort *)(param_2 + 0x4b) + uVar6) - (uint)*(ushort *)(param_1 + 0x4b);
            if ((iVar9 - uVar8) + iVar5 < (uint)(iVar5 * 2)) {
              uVar10 = *puVar14;
              if ((((iVar9 - uVar10) + uVar6 <= uVar6 << 1) &&
                  (iVar5 = (uint)*(ushort *)((int)param_2 + 0x12e) + (uint)*puVar12 + 200,
                  (*(int *)(puVar12 + -3) - param_2[0x4a]) + iVar5 <= (uint)(iVar5 * 2))) &&
                 (0 < (int)(param_2[0x4a] - *(int *)(puVar12 + -3) ^ uVar16))) {
                iVar5 = -(uint)(*(ushort *)(param_1 + 0x4b) >> 1);
                iVar2 = iVar5 + (uint)*(ushort *)(param_2 + 0x4b);
                iVar5 = iVar5 + uVar6;
                uVar6 = iVar2 * 2;
                uVar7 = iVar5 * 2;
                bVar3 = (uVar8 - uVar10) + iVar2 < uVar6;
                if ((iVar9 - uVar10) + iVar5 < uVar7) {
                  bVar3 = bVar3 | 2;
                }
                if (bVar3 == 3) {
                  iVar11 = (int)*(short *)((int)param_1 + 0x3a) + (int)*(short *)(param_1 + 0x4c);
                  bVar4 = (uVar8 - iVar11) + iVar2 < uVar6;
                  if ((uint)((iVar9 - iVar11) + iVar5) < uVar7) {
                    bVar4 = bVar4 | 2;
                  }
                  if (bVar4 == 3) {
                    return;
                  }
LAB_8004f3d8:
                  FUN_8004f4e4(param_1,puVar13,uVar16,iVar15);
                  return;
                }
                bVar4 = 1;
                if ((bVar17 == 0) && ((bVar3 & 1) != 0)) goto LAB_8004f3d8;
                if (bVar3 == 1) {
                  FUN_8004f47c(param_1,puVar1 + 0x48,puVar1[0x48] - uVar10,iVar11);
                  return;
                }
                iVar9 = (int)*(short *)((int)param_1 + 0x3a) + (int)*(short *)(param_1 + 0x4c);
                if (((uVar8 - iVar9) + iVar2 < uVar6) && ((puVar1[0x48] - iVar9) + iVar5 < uVar7)) {
LAB_8004f410:
                  FUN_8004f47c(param_1,puVar13,uVar18,iVar11);
                  return;
                }
                if ((int)(uVar18 ^ uVar8 - puVar1[0x48]) < 0) {
                  FUN_8004f4e4(param_1,puVar13,uVar16,iVar15);
                }
              }
            }
          }
          puVar1 = puVar1 + 0xda;
          puVar12 = puVar12 + 0x1b4;
        } while (puVar1 < DAT_800e85f8);
      }
      bVar4 = bVar4 & (bVar17 ^ bVar4);
      if ((bVar4 & 1) != 0) {
        uVar6 = param_1[10];
        if (-1 < (int)uVar18) {
          iVar11 = -iVar11;
        }
        uVar18 = (*puVar13 - (int)*(short *)(param_1 + 0x4c)) + iVar11;
        param_1[10] = uVar18;
        *puVar14 = *puVar14 + (uVar18 - uVar6);
      }
      if ((bVar4 & 2) != 0) {
        uVar18 = param_1[0xc];
        if (-1 < (int)uVar16) {
          iVar15 = -iVar15;
        }
        uVar16 = (param_2[0x4a] - (int)*(short *)((int)param_1 + 0x132)) + iVar15;
        param_1[0xc] = uVar16;
        param_1[0x4a] = param_1[0x4a] + (uVar16 - uVar18);
      }
      uVar16 = FUN_8004f54c(param_1,puVar14);
      param_1[0xa0] = uVar16;
    }
  }
  return;
}
