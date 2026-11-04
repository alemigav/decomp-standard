/* FUN_8004226c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004226c  body 0x8004226c..0x80042453  size 488 B
 * body sha256 4d2a936edf290ad4bf314ba615ae448dc35e21f9c53fe899543a0be1cdc7c850
 * provider record sha256 c7a1ecb011f35598b8de21f50b734fc993aef1a7a399069552354dac7ea631d6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined2 * FUN_8004226c(short *param_1,short *param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar12 = (int)*param_1;
  iVar6 = (int)*param_2;
  iVar13 = (int)param_1[1];
  iVar8 = (int)param_2[3];
  iVar14 = (int)param_1[2];
  iVar10 = (int)param_2[6];
  iVar15 = (int)param_1[3];
  iVar4 = (int)param_1[4];
  iVar5 = (int)param_1[5];
  *param_3 = (short)(iVar13 * iVar8 + iVar12 * iVar6 + iVar14 * iVar10 >> 0xc);
  iVar2 = (int)param_1[6];
  iVar3 = (int)param_1[7];
  iVar1 = (int)param_1[8];
  param_3[3] = (short)(iVar4 * iVar8 + iVar15 * iVar6 + iVar5 * iVar10 >> 0xc);
  iVar7 = (int)param_2[1];
  iVar9 = (int)param_2[4];
  param_3[6] = (short)(iVar3 * iVar8 + iVar2 * iVar6 + iVar1 * iVar10 >> 0xc);
  iVar10 = (int)param_2[7];
  param_3[1] = (short)(iVar13 * iVar9 + iVar12 * iVar7 + iVar14 * iVar10 >> 0xc);
  param_3[4] = (short)(iVar4 * iVar9 + iVar15 * iVar7 + iVar5 * iVar10 >> 0xc);
  iVar6 = (int)param_2[2];
  iVar8 = (int)param_2[5];
  iVar11 = (int)param_2[8];
  param_3[7] = (short)(iVar3 * iVar9 + iVar2 * iVar7 + iVar1 * iVar10 >> 0xc);
  param_3[2] = (short)(iVar13 * iVar8 + iVar12 * iVar6 + iVar14 * iVar11 >> 0xc);
  param_3[5] = (short)(iVar4 * iVar8 + iVar15 * iVar6 + iVar5 * iVar11 >> 0xc);
  param_3[8] = (short)(iVar3 * iVar8 + iVar2 * iVar6 + iVar1 * iVar11 >> 0xc);
  return param_3;
}
