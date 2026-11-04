/* FUN_8004953c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004953c  body 0x8004953c..0x80049673  size 312 B
 * body sha256 af51d10bfba02b781f5a4cadfe5c44d630e4a41b3086f1137cc659a61ae2ee2e
 * provider record sha256 3f1fdf8112ca01267f9b5241a32ef2e0b95709845dc477e24b2685246b9aaf09
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004953c(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar6 = *(float *)(param_1 + 8);
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x1c);
  fVar5 = *(float *)(param_1 + 0x28);
  *(float *)(param_1 + 8) = *(float *)(param_1 + 4) * fVar1 + *(float *)(param_1 + 8) * fVar2;
  *(float *)(param_1 + 0x10) = fVar3 * fVar2 - *(float *)(param_1 + 0x14) * fVar1;
  *(float *)(param_1 + 4) = *(float *)(param_1 + 4) * fVar2 - fVar6 * fVar1;
  *(float *)(param_1 + 0x14) = fVar3 * fVar1 + *(float *)(param_1 + 0x14) * fVar2;
  *(float *)(param_1 + 0x1c) = fVar4 * fVar2 - *(float *)(param_1 + 0x20) * fVar1;
  *(float *)(param_1 + 0x20) = fVar4 * fVar1 + *(float *)(param_1 + 0x20) * fVar2;
  *(float *)(param_1 + 0x28) = fVar5 * fVar2 - *(float *)(param_1 + 0x2c) * fVar1;
  *(float *)(param_1 + 0x2c) = fVar5 * fVar1 + *(float *)(param_1 + 0x2c) * fVar2;
  return;
}
