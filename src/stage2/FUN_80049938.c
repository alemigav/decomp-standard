/* FUN_80049938
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049938  body 0x80049938..0x80049a83  size 332 B
 * body sha256 341e50b806e6819980fd67a666b8fb547880346a312df0ad162b03e411c0ad52
 * provider record sha256 baeeca5865f1d8b8f80328ba336c5784c618c24e1d90cfeb6eb364407566ab03
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80049938(float *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)func_0x8000d050(*param_2);
  fVar2 = (float)func_0x80006be0(*param_2);
  fVar3 = (float)func_0x8000d050(param_2[1]);
  fVar4 = (float)func_0x80006be0(param_2[1]);
  fVar5 = (float)func_0x8000d050(param_2[2]);
  fVar6 = (float)func_0x80006be0(param_2[2]);
  param_1[2] = -fVar3;
  *param_1 = fVar4 * fVar6;
  param_1[1] = fVar4 * fVar5;
  param_1[3] = fVar1 * fVar3 * fVar6 - fVar2 * fVar5;
  param_1[4] = fVar1 * fVar3 * fVar5 + fVar2 * fVar6;
  param_1[5] = fVar1 * fVar4;
  param_1[6] = fVar2 * fVar3 * fVar6 + fVar1 * fVar5;
  param_1[7] = fVar2 * fVar3 * fVar5 - fVar1 * fVar6;
  param_1[8] = fVar2 * fVar4;
  return;
}
