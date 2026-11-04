/* FUN_800490ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800490ec  body 0x800490ec..0x800491cb  size 224 B
 * body sha256 711a73ee07f3ae79781f8b048e61ce007e3e13c9dc12f29be7aab259437cce7f
 * provider record sha256 cba6c2329f5baf4dcd4d6d2f8def541b4ab578236d8e848f5e27fb3dd9f9961b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800490ec(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar3 = *(float *)(param_1 + 4);
  fVar4 = *(float *)(param_1 + 0x10);
  fVar5 = *(float *)(param_1 + 0x1c);
  *(float *)(param_1 + 4) = fVar3 * fVar2 - *(float *)(param_1 + 8) * fVar1;
  *(float *)(param_1 + 8) = fVar3 * fVar1 + *(float *)(param_1 + 8) * fVar2;
  *(float *)(param_1 + 0x10) = fVar4 * fVar2 - *(float *)(param_1 + 0x14) * fVar1;
  *(float *)(param_1 + 0x14) = fVar4 * fVar1 + *(float *)(param_1 + 0x14) * fVar2;
  *(float *)(param_1 + 0x1c) = fVar5 * fVar2 - *(float *)(param_1 + 0x20) * fVar1;
  *(float *)(param_1 + 0x20) = fVar5 * fVar1 + *(float *)(param_1 + 0x20) * fVar2;
  return;
}
