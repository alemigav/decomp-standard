/* FUN_8002b810
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002b810  body 0x8002b810..0x8002bb3f  size 816 B
 * body sha256 a8ceccfad5e9f348eee5fd8df3672b3d02a6efff37e3cba29f39925472715294
 * provider record sha256 d3e31f5c97733c812e21ea7222fcb5bccc198bb63f77ce0bf5b9c36567f671d7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002b810(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  char local_30 [8];
  undefined2 local_28;
  undefined2 local_26;
  byte local_24;
  byte local_23;
  
  puVar6 = (undefined4 *)param_1[5];
  puVar4 = (undefined1 *)*puVar6;
  iVar3 = puVar6[1];
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar6[3])();
    if (iVar3 == 0) {
      return 0;
    }
    puVar4 = (undefined1 *)*puVar6;
    iVar3 = puVar6[1];
  }
  iVar3 = iVar3 + -1;
  uVar1 = *puVar4;
  puVar4 = puVar4 + 1;
  if (iVar3 == 0) {
    iVar3 = (*(code *)puVar6[3])(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar4 = (undefined1 *)*puVar6;
    iVar3 = puVar6[1];
  }
  iVar3 = iVar3 + -1;
  uVar7 = (uint)CONCAT11(uVar1,*puVar4);
  iVar8 = uVar7 - 2;
  pcVar5 = puVar4 + 1;
  if (iVar8 < 0xe) {
    *(undefined4 *)(*param_1 + 0x14) = 0x45;
LAB_8002bad8:
    *(int *)(*param_1 + 0x18) = iVar8;
  }
  else {
    iVar8 = 0;
    do {
      if (iVar3 == 0) {
        iVar3 = (*(code *)puVar6[3])(param_1);
        if (iVar3 == 0) {
          return 0;
        }
        pcVar5 = (char *)*puVar6;
        iVar3 = puVar6[1];
      }
      iVar3 = iVar3 + -1;
      local_30[iVar8] = *pcVar5;
      iVar8 = iVar8 + 1;
      pcVar5 = pcVar5 + 1;
    } while (iVar8 < 0xe);
    iVar8 = uVar7 - 0x10;
    if ((((local_30[0] == 'J') && (local_30[1] == 'F')) && (local_30[2] == 'I')) &&
       ((local_30[3] == 'F' && (local_30[4] == '\0')))) {
      if (local_30[5] != 1) {
        *(undefined4 *)(*param_1 + 0x14) = 0x26;
        *(uint *)(*param_1 + 0x18) = (uint)(byte)local_30[5];
        *(uint *)(*param_1 + 0x1c) = (uint)(byte)local_30[6];
        (**(code **)*param_1)(param_1);
      }
      if ((byte)local_30[6] < 3) {
        param_1[0x3b] = 1;
      }
      else {
        *(undefined4 *)(*param_1 + 0x14) = 0x51;
        *(uint *)(*param_1 + 0x18) = (uint)(byte)local_30[5];
        *(uint *)(*param_1 + 0x1c) = (uint)(byte)local_30[6];
        (**(code **)(*param_1 + 4))(param_1,1);
        param_1[0x3b] = 1;
      }
      *(char *)(param_1 + 0x3c) = local_30[7];
      *(undefined2 *)((int)param_1 + 0xf2) = local_28;
      *(undefined2 *)(param_1 + 0x3d) = local_26;
      iVar2 = *param_1;
      *(uint *)(iVar2 + 0x18) = (uint)*(ushort *)((int)param_1 + 0xf2);
      *(uint *)(iVar2 + 0x1c) = (uint)*(ushort *)(param_1 + 0x3d);
      *(uint *)(iVar2 + 0x20) = (uint)*(byte *)(param_1 + 0x3c);
      *(undefined4 *)(*param_1 + 0x14) = 0x4f;
      (**(code **)(*param_1 + 4))(param_1,1);
      if (local_24 != 0 || local_23 != 0) {
        *(undefined4 *)(*param_1 + 0x14) = 0x52;
        *(uint *)(*param_1 + 0x18) = (uint)local_24;
        *(uint *)(*param_1 + 0x1c) = (uint)local_23;
        (**(code **)(*param_1 + 4))(param_1,1);
      }
      if (iVar8 == (uint)local_24 * (uint)local_23 * 3) goto LAB_8002baf4;
      *(undefined4 *)(*param_1 + 0x14) = 0x50;
      goto LAB_8002bad8;
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x45;
    *(uint *)(*param_1 + 0x18) = uVar7 - 2;
  }
  (**(code **)(*param_1 + 4))(param_1,1);
LAB_8002baf4:
  *puVar6 = pcVar5;
  puVar6[1] = iVar3;
  if (0 < iVar8) {
    (**(code **)(param_1[5] + 0x10))(param_1,iVar8);
  }
  return 1;
}
