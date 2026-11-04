/* FUN_80183a40
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80183a40  body 0x80183a40..0x80183b8f  size 336 B
 * body sha256 9eb3754c014412ca9a23b5d2896c677389f10293af8816159f821b7fa393a19f
 * provider record sha256 fc4f26f43eb5881822f2bbf5508ede13de358463c6cb7bbac2f6dc7e8a35e75e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80183a40(byte *param_1,undefined1 *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  int iVar8;
  byte *pbVar9;
  
  pbVar9 = param_1 + param_3;
  iVar8 = 0;
  if (0 < param_5) {
    puVar7 = param_2 + 7;
    pbVar6 = pbVar9 + 8;
    pbVar5 = param_1 + 8;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + param_4;
      bVar2 = *pbVar9;
      pbVar9 = pbVar9 + param_4;
      iVar8 = iVar8 + 1;
      bVar3 = pbVar5[-7];
      bVar4 = pbVar6[-7];
      *param_2 = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      param_2 = param_2 + param_4;
      bVar1 = pbVar5[-6];
      bVar2 = pbVar6[-6];
      puVar7[-6] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-5];
      bVar4 = pbVar6[-5];
      puVar7[-5] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-4];
      bVar2 = pbVar6[-4];
      puVar7[-4] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-3];
      bVar4 = pbVar6[-3];
      puVar7[-3] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = pbVar5[-2];
      bVar2 = pbVar6[-2];
      puVar7[-2] = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      bVar3 = pbVar5[-1];
      bVar4 = pbVar6[-1];
      puVar7[-1] = (char)((uint)bVar1 + (uint)bVar3 + (uint)bVar2 + (uint)bVar4 + 2 >> 2);
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + param_4;
      bVar2 = *pbVar6;
      pbVar6 = pbVar6 + param_4;
      *puVar7 = (char)((uint)bVar3 + (uint)bVar1 + (uint)bVar4 + (uint)bVar2 + 2 >> 2);
      puVar7 = puVar7 + param_4;
    } while (iVar8 < param_5);
  }
  return;
}
