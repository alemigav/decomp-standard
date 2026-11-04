/* FUN_80041454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041454  body 0x80041454..0x80041587  size 308 B
 * body sha256 457f3e85607372d2cfe60bbe58faface573d01c6d95185dacbd0a7a31fdbd22f
 * provider record sha256 8236a538f1beb6808ceaf0a697275ee94daa19cdb2a41146359526e85ebc8325
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80041454(undefined4 param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_800408c0();
  iVar5 = FUN_80040968(param_1);
  sVar1 = *param_2;
  sVar2 = param_2[1];
  sVar3 = param_2[2];
  *param_2 = (short)(sVar1 * iVar4 + param_2[6] * iVar5 >> 0xc);
  param_2[6] = (short)(param_2[6] * iVar4 - sVar1 * iVar5 >> 0xc);
  param_2[1] = (short)(sVar2 * iVar4 + param_2[7] * iVar5 >> 0xc);
  param_2[7] = (short)(param_2[7] * iVar4 - sVar2 * iVar5 >> 0xc);
  param_2[2] = (short)(sVar3 * iVar4 + param_2[8] * iVar5 >> 0xc);
  param_2[8] = (short)(param_2[8] * iVar4 - sVar3 * iVar5 >> 0xc);
  return;
}
