/* FUN_80182d00
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80182d00  body 0x80182d00..0x80182f77  size 632 B
 * body sha256 09fbec743a3c07fdaad8341f53670fcd96842a331588f832716623f0129ce852
 * provider record sha256 cc195ef514f6f584d1a9b55e690821fe08432aae65c0e490c8a900a49b5ad545
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80182d00(byte *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < param_4) {
    pbVar3 = param_2 + 0xf;
    pbVar4 = param_1 + 0x10;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + param_3;
      iVar5 = iVar5 + 1;
      bVar2 = pbVar4[-0xf];
      *param_2 = (byte)((uint)*param_2 + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      param_2 = param_2 + param_3;
      bVar1 = pbVar4[-0xe];
      pbVar3[-0xe] = (byte)((uint)pbVar3[-0xe] + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      bVar2 = pbVar4[-0xd];
      pbVar3[-0xd] = (byte)((uint)pbVar3[-0xd] + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      bVar1 = pbVar4[-0xc];
      pbVar3[-0xc] = (byte)((uint)pbVar3[-0xc] + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      bVar2 = pbVar4[-0xb];
      pbVar3[-0xb] = (byte)((uint)pbVar3[-0xb] + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      bVar1 = pbVar4[-10];
      pbVar3[-10] = (byte)((uint)pbVar3[-10] + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      bVar2 = pbVar4[-9];
      pbVar3[-9] = (byte)((uint)pbVar3[-9] + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      bVar1 = pbVar4[-8];
      pbVar3[-8] = (byte)((uint)pbVar3[-8] + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      bVar2 = pbVar4[-7];
      pbVar3[-7] = (byte)((uint)pbVar3[-7] + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      bVar1 = pbVar4[-6];
      pbVar3[-6] = (byte)((uint)pbVar3[-6] + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      bVar2 = pbVar4[-5];
      pbVar3[-5] = (byte)((uint)pbVar3[-5] + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      bVar1 = pbVar4[-4];
      pbVar3[-4] = (byte)((uint)pbVar3[-4] + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      bVar2 = pbVar4[-3];
      pbVar3[-3] = (byte)((uint)pbVar3[-3] + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      bVar1 = pbVar4[-2];
      pbVar3[-2] = (byte)((uint)pbVar3[-2] + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      bVar2 = pbVar4[-1];
      pbVar3[-1] = (byte)((uint)pbVar3[-1] + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + param_3;
      *pbVar3 = (byte)((uint)*pbVar3 + ((uint)bVar2 + (uint)bVar1 + 1 >> 1) + 1 >> 1);
      pbVar3 = pbVar3 + param_3;
    } while (iVar5 < param_4);
  }
  return;
}
