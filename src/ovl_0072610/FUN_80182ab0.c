/* FUN_80182ab0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80182ab0  body 0x80182ab0..0x80182c27  size 376 B
 * body sha256 fd320a0c5ca9d45bdc0a6db917c4d05d74324bc93a5a5a30e9bf97b2911e0f4b
 * provider record sha256 ee5f5f4bb0ed229b4d73861d2f64f3db9a937c469fdb27efb181165aa3a4ddab
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80182ab0(byte *param_1,undefined1 *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < param_4) {
    puVar4 = param_2 + 0xf;
    pbVar3 = param_1 + 0x10;
    do {
      bVar1 = pbVar3[-0xf];
      *param_2 = (char)((uint)*param_1 + (uint)bVar1 + 1 >> 1);
      bVar2 = pbVar3[-0xe];
      puVar4[-0xe] = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      bVar1 = pbVar3[-0xd];
      puVar4[-0xd] = (char)((uint)bVar2 + (uint)bVar1 + 1 >> 1);
      bVar2 = pbVar3[-0xc];
      puVar4[-0xc] = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      bVar1 = pbVar3[-0xb];
      puVar4[-0xb] = (char)((uint)bVar2 + (uint)bVar1 + 1 >> 1);
      bVar2 = pbVar3[-10];
      puVar4[-10] = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      bVar1 = pbVar3[-9];
      puVar4[-9] = (char)((uint)bVar2 + (uint)bVar1 + 1 >> 1);
      bVar2 = pbVar3[-8];
      puVar4[-8] = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      bVar1 = pbVar3[-7];
      puVar4[-7] = (char)((uint)bVar2 + (uint)bVar1 + 1 >> 1);
      bVar2 = pbVar3[-6];
      puVar4[-6] = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      bVar1 = pbVar3[-5];
      puVar4[-5] = (char)((uint)bVar2 + (uint)bVar1 + 1 >> 1);
      bVar2 = pbVar3[-4];
      puVar4[-4] = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      bVar1 = pbVar3[-3];
      param_1 = param_1 + param_3;
      puVar4[-3] = (char)((uint)bVar2 + (uint)bVar1 + 1 >> 1);
      bVar2 = pbVar3[-2];
      iVar5 = iVar5 + 1;
      puVar4[-2] = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      bVar1 = pbVar3[-1];
      param_2 = param_2 + param_3;
      puVar4[-1] = (char)((uint)bVar2 + (uint)bVar1 + 1 >> 1);
      bVar2 = *pbVar3;
      pbVar3 = pbVar3 + param_3;
      *puVar4 = (char)((uint)bVar1 + (uint)bVar2 + 1 >> 1);
      puVar4 = puVar4 + param_3;
    } while (iVar5 < param_4);
  }
  return;
}
