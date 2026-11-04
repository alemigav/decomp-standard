/* FUN_800497b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800497b4  body 0x800497b4..0x800498eb  size 312 B
 * body sha256 bfbaad95d8c41c032a4090fbac5d5584574c0bb6c31faf750e68c3cbc54906d2
 * provider record sha256 440ea36c1afde4a7da8c74a5d1b22a32363e01f68c2f0af3480f4f12e57ee4ca
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800497b4(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar6 = param_1[1];
  fVar3 = param_1[3];
  fVar4 = param_1[6];
  fVar5 = param_1[9];
  param_1[1] = *param_1 * fVar1 + param_1[1] * fVar2;
  param_1[3] = fVar3 * fVar2 - param_1[4] * fVar1;
  *param_1 = *param_1 * fVar2 - fVar6 * fVar1;
  param_1[4] = fVar3 * fVar1 + param_1[4] * fVar2;
  param_1[6] = fVar4 * fVar2 - param_1[7] * fVar1;
  param_1[7] = fVar4 * fVar1 + param_1[7] * fVar2;
  param_1[9] = fVar5 * fVar2 - param_1[10] * fVar1;
  param_1[10] = fVar5 * fVar1 + param_1[10] * fVar2;
  return;
}
