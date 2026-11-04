/* FUN_8002e900
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e900  body 0x8002e900..0x8002edcf  size 1232 B
 * body sha256 dfeee17cdd04370fa0dc7a9c55b2409801db34b907f506fc8ef3107f7f4c72d9
 * provider record sha256 50d595aad301ffd5a89397bb33b1798828fdefed5324b65d7dc07d2acaece7a7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e900(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  short sVar7;
  undefined1 *puVar8;
  float *pfVar9;
  int iVar10;
  float *pfVar11;
  short *psVar12;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float local_158 [16];
  float local_118 [8];
  float local_f8 [8];
  float local_d8 [8];
  float local_b8 [8];
  float local_98 [8];
  float local_78 [8];
  float local_58;
  float local_50;
  float local_48;
  
  pfVar14 = local_158;
  pfVar15 = local_158;
  pfVar11 = local_f8;
  psVar12 = param_3 + 0x38;
  pfVar13 = *(float **)(param_2 + 0x4c);
  iVar10 = *(int *)(param_1 + 0x114) + 0x80;
  pfVar9 = pfVar13 + 0x38;
  for (iVar16 = 8; 0 < iVar16; iVar16 = iVar16 + -1) {
    psVar1 = psVar12 + -0x30;
    psVar2 = psVar12 + -0x28;
    psVar3 = psVar12 + -0x20;
    psVar4 = psVar12 + -0x18;
    psVar5 = psVar12 + -0x10;
    psVar6 = psVar12 + -8;
    sVar7 = *psVar12;
    psVar12 = psVar12 + 1;
    if (sVar7 == 0 &&
        (*psVar6 == 0 &&
        (*psVar5 == 0 && (*psVar4 == 0 && (*psVar3 == 0 && (*psVar1 == 0 && *psVar2 == 0)))))) {
      fVar17 = (float)(int)*param_3 * *pfVar13;
      *pfVar14 = fVar17;
      pfVar11[-0x10] = fVar17;
      pfVar11[-8] = fVar17;
      *pfVar11 = fVar17;
      pfVar11[8] = fVar17;
      pfVar11[0x10] = fVar17;
      pfVar11[0x18] = fVar17;
      pfVar11[0x20] = fVar17;
    }
    else {
      fVar24 = (float)(int)*psVar2 * pfVar9[-0x28];
      fVar23 = (float)(int)*psVar4 * pfVar9[-0x18];
      fVar25 = (float)(int)*psVar6 * pfVar9[-8];
      fVar19 = (float)(int)*psVar1 * pfVar9[-0x30];
      fVar20 = (float)(int)*psVar3 * pfVar9[-0x20];
      fVar21 = (float)(int)*psVar5 * pfVar9[-0x10];
      fVar22 = (float)(int)sVar7 * *pfVar9;
      local_50 = fVar21 - fVar20;
      local_48 = fVar19 - fVar22;
      local_58 = (local_50 + local_48) * 1.847759;
      fVar18 = (float)(int)*param_3 * *pfVar13 + fVar23;
      fVar23 = (float)(int)*param_3 * *pfVar13 - fVar23;
      fVar17 = fVar24 + fVar25;
      fVar21 = fVar21 + fVar20;
      fVar19 = fVar19 + fVar22;
      fVar22 = (fVar24 - fVar25) * 1.4142135 - fVar17;
      fVar24 = fVar23 + fVar22;
      fVar23 = fVar23 - fVar22;
      fVar22 = fVar18 + fVar17;
      fVar18 = fVar18 - fVar17;
      fVar17 = fVar19 + fVar21;
      fVar20 = (local_50 * -2.613126 + local_58) - fVar17;
      fVar19 = (fVar19 - fVar21) * 1.4142135 - fVar20;
      fVar21 = (local_48 * 1.0823922 - local_58) + fVar19;
      *pfVar14 = fVar22 + fVar17;
      pfVar11[-0x10] = fVar24 + fVar20;
      pfVar11[0x20] = fVar22 - fVar17;
      pfVar11[0x18] = fVar24 - fVar20;
      pfVar11[-8] = fVar23 + fVar19;
      pfVar11[0x10] = fVar23 - fVar19;
      pfVar11[8] = fVar18 + fVar21;
      *pfVar11 = fVar18 - fVar21;
    }
    pfVar14 = pfVar14 + 1;
    pfVar13 = pfVar13 + 1;
    pfVar11 = pfVar11 + 1;
    param_3 = param_3 + 1;
    pfVar9 = pfVar9 + 1;
  }
  iVar16 = 0;
  pfVar9 = local_158 + 7;
  do {
    local_50 = pfVar9[-2] - pfVar9[-4];
    local_48 = pfVar9[-6] - *pfVar9;
    local_58 = (local_50 + local_48) * 1.847759;
    fVar21 = pfVar9[-2] + pfVar9[-4];
    fVar19 = pfVar9[-6] + *pfVar9;
    fVar17 = pfVar9[-5] + pfVar9[-1];
    fVar24 = *pfVar15 - pfVar9[-3];
    fVar22 = (pfVar9[-5] - pfVar9[-1]) * 1.4142135 - fVar17;
    fVar25 = fVar24 + fVar22;
    fVar24 = fVar24 - fVar22;
    fVar18 = *pfVar15 + pfVar9[-3];
    fVar22 = fVar18 + fVar17;
    fVar20 = fVar19 + fVar21;
    puVar8 = (undefined1 *)(*param_4 + param_5);
    fVar18 = fVar18 - fVar17;
    *puVar8 = *(undefined1 *)(iVar10 + ((int)(fVar22 + fVar20) + 4 >> 3 & 0x3ffU));
    fVar23 = (local_50 * -2.613126 + local_58) - fVar20;
    puVar8[7] = *(undefined1 *)(iVar10 + ((int)(fVar22 - fVar20) + 4 >> 3 & 0x3ffU));
    fVar17 = (fVar19 - fVar21) * 1.4142135 - fVar23;
    puVar8[1] = *(undefined1 *)(iVar10 + ((int)(fVar25 + fVar23) + 4 >> 3 & 0x3ffU));
    puVar8[6] = *(undefined1 *)(iVar10 + ((int)(fVar25 - fVar23) + 4 >> 3 & 0x3ffU));
    iVar16 = iVar16 + 1;
    puVar8[2] = *(undefined1 *)(iVar10 + ((int)(fVar24 + fVar17) + 4 >> 3 & 0x3ffU));
    fVar22 = (local_48 * 1.0823922 - local_58) + fVar17;
    pfVar9 = pfVar9 + 8;
    puVar8[5] = *(undefined1 *)(iVar10 + ((int)(fVar24 - fVar17) + 4 >> 3 & 0x3ffU));
    pfVar15 = pfVar15 + 8;
    puVar8[4] = *(undefined1 *)(iVar10 + ((int)(fVar18 + fVar22) + 4 >> 3 & 0x3ffU));
    puVar8[3] = *(undefined1 *)(iVar10 + ((int)(fVar18 - fVar22) + 4 >> 3 & 0x3ffU));
    param_4 = param_4 + 1;
  } while (iVar16 < 8);
  return;
}
