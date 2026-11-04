/* FUN_8002bb40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002bb40  body 0x8002bb40..0x8002bd7f  size 576 B
 * body sha256 cc49defefbf2f39690e06aaa9a346c3a808d0566659827e78c894518817bb2e0
 * provider record sha256 b9ad16ec5bbc8780c2657eacbc43fdd77127cd949afbf6ff30f8cade4d31859a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002bb40(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  char local_30 [5];
  ushort local_2b;
  ushort local_29;
  ushort local_27;
  byte local_25;
  
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
  if (iVar8 < 0xc) {
    *(undefined4 *)(*param_1 + 0x14) = 0x46;
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
    } while (iVar8 < 0xc);
    iVar8 = uVar7 - 0xe;
    if ((((local_30[0] == 'A') && (local_30[1] == 'd')) && (local_30[2] == 'o')) &&
       ((local_30[3] == 'b' && (local_30[4] == 'e')))) {
      iVar2 = *param_1;
      *(uint *)(iVar2 + 0x18) = (uint)local_2b;
      *(uint *)(iVar2 + 0x1c) = (uint)local_29;
      *(uint *)(iVar2 + 0x20) = (uint)local_27;
      *(uint *)(iVar2 + 0x24) = (uint)local_25;
      *(undefined4 *)(*param_1 + 0x14) = 0x44;
      (**(code **)(*param_1 + 4))(param_1,1);
      param_1[0x3e] = 1;
      *(byte *)(param_1 + 0x3f) = local_25;
      goto LAB_8002bd34;
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x46;
    *(uint *)(*param_1 + 0x18) = uVar7 - 2;
  }
  (**(code **)(*param_1 + 4))(param_1,1);
LAB_8002bd34:
  *puVar6 = pcVar5;
  puVar6[1] = iVar3;
  if (0 < iVar8) {
    (**(code **)(param_1[5] + 0x10))(param_1,iVar8);
  }
  return 1;
}
