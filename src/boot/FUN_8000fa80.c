/* FUN_8000fa80
 * image   boot (boot), base 0x80000480
 * address 0x8000fa80  body 0x8000fa80..0x8000febf  size 1088 B
 * body sha256 1994080db626d188bfdfc478924d44125eff04913b2bfa225c224be1c7fbbb67
 * provider record sha256 df95f40bdfcb60356fb61825fbd29815b0a60db71c5d53216c5657fbfb9e83cf
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000fa80(double *param_1,char param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  bool bVar4;
  undefined4 uVar5;
  short sVar8;
  int iVar6;
  uint uVar7;
  ushort uVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  ushort uVar13;
  byte bVar14;
  double *pdVar15;
  byte *pbVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  char *pcVar19;
  int iVar20;
  char *pcVar21;
  char *pcVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  char local_68;
  char local_67;
  char local_66 [6];
  char local_60 [24];
  ushort local_48 [4];
  int local_40 [2];
  
  pcVar22 = &local_68;
  dVar24 = *param_1;
  if (*(int *)((int)param_1 + 0x24) < 0) {
    uVar5 = 6;
  }
  else if ((*(int *)((int)param_1 + 0x24) != 0) || (uVar5 = 1, !(param_2 == 'g' || param_2 == 'G')))
  goto LAB_8000fafc;
  *(undefined4 *)((int)param_1 + 0x24) = uVar5;
LAB_8000fafc:
  sVar8 = FUN_8000fec0(local_48,param_1);
  if (0 < sVar8) {
    puVar17 = &DAT_80011edc;
    puVar18 = *(undefined1 **)(param_1 + 1);
    if (sVar8 == 2) {
      puVar17 = &DAT_80011ed8;
    }
    *(undefined4 *)((int)param_1 + 0x14) = 3;
    uVar1 = puVar17[1];
    uVar2 = puVar17[2];
    *puVar18 = *puVar17;
    puVar18[1] = uVar1;
    puVar18[2] = uVar2;
    return;
  }
  sVar10 = 0;
  if (sVar8 == 0) {
    local_48[0] = 0;
  }
  else {
    if (dVar24 < 0.0) {
      dVar24 = -dVar24;
    }
    iVar11 = ((short)local_48[0] * 0x7597) / 100000 + -4;
    iVar6 = iVar11 * 0x10000 >> 0x10;
    local_48[0] = (ushort)iVar11;
    if (iVar6 < 0) {
      uVar12 = 3U - iVar6 & 0xfffffffc;
      local_48[0] = -(short)uVar12;
      if (0 < (int)uVar12) {
        pdVar15 = (double *)&DAT_80011e90;
        do {
          uVar7 = uVar12 & 1;
          uVar12 = (int)uVar12 >> 1;
          if (uVar7 != 0) {
            dVar24 = dVar24 * *pdVar15;
          }
          pdVar15 = pdVar15 + 1;
        } while (0 < (int)uVar12);
      }
    }
    else if (0 < iVar6) {
      local_48[0] = local_48[0] & 0xfffc;
      dVar23 = _DAT_80011ee0;
      if (0 < (short)local_48[0]) {
        pdVar15 = (double *)&DAT_80011e90;
        uVar13 = local_48[0];
        do {
          uVar9 = uVar13 & 1;
          uVar13 = (short)uVar13 >> 1;
          if (uVar9 != 0) {
            dVar23 = dVar23 * *pdVar15;
          }
          pdVar15 = pdVar15 + 1;
        } while (0 < (short)uVar13);
      }
      dVar24 = dVar24 / dVar23;
    }
    iVar6 = *(int *)((int)param_1 + 0x24) + 6;
    if (param_2 == 'f') {
      iVar6 = *(int *)((int)param_1 + 0x24) + 10 + (int)(short)local_48[0];
    }
    if (0x13 < iVar6) {
      iVar6 = 0x13;
    }
    local_68 = '0';
    pcVar21 = &local_67;
    dVar25 = 0.0;
    dVar23 = _DAT_80011ee8;
    while (bVar4 = 0 < iVar6, iVar6 = iVar6 + -8, bVar4 && dVar25 < dVar24) {
      iVar11 = (int)dVar24;
      pcVar21 = pcVar21 + 8;
      if (0 < iVar6) {
        dVar24 = (dVar24 - (double)iVar11) * dVar23;
      }
      iVar20 = 8;
      if (iVar11 < 1) goto LAB_8000fd30;
      iVar20 = 7;
      do {
        if (iVar20 < 0) goto LAB_8000fd30;
        FUN_80010500(local_40,iVar11,10);
        pcVar21 = pcVar21 + -1;
        *pcVar21 = (char)local_40[1] + '0';
        iVar20 = iVar20 + -1;
        iVar11 = local_40[0];
      } while (0 < local_40[0]);
      for (; -1 < iVar20; iVar20 = iVar20 + -1) {
        pcVar21 = pcVar21 + -1;
        *pcVar21 = '0';
LAB_8000fd30:
      }
      pcVar21 = pcVar21 + 8;
    }
    pcVar21 = pcVar21 + (-1 - (int)&local_68);
    local_48[0] = local_48[0] + 7;
    pcVar22 = &local_67;
    while (local_67 == '0') {
      pcVar22 = pcVar22 + 1;
      local_48[0] = local_48[0] - 1;
      pcVar21 = pcVar21 + -1;
      local_67 = *pcVar22;
    }
    if (param_2 == 'f') {
      pcVar19 = (char *)(*(int *)((int)param_1 + 0x24) + 1 + (int)(short)local_48[0]);
    }
    else {
      pcVar19 = (char *)(*(int *)((int)param_1 + 0x24) + (uint)(param_2 == 'e' || param_2 == 'E'));
    }
    if ((int)pcVar21 < (int)(short)pcVar19) {
      pcVar19 = pcVar21;
    }
    sVar10 = (short)pcVar19;
    iVar6 = (int)sVar10;
    if (0 < iVar6) {
      bVar14 = 0x30;
      if (iVar6 < (int)pcVar21) {
        bVar14 = -(0x34U < (byte)pcVar22[iVar6]) & 0x39U | 0x30;
      }
      iVar6 = iVar6 + -1;
      pbVar16 = (byte *)(pcVar22 + iVar6);
      bVar3 = *pbVar16;
      while (bVar3 == bVar14) {
        pbVar16 = pbVar16 + -1;
        pcVar19 = pcVar19 + -1;
        sVar10 = (short)pcVar19;
        iVar6 = iVar6 + -1;
        bVar3 = *pbVar16;
      }
      if (bVar14 == 0x39) {
        pcVar22[iVar6] = pcVar22[iVar6] + '\x01';
      }
      if (iVar6 < 0) {
        pcVar22 = pcVar22 + -1;
        sVar10 = sVar10 + 1;
        local_48[0] = local_48[0] + 1;
      }
    }
  }
  FUN_8000ff58(param_1,param_2,pcVar22,(int)sVar10,(int)(short)local_48[0]);
  return;
}
