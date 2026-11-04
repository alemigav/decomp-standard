/* FUN_800aaf90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aaf90  body 0x800aaf90..0x800ab19f  size 528 B
 * body sha256 a33274bdd9cda66c351fb3e70b81827d1639c1361c1041aa6c45034fc4eb25d1
 * provider record sha256 6ceac3d71353ec3fa7abdf557f041f93f1c203b0c284ebef9b499fe2a4e325c4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800aaf90(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = param_2[4] * param_2[8] - param_2[7] * param_2[5];
  fVar1 = -(param_2[3] * param_2[8] - param_2[6] * param_2[5]);
  fVar2 = param_2[3] * param_2[7] - param_2[6] * param_2[4];
  fVar3 = 1.0 / (*param_2 * fVar4 + param_2[1] * fVar1 + param_2[2] * fVar2);
  fVar4 = fVar3 * fVar4;
  fVar2 = fVar3 * fVar2;
  *param_1 = fVar4;
  param_1[3] = fVar3 * fVar1;
  param_1[6] = fVar2;
  fVar1 = -fVar3;
  param_1[1] = fVar1 * (param_2[1] * param_2[8] - param_2[7] * param_2[2]);
  param_1[4] = fVar3 * (*param_2 * param_2[8] - param_2[6] * param_2[2]);
  param_1[7] = fVar1 * (*param_2 * param_2[7] - param_2[6] * param_2[1]);
  param_1[2] = fVar3 * (param_2[1] * param_2[5] - param_2[4] * param_2[2]);
  param_1[5] = fVar1 * (*param_2 * param_2[5] - param_2[3] * param_2[2]);
  fVar3 = fVar3 * (*param_2 * param_2[4] - param_2[3] * param_2[1]);
  param_1[8] = fVar3;
  param_1[9] = (-param_2[9] * fVar4 - param_2[10] * param_1[1]) - param_2[0xb] * param_1[2];
  param_1[10] = (-param_2[9] * param_1[3] - param_2[10] * param_1[4]) - param_2[0xb] * param_1[5];
  param_1[0xb] = (-param_2[9] * fVar2 - param_2[10] * param_1[7]) - param_2[0xb] * fVar3;
  return;
}
