/* FUN_80183b90
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80183b90  body 0x80183b90..0x80183ea3  size 788 B
 * body sha256 319b255127f5bfaabd02191b993c9987dd6bd6bed77caec046f4269353094df4
 * provider record sha256 94e8adef693f4a4753576585818ac7b9fac7fcf306647a752d539de7af1d446d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80183b90(byte *param_1,byte *param_2,int param_3,int param_4,int param_5)

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
    pbVar6 = param_2 + 0xf;
    pbVar8 = pbVar10 + 0x10;
    pbVar7 = param_1 + 0x10;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + param_4;
      bVar2 = *pbVar10;
      pbVar10 = pbVar10 + param_4;
      iVar9 = iVar9 + 1;
      iVar5 = (uint)pbVar7[-0xf] + (uint)pbVar8[-0xf] + 2;
      *param_2 = (byte)((uint)*param_2 + ((uint)bVar1 + (uint)bVar2 + iVar5 >> 2) + 1 >> 1);
      param_2 = param_2 + param_4;
      bVar1 = pbVar7[-0xe];
      bVar2 = pbVar8[-0xe];
      pbVar6[-0xe] = (byte)((uint)pbVar6[-0xe] + ((uint)bVar1 + (uint)bVar2 + iVar5 >> 2) + 1 >> 1);
      bVar3 = pbVar7[-0xd];
      bVar4 = pbVar8[-0xd];
      pbVar6[-0xd] = (byte)((uint)pbVar6[-0xd] +
                            ((uint)bVar3 + (uint)bVar4 + (uint)bVar1 + (uint)bVar2 + 2 >> 2) + 1 >>
                           1);
      bVar1 = pbVar7[-0xc];
      bVar2 = pbVar8[-0xc];
      pbVar6[-0xc] = (byte)((uint)pbVar6[-0xc] +
                            ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)bVar4 + 2 >> 2) + 1 >>
                           1);
      bVar3 = pbVar7[-0xb];
      bVar4 = pbVar8[-0xb];
      pbVar6[-0xb] = (byte)((uint)pbVar6[-0xb] +
                            ((uint)bVar3 + (uint)bVar4 + (uint)bVar1 + (uint)bVar2 + 2 >> 2) + 1 >>
                           1);
      bVar1 = pbVar7[-10];
      bVar2 = pbVar8[-10];
      pbVar6[-10] = (byte)((uint)pbVar6[-10] +
                           ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)bVar4 + 2 >> 2) + 1 >> 1
                          );
      bVar3 = pbVar7[-9];
      bVar4 = pbVar8[-9];
      pbVar6[-9] = (byte)((uint)pbVar6[-9] +
                          ((uint)bVar3 + (uint)bVar4 + (uint)bVar1 + (uint)bVar2 + 2 >> 2) + 1 >> 1)
      ;
      bVar1 = pbVar7[-8];
      bVar2 = pbVar8[-8];
      pbVar6[-8] = (byte)((uint)pbVar6[-8] +
                          ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)bVar4 + 2 >> 2) + 1 >> 1)
      ;
      bVar3 = pbVar7[-7];
      bVar4 = pbVar8[-7];
      pbVar6[-7] = (byte)((uint)pbVar6[-7] +
                          ((uint)bVar3 + (uint)bVar4 + (uint)bVar1 + (uint)bVar2 + 2 >> 2) + 1 >> 1)
      ;
      bVar1 = pbVar7[-6];
      bVar2 = pbVar8[-6];
      pbVar6[-6] = (byte)((uint)pbVar6[-6] +
                          ((uint)bVar1 + (uint)bVar2 + (uint)bVar3 + (uint)bVar4 + 2 >> 2) + 1 >> 1)
      ;
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
                       ((uint)bVar3 + (uint)bVar4 + 2 + (uint)bVar1 + (uint)bVar2 >> 2) + 1 >> 1);
      pbVar6 = pbVar6 + param_4;
    } while (iVar9 < param_5);
  }
  return;
}
