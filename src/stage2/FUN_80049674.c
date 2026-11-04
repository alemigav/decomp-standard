/* FUN_80049674
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049674  body 0x80049674..0x800497b3  size 320 B
 * body sha256 fec6505c6fdf293f008f4459684e2bc14a5f373a07a6eecd10fea609dd022c8b
 * provider record sha256 864f7dd3324986251152806c854660cf7f161b66404a5e33ccd80132a288e171
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80049674(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar6 = param_1[2];
  fVar5 = param_1[5];
  fVar3 = param_1[6];
  fVar4 = param_1[9];
  param_1[2] = -*param_1 * fVar1 + param_1[2] * fVar2;
  param_1[5] = -param_1[3] * fVar1 + param_1[5] * fVar2;
  param_1[6] = fVar3 * fVar2 + param_1[8] * fVar1;
  *param_1 = *param_1 * fVar2 + fVar6 * fVar1;
  param_1[3] = param_1[3] * fVar2 + fVar5 * fVar1;
  param_1[8] = -fVar3 * fVar1 + param_1[8] * fVar2;
  param_1[9] = fVar4 * fVar2 + param_1[0xb] * fVar1;
  param_1[0xb] = -fVar4 * fVar1 + param_1[0xb] * fVar2;
  return;
}
