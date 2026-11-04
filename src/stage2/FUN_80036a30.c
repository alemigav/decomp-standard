/* FUN_80036a30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036a30  body 0x80036a30..0x80036b2b  size 252 B
 * body sha256 5afcb87a5a439df15cbd9d99cd2e64ab3dbabb279e303c2167d132bb0b50931f
 * provider record sha256 dbd490064c2ca6051cf76e7130f3dc073f14e48de75a487229a147712ce91f23
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80036a30(int *param_1,int *param_2,short param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  short sVar5;
  int iVar4;
  int iVar6;
  int iVar7;
  short local_20 [4];
  
  local_20[2] = 0;
  local_20[1] = 0;
  iVar7 = *param_1;
  iVar2 = *param_2;
  iVar6 = param_2[2];
  iVar3 = param_1[2];
  local_20[0] = param_3;
  sVar5 = FUN_80032d14((int)(short)*param_1,(int)*(short *)((int)param_1 + 10),(int)(short)*param_2,
                       (int)*(short *)((int)param_2 + 10));
  FUN_800837d0((int)sVar5,local_20,local_20);
  *param_1 = *param_1 + (int)local_20[0];
  iVar4 = param_1[2];
  param_1[2] = iVar4 + local_20[2];
  bVar1 = ((iVar7 - iVar2 & 0x80000000U | (iVar3 - iVar6 & 0x80000000U) >> 1) ^
          *param_1 - *param_2 & 0x80000000U) !=
          ((iVar4 + local_20[2]) - param_2[2] & 0x80000000U) >> 1;
  if (bVar1) {
    *param_1 = *param_2;
    param_1[2] = param_2[2];
  }
  return bVar1;
}
