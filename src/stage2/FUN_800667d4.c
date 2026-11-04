/* FUN_800667d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800667d4  body 0x800667d4..0x80066c3f  size 1132 B
 * body sha256 22da36ac8a1d204091d4e5e5404523adc1a5a9e77ec1af8b97fd9904be0030ad
 * provider record sha256 75c6f330051a2e0c41e888c5283de68db5536bff30c6c258928108ec61d35936
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800667d4(int *param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  ushort uVar5;
  short sVar6;
  int iVar4;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  short *psVar12;
  short *psVar13;
  int iVar14;
  
  puVar2 = DAT_800df938;
  iVar14 = *param_1;
  iVar10 = param_1[2];
  _DAT_80139e34 = &DAT_800e1068;
  DAT_800e1068 = 0;
  psVar11 = *(short **)(DAT_800df92c + 0x20);
  iVar3 = *(int *)(psVar11 + 2);
  uVar5 = FUN_800667b0(iVar14,iVar10,(int)*psVar11,(int)psVar11[1]);
  iVar14 = iVar14 + param_2;
  iVar10 = iVar10 + param_2;
  _DAT_80139e30 = 0;
  psVar13 = psVar11;
switchD_80066af0_default:
  do {
    do {
      do {
        psVar12 = psVar13;
        psVar13 = psVar12 + 8;
        if (psVar13 == psVar11 + iVar3 * 8) {
          return (int)(short)_DAT_80139e30;
        }
      } while ((psVar12[0xd] & uVar5) == 0);
      if ((param_2 & 1) != 0) {
        sVar6 = FUN_80040a58(((int)psVar12[9] + (uint)((ushort)psVar12[0xb] >> 1)) - iVar10,
                             ((int)*psVar13 + (uint)((ushort)psVar12[10] >> 1)) - iVar14);
        uVar7 = sVar6 - *(short *)((int)puVar2 + 0x66);
        uVar8 = uVar7 & 0xfff;
        if ((uVar7 & 0xc00) == 0xc00) {
          sVar6 = 0x1000;
LAB_80066920:
          uVar8 = sVar6 - uVar8;
        }
        else if ((uVar7 & 0x800) == 0) {
          sVar6 = 0x800;
          if ((uVar7 & 0x400) != 0) goto LAB_80066920;
        }
        else {
          uVar8 = uVar8 - 0x800;
        }
        param_2 = (uint)*(ushort *)((int)puVar2 + 0x12e);
        uVar9 = (uint)*(ushort *)(puVar2 + 0x4b);
        if (param_2 < uVar9) {
          iVar10 = FUN_800408c0((int)(short)uVar8);
          param_2 = param_2 + ((int)((uVar9 - param_2) * iVar10) >> 0xc);
        }
        else {
          iVar10 = FUN_80040968((int)(short)uVar8);
          param_2 = uVar9 + ((int)((param_2 - uVar9) * iVar10) >> 0xc);
        }
        iVar14 = *param_1 + param_2;
        iVar10 = param_1[2] + param_2;
      }
    } while (((((uint)(ushort)psVar12[10] + param_2 * 2 <= (uint)(iVar14 - *psVar13)) ||
              ((uint)(ushort)psVar12[0xb] + param_2 * 2 <= (uint)(iVar10 - psVar12[9]))) ||
             (((uint)(ushort)psVar12[0xc] & param_4 & 0xffff) == 0)) ||
            ((((uint)(ushort)psVar12[0xc] & param_4 >> 0x10) != 0 ||
             ((*(uint *)(psVar12 + 0xe) & param_3) == 0))));
    *_DAT_80139e34 = psVar13;
    puVar1 = _DAT_80139e34 + 1;
    _DAT_80139e34 = _DAT_80139e34 + 1;
    *puVar1 = 0;
    if (param_4 >> 0x10 == 0) {
      switch(psVar12[0xc] & 0xf) {
      case 0:
      case 7:
      case 8:
        _DAT_80139e30 = _DAT_80139e30 | 1;
        goto switchD_80066af0_default;
      case 1:
        uVar8 = FUN_80067578(puVar2 + 0x48,param_2,psVar13);
        break;
      case 2:
        uVar8 = FUN_800679f0(puVar2 + 0x48,param_2,psVar13);
        break;
      case 3:
        uVar8 = FUN_80067e6c(puVar2 + 0x48,param_2,psVar13);
        break;
      case 4:
        uVar8 = FUN_800682dc(puVar2 + 0x48,param_2,psVar13);
        break;
      case 5:
        uVar8 = FUN_80068e4c(puVar2 + 0x48,param_2,psVar13);
        break;
      case 6:
        uVar8 = FUN_800691c0(puVar2 + 0x48,param_2,psVar13);
        break;
      case 9:
        _DAT_80139e30 = _DAT_80139e30 | 3;
        goto switchD_80066af0_default;
      case 10:
        _DAT_80139e30 = _DAT_80139e30 | 4;
        goto switchD_80066af0_default;
      case 0xb:
        _DAT_80139e30 = _DAT_80139e30 | 8;
        goto switchD_80066af0_default;
      case 0xc:
        _DAT_80139e30 = _DAT_80139e30 | 0x10;
        DAT_80112718 = psVar13;
      default:
        goto switchD_80066af0_default;
      }
      _DAT_80139e30 = _DAT_80139e30 | uVar8;
      goto switchD_80066af0_default;
    }
    _DAT_80139e38 = puVar2[0x48];
    _DAT_80139e3c = puVar2[0x4a];
    iVar4 = (*(code *)(&PTR_FUN_801126c0)[(ushort)psVar12[0xc] & 0xf])(puVar2,param_2,psVar13);
    uVar9 = _DAT_80139e3c;
    if (iVar4 != 0) {
      iVar4 = puVar2[0x48] - _DAT_80139e38;
      iVar14 = iVar14 + iVar4;
      puVar2[10] = puVar2[10] + iVar4;
      *(short *)(puVar2 + 0x80) = *(short *)(puVar2 + 0x80) + (short)iVar4;
      iVar4 = puVar2[0x4a] - uVar9;
      iVar10 = iVar10 + iVar4;
      _DAT_80139e30 = _DAT_80139e30 | 1;
      puVar2[0xc] = puVar2[0xc] + iVar4;
      *(short *)(puVar2 + 0x81) = *(short *)(puVar2 + 0x81) + (short)iVar4;
      if (iVar4 != 0) {
        *puVar2 = *puVar2 | 0x4000;
      }
    }
  } while( true );
}
