/* FUN_80048590
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048590  body 0x80048590..0x8004878b  size 508 B
 * body sha256 ca8115ca1106f1c87a74924d6ae7dd9b15eeeb3d81d2b4973a784fe45362ddbb
 * provider record sha256 8f68586860c6f4746a446fac485d57c769cebe5f24e0bad6004e335c8d81daa9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80048590(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  fVar5 = *param_1;
  fVar9 = param_1[1];
  fVar10 = param_2[4];
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = param_2[5];
  fVar6 = param_1[2];
  fVar8 = param_2[7];
  fVar4 = param_2[8];
  fVar7 = param_1[3];
  *param_1 = fVar5 * *param_2 + fVar9 * param_2[3] + fVar6 * param_2[6];
  param_1[1] = fVar5 * fVar1 + fVar9 * fVar10 + fVar6 * fVar8;
  fVar1 = *param_2;
  param_1[2] = fVar5 * fVar2 + fVar9 * fVar3 + fVar6 * fVar4;
  fVar2 = param_2[1];
  fVar10 = param_1[4];
  fVar11 = param_2[4];
  fVar3 = param_2[2];
  fVar4 = param_2[5];
  fVar6 = param_1[5];
  fVar9 = param_2[7];
  fVar5 = param_2[8];
  fVar8 = param_1[6];
  param_1[3] = fVar7 * fVar1 + fVar10 * param_2[3] + fVar6 * param_2[6];
  param_1[4] = fVar7 * fVar2 + fVar10 * fVar11 + fVar6 * fVar9;
  fVar1 = *param_2;
  param_1[5] = fVar7 * fVar3 + fVar10 * fVar4 + fVar6 * fVar5;
  fVar2 = param_2[1];
  fVar10 = param_1[7];
  fVar11 = param_2[4];
  fVar3 = param_2[2];
  fVar4 = param_2[5];
  fVar6 = param_1[8];
  fVar9 = param_2[7];
  fVar5 = param_2[8];
  param_1[6] = fVar8 * fVar1 + fVar10 * param_2[3] + fVar6 * param_2[6];
  fVar7 = param_1[9];
  param_1[7] = fVar8 * fVar2 + fVar10 * fVar11 + fVar6 * fVar9;
  fVar1 = *param_2;
  param_1[8] = fVar8 * fVar3 + fVar10 * fVar4 + fVar6 * fVar5;
  fVar2 = param_2[1];
  fVar10 = param_1[10];
  fVar11 = param_2[4];
  fVar3 = param_2[2];
  fVar4 = param_2[5];
  fVar8 = param_1[0xb];
  fVar9 = param_2[7];
  fVar5 = param_2[8];
  fVar6 = param_2[10];
  param_1[9] = fVar7 * fVar1 + fVar10 * param_2[3] + fVar8 * param_2[6] + param_2[9];
  fVar1 = param_2[0xb];
  param_1[10] = fVar7 * fVar2 + fVar10 * fVar11 + fVar8 * fVar9 + fVar6;
  param_1[0xb] = fVar7 * fVar3 + fVar10 * fVar4 + fVar8 * fVar5 + fVar1;
  return;
}
