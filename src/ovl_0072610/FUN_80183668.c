/* FUN_80183668
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80183668  body 0x80183668..0x801837ef  size 392 B
 * body sha256 6c765aab1ea51a34510e4d9a490d727551b62e96b4c5f77850bbdd3490b4ddbe
 * provider record sha256 f1d5a368775ef5821d7b8e9741f39e2a01e8b00b2ef579f195c4a92c2bf31d41
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80183668(byte *param_1,byte *param_2,int param_3,int param_4,int param_5)

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
    pbVar3 = param_2 + 7;
    pbVar5 = pbVar7 + 7;
    pbVar4 = param_1 + 7;
    do {
      *param_2 = (byte)((uint)*param_2 + ((uint)*param_1 + (uint)*pbVar7 + 1 >> 1) + 1 >> 1);
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
