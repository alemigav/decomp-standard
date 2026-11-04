/* FUN_8002bf74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002bf74  body 0x8002bf74..0x8002c3b3  size 1088 B
 * body sha256 fe21be5e775676d8953b0eb4dab5a1287592ea10c34928bb44338865d451c60a
 * provider record sha256 08ca05dc4890c3949793a8f9780ab90d834f97018d1b51604171ce49a14bfc64
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002bf74(int *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 ****ppppuVar4;
  undefined4 *puVar5;
  undefined4 ***pppuVar6;
  undefined4 ***pppuVar7;
  undefined4 ***pppuVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  int iVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  undefined4 *puVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  byte local_140;
  undefined4 ***local_138 [64];
  undefined4 ****local_38;
  undefined4 ****local_34;
  uint *local_30;
  
  puVar15 = (undefined4 *)param_1[5];
  puVar13 = (undefined1 *)*puVar15;
  iVar12 = puVar15[1];
  if (iVar12 == 0) {
    iVar12 = (*(code *)puVar15[3])();
    if (iVar12 == 0) {
      return 0;
    }
    puVar13 = (undefined1 *)*puVar15;
    iVar12 = puVar15[1];
  }
  iVar12 = iVar12 + -1;
  uVar1 = *puVar13;
  puVar13 = puVar13 + 1;
  if (iVar12 == 0) {
    iVar12 = (*(code *)puVar15[3])(param_1);
    if (iVar12 == 0) {
      return 0;
    }
    puVar13 = (undefined1 *)*puVar15;
    iVar12 = puVar15[1];
  }
  iVar12 = iVar12 + -1;
  pbVar14 = puVar13 + 1;
  iVar18 = CONCAT11(uVar1,*puVar13) - 2;
  local_30 = &local_150;
  local_38 = local_138;
  local_34 = &local_38;
  do {
    if (iVar18 < 1) {
      *puVar15 = pbVar14;
      puVar15[1] = iVar12;
      return 1;
    }
    if (iVar12 == 0) {
      iVar12 = (*(code *)puVar15[3])(param_1);
      if (iVar12 == 0) {
        return 0;
      }
      pbVar14 = (byte *)*puVar15;
      iVar12 = puVar15[1];
    }
    puVar11 = local_30;
    iVar12 = iVar12 + -1;
    bVar2 = *pbVar14;
    uVar17 = (uint)bVar2;
    pbVar14 = pbVar14 + 1;
    iVar16 = 0;
    iVar9 = 1;
    *(undefined4 *)(*param_1 + 0x14) = 0x48;
    *(uint *)(*param_1 + 0x18) = uVar17;
    (**(code **)(*param_1 + 4))(param_1);
    local_150 = local_150 & 0xffffff;
    do {
      puVar11 = (uint *)((int)puVar11 + 1);
      if (iVar12 == 0) {
        iVar12 = (*(code *)puVar15[3])(param_1);
        if (iVar12 == 0) {
          return 0;
        }
        pbVar14 = (byte *)*puVar15;
        iVar12 = puVar15[1];
      }
      iVar12 = iVar12 + -1;
      bVar3 = *pbVar14;
      pbVar14 = pbVar14 + 1;
      *(byte *)puVar11 = bVar3;
      iVar16 = iVar16 + (uint)bVar3;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x11);
    iVar9 = *param_1;
    *(uint *)(iVar9 + 0x18) = local_150 >> 0x10 & 0xff;
    *(uint *)(iVar9 + 0x1c) = local_150 >> 8 & 0xff;
    *(uint *)(iVar9 + 0x20) = local_150 & 0xff;
    *(uint *)(iVar9 + 0x24) = local_14c >> 0x18;
    *(uint *)(iVar9 + 0x28) = local_14c >> 0x10 & 0xff;
    *(uint *)(iVar9 + 0x2c) = local_14c >> 8 & 0xff;
    *(uint *)(iVar9 + 0x30) = local_14c & 0xff;
    *(uint *)(iVar9 + 0x34) = local_148 >> 0x18;
    *(undefined4 *)(*param_1 + 0x14) = 0x4e;
    (**(code **)(*param_1 + 4))(param_1,2);
    iVar9 = *param_1;
    *(uint *)(iVar9 + 0x18) = local_148 >> 0x10 & 0xff;
    *(uint *)(iVar9 + 0x1c) = local_148 >> 8 & 0xff;
    *(uint *)(iVar9 + 0x20) = local_148 & 0xff;
    *(uint *)(iVar9 + 0x24) = local_144 >> 0x18;
    *(uint *)(iVar9 + 0x28) = local_144 >> 0x10 & 0xff;
    *(uint *)(iVar9 + 0x2c) = local_144 >> 8 & 0xff;
    *(uint *)(iVar9 + 0x30) = local_144 & 0xff;
    *(uint *)(iVar9 + 0x34) = (uint)local_140;
    *(undefined4 *)(*param_1 + 0x14) = 0x4e;
    (**(code **)(*param_1 + 4))(param_1,2);
    if ((0x100 < iVar16) || (iVar18 + -0x11 < iVar16)) {
      *(undefined4 *)(*param_1 + 0x14) = 0x17;
      (**(code **)*param_1)(param_1);
    }
    iVar9 = 0;
    if (0 < iVar16) {
      do {
        if (iVar12 == 0) {
          iVar12 = (*(code *)puVar15[3])(param_1);
          if (iVar12 == 0) {
            return 0;
          }
          pbVar14 = (byte *)*puVar15;
          iVar12 = puVar15[1];
        }
        iVar12 = iVar12 + -1;
        *(byte *)((int)local_38 + iVar9) = *pbVar14;
        iVar9 = iVar9 + 1;
        pbVar14 = pbVar14 + 1;
      } while (iVar9 < iVar16);
    }
    iVar18 = (iVar18 + -0x11) - iVar16;
    if ((bVar2 & 0x10) == 0) {
      iVar9 = uVar17 * 4 + 0x8c;
    }
    else {
      uVar17 = uVar17 - 0x10;
      iVar9 = uVar17 * 4 + 0x9c;
    }
    piVar10 = (int *)((int)param_1 + iVar9);
    if (3 < uVar17) {
      *(undefined4 *)(*param_1 + 0x14) = 0x18;
      *(uint *)(*param_1 + 0x18) = uVar17;
      (**(code **)*param_1)(param_1);
    }
    puVar11 = (uint *)*piVar10;
    if (puVar11 == (uint *)0x0) {
      iVar9 = FUN_8002841c(param_1);
      *piVar10 = iVar9;
      puVar11 = (uint *)*piVar10;
    }
    *puVar11 = local_150;
    puVar11[1] = local_14c;
    puVar11[2] = local_148;
    puVar11[3] = local_144;
    *(byte *)(puVar11 + 4) = local_140;
    puVar5 = (undefined4 *)(*piVar10 + 0x11);
    ppppuVar4 = local_138;
    if (((uint)puVar5 & 3) == 0) {
      do {
        pppuVar8 = ppppuVar4[1];
        pppuVar6 = ppppuVar4[2];
        pppuVar7 = ppppuVar4[3];
        *puVar5 = *ppppuVar4;
        puVar5[1] = pppuVar8;
        puVar5[2] = pppuVar6;
        puVar5[3] = pppuVar7;
        ppppuVar4 = ppppuVar4 + 4;
        puVar5 = puVar5 + 4;
      } while (ppppuVar4 != local_34);
    }
    else {
      do {
        pppuVar7 = ppppuVar4[1];
        pppuVar8 = ppppuVar4[2];
        pppuVar6 = ppppuVar4[3];
        *puVar5 = *ppppuVar4;
        puVar5[1] = pppuVar7;
        puVar5[2] = pppuVar8;
        puVar5[3] = pppuVar6;
        ppppuVar4 = ppppuVar4 + 4;
        puVar5 = puVar5 + 4;
      } while (ppppuVar4 != local_34);
    }
  } while( true );
}
