/* FUN_80069f1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069f1c  body 0x80069f1c..0x8006a42b  size 1296 B
 * body sha256 d466c879efa346371a3ef5f688ae522392e84d0c6ed50b1a7edad2d57931a162
 * provider record sha256 a6a9ecdd47b74e70326e6e997f0f1db7a6520aba7be41bb7e4b6e2a442522922
 * callees 14 direct (14 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80069f1c(uint *param_1,int param_2,ushort param_3,int param_4)

{
  int iVar1;
  ushort uVar4;
  int iVar2;
  int iVar3;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  int *piVar9;
  short *psVar10;
  short *psVar11;
  short *psVar12;
  uint uVar13;
  
  uVar6 = *param_1;
  uVar13 = param_1[2];
  psVar10 = *(short **)(DAT_800df92c + 0x20);
  iVar1 = *(int *)(psVar10 + 2);
  uVar4 = FUN_800667b0(uVar6,uVar13,(int)*psVar10,(int)psVar10[1]);
  DAT_80112708 = *(int *)(psVar10 + 4);
  _DAT_80139e42 = 0;
  DAT_80112710 = 0;
  DAT_8011270c = (uint)(0 < (int)param_1[1]);
  psVar12 = psVar10;
  DAT_80112714 = DAT_80112708;
  if (param_4 == 0) {
    puVar7 = &DAT_800e18f8;
    DAT_80112714 = DAT_80112708;
    if (DAT_800e85f8 != &DAT_800e18f8) {
      piVar9 = &DAT_800e1a1c;
      DAT_80112714 = DAT_80112708;
      do {
        if (((*puVar7 & 1) != 0) && (param_1 != puVar7 + 10)) {
          FUN_80050eb8(puVar7);
          iVar2 = FUN_8004f774(param_1,puVar7,param_2,0);
          if (iVar2 != 0) {
            iVar2 = *piVar9 - (uint)*(ushort *)((int)piVar9 + 0x16);
            if (iVar2 < (int)param_1[1]) {
              if ((int)(*piVar9 + (uint)*(ushort *)((int)piVar9 + 0x16)) < (int)param_1[1])
              goto LAB_8006a0d0;
              iVar2 = *piVar9 - (uint)*(ushort *)((int)piVar9 + 0x16);
              DAT_8011270c = DAT_8011270c | 1;
              if (iVar2 < DAT_80112710) {
                DAT_80112710 = iVar2;
              }
              iVar2 = param_1[1] - 1;
            }
            if (iVar2 < _DAT_80139e42) {
              _DAT_80139e42 = (short)iVar2;
            }
          }
        }
LAB_8006a0d0:
        puVar7 = puVar7 + 0xda;
        piVar9 = piVar9 + 0xda;
      } while (puVar7 != DAT_800e85f8);
    }
  }
switchD_8006a1c4_caseD_a:
  do {
    do {
      do {
        do {
          do {
            psVar11 = psVar12;
            psVar12 = psVar11 + 8;
            if (psVar12 == psVar10 + iVar1 * 8) {
              return (int)_DAT_80139e42;
            }
          } while ((psVar11[0xd] & uVar4) == 0);
        } while ((uint)(ushort)psVar11[10] + param_2 * 2 <= (uVar6 + param_2) - (int)*psVar12);
      } while ((uint)(ushort)psVar11[0xb] + param_2 * 2 <= (uVar13 + param_2) - (int)psVar11[9]);
    } while ((psVar11[0xc] & param_3) == 0);
  } while ((psVar11[0xc] & 0xfU) == 10);
  iVar2 = 0;
  for (uVar5 = *(uint *)(psVar11 + 0xe); (uVar5 & 1) == 0; uVar5 = (int)uVar5 >> 1) {
    iVar2 = iVar2 + -0x708;
  }
  iVar8 = ((ushort)psVar11[0xd] >> 6 & 0x1f) * -0x708;
  switch(psVar11[0xc] & 0xf) {
  default:
    goto switchD_8006a1c4_caseD_0;
  case 1:
    iVar3 = FUN_80067578(param_1,param_2,psVar12);
    break;
  case 2:
    iVar3 = FUN_800679f0(param_1,param_2,psVar12);
    break;
  case 3:
    iVar3 = FUN_80067e6c(param_1,param_2,psVar12);
    break;
  case 4:
    iVar3 = FUN_800682dc(param_1,param_2,psVar12);
    break;
  case 5:
    iVar3 = FUN_80068e4c(param_1,param_2,psVar12);
    break;
  case 6:
    iVar3 = FUN_800691c0(param_1,param_2,psVar12);
    break;
  case 7:
    iVar3 = FUN_80069338(param_1,param_2,psVar12);
    break;
  case 8:
    iVar3 = FUN_8006956c(param_1,param_2,psVar12);
    break;
  case 10:
    goto switchD_8006a1c4_caseD_a;
  case 0xb:
    iVar3 = FUN_80069c60(*param_1,param_1[2],param_2,psVar12);
    iVar8 = iVar8 + iVar3;
    goto LAB_8006a340;
  case 0xc:
    iVar3 = FUN_80069dac(param_1,iVar2,iVar8,psVar12);
    iVar8 = iVar8 + iVar3;
    goto LAB_8006a340;
  case 0xd:
    iVar8 = FUN_80069ebc(param_1,iVar2,iVar8,psVar12);
    goto LAB_8006a340;
  }
  if (iVar3 != 0) {
switchD_8006a1c4_caseD_0:
    iVar8 = iVar8 + (uint)((ushort)psVar11[0xd] >> 0xb) * -100;
LAB_8006a340:
    if ((int)param_1[1] <= iVar2) {
      if (iVar8 < (int)param_1[1]) {
        DAT_8011270c = DAT_8011270c | 1;
        if (iVar8 < DAT_80112710) {
          DAT_80112710 = iVar8;
        }
      }
      else {
        if (iVar8 < _DAT_80139e42) {
          _DAT_80139e42 = (short)iVar8;
        }
        if ((int)param_1[1] < iVar8) goto switchD_8006a1c4_caseD_a;
      }
    }
    if ((int)param_1[1] < iVar2) {
      DAT_8011270c = DAT_8011270c | 2;
      if (DAT_80112714 < iVar2) {
        DAT_80112714 = iVar2;
      }
    }
    else if (DAT_80112708 < iVar2) {
      DAT_80112708 = iVar2;
    }
  }
  goto switchD_8006a1c4_caseD_a;
}
