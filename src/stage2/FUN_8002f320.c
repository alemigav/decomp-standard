/* FUN_8002f320
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002f320  body 0x8002f320..0x8002f883  size 1380 B
 * body sha256 0fb89011fbf821db2e108d56d4bf6484431f34f20945018fcc0fe1922a7a1fd0
 * provider record sha256 5c2390465ced8255fdd19f5c85db0f6464993db2bd68cd984dfb09d8181b1c6c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002f320(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  short *psVar10;
  undefined1 *puVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  int local_a0 [16];
  int local_60 [8];
  int local_40 [8];
  
  piVar16 = local_a0;
  piVar17 = local_a0;
  piVar12 = local_60;
  psVar10 = param_3 + 0x38;
  piVar14 = *(int **)(param_2 + 0x4c);
  iVar15 = *(int *)(param_1 + 0x114) + 0x80;
  piVar9 = piVar14 + 8;
  for (iVar13 = 8; 0 < iVar13; iVar13 = iVar13 + -1) {
    if (iVar13 != 4) {
      if (*psVar10 == 0 &&
          (psVar10[-8] == 0 &&
          (psVar10[-0x10] == 0 &&
          (psVar10[-0x20] == 0 && (psVar10[-0x30] == 0 && psVar10[-0x28] == 0))))) {
        iVar2 = (int)*param_3 * *piVar14 * 4;
        *piVar16 = iVar2;
        piVar12[-8] = iVar2;
        *piVar12 = iVar2;
        piVar12[8] = iVar2;
      }
      else {
        iVar2 = (int)*psVar10 * piVar9[0x30];
        iVar5 = (int)psVar10[-0x30] * *piVar9;
        iVar4 = (int)psVar10[-0x28] * piVar9[8] * 0x3b21 + (int)psVar10[-8] * piVar9[0x28] * -0x187e
        ;
        iVar6 = (int)psVar10[-0x10] * piVar9[0x20];
        iVar7 = (int)*param_3 * *piVar14 * 0x4000;
        iVar3 = iVar7 + iVar4;
        iVar7 = iVar7 - iVar4;
        iVar4 = (int)psVar10[-0x20] * piVar9[0x10];
        iVar8 = iVar6 * 0x2e75 + iVar2 * -0x6c2 + iVar4 * -0x4587 + iVar5 * 0x21f9;
        iVar2 = iVar6 * -0x133e + iVar2 * -0x1050 + iVar4 * 0x1ccd + iVar5 * 0x5203;
        *piVar16 = iVar3 + iVar2 + 0x800 >> 0xc;
        piVar12[8] = (iVar3 - iVar2) + 0x800 >> 0xc;
        piVar12[-8] = iVar7 + iVar8 + 0x800 >> 0xc;
        *piVar12 = (iVar7 - iVar8) + 0x800 >> 0xc;
      }
    }
    psVar10 = psVar10 + 1;
    param_3 = param_3 + 1;
    piVar9 = piVar9 + 1;
    piVar14 = piVar14 + 1;
    piVar12 = piVar12 + 1;
    piVar16 = piVar16 + 1;
  }
  piVar9 = local_a0 + 7;
  for (iVar13 = 0; iVar13 < 4; iVar13 = iVar13 + 1) {
    iVar4 = piVar9[-6];
    iVar6 = piVar9[-4];
    iVar5 = piVar9[-2];
    iVar2 = *piVar9;
    puVar11 = (undefined1 *)(*param_4 + param_5);
    if (((((iVar4 == 0 && piVar9[-5] == 0) && iVar6 == 0) && iVar5 == 0) && piVar9[-1] == 0) &&
        iVar2 == 0) {
      uVar1 = *(undefined1 *)(iVar15 + (*piVar17 + 0x10 >> 5 & 0x3ffU));
      *puVar11 = uVar1;
      puVar11[1] = uVar1;
      puVar11[2] = uVar1;
      puVar11[3] = uVar1;
    }
    else {
      iVar7 = piVar9[-5] * 0x3b21 + piVar9[-1] * -0x187e;
      iVar3 = *piVar17 * 0x4000 + iVar7;
      iVar7 = *piVar17 * 0x4000 - iVar7;
      iVar8 = iVar5 * -0x133e + iVar2 * -0x1050 + iVar6 * 0x1ccd + iVar4 * 0x5203;
      *puVar11 = *(undefined1 *)(iVar15 + (iVar3 + iVar8 + 0x40000 >> 0x13 & 0x3ffU));
      iVar2 = iVar5 * 0x2e75 + iVar2 * -0x6c2 + iVar6 * -0x4587 + iVar4 * 0x21f9;
      puVar11[3] = *(undefined1 *)(iVar15 + ((iVar3 - iVar8) + 0x40000 >> 0x13 & 0x3ffU));
      puVar11[1] = *(undefined1 *)(iVar15 + (iVar7 + iVar2 + 0x40000 >> 0x13 & 0x3ffU));
      puVar11[2] = *(undefined1 *)(iVar15 + ((iVar7 - iVar2) + 0x40000 >> 0x13 & 0x3ffU));
    }
    piVar17 = piVar17 + 8;
    piVar9 = piVar9 + 8;
    param_4 = param_4 + 1;
  }
  return;
}
