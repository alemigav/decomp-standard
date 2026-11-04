/* FUN_80041018
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041018  body 0x80041018..0x800411b7  size 416 B
 * body sha256 2fe6dd30a94731f4002732c8c393c9380189fa74d445f084f567113c19ae856d
 * provider record sha256 d6342dd81fac0d19b51f32ceaaa5c8ebb1920c7d1fbd7eaf27f9e7a55f96e4c9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80041018(short *param_1,undefined2 *param_2)

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
  iVar7 = iVar2 * iVar4 >> 0xc;
  param_2[5] = -(short)iVar2;
  param_2[2] = (short)(iVar4 * iVar1 >> 0xc);
  param_2[3] = (short)(iVar1 * iVar6 >> 0xc);
  param_2[1] = (short)(iVar7 * iVar5 - iVar3 * iVar6 >> 0xc);
  param_2[4] = (short)(iVar1 * iVar5 >> 0xc);
  param_2[8] = (short)(iVar1 * iVar3 >> 0xc);
  *param_2 = (short)(iVar3 * iVar5 + iVar7 * iVar6 >> 0xc);
  param_2[6] = (short)(iVar2 * (iVar3 * iVar6 >> 0xc) - iVar4 * iVar5 >> 0xc);
  param_2[7] = (short)(iVar4 * iVar6 + iVar2 * (iVar3 * iVar5 >> 0xc) >> 0xc);
  return;
}
