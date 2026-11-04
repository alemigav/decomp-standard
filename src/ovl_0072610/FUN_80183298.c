/* FUN_80183298
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80183298  body 0x80183298..0x8018339f  size 264 B
 * body sha256 42aad6d5f69e08e756aa5ccd9f00fce320c9f0cfdbfe5574aa449ebe06fa2188
 * provider record sha256 d00bbcad3038818243f4d3733922fc98338b5d335ad59f27e6dc9ffddb6c18fb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80183298(byte *param_1,undefined1 *param_2,int param_3,int param_4,int param_5)

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
    puVar5 = param_2 + 7;
    pbVar4 = pbVar7 + 7;
    pbVar3 = param_1 + 7;
    do {
      *param_2 = (char)((uint)*param_1 + (uint)*pbVar7 + 1 >> 1);
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
