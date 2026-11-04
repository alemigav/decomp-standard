/* FUN_8002c3b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002c3b4  body 0x8002c3b4..0x8002c74b  size 920 B
 * body sha256 b3b72bf0e6c439e5b91d3f2d013f6bb4024856d001b87523a05b3b016600b316
 * provider record sha256 d6dff81bdea7afa9aa9266653df31a7ec2b03944e14a52ccfe6264ba2aff473f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002c3b4(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort uVar12;
  ushort *puVar11;
  int iVar13;
  undefined1 *puVar14;
  byte *pbVar15;
  undefined4 *puVar16;
  ushort *puVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int local_48;
  
  puVar16 = (undefined4 *)param_1[5];
  puVar14 = (undefined1 *)*puVar16;
  iVar13 = puVar16[1];
  if (iVar13 == 0) {
    iVar13 = (*(code *)puVar16[3])();
    if (iVar13 == 0) {
      return 0;
    }
    puVar14 = (undefined1 *)*puVar16;
    iVar13 = puVar16[1];
  }
  iVar13 = iVar13 + -1;
  uVar1 = *puVar14;
  puVar14 = puVar14 + 1;
  if (iVar13 == 0) {
    iVar13 = (*(code *)puVar16[3])(param_1);
    if (iVar13 == 0) {
      return 0;
    }
    puVar14 = (undefined1 *)*puVar16;
    iVar13 = puVar16[1];
  }
  iVar13 = iVar13 + -1;
  pbVar15 = puVar14 + 1;
  iVar8 = CONCAT11(uVar1,*puVar14) - 2;
  do {
    do {
      local_48 = iVar8;
      if (local_48 < 1) {
        *puVar16 = pbVar15;
        puVar16[1] = iVar13;
        return 1;
      }
      if (iVar13 == 0) {
        iVar13 = (*(code *)puVar16[3])(param_1);
        if (iVar13 == 0) {
          return 0;
        }
        pbVar15 = (byte *)*puVar16;
        iVar13 = puVar16[1];
      }
      iVar13 = iVar13 + -1;
      bVar2 = *pbVar15;
      pbVar15 = pbVar15 + 1;
      iVar9 = (int)(uint)bVar2 >> 4;
      *(undefined4 *)(*param_1 + 0x14) = 0x49;
      uVar10 = bVar2 & 0xf;
      *(uint *)(*param_1 + 0x18) = uVar10;
      *(int *)(*param_1 + 0x1c) = iVar9;
      (**(code **)(*param_1 + 4))(param_1,1);
      if (3 < uVar10) {
        *(undefined4 *)(*param_1 + 0x14) = 0x19;
        *(uint *)(*param_1 + 0x18) = uVar10;
        (**(code **)*param_1)(param_1);
      }
      if (param_1[uVar10 + 0x1f] == 0) {
        iVar8 = FUN_800283f0(param_1);
        param_1[uVar10 + 0x1f] = iVar8;
      }
      puVar17 = (ushort *)param_1[uVar10 + 0x1f];
      iVar8 = 0;
      puVar11 = puVar17;
      do {
        if (iVar9 == 0) {
          if (iVar13 == 0) {
            iVar13 = (*(code *)puVar16[3])(param_1);
            if (iVar13 == 0) {
              return 0;
            }
            pbVar15 = (byte *)*puVar16;
            iVar13 = puVar16[1];
          }
          uVar12 = (ushort)*pbVar15;
        }
        else {
          if (iVar13 == 0) {
            iVar13 = (*(code *)puVar16[3])(param_1);
            if (iVar13 == 0) {
              return 0;
            }
            pbVar15 = (byte *)*puVar16;
            iVar13 = puVar16[1];
          }
          iVar13 = iVar13 + -1;
          bVar2 = *pbVar15;
          pbVar15 = pbVar15 + 1;
          if (iVar13 == 0) {
            iVar13 = (*(code *)puVar16[3])(param_1);
            if (iVar13 == 0) {
              return 0;
            }
            pbVar15 = (byte *)*puVar16;
            iVar13 = puVar16[1];
          }
          uVar12 = CONCAT11(bVar2,*pbVar15);
        }
        pbVar15 = pbVar15 + 1;
        iVar13 = iVar13 + -1;
        *puVar11 = uVar12;
        iVar8 = iVar8 + 1;
        puVar11 = puVar11 + 1;
      } while (iVar8 < 0x40);
      iVar7 = 0xe;
      iVar6 = 0xc;
      iVar5 = 10;
      iVar4 = 8;
      iVar8 = 6;
      iVar20 = 4;
      iVar19 = 2;
      puVar11 = puVar17;
      for (iVar18 = 0; iVar18 < 0x40; iVar18 = iVar18 + 8) {
        iVar3 = *param_1;
        *(uint *)(iVar3 + 0x18) = (uint)*puVar11;
        *(uint *)(iVar3 + 0x1c) = (uint)*(ushort *)((int)puVar17 + iVar19);
        *(uint *)(iVar3 + 0x20) = (uint)*(ushort *)((int)puVar17 + iVar20);
        *(uint *)(iVar3 + 0x24) = (uint)*(ushort *)((int)puVar17 + iVar8);
        *(uint *)(iVar3 + 0x28) = (uint)*(ushort *)((int)puVar17 + iVar4);
        *(uint *)(iVar3 + 0x2c) = (uint)*(ushort *)((int)puVar17 + iVar5);
        *(uint *)(iVar3 + 0x30) = (uint)*(ushort *)((int)puVar17 + iVar6);
        *(uint *)(iVar3 + 0x34) = (uint)*(ushort *)((int)puVar17 + iVar7);
        *(undefined4 *)(*param_1 + 0x14) = 0x55;
        (**(code **)(*param_1 + 4))(param_1,2);
        iVar7 = iVar7 + 0x10;
        iVar20 = iVar20 + 0x10;
        iVar19 = iVar19 + 0x10;
        puVar11 = puVar11 + 8;
        iVar6 = iVar6 + 0x10;
        iVar5 = iVar5 + 0x10;
        iVar4 = iVar4 + 0x10;
        iVar8 = iVar8 + 0x10;
      }
      iVar8 = local_48 + -0x41;
    } while (iVar9 == 0);
    iVar8 = local_48 + -0x81;
  } while( true );
}
