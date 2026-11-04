/* FUN_8017eed4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017eed4  body 0x8017eed4..0x8017f253  size 896 B
 * body sha256 503011f602d002cabaea63e71244233477ce1e319c96590ac18f5f7a6b66fe19
 * provider record sha256 e0bf99388ad8b32142ce34477a6e6432389a83769f61750505f27ee8ce4f8811
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017eed4(uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  byte *pbVar5;
  short *psVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  
  iVar8 = DAT_80185740;
  if (param_5 == 0) {
    iVar8 = DAT_80185740 + 0x80;
  }
  iVar9 = 0;
  if (3 < (int)param_1) {
    iVar9 = (param_1 & 1) + 1;
  }
  if (iVar9 == 0) {
    if (DAT_801857a0 == 3) {
      if (param_4 == 0) {
        iVar2 = (param_1 & 1) << 3;
        uVar4 = DAT_80185734 + DAT_80185754 * (param_3 + (param_1 & 2) * 4) + param_2;
        iVar9 = DAT_80185754;
      }
      else {
        iVar2 = (param_1 & 1) << 3;
        uVar4 = DAT_80185734 + DAT_80185754 * (param_3 + ((int)(param_1 & 2) >> 1)) + param_2;
        iVar9 = DAT_80185754 << 1;
      }
    }
    else {
      iVar9 = DAT_80185754 * 2;
      iVar2 = (param_1 & 1) << 3;
      uVar4 = DAT_80185734 + iVar9 * (param_3 + (param_1 & 2) * 4) + param_2;
    }
  }
  else {
    if (DAT_8018575c != 3) {
      param_2 = param_2 >> 1;
    }
    if (DAT_8018575c == 1) {
      param_3 = param_3 >> 1;
    }
    if (DAT_801857a0 == 3) {
      if ((param_4 == 0) || (DAT_8018575c == 1)) {
        iVar2 = DAT_80185760 * (param_3 + (param_1 & 2) * 4);
        piVar3 = &DAT_80185734 + iVar9;
        iVar9 = DAT_80185760;
      }
      else {
        iVar2 = DAT_80185760 * (param_3 + ((int)(param_1 & 2) >> 1));
        piVar3 = &DAT_80185734 + iVar9;
        iVar9 = DAT_80185760 << 1;
      }
    }
    else {
      iVar2 = DAT_80185760 * 2 * (param_3 + (param_1 & 2) * 4);
      piVar3 = &DAT_80185734 + iVar9;
      iVar9 = DAT_80185760 * 2;
    }
    uVar4 = param_1 & 8;
    iVar2 = *piVar3 + iVar2 + param_2;
  }
  pbVar7 = (byte *)(iVar2 + uVar4);
  psVar10 = (short *)(DAT_80186c94 + param_1 * 0x80 + 0x438);
  if (param_5 == 0) {
    iVar2 = 0;
    psVar6 = psVar10 + 7;
    pbVar5 = pbVar7 + 7;
    do {
      *pbVar7 = *(byte *)(iVar8 + *psVar10);
      pbVar5[-6] = *(byte *)(iVar8 + psVar6[-6]);
      pbVar5[-5] = *(byte *)(iVar8 + psVar6[-5]);
      pbVar5[-4] = *(byte *)(iVar8 + psVar6[-4]);
      pbVar5[-3] = *(byte *)(iVar8 + psVar6[-3]);
      pbVar5[-2] = *(byte *)(iVar8 + psVar6[-2]);
      psVar10 = psVar10 + 8;
      iVar2 = iVar2 + 1;
      pbVar5[-1] = *(byte *)(iVar8 + psVar6[-1]);
      sVar1 = *psVar6;
      pbVar7 = pbVar7 + iVar9;
      psVar6 = psVar6 + 8;
      *pbVar5 = *(byte *)(iVar8 + sVar1);
      pbVar5 = pbVar5 + iVar9;
    } while (iVar2 < 8);
    return;
  }
  iVar2 = 0;
  psVar6 = psVar10 + 7;
  pbVar5 = pbVar7 + 7;
  do {
    *pbVar7 = *(byte *)(iVar8 + (int)*psVar10 + (uint)*pbVar7);
    pbVar5[-6] = *(byte *)(iVar8 + (int)psVar6[-6] + (uint)pbVar5[-6]);
    pbVar5[-5] = *(byte *)(iVar8 + (int)psVar6[-5] + (uint)pbVar5[-5]);
    pbVar5[-4] = *(byte *)(iVar8 + (int)psVar6[-4] + (uint)pbVar5[-4]);
    pbVar5[-3] = *(byte *)(iVar8 + (int)psVar6[-3] + (uint)pbVar5[-3]);
    pbVar5[-2] = *(byte *)(iVar8 + (int)psVar6[-2] + (uint)pbVar5[-2]);
    psVar10 = psVar10 + 8;
    iVar2 = iVar2 + 1;
    pbVar5[-1] = *(byte *)(iVar8 + (int)psVar6[-1] + (uint)pbVar5[-1]);
    sVar1 = *psVar6;
    pbVar7 = pbVar7 + iVar9;
    psVar6 = psVar6 + 8;
    *pbVar5 = *(byte *)(iVar8 + (int)sVar1 + (uint)*pbVar5);
    pbVar5 = pbVar5 + iVar9;
  } while (iVar2 < 8);
  return;
}
