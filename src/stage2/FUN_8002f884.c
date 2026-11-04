/* FUN_8002f884
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002f884  body 0x8002f884..0x8002fbbb  size 824 B
 * body sha256 85c68c23ddefe0fbdf8638c69a6784d8e3c4ab413435eb42d465f97f9e0be0ab
 * provider record sha256 06564017047fa3cc1072dd18ed876477f8f3f48197fc576b85e0fc549b75a12e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002f884(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  short *psVar7;
  undefined1 *puVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int local_60 [16];
  
  piVar4 = local_60;
  piVar5 = local_60;
  piVar12 = local_60 + 8;
  psVar7 = param_3 + 0x38;
  piVar10 = *(int **)(param_2 + 0x4c);
  iVar11 = *(int *)(param_1 + 0x114) + 0x80;
  piVar6 = piVar10 + 8;
  for (iVar9 = 8; 0 < iVar9; iVar9 = iVar9 + -1) {
    if (((iVar9 != 6) && (iVar9 != 4)) && (iVar9 != 2)) {
      if (*psVar7 == 0 && (psVar7[-0x10] == 0 && (psVar7[-0x30] == 0 && psVar7[-0x20] == 0))) {
        iVar1 = (int)*param_3 * *piVar10 * 4;
        *piVar4 = iVar1;
      }
      else {
        iVar3 = (int)*param_3 * *piVar10 * 0x8000;
        iVar1 = (int)psVar7[-0x10] * piVar6[0x20] * 0x1b37 + (int)*psVar7 * piVar6[0x30] * -0x1712 +
                (int)psVar7[-0x20] * piVar6[0x10] * -0x28ba + (int)psVar7[-0x30] * *piVar6 * 0x73fc;
        *piVar4 = iVar3 + iVar1 + 0x1000 >> 0xd;
        iVar1 = (iVar3 - iVar1) + 0x1000 >> 0xd;
      }
      *piVar12 = iVar1;
    }
    psVar7 = psVar7 + 1;
    param_3 = param_3 + 1;
    piVar6 = piVar6 + 1;
    piVar10 = piVar10 + 1;
    piVar12 = piVar12 + 1;
    piVar4 = piVar4 + 1;
  }
  piVar4 = local_60 + 7;
  for (iVar9 = 0; iVar9 < 2; iVar9 = iVar9 + 1) {
    puVar8 = (undefined1 *)(*param_4 + param_5);
    if (((piVar4[-6] == 0 && piVar4[-4] == 0) && piVar4[-2] == 0) && *piVar4 == 0) {
      uVar2 = *(undefined1 *)(iVar11 + (*piVar5 + 0x10 >> 5 & 0x3ffU));
      *puVar8 = uVar2;
    }
    else {
      iVar1 = *piVar5;
      iVar3 = piVar4[-2] * 0x1b37 + *piVar4 * -0x1712 + piVar4[-4] * -0x28ba + piVar4[-6] * 0x73fc;
      *puVar8 = *(undefined1 *)(iVar11 + (iVar1 * 0x8000 + iVar3 + 0x80000 >> 0x14 & 0x3ffU));
      uVar2 = *(undefined1 *)(iVar11 + ((iVar1 * 0x8000 - iVar3) + 0x80000 >> 0x14 & 0x3ffU));
    }
    piVar5 = piVar5 + 8;
    piVar4 = piVar4 + 8;
    puVar8[1] = uVar2;
    param_4 = param_4 + 1;
  }
  return;
}
