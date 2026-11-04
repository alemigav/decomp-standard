/* FUN_801830d0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801830d0  body 0x801830d0..0x80183297  size 456 B
 * body sha256 c6e8cdd3973bb8c49b2cc6e87e628c71770739b73cca4dd8f4a6f90bb556b53a
 * provider record sha256 20d4eaa27868cf3c87ecf0c724e3546294eb23c9a8ad7de0ff39f30873a8fa9d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801830d0(byte *param_1,undefined1 *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  byte *pbVar7;
  
  pbVar7 = param_1 + param_3;
  iVar6 = 0;
  if (0 < param_5) {
    puVar5 = param_2 + 0xf;
    pbVar4 = pbVar7 + 0xf;
    pbVar3 = param_1 + 0xf;
    do {
      *param_2 = (char)((uint)*param_1 + (uint)*pbVar7 + 1 >> 1);
      puVar5[-0xe] = (char)((uint)pbVar3[-0xe] + (uint)pbVar4[-0xe] + 1 >> 1);
      puVar5[-0xd] = (char)((uint)pbVar3[-0xd] + (uint)pbVar4[-0xd] + 1 >> 1);
      puVar5[-0xc] = (char)((uint)pbVar3[-0xc] + (uint)pbVar4[-0xc] + 1 >> 1);
      puVar5[-0xb] = (char)((uint)pbVar3[-0xb] + (uint)pbVar4[-0xb] + 1 >> 1);
      puVar5[-10] = (char)((uint)pbVar3[-10] + (uint)pbVar4[-10] + 1 >> 1);
      puVar5[-9] = (char)((uint)pbVar3[-9] + (uint)pbVar4[-9] + 1 >> 1);
      puVar5[-8] = (char)((uint)pbVar3[-8] + (uint)pbVar4[-8] + 1 >> 1);
      puVar5[-7] = (char)((uint)pbVar3[-7] + (uint)pbVar4[-7] + 1 >> 1);
      puVar5[-6] = (char)((uint)pbVar3[-6] + (uint)pbVar4[-6] + 1 >> 1);
      puVar5[-5] = (char)((uint)pbVar3[-5] + (uint)pbVar4[-5] + 1 >> 1);
      param_1 = param_1 + param_4;
      puVar5[-4] = (char)((uint)pbVar3[-4] + (uint)pbVar4[-4] + 1 >> 1);
      pbVar7 = pbVar7 + param_4;
      puVar5[-3] = (char)((uint)pbVar3[-3] + (uint)pbVar4[-3] + 1 >> 1);
      iVar6 = iVar6 + 1;
      puVar5[-2] = (char)((uint)pbVar3[-2] + (uint)pbVar4[-2] + 1 >> 1);
      param_2 = param_2 + param_4;
      puVar5[-1] = (char)((uint)pbVar3[-1] + (uint)pbVar4[-1] + 1 >> 1);
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + param_4;
      bVar2 = *pbVar4;
      pbVar4 = pbVar4 + param_4;
      *puVar5 = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      puVar5 = puVar5 + param_4;
    } while (iVar6 < param_5);
  }
  return;
}
