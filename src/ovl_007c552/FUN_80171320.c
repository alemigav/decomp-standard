/* FUN_80171320
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x80171320  body 0x80171320..0x8017138b  size 108 B
 * body sha256 c9758a9247b74932454fa49f14ff37ab98b624dbdc6004c2d9d5912b560cf499
 * provider record sha256 73ec1f03c03b2cf04c69e90e4c4f829bd154cb454df6996eda75349a709673cf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80171320(undefined4 *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  ushort *puVar6;
  uint uVar7;
  
  uVar7 = 0;
  pbVar5 = (byte *)*param_2;
  puVar6 = (ushort *)*param_1;
  pbVar4 = pbVar5 + 1;
  do {
    pbVar1 = pbVar4 + 1;
    bVar2 = *pbVar4;
    pbVar4 = pbVar4 + 3;
    bVar3 = *pbVar5;
    pbVar5 = pbVar5 + 3;
    uVar7 = uVar7 + 1;
    *puVar6 = (ushort)(*pbVar1 >> 3) * 2 + (ushort)(bVar2 >> 3) * 0x40 +
              (ushort)(bVar3 >> 3) * 0x800 | 1;
    puVar6 = puVar6 + 1;
  } while (uVar7 < 0x140);
  *param_1 = puVar6;
  *param_2 = pbVar5;
  return;
}
