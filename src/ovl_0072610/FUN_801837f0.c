/* FUN_801837f0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801837f0  body 0x801837f0..0x80183a3f  size 592 B
 * body sha256 85ccdbf0fc2bd6bcd7038e869c7f79755b59d46547e76f35b8262c60f54967d5
 * provider record sha256 cec72b453b9e39623babc42f2fcbf171fcb5cd8f48997e698b0396303a4944fb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801837f0(byte *param_1,undefined1 *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  int iVar8;
  byte *pbVar9;
  
  pbVar9 = param_1 + param_3;
  iVar8 = 0;
  if (0 < param_5) {
    puVar7 = param_2 + 0xf;
    pbVar6 = pbVar9 + 0x10;
    pbVar5 = param_1 + 0x10;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + param_4;
      bVar2 = *pbVar9;
      pbVar9 = pbVar9 + param_4;
      iVar8 = iVar8 + 1;
      bVar3 = pbVar5[-0xf];
      bVar4 = pbVar6[-0xf];
      *param_2 = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      param_2 = param_2 + param_4;
      bVar1 = pbVar5[-0xe];
      bVar2 = pbVar6[-0xe];
      puVar7[-0xe] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-0xd];
      bVar4 = pbVar6[-0xd];
      puVar7[-0xd] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-0xc];
      bVar2 = pbVar6[-0xc];
      puVar7[-0xc] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-0xb];
      bVar4 = pbVar6[-0xb];
      puVar7[-0xb] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-10];
      bVar2 = pbVar6[-10];
      puVar7[-10] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-9];
      bVar4 = pbVar6[-9];
      puVar7[-9] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-8];
      bVar2 = pbVar6[-8];
      puVar7[-8] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-7];
      bVar4 = pbVar6[-7];
      puVar7[-7] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-6];
      bVar2 = pbVar6[-6];
      puVar7[-6] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-5];
      bVar4 = pbVar6[-5];
      puVar7[-5] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-4];
      bVar2 = pbVar6[-4];
      puVar7[-4] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-3];
      bVar4 = pbVar6[-3];
      puVar7[-3] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-2];
      bVar2 = pbVar6[-2];
      puVar7[-2] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-1];
      bVar4 = pbVar6[-1];
      puVar7[-1] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + param_4;
      bVar2 = *pbVar6;
      pbVar6 = pbVar6 + param_4;
      *puVar7 = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      puVar7 = puVar7 + param_4;
    } while (iVar8 < param_5);
  }
  return;
}
