/* FUN_80041588
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041588  body 0x80041588..0x800416bb  size 308 B
 * body sha256 691c2bb979fba487c3e625e59aed8a96815042d9adc573580fb0d826f52cc32b
 * provider record sha256 891c26a12224cecbcc6b210a9d4cd24903f507988ca3a0e1032be1291a37efcc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80041588(undefined4 param_1,short *param_2)

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
  *param_2 = (short)(sVar1 * iVar4 - param_2[3] * iVar5 >> 0xc);
  param_2[3] = (short)(sVar1 * iVar5 + param_2[3] * iVar4 >> 0xc);
  param_2[1] = (short)(sVar2 * iVar4 - param_2[4] * iVar5 >> 0xc);
  param_2[4] = (short)(sVar2 * iVar5 + param_2[4] * iVar4 >> 0xc);
  param_2[2] = (short)(sVar3 * iVar4 - param_2[5] * iVar5 >> 0xc);
  param_2[5] = (short)(sVar3 * iVar5 + param_2[5] * iVar4 >> 0xc);
  return;
}
