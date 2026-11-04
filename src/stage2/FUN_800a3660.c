/* FUN_800a3660
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a3660  body 0x800a3660..0x800a3bf3  size 1428 B
 * body sha256 e0fb524aeb635243c2a1f567029da4afcb6e32cb5553f812a51ef55a2ca67126
 * provider record sha256 b9c85008ec58a62522a0a49b692fe207812a61587f7d3bd2a6f50c0d6e040b77
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a3660(int *param_1,uint param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  ushort uVar13;
  ushort uVar14;
  int *piVar15;
  int local_68 [2];
  undefined2 uStack_5e;
  undefined2 local_5a;
  uint local_58 [4];
  uint *local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  uVar14 = 0;
  local_58[2] = param_2 + param_3;
  local_58[3] = param_2 - 0x600;
  if (_DAT_80143f98 != (int *)0x0) {
    iVar10 = 0x600;
    iVar9 = -0x7fec0000;
    iVar8 = -0x7fec0000;
    iVar7 = -0x7fec0000;
    iVar6 = -0x7fec0000;
    piVar11 = _DAT_80143f98;
    uVar13 = uVar14;
    do {
      piVar15 = (int *)piVar11[1];
      uVar14 = uVar13;
      if (((piVar11[3] == param_4) && (uVar12 = piVar11[2], uVar12 < local_58[2])) &&
         (local_58[3] < uVar12)) {
        iVar5 = piVar11[4];
        if ((iVar5 != iVar10) && (uVar4 = param_2 + param_3, uVar12 + iVar5 < uVar4)) {
          if (uVar4 < uVar12 + 0x600) {
            uVar12 = (uVar4 - (uVar12 + iVar5)) + 0xff & 0xffffff00;
          }
          else {
            uVar12 = iVar10 - iVar5;
          }
          uVar3 = *(undefined4 *)(iVar8 + 0x3fdc);
          *(int *)(iVar9 + 0x3fd0) = *(int *)(iVar9 + 0x3fd0) + 0xc;
          local_40 = iVar6;
          local_3c = iVar7;
          local_38 = iVar8;
          local_34 = iVar9;
          local_30 = iVar10;
          uVar3 = FUN_80135cb0(uVar3);
          iVar6 = _DAT_80143fec;
          iVar7 = piVar11[2];
          iVar8 = piVar11[4];
          uVar14 = *(ushort *)(local_3c + 0x3fcc);
          *(undefined4 *)(local_38 + 0x3fdc) = uVar3;
          puVar1 = (uint *)((uint)uVar14 * 0xc + iVar6);
          puVar1[1] = iVar7 + iVar8;
          *puVar1 = uVar12;
          *(int *)((uint)uVar14 * 0xc + iVar6 + 8) = piVar11[5] + piVar11[4];
          iVar6 = piVar11[4];
          *(ushort *)(local_3c + 0x3fcc) = uVar14 + 1;
          piVar11[4] = iVar6 + uVar12;
          iVar6 = local_40;
          iVar7 = local_3c;
          iVar8 = local_38;
          iVar9 = local_34;
          iVar10 = local_30;
        }
        if (piVar11 != *(int **)(iVar6 + 0x3f98)) {
          if (*piVar11 != 0) {
            *(int *)(*piVar11 + 4) = piVar11[1];
          }
          if ((int *)piVar11[1] == (int *)0x0) {
            _DAT_80143f94 = *piVar11;
          }
          else {
            *(int *)piVar11[1] = *piVar11;
          }
          puVar2 = *(undefined4 **)(iVar6 + 0x3f98);
          *(int **)(iVar6 + 0x3f98) = piVar11;
          *puVar2 = piVar11;
          piVar11[1] = (int)puVar2;
          *piVar11 = 0;
        }
        uVar12 = piVar11[2];
        if (param_2 < uVar12) {
          local_68[uVar13] = piVar11[5];
          local_58[uVar13] = piVar11[2];
          iVar5 = param_3 - (piVar11[2] - param_2);
          local_68[uVar13 + 2] = iVar5;
        }
        else {
          if (param_2 + param_3 <= uVar12 + piVar11[4]) {
            uVar14 = uVar13 + 1;
            local_68[uVar13] = piVar11[5] + (param_2 - uVar12);
            local_58[uVar13] = param_2;
            local_68[uVar13 + 2] = param_3;
            param_3 = 0;
            break;
          }
          local_68[uVar13] = piVar11[5] + (param_2 - uVar12);
          local_58[uVar13] = param_2;
          iVar5 = (piVar11[2] + piVar11[4]) - param_2;
          local_68[uVar13 + 2] = iVar5;
          param_2 = piVar11[2] + piVar11[4];
        }
        param_3 = param_3 - iVar5;
        uVar14 = uVar13 + 1;
      }
      piVar11 = piVar15;
      uVar13 = uVar14;
    } while (piVar15 != (int *)0x0);
  }
  if (param_3 != 0) {
    local_44 = local_68;
    local_48 = local_58;
    uVar12 = (param_2 - param_4) % 0x600;
    do {
      iVar6 = FUN_800a35c8(param_4);
      *(uint *)(iVar6 + 8) = param_2 - uVar12;
      *(int *)(iVar6 + 0xc) = param_4;
      uVar3 = _DAT_80143fdc;
      if (param_3 + uVar12 < 0x601) {
        *(uint *)(iVar6 + 0x10) = param_3 + uVar12 + 0xff & 0xffffff00;
        _DAT_80143fd0 = _DAT_80143fd0 + 0xc;
        _DAT_80143fdc = FUN_80135cb0(uVar3);
        iVar7 = _DAT_80143fec;
        uVar4 = (uint)_DAT_80143fcc;
        puVar2 = (undefined4 *)(uVar4 * 0xc + _DAT_80143fec);
        puVar2[1] = *(undefined4 *)(iVar6 + 8);
        _DAT_80143fcc = _DAT_80143fcc + 1;
        *puVar2 = *(undefined4 *)(iVar6 + 0x10);
        *(undefined4 *)(uVar4 * 0xc + iVar7 + 8) = *(undefined4 *)(iVar6 + 0x14);
        local_44[uVar14] = *(int *)(iVar6 + 0x14) + uVar12;
        local_48[uVar14] = *(int *)(iVar6 + 8) + uVar12;
        local_68[uVar14 + 2] = param_3;
        param_3 = 0;
      }
      else {
        *(undefined4 *)(iVar6 + 0x10) = 0x600;
        _DAT_80143fd0 = _DAT_80143fd0 + 0xc;
        _DAT_80143fdc = FUN_80135cb0(uVar3);
        iVar7 = _DAT_80143fec;
        param_3 = param_3 + -0x600 + uVar12;
        param_2 = param_2 - (uVar12 - 0x600);
        uVar4 = (uint)_DAT_80143fcc;
        puVar2 = (undefined4 *)(uVar4 * 0xc + _DAT_80143fec);
        puVar2[1] = *(undefined4 *)(iVar6 + 8);
        *puVar2 = 0x600;
        _DAT_80143fcc = _DAT_80143fcc + 1;
        *(undefined4 *)(uVar4 * 0xc + iVar7 + 8) = *(undefined4 *)(iVar6 + 0x14);
        local_44[uVar14] = *(int *)(iVar6 + 0x14) + uVar12;
        local_48[uVar14] = *(int *)(iVar6 + 8) + uVar12;
        local_68[uVar14 + 2] = 0x600 - uVar12;
      }
      uVar14 = uVar14 + 1;
      uVar12 = 0;
    } while (param_3 != 0);
  }
  if (uVar14 == 1) {
    *param_1 = local_68[0];
    *(undefined2 *)((int)param_1 + 10) = 0;
    *(undefined2 *)(param_1 + 2) = uStack_5e;
  }
  else if (local_58[0] < local_58[1]) {
    *param_1 = local_68[0];
    param_1[1] = local_68[1];
    *(undefined2 *)(param_1 + 2) = uStack_5e;
    *(undefined2 *)((int)param_1 + 10) = local_5a;
  }
  else {
    *param_1 = local_68[1];
    param_1[1] = local_68[0];
    *(undefined2 *)(param_1 + 2) = local_5a;
    *(undefined2 *)((int)param_1 + 10) = uStack_5e;
  }
  return;
}
