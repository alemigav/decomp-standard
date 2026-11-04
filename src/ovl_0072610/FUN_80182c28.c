/* FUN_80182c28
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80182c28  body 0x80182c28..0x80182cff  size 216 B
 * body sha256 ab4196c36a9138fcd6227828caf0bc7557ce9de419ccd7b2a4c8e6867e75b477
 * provider record sha256 5ddc7a221ec907a269fec05038b89dfb71c311070b8508a082e396e33b6a7a8d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80182c28(byte *param_1,undefined1 *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < param_4) {
    puVar4 = param_2 + 7;
    pbVar3 = param_1 + 8;
    do {
      bVar1 = pbVar3[-7];
      *param_2 = (char)((uint)*param_1 + (uint)bVar1 + 1 >> 1);
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
