/* FUN_8004bf6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004bf6c  body 0x8004bf6c..0x8004c21b  size 688 B
 * body sha256 97bc2bbb816e663ebb8303b2ca97a9633d3d8b64c573fa7d86e0f24effa8f006
 * provider record sha256 9721a07ab0a748ab3eadd89ddd8350251110ca2c813b112f83499ed6c224e119
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004bf6c(int param_1,uint param_2,ushort param_3,undefined1 param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = DAT_8010aa88;
  pbVar1 = (byte *)FUN_8004bad8(param_4);
  if (*pbVar1 != 0xf7) {
    puVar4 = puVar6 + 3;
    bVar2 = *pbVar1;
    do {
      iVar5 = 0xe;
      if (bVar2 == 0xee) {
        pbVar1 = pbVar1 + 1;
        *(byte *)((int)puVar4 + -3) = (*pbVar1 / 0x12) * '\x0e' + -0x2e;
LAB_8004c134:
        *puVar6 = 0x64808080;
        puVar4[-2] = param_2 & 0xffff | param_1 << 0x10;
        puVar4[1] = 0xe000e;
        bVar2 = *pbVar1;
        puVar6 = puVar6 + 5;
        *(undefined1 *)((int)puVar4 + -9) = 0;
        *(ushort *)((int)puVar4 + -2) = (param_3 & 0x30) << 2;
        *puVar4 = &DAT_8010b2bc;
        *(byte *)(puVar4 + -1) = (bVar2 % 0x12) * '\x0e';
        puVar4 = puVar4 + 5;
        if (puVar6 == (undefined4 *)&UNK_800ff688) break;
      }
      else {
        if (0xee < bVar2) {
          if (bVar2 == 0xef) {
            pbVar1 = pbVar1 + 1;
            *(byte *)((int)puVar4 + -3) = (*pbVar1 / 0x12) * '\x0e';
          }
          else {
            if (bVar2 != 0xf0) goto LAB_8004c0dc;
            pbVar1 = pbVar1 + 1;
            *(byte *)((int)puVar4 + -3) = (*pbVar1 / 0x12) * '\x0e' + -0x3c;
          }
          goto LAB_8004c134;
        }
        if (bVar2 != 0) {
LAB_8004c0dc:
          *(byte *)((int)puVar4 + -3) = (*pbVar1 / 0x12) * '\x0e' + '\x1c';
          if (((param_3 & 0x4000) != 0) && (iVar3 = (uint)*pbVar1 * 2, *pbVar1 < 0x57)) {
            param_1 = param_1 - (char)(&DAT_800f9ec0)[iVar3];
            iVar5 = (int)(char)(&DAT_800f9ec1)[iVar3] + (int)(char)(&DAT_800f9ec0)[iVar3];
          }
          goto LAB_8004c134;
        }
        if ((param_3 & 0x4000) != 0) {
          iVar5 = 8;
        }
      }
      pbVar1 = pbVar1 + 1;
      bVar2 = *pbVar1;
      param_1 = param_1 + iVar5;
    } while (bVar2 != 0xf7);
  }
  if (DAT_8010aa88 != puVar6) {
    DAT_800df8b4 = FUN_80043868(DAT_800df8b4,DAT_8010aa88,puVar6);
  }
  DAT_8010aa88 = puVar6;
  return;
}
