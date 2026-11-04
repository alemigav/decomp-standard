/* FUN_80183ea4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80183ea4  body 0x80183ea4..0x80184057  size 436 B
 * body sha256 badb73d7d037508ad81755d56e5585dfa68a9d758def45b2b14d3f2e316ad106
 * provider record sha256 2a1aa1cbd0c14f5d59ff67dbaa0c0287f17f2baf9216e6dc8782fcd88dcb51e4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80183ea4(byte *param_1,byte *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  
  pbVar10 = param_1 + param_3;
  iVar9 = 0;
  if (0 < param_5) {
    pbVar6 = param_2 + 7;
    pbVar8 = pbVar10 + 8;
    pbVar7 = param_1 + 8;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + param_4;
      bVar2 = *pbVar10;
      pbVar10 = pbVar10 + param_4;
      iVar9 = iVar9 + 1;
      iVar5 = (uint)pbVar7[-7] + (uint)pbVar8[-7] + 2;
      *param_2 = (byte)((uint)*param_2 + ((uint)bVar1 + (uint)bVar2 + iVar5 >> 2) + 1 >> 1);
      param_2 = param_2 + param_4;
      bVar1 = pbVar7[-6];
      bVar2 = pbVar8[-6];
      pbVar6[-6] = (byte)((uint)pbVar6[-6] + ((uint)bVar1 + (uint)bVar2 + iVar5 >> 2) + 1 >> 1);
      bVar3 = pbVar7[-5];
      bVar4 = pbVar8[-5];
      pbVar6[-5] = (byte)((uint)pbVar6[-5] +
                          ((uint)bVar3 + (uint)bVar4 + (uint)bVar1 + (uint)bVar2 + 2 >> 2) + 1 >> 1)
      ;
      bVar1 = pbVar7[-4];
      bVar2 = pbVar8[-4];
      pbVar6[-4] = (byte)((uint)pbVar6[-4] +
                          ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)bVar4 + 2 >> 2) + 1 >> 1)
      ;
      bVar3 = pbVar7[-3];
      bVar4 = pbVar8[-3];
      pbVar6[-3] = (byte)((uint)pbVar6[-3] +
                          ((uint)bVar3 + (uint)bVar4 + (uint)bVar1 + (uint)bVar2 + 2 >> 2) + 1 >> 1)
      ;
      bVar1 = pbVar7[-2];
      bVar2 = pbVar8[-2];
      pbVar6[-2] = (byte)((uint)pbVar6[-2] +
                          ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)bVar4 + 2 >> 2) + 1 >> 1)
      ;
      bVar3 = pbVar7[-1];
      bVar4 = pbVar8[-1];
      pbVar6[-1] = (byte)((uint)pbVar6[-1] +
                          ((uint)bVar3 + (uint)bVar4 + (uint)bVar1 + (uint)bVar2 + 2 >> 2) + 1 >> 1)
      ;
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + param_4;
      bVar2 = *pbVar8;
      pbVar8 = pbVar8 + param_4;
      *pbVar6 = (byte)((uint)*pbVar6 +
                       ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)bVar4 + 2 >> 2) + 1 >> 1);
      pbVar6 = pbVar6 + param_4;
    } while (iVar9 < param_5);
  }
  return;
}
