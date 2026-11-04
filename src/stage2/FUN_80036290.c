/* FUN_80036290
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036290  body 0x80036290..0x80036693  size 1028 B
 * body sha256 7a444a894902c0102573c89ee1d0b47c4866eb135a92d37c0397fd63bd21639a
 * provider record sha256 a7117aee338e4faf9786867a67c372f57e41ef5a07fee5fc306c95f56d037eb1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80036290(int param_1,int param_2,byte *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  short *psVar6;
  int *piVar7;
  uint uVar8;
  ushort *puVar9;
  short sVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  ushort *puVar17;
  int local_70 [8];
  short local_50;
  short local_4e;
  short local_4c;
  short local_48;
  short local_46;
  short local_44;
  short local_40;
  short local_3e;
  short local_3c;
  short local_38;
  short local_36;
  short local_34;
  int *local_30;
  int local_2c;
  
  puVar11 = *(uint **)(param_2 + 200);
  piVar2 = (int *)puVar11[3];
  if (piVar2 != (int *)0x0) {
    piVar7 = (int *)puVar11[1];
    uVar12 = 0;
    local_30 = piVar2;
    if (*puVar11 != 0) {
      piVar4 = local_70;
      do {
        iVar3 = *piVar7;
        piVar7 = piVar7 + 4;
        uVar12 = uVar12 + 1;
        *piVar4 = iVar3;
        piVar4 = piVar4 + 1;
      } while (uVar12 < *puVar11);
    }
    if (uVar12 < 8) {
      piVar7 = local_70 + uVar12;
      do {
        *piVar7 = 0;
        uVar12 = uVar12 + 1;
        piVar7 = piVar7 + 1;
      } while (uVar12 < 8);
    }
    puVar17 = *(ushort **)(param_3 + 0x34);
    local_2c = *(int *)(param_3 + 0xc);
    iVar16 = *(int *)(param_3 + 0x24);
    iVar15 = *(int *)(param_3 + 0x10);
    local_30 = local_30 + *piVar2 + 1;
    uVar12 = (uint)*(ushort *)(param_3 + 2);
    iVar3 = *(int *)(param_1 + 0x234) + (uint)*param_3 * 0x178;
    iVar5 = *(int *)(param_1 + 0x234) + (uint)param_3[1] * 0x178;
    iVar13 = iVar5 + 0x38;
    do {
      uVar14 = (uint)puVar17[1];
      if (uVar14 == 0) {
        FUN_8004276c(iVar13,iVar16,&local_50);
        FUN_8004276c(iVar13,iVar15,&local_48);
        local_50 = local_50 + *(short *)(iVar5 + 0x4e);
        local_4e = local_4e + *(short *)(iVar5 + 0x52);
        local_4c = local_4c + *(short *)(iVar5 + 0x56);
LAB_800365ac:
      }
      else {
        FUN_8004276c(iVar3 + 0x38,local_2c,&local_50);
        FUN_8004276c(iVar3 + 0x38,iVar15,&local_48);
        local_50 = local_50 + *(short *)(iVar3 + 0x4e);
        local_4e = local_4e + *(short *)(iVar3 + 0x52);
        local_4c = local_4c + *(short *)(iVar3 + 0x56);
        if (uVar14 < 0x1000) {
          FUN_8004276c(iVar13,iVar16,&local_40);
          FUN_8004276c(iVar13,iVar15,&local_38);
          uVar8 = 0x1000 - uVar14 & 0xffff;
          local_40 = local_40 + *(short *)(iVar5 + 0x4e);
          local_3e = local_3e + *(short *)(iVar5 + 0x52);
          local_3c = local_3c + *(short *)(iVar5 + 0x56);
          local_50 = (short)((int)((int)local_50 * uVar14 + (int)local_40 * uVar8) >> 0xc);
          local_48 = (short)((int)((int)local_48 * uVar14 + (int)local_38 * uVar8) >> 0xc);
          local_46 = (short)((int)((int)local_46 * uVar14 + (int)local_36 * uVar8) >> 0xc);
          local_44 = (short)((int)((int)local_44 * uVar14 + (int)local_34 * uVar8) >> 0xc);
          local_4e = (short)((int)((int)local_4e * uVar14 + (int)local_3e * uVar8) >> 0xc);
          local_4c = (short)((int)((int)local_4c * uVar14 + (int)local_3c * uVar8) >> 0xc);
          goto LAB_800365ac;
        }
      }
      sVar10 = *(short *)(piVar2 + *puVar17 + 1);
      puVar9 = (ushort *)(local_30 + (short)piVar2[*puVar17 + 1]);
      while (bVar1 = sVar10 != 0, sVar10 = sVar10 + -1, bVar1) {
        psVar6 = (short *)(local_70[*puVar9] + (uint)puVar9[1] * 0x10);
        *psVar6 = local_50;
        psVar6[1] = local_4e;
        psVar6[2] = local_4c;
        *(char *)(psVar6 + 6) = (char)((ushort)local_48 >> 8);
        puVar9 = puVar9 + 2;
        *(char *)((int)psVar6 + 0xd) = (char)((ushort)local_46 >> 8);
        *(char *)(psVar6 + 7) = (char)((ushort)local_44 >> 8);
      }
      iVar15 = iVar15 + 8;
      iVar16 = iVar16 + 8;
      uVar12 = uVar12 - 1;
      puVar17 = puVar17 + 2;
      local_2c = local_2c + 8;
    } while (uVar12 != 0);
  }
  return;
}
