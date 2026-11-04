/* FUN_8002edd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002edd0  body 0x8002edd0..0x8002f313  size 1348 B
 * body sha256 8c31bc54faebea0efe7f6c11a13d68597bde34e82724a13ad2e268280af32fd0
 * provider record sha256 b210a923e72e548e52d955b65405910e63b865af9b1e47d79f2d06fc88cbca5f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002edd0(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  undefined1 uVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  undefined1 *puVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  int *piVar24;
  int *piVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int local_130 [16];
  int local_f0 [8];
  int local_d0 [8];
  int local_b0 [8];
  int local_90 [8];
  int local_70 [8];
  int local_50 [8];
  int local_30;
  
  piVar23 = local_130;
  piVar24 = local_130;
  piVar19 = local_d0;
  psVar13 = param_3 + 0x38;
  piVar25 = *(int **)(param_2 + 0x4c);
  iVar26 = *(int *)(param_1 + 0x114) + 0x80;
  piVar11 = piVar25 + 0x38;
  for (iVar27 = 8; 0 < iVar27; iVar27 = iVar27 + -1) {
    psVar1 = psVar13 + -0x30;
    psVar2 = psVar13 + -0x28;
    psVar3 = psVar13 + -0x20;
    psVar4 = psVar13 + -0x18;
    psVar5 = psVar13 + -0x10;
    psVar6 = psVar13 + -8;
    sVar8 = *psVar13;
    psVar13 = psVar13 + 1;
    if (sVar8 == 0 &&
        (*psVar6 == 0 &&
        (*psVar5 == 0 && (*psVar4 == 0 && (*psVar3 == 0 && (*psVar1 == 0 && *psVar2 == 0)))))) {
      iVar9 = (int)*param_3 * *piVar25;
      *piVar23 = iVar9;
      piVar19[-0x10] = iVar9;
      piVar19[-8] = iVar9;
      *piVar19 = iVar9;
      piVar19[8] = iVar9;
      piVar19[0x10] = iVar9;
      piVar19[0x18] = iVar9;
      piVar19[0x20] = iVar9;
    }
    else {
      iVar9 = (int)*psVar2 * piVar11[-0x28];
      iVar10 = (int)*psVar4 * piVar11[-0x18];
      iVar12 = (int)*psVar6 * piVar11[-8];
      iVar14 = (int)*psVar1 * piVar11[-0x30];
      iVar21 = (int)*param_3 * *piVar25 + iVar10;
      iVar15 = (int)*psVar3 * piVar11[-0x20];
      iVar10 = (int)*param_3 * *piVar25 - iVar10;
      iVar17 = iVar9 + iVar12;
      iVar18 = (int)*psVar5 * piVar11[-0x10];
      iVar28 = iVar21 + iVar17;
      iVar21 = iVar21 - iVar17;
      iVar16 = (int)sVar8 * *piVar11;
      iVar17 = ((iVar9 - iVar12) * 0x16a >> 8) - iVar17;
      iVar22 = iVar10 + iVar17;
      iVar10 = iVar10 - iVar17;
      local_30 = iVar18 + iVar15;
      iVar18 = iVar18 - iVar15;
      iVar9 = iVar14 + iVar16;
      iVar14 = iVar14 - iVar16;
      iVar15 = iVar9 + local_30;
      iVar16 = (iVar18 + iVar14) * 0x1d9 >> 8;
      iVar12 = ((iVar18 * -0x29d >> 8) + iVar16) - iVar15;
      iVar9 = ((iVar9 - local_30) * 0x16a >> 8) - iVar12;
      iVar14 = ((iVar14 * 0x115 >> 8) - iVar16) + iVar9;
      *piVar23 = iVar28 + iVar15;
      piVar19[0x20] = iVar28 - iVar15;
      piVar19[-0x10] = iVar22 + iVar12;
      piVar19[0x18] = iVar22 - iVar12;
      piVar19[-8] = iVar10 + iVar9;
      piVar19[0x10] = iVar10 - iVar9;
      piVar19[8] = iVar21 + iVar14;
      *piVar19 = iVar21 - iVar14;
    }
    param_3 = param_3 + 1;
    piVar25 = piVar25 + 1;
    piVar11 = piVar11 + 1;
    piVar19 = piVar19 + 1;
    piVar23 = piVar23 + 1;
  }
  piVar11 = local_130 + 7;
  for (iVar27 = 0; iVar27 < 8; iVar27 = iVar27 + 1) {
    iVar17 = piVar11[-6];
    iVar10 = piVar11[-5];
    iVar16 = piVar11[-4];
    iVar18 = piVar11[-3];
    iVar14 = piVar11[-2];
    iVar9 = piVar11[-1];
    iVar12 = *piVar11;
    puVar20 = (undefined1 *)(*param_4 + param_5);
    iVar15 = iVar10 + iVar9;
    if ((((((iVar17 == 0 && iVar10 == 0) && iVar16 == 0) && iVar18 == 0) && iVar14 == 0) &&
        iVar9 == 0) && iVar12 == 0) {
      uVar7 = *(undefined1 *)(iVar26 + (*piVar24 >> 5 & 0x3ffU));
      *puVar20 = uVar7;
      puVar20[1] = uVar7;
      puVar20[2] = uVar7;
      puVar20[3] = uVar7;
      puVar20[4] = uVar7;
      puVar20[5] = uVar7;
      puVar20[6] = uVar7;
      puVar20[7] = uVar7;
    }
    else {
      iVar9 = ((iVar10 - iVar9) * 0x16a >> 8) - iVar15;
      local_30 = iVar14 + iVar16;
      iVar21 = iVar17 + iVar12 + local_30;
      iVar22 = ((iVar14 - iVar16) + (iVar17 - iVar12)) * 0x1d9 >> 8;
      iVar10 = *piVar24 + iVar18;
      iVar18 = *piVar24 - iVar18;
      iVar28 = iVar10 + iVar15;
      iVar10 = iVar10 - iVar15;
      iVar15 = iVar18 + iVar9;
      iVar18 = iVar18 - iVar9;
      *puVar20 = *(undefined1 *)(iVar26 + (iVar28 + iVar21 >> 5 & 0x3ffU));
      iVar9 = (((iVar14 - iVar16) * -0x29d >> 8) + iVar22) - iVar21;
      puVar20[7] = *(undefined1 *)(iVar26 + (iVar28 - iVar21 >> 5 & 0x3ffU));
      iVar14 = (((iVar17 + iVar12) - local_30) * 0x16a >> 8) - iVar9;
      puVar20[1] = *(undefined1 *)(iVar26 + (iVar15 + iVar9 >> 5 & 0x3ffU));
      puVar20[6] = *(undefined1 *)(iVar26 + (iVar15 - iVar9 >> 5 & 0x3ffU));
      puVar20[2] = *(undefined1 *)(iVar26 + (iVar18 + iVar14 >> 5 & 0x3ffU));
      iVar9 = (((iVar17 - iVar12) * 0x115 >> 8) - iVar22) + iVar14;
      puVar20[5] = *(undefined1 *)(iVar26 + (iVar18 - iVar14 >> 5 & 0x3ffU));
      puVar20[4] = *(undefined1 *)(iVar26 + (iVar10 + iVar9 >> 5 & 0x3ffU));
      puVar20[3] = *(undefined1 *)(iVar26 + (iVar10 - iVar9 >> 5 & 0x3ffU));
    }
    piVar24 = piVar24 + 8;
    piVar11 = piVar11 + 8;
    param_4 = param_4 + 1;
  }
  return;
}
