/* FUN_80009078
 * image   boot (boot), base 0x80000480
 * address 0x80009078  body 0x80009078..0x8000911f  size 168 B
 * body sha256 513766e3ee9fc401723a5580ca0ceedc23ecb292af88b47e13aaf3cb6a1024f8
 * provider record sha256 8b9d7087dee72ebdeb58fa57c77926972f5525e14f31aa949080ec7011384da9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80009078(float *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  
  puVar7 = param_2 + 8;
  iVar8 = 0;
  do {
    iVar6 = 0;
    pfVar5 = param_1;
    do {
      uVar3 = *param_2;
      uVar1 = *(ushort *)puVar7;
      uVar4 = *param_2;
      uVar2 = *puVar7;
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 1;
      param_2 = param_2 + 1;
      *pfVar5 = (float)(int)(uVar3 & 0xffff0000 | (uint)uVar1) * 1.5258789e-05;
      pfVar5[1] = (float)(int)(uVar4 << 0x10 | (uint)(ushort)uVar2) * 1.5258789e-05;
      pfVar5 = pfVar5 + 2;
    } while (iVar6 < 2);
    iVar8 = iVar8 + 1;
    param_1 = param_1 + 4;
  } while (iVar8 < 4);
  return;
}
