/* FUN_8006ab40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ab40  body 0x8006ab40..0x8006b21f  size 1760 B
 * body sha256 1f4b3f5efa57b2cb987c45c605ac9e50f1bf38a8f5715bd4c84019d438b74092
 * provider record sha256 bdcee1b0fceb81504fde280005fb9a3977c1a8460bf0beb319d8f3fc2eb2a0ac
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8006ab40(int *param_1,int *param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  
  psVar6 = *(short **)(DAT_800df92c + 0x20);
  psVar14 = psVar6 + *(int *)(psVar6 + 2) * 8;
LAB_8006aba0:
  psVar6 = psVar6 + 8;
LAB_8006aba4:
  do {
    while( true ) {
      if (psVar6 == psVar14) {
        return 0;
      }
      if (((ushort)psVar6[4] & param_3) == 0) goto LAB_8006aba0;
      if ((&DAT_801126f8)[(ushort)psVar6[4] & 0xf] == '\0') break;
      psVar6 = psVar6 + 8;
    }
    _DAT_80139e44 = 3;
    if (((uint)(*param_1 - (int)*psVar6) < (uint)(ushort)psVar6[2]) &&
       ((uint)(param_1[2] - (int)psVar6[1]) < (uint)(ushort)psVar6[3])) {
      _DAT_80139e44 = 2;
    }
    else if (((uint)(*param_2 - (int)*psVar6) < (uint)(ushort)psVar6[2]) &&
            ((uint)(param_2[2] - (int)psVar6[1]) < (uint)(ushort)psVar6[3])) {
      _DAT_80139e44 = 2;
    }
    else {
      iVar8 = (int)psVar6[1];
      iVar4 = param_1[2];
      uVar11 = (uint)(ushort)psVar6[2];
      iVar2 = (int)*psVar6;
      iVar3 = *param_1;
      uVar1 = (uint)(ushort)psVar6[3];
      iVar9 = param_2[2];
      iVar12 = *param_2;
      iVar10 = iVar3 - iVar12;
      iVar7 = iVar4 - iVar9;
      iVar5 = iVar8 + uVar1;
      if ((-1 < (int)((uVar11 * (iVar4 - iVar8) - uVar1 * (iVar3 - iVar2) ^
                      uVar11 * (iVar9 - iVar8) - uVar1 * (iVar12 - iVar2)) &
                     (iVar10 * (iVar8 - iVar4) - iVar7 * (iVar2 - iVar3) ^
                     iVar10 * (iVar5 - iVar4) - iVar7 * ((iVar2 + uVar11) - iVar3)))) &&
         (-1 < (int)((uVar11 * (iVar5 - iVar4) - uVar1 * (iVar3 - iVar2) ^
                     uVar11 * (iVar5 - iVar9) - uVar1 * (iVar12 - iVar2)) &
                    (iVar10 * (iVar5 - iVar4) - iVar7 * (iVar2 - iVar3) ^
                    iVar10 * (iVar8 - iVar4) - iVar7 * ((iVar2 + uVar11) - iVar3))))) {
        psVar6 = psVar6 + 8;
        goto LAB_8006aba4;
      }
    }
    if (param_4 == 0) {
      return 1;
    }
    iVar9 = 0;
    for (uVar1 = *(uint *)(psVar6 + 6); (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
      iVar9 = iVar9 + -0x708;
    }
    iVar8 = (uint)((ushort)psVar6[5] >> 0xb) * -100 + ((ushort)psVar6[5] >> 6 & 0x1f) * -0x708;
    if ((((uint)(param_1[1] - iVar8) < (uint)(iVar9 - iVar8)) &&
        ((uint)(param_1[2] - (int)psVar6[1]) < (uint)(ushort)psVar6[3])) ||
       (((uint)(param_2[1] - iVar8) < (uint)(iVar9 - iVar8) &&
        ((uint)(param_2[2] - (int)psVar6[1]) < (uint)(ushort)psVar6[3])))) {
      _DAT_80139e44 = _DAT_80139e44 ^ 2;
LAB_8006b014:
      if ((((uint)(param_1[1] - iVar8) < (uint)(iVar9 - iVar8)) &&
          ((uint)(*param_1 - (int)*psVar6) < (uint)(ushort)psVar6[2])) ||
         (((uint)(param_2[1] - iVar8) < (uint)(iVar9 - iVar8) &&
          ((uint)(*param_2 - (int)*psVar6) < (uint)(ushort)psVar6[2])))) break;
      iVar7 = param_1[1];
      uVar1 = (uint)(ushort)psVar6[2];
      iVar4 = (int)*psVar6;
      iVar5 = *param_1;
      iVar13 = iVar9 - iVar8;
      iVar3 = param_2[1];
      iVar2 = *param_2;
      iVar12 = iVar5 - iVar2;
      iVar10 = iVar7 - iVar3;
      if (((int)((uVar1 * (iVar7 - iVar8) - iVar13 * (iVar5 - iVar4) ^
                 uVar1 * (iVar3 - iVar8) - iVar13 * (iVar2 - iVar4)) &
                (iVar12 * (iVar8 - iVar7) - iVar10 * (iVar4 - iVar5) ^
                iVar12 * (iVar9 - iVar7) - iVar10 * ((iVar4 + uVar1) - iVar5))) < 0) ||
         (psVar6 = psVar6 + 8,
         (int)((uVar1 * (iVar9 - iVar7) - iVar13 * (iVar5 - iVar4) ^
               uVar1 * (iVar9 - iVar3) - iVar13 * (iVar2 - iVar4)) &
              (iVar12 * (iVar9 - iVar7) - iVar10 * (iVar4 - iVar5) ^
              iVar12 * (iVar8 - iVar7) - iVar10 * ((iVar4 + uVar1) - iVar5))) < 0)) {
        return 1;
      }
    }
    else {
      iVar7 = param_1[1];
      uVar1 = (uint)(ushort)psVar6[3];
      iVar4 = (int)psVar6[1];
      iVar5 = param_1[2];
      iVar13 = iVar9 - iVar8;
      iVar3 = param_2[1];
      iVar2 = param_2[2];
      iVar12 = iVar5 - iVar2;
      iVar10 = iVar7 - iVar3;
      if (((int)((uVar1 * (iVar7 - iVar8) - iVar13 * (iVar5 - iVar4) ^
                 uVar1 * (iVar3 - iVar8) - iVar13 * (iVar2 - iVar4)) &
                (iVar12 * (iVar8 - iVar7) - iVar10 * (iVar4 - iVar5) ^
                iVar12 * (iVar9 - iVar7) - iVar10 * ((iVar4 + uVar1) - iVar5))) < 0) ||
         ((int)((uVar1 * (iVar9 - iVar7) - iVar13 * (iVar5 - iVar4) ^
                uVar1 * (iVar9 - iVar3) - iVar13 * (iVar2 - iVar4)) &
               (iVar12 * (iVar9 - iVar7) - iVar10 * (iVar4 - iVar5) ^
               iVar12 * (iVar8 - iVar7) - iVar10 * ((iVar4 + uVar1) - iVar5))) < 0))
      goto LAB_8006b014;
      psVar6 = psVar6 + 8;
    }
  } while( true );
  if (_DAT_80139e44 != 0) {
    return 1;
  }
  goto LAB_8006aba0;
}
