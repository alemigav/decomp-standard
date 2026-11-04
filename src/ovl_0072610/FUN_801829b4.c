/* FUN_801829b4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801829b4  body 0x801829b4..0x80182aaf  size 252 B
 * body sha256 3cb282e81dc0d949bbef9a783ac1c883032b2b320b79c3b1306a12ffe11198d6
 * provider record sha256 d537d841daf9853b2bb9a95b82e9e86b86f1ef715e57fe0104e493634aff5580
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801829b4(byte *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_4) {
    pbVar3 = param_2 + 7;
    pbVar2 = param_1 + 7;
    do {
      *param_2 = (byte)((uint)*param_2 + (uint)*param_1 + 1 >> 1);
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
