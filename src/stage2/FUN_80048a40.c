/* FUN_80048a40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048a40  body 0x80048a40..0x80048bab  size 364 B
 * body sha256 39001c0a2b74a8f151e0e3d2bf69b65ae0b92e5aea086d1e432cc1cf91ca0ed5
 * provider record sha256 fe04cc7e4d5b40ffa229fad4c1cea95abe47d543b740128d2c608dab8c535322
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80048a40(float *param_1,float *param_2)

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
  fVar9 = param_1[7];
  fVar10 = param_2[4];
  fVar3 = param_2[2];
  fVar4 = param_2[5];
  fVar6 = param_1[8];
  fVar7 = param_2[7];
  fVar5 = param_2[8];
  param_1[6] = fVar8 * fVar1 + fVar9 * param_2[3] + fVar6 * param_2[6];
  param_1[7] = fVar8 * fVar2 + fVar9 * fVar10 + fVar6 * fVar7;
  param_1[8] = fVar8 * fVar3 + fVar9 * fVar4 + fVar6 * fVar5;
  return;
}
