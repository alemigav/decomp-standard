/* FUN_800b63b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b63b4  body 0x800b63b4..0x800b6467  size 180 B
 * body sha256 1ebcf21c74e595b652c4dad226835a22458652a23d1847e84ac214543252a1d4
 * provider record sha256 e7a779bcf75ae600c72c61913f3c8e49769b14c5f651b41731e8953a02a529fe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b63b4(undefined2 *param_1,int param_2,int param_3,short *param_4)

{
  short *psVar1;
  bool bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  iVar6 = (int)(short)param_1[0xb3];
  if ((-1 < param_2 + -0x28) && (param_2 + -0x78 < 1)) {
    iVar6 = param_2;
  }
  param_1[0xb3] = (short)iVar6;
  uVar4 = *(ushort *)(&UNK_800b6468 + param_3 * 2);
  iVar5 = 0x77;
  puVar7 = param_1;
  do {
    iVar5 = iVar5 + -1;
    *puVar7 = puVar7[0x28];
    puVar7 = puVar7 + 1;
  } while (-1 < iVar5);
  iVar5 = 0x27;
  puVar7 = param_1 + -iVar6;
  do {
    psVar1 = puVar7 + 0x78;
    puVar7 = puVar7 + 1;
    sVar3 = *param_4;
    param_4 = param_4 + 1;
    param_1[0x78] = (short)((int)((int)*psVar1 * (uint)uVar4 + 0x4000) >> 0xf) + sVar3;
    param_1 = param_1 + 1;
    bVar2 = 0 < iVar5;
    iVar5 = iVar5 + -1;
  } while (bVar2);
  return;
}
