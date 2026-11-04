/* FUN_8004c70c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c70c  body 0x8004c70c..0x8004c90f  size 516 B
 * body sha256 bdd56362ae58f787295c83803790306b632c30214eace4689b5dcac40becab61
 * provider record sha256 d52a946ce968a41e6eab486eb3172d54db5f27a78a6eecfaa796a66d09c50f28
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8004c70c(short *param_1,uint param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  
  puVar9 = DAT_8010aa88;
  if (DAT_8010aa88 == (undefined4 *)&UNK_800ff688) {
    uVar2 = *(uint *)(param_3 + 0xd008);
  }
  else {
    pbVar8 = (byte *)(param_1 + 1);
    sVar3 = FUN_800844cc((int)*param_1);
    uVar7 = (int)sVar3 & 0x4000;
    puVar5 = puVar9 + 3;
    uVar2 = (uint)*pbVar8;
    do {
      iVar6 = 0xe;
      if (uVar2 == 0x20) {
        if (uVar7 != 0) {
          iVar6 = 8;
        }
      }
      else {
        if ((uVar7 != 0) && (iVar4 = (uVar2 - 0x24) * 2, uVar2 - 0x24 < 0x57)) {
          param_2 = param_2 - (int)(char)(&DAT_800f9ec0)[iVar4];
          iVar6 = (int)(char)(&DAT_800f9ec1)[iVar4] + (int)(char)(&DAT_800f9ec0)[iVar4];
        }
        *puVar9 = 0x80808000;
        *(undefined1 *)((int)puVar5 + -9) = 0;
        puVar5[-2] = param_2 << 0x10 | param_2 >> 0x10;
        *(byte *)(puVar5 + -1) = (*pbVar8 % 0x12) * '\x0e';
        bVar1 = *pbVar8;
        puVar9 = puVar9 + 5;
        *(ushort *)((int)puVar5 + -2) =
             ((short)(((int)sVar3 & 0xf0U) >> 3) + ((short)(char)((ushort)sVar3 >> 8) & 1U)) * 0x40;
        puVar5[1] = 0xe000e;
        *puVar5 = &DAT_8010b2bc;
        *(byte *)((int)puVar5 + -3) = (bVar1 / 0x12) * '\x0e';
        puVar5 = puVar5 + 5;
        if (puVar9 == (undefined4 *)&UNK_800ff688) break;
      }
      pbVar8 = pbVar8 + 1;
      uVar2 = (uint)*pbVar8;
      param_2 = param_2 + iVar6;
    } while (uVar2 != 0);
    if (DAT_8010aa88 != puVar9) {
      DAT_800df8b4 = FUN_80043868(DAT_800df8b4,DAT_8010aa88,puVar9);
    }
    uVar2 = (uint)(pbVar8 + 2) & 0xfffffffe;
    DAT_8010aa88 = puVar9;
  }
  return uVar2;
}
