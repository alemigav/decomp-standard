/* FUN_80040e58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040e58  body 0x80040e58..0x80041017  size 448 B
 * body sha256 204d6243cd2ff9861ebd247a22ed4c947438c2b88d126a6011fe4f03eb43e553
 * provider record sha256 8455cdfb1a93ed27b344fe376aa482d8f0269c6ac466a192a21ab6414b12bc36
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040e58(short *param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = FUN_800408c0((int)*param_1);
  iVar2 = FUN_80040968((int)*param_1);
  iVar3 = FUN_800408c0((int)param_1[1]);
  iVar4 = FUN_80040968((int)param_1[1]);
  iVar5 = FUN_800408c0((int)param_1[2]);
  iVar6 = FUN_80040968((int)param_1[2]);
  iVar7 = iVar4 * iVar5 >> 0xc;
  param_2[2] = (short)iVar4;
  *param_2 = (short)(iVar3 * iVar5 >> 0xc);
  param_2[1] = -(short)(iVar3 * iVar6 >> 0xc);
  param_2[5] = (short)(-(iVar2 * iVar3) >> 0xc);
  param_2[8] = (short)(iVar1 * iVar3 >> 0xc);
  param_2[3] = (short)(iVar1 * iVar6 + iVar2 * iVar7 >> 0xc);
  param_2[4] = (short)(iVar1 * iVar5 - (iVar2 * iVar4 >> 0xc) * iVar6 >> 0xc);
  param_2[6] = (short)(iVar2 * iVar6 - iVar1 * iVar7 >> 0xc);
  param_2[7] = (short)(iVar2 * iVar5 + iVar1 * (iVar4 * iVar6 >> 0xc) >> 0xc);
  return;
}
