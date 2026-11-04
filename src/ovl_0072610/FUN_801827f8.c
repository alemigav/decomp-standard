/* FUN_801827f8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801827f8  body 0x801827f8..0x801829b3  size 444 B
 * body sha256 be4d1cc498aad01d30cfb726e5498da8bac4bc9bda1eaa550e23058a7b2666f4
 * provider record sha256 f1f1469996e19567da182c36364d376a098c62d51d08a0e5113de3eb5453adc3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801827f8(byte *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_4) {
    pbVar3 = param_2 + 0xf;
    pbVar2 = param_1 + 0xf;
    do {
      *param_2 = (byte)((uint)*param_2 + (uint)*param_1 + 1 >> 1);
      pbVar3[-0xe] = (byte)((uint)pbVar3[-0xe] + (uint)pbVar2[-0xe] + 1 >> 1);
      pbVar3[-0xd] = (byte)((uint)pbVar3[-0xd] + (uint)pbVar2[-0xd] + 1 >> 1);
      pbVar3[-0xc] = (byte)((uint)pbVar3[-0xc] + (uint)pbVar2[-0xc] + 1 >> 1);
      pbVar3[-0xb] = (byte)((uint)pbVar3[-0xb] + (uint)pbVar2[-0xb] + 1 >> 1);
      pbVar3[-10] = (byte)((uint)pbVar3[-10] + (uint)pbVar2[-10] + 1 >> 1);
      pbVar3[-9] = (byte)((uint)pbVar3[-9] + (uint)pbVar2[-9] + 1 >> 1);
      pbVar3[-8] = (byte)((uint)pbVar3[-8] + (uint)pbVar2[-8] + 1 >> 1);
      pbVar3[-7] = (byte)((uint)pbVar3[-7] + (uint)pbVar2[-7] + 1 >> 1);
      pbVar3[-6] = (byte)((uint)pbVar3[-6] + (uint)pbVar2[-6] + 1 >> 1);
      pbVar3[-5] = (byte)((uint)pbVar3[-5] + (uint)pbVar2[-5] + 1 >> 1);
      pbVar3[-4] = (byte)((uint)pbVar3[-4] + (uint)pbVar2[-4] + 1 >> 1);
      param_1 = param_1 + param_3;
      pbVar3[-3] = (byte)((uint)pbVar3[-3] + (uint)pbVar2[-3] + 1 >> 1);
      iVar4 = iVar4 + 1;
      pbVar3[-2] = (byte)((uint)pbVar3[-2] + (uint)pbVar2[-2] + 1 >> 1);
      param_2 = param_2 + param_3;
      pbVar3[-1] = (byte)((uint)pbVar3[-1] + (uint)pbVar2[-1] + 1 >> 1);
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + param_3;
      *pbVar3 = (byte)((uint)*pbVar3 + (uint)bVar1 + 1 >> 1);
      pbVar3 = pbVar3 + param_3;
    } while (iVar4 < param_4);
  }
  return;
}
