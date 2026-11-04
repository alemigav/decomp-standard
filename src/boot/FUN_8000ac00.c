/* FUN_8000ac00
 * image   boot (boot), base 0x80000480
 * address 0x8000ac00  body 0x8000ac00..0x8000adcb  size 460 B
 * body sha256 5c9c0cbdd42f4ffa416dd8f040880ee91b837f70095737a01419395e2befa4a7
 * provider record sha256 0f19a32a2e36a8adcf45d2ee616cf2119ca94a134e2d32d9f437065aa1845b20
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000ac00(uint param_1,uint *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_60 [24];
  ushort local_48;
  short local_44;
  short local_42;
  undefined1 local_40 [24];
  ushort local_28;
  short local_20;
  short local_1e [3];
  
  FUN_8000cfb4();
  iVar2 = FUN_8000aa10(param_1,param_3);
  FUN_8000d020();
  if (iVar2 == 0) {
    param_2[1] = param_1;
    param_2[2] = param_3;
    *param_2 = 0;
    *(undefined1 *)((int)param_2 + 0x65) = 0;
    iVar2 = FUN_8000a66c(param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_800087a0(param_2[1],param_2[2],1,auStack_60);
      if (iVar2 == 0) {
        FUN_80009c68(auStack_60,&local_20,local_1e);
        if (((local_44 == local_20) && (local_42 == local_1e[0])) ||
           (iVar2 = FUN_80009f8c(param_2,auStack_60), iVar2 == 0)) {
          puVar6 = auStack_60;
          if ((local_48 & 1) == 0) {
            puVar6 = local_40;
            iVar2 = FUN_80009cac(param_2,auStack_60,puVar6);
            if (iVar2 != 0) {
              return iVar2;
            }
            if ((local_28 & 1) == 0) {
              return 0xb;
            }
          }
          iVar2 = 0;
          puVar5 = puVar6;
          do {
            iVar4 = iVar2 + 1;
            *(undefined1 *)((int)param_2 + iVar2 + 0xc) = *puVar5;
            puVar5 = puVar5 + 1;
            iVar2 = iVar4;
          } while (iVar4 < 0x20);
          param_2[0x13] = (uint)(byte)puVar6[0x1b];
          bVar1 = puVar6[0x1a];
          param_2[0x14] = 0x10;
          param_2[0x15] = 8;
          *(byte *)(param_2 + 0x19) = bVar1;
          param_2[0x18] = (uint)bVar1 * 2 + 3;
          uVar3 = (*(byte *)(param_2 + 0x19) + 1) * 8;
          param_2[0x16] = uVar3;
          param_2[0x17] = uVar3 + (uint)*(byte *)(param_2 + 0x19) * 8;
          iVar2 = FUN_800087a0(param_2[1],param_2[2],7,param_2 + 0xb);
          if (iVar2 == 0) {
            iVar2 = FUN_8000add0(param_2);
            *param_2 = *param_2 | 1;
          }
        }
      }
    }
  }
  return iVar2;
}
