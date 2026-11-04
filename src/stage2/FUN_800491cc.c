/* FUN_800491cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800491cc  body 0x800491cc..0x800492b3  size 232 B
 * body sha256 531ed3fae273f5eb6dfdc353780e68165588c9efaf8723e5f37c1c5661f8e649
 * provider record sha256 3c12709178907021ccf6542f1327518108a7e7061f5c3fa09df136b97b3efced
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800491cc(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar3 = *param_1;
  fVar4 = param_1[3];
  fVar5 = param_1[6];
  *param_1 = fVar3 * fVar2 + param_1[2] * fVar1;
  param_1[2] = -fVar3 * fVar1 + param_1[2] * fVar2;
  param_1[3] = fVar4 * fVar2 + param_1[5] * fVar1;
  param_1[5] = -fVar4 * fVar1 + param_1[5] * fVar2;
  param_1[6] = fVar5 * fVar2 + param_1[8] * fVar1;
  param_1[8] = -fVar5 * fVar1 + param_1[8] * fVar2;
  return;
}
