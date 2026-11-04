/* FUN_801833a0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801833a0  body 0x801833a0..0x80183667  size 712 B
 * body sha256 4613d889e0ccfa2a6f8f0455e8b35700eba01ea933d2545d2b665df9a02fa729
 * provider record sha256 d4ed627885b0182c7d8c24a84d1022dd7cd9c79bfae7a17b294012e58540dc0b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801833a0(byte *param_1,byte *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  
  pbVar7 = param_1 + param_3;
  iVar6 = 0;
  if (0 < param_5) {
    pbVar3 = param_2 + 0xf;
    pbVar5 = pbVar7 + 0xf;
    pbVar4 = param_1 + 0xf;
    do {
      *param_2 = (byte)((uint)*param_2 + ((uint)*param_1 + (uint)*pbVar7 + 1 >> 1) + 1 >> 1);
      pbVar3[-0xe] = (byte)((uint)pbVar3[-0xe] + ((uint)pbVar4[-0xe] + (uint)pbVar5[-0xe] + 1 >> 1)
                            + 1 >> 1);
      pbVar3[-0xd] = (byte)((uint)pbVar3[-0xd] + ((uint)pbVar4[-0xd] + (uint)pbVar5[-0xd] + 1 >> 1)
                            + 1 >> 1);
      pbVar3[-0xc] = (byte)((uint)pbVar3[-0xc] + ((uint)pbVar4[-0xc] + (uint)pbVar5[-0xc] + 1 >> 1)
                            + 1 >> 1);
      pbVar3[-0xb] = (byte)((uint)pbVar3[-0xb] + ((uint)pbVar4[-0xb] + (uint)pbVar5[-0xb] + 1 >> 1)
                            + 1 >> 1);
      pbVar3[-10] = (byte)((uint)pbVar3[-10] + ((uint)pbVar4[-10] + (uint)pbVar5[-10] + 1 >> 1) + 1
                          >> 1);
      pbVar3[-9] = (byte)((uint)pbVar3[-9] + ((uint)pbVar4[-9] + (uint)pbVar5[-9] + 1 >> 1) + 1 >> 1
                         );
      pbVar3[-8] = (byte)((uint)pbVar3[-8] + ((uint)pbVar4[-8] + (uint)pbVar5[-8] + 1 >> 1) + 1 >> 1
                         );
      pbVar3[-7] = (byte)((uint)pbVar3[-7] + ((uint)pbVar4[-7] + (uint)pbVar5[-7] + 1 >> 1) + 1 >> 1
                         );
      pbVar3[-6] = (byte)((uint)pbVar3[-6] + ((uint)pbVar4[-6] + (uint)pbVar5[-6] + 1 >> 1) + 1 >> 1
                         );
      pbVar3[-5] = (byte)((uint)pbVar3[-5] + ((uint)pbVar4[-5] + (uint)pbVar5[-5] + 1 >> 1) + 1 >> 1
                         );
      param_1 = param_1 + param_4;
      pbVar3[-4] = (byte)((uint)pbVar3[-4] + ((uint)pbVar4[-4] + (uint)pbVar5[-4] + 1 >> 1) + 1 >> 1
                         );
      pbVar7 = pbVar7 + param_4;
      pbVar3[-3] = (byte)((uint)pbVar3[-3] + ((uint)pbVar4[-3] + (uint)pbVar5[-3] + 1 >> 1) + 1 >> 1
                         );
      iVar6 = iVar6 + 1;
      pbVar3[-2] = (byte)((uint)pbVar3[-2] + ((uint)pbVar4[-2] + (uint)pbVar5[-2] + 1 >> 1) + 1 >> 1
                         );
      param_2 = param_2 + param_4;
      pbVar3[-1] = (byte)((uint)pbVar3[-1] + ((uint)pbVar4[-1] + (uint)pbVar5[-1] + 1 >> 1) + 1 >> 1
                         );
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + param_4;
      bVar2 = *pbVar5;
      pbVar5 = pbVar5 + param_4;
      *pbVar3 = (byte)((uint)*pbVar3 + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      pbVar3 = pbVar3 + param_4;
    } while (iVar6 < param_5);
  }
  return;
}
