/* FUN_80182f78
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80182f78  body 0x80182f78..0x801830cf  size 344 B
 * body sha256 35fd46fafab04a3440387b236e4344ebab875b8759569de0f5d109b1496b2fe5
 * provider record sha256 273315eefaa1dc55f2f206fa367223d63a274b0d73c2f2409f436d1265342722
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80182f78(byte *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < param_4) {
    pbVar3 = param_2 + 7;
    pbVar4 = param_1 + 8;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + param_3;
      iVar5 = iVar5 + 1;
      bVar2 = pbVar4[-7];
      *param_2 = (byte)((uint)*param_2 + ((uint)bVar1 + (uint)bVar2 + 1 >> 1) + 1 >> 1);
      param_2 = param_2 + param_3;
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
