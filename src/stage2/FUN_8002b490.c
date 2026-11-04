/* FUN_8002b490
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002b490  body 0x8002b490..0x8002b80f  size 896 B
 * body sha256 17cf7fc8820c62058b58a1f9b00be696bb86d5e3722fc9f9ffa854d097c94dd2
 * provider record sha256 dde068512ae69929dbdcfa82007136acf66614f0894ca447ba1e3c45062b906d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002b490(int *param_1)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  int local_30;
  
  puVar11 = (undefined4 *)param_1[5];
  puVar9 = (undefined1 *)*puVar11;
  iVar7 = puVar11[1];
  if (*(int *)(param_1[0x5d] + 0x54) == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    (**(code **)*param_1)();
  }
  if (iVar7 == 0) {
    iVar7 = (*(code *)puVar11[3])(param_1);
    if (iVar7 == 0) {
      return 0;
    }
    puVar9 = (undefined1 *)*puVar11;
    iVar7 = puVar11[1];
  }
  iVar7 = iVar7 + -1;
  uVar2 = *puVar9;
  puVar9 = puVar9 + 1;
  if (iVar7 == 0) {
    iVar7 = (*(code *)puVar11[3])(param_1);
    if (iVar7 == 0) {
      return 0;
    }
    puVar9 = (undefined1 *)*puVar11;
    iVar7 = puVar11[1];
  }
  iVar7 = iVar7 + -1;
  uVar3 = *puVar9;
  pbVar10 = puVar9 + 1;
  if (iVar7 == 0) {
    iVar7 = (*(code *)puVar11[3])(param_1);
    if (iVar7 == 0) {
      return 0;
    }
    pbVar10 = (byte *)*puVar11;
    iVar7 = puVar11[1];
  }
  uVar13 = (uint)*pbVar10;
  if ((((uint)CONCAT11(uVar2,uVar3) != uVar13 * 2 + 6) || (uVar13 == 0)) || (4 < uVar13)) {
    *(undefined4 *)(*param_1 + 0x14) = 9;
    (**(code **)*param_1)(param_1);
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x5f;
  *(uint *)(*param_1 + 0x18) = uVar13;
  local_30 = 0;
  (**(code **)(*param_1 + 4))(param_1,1);
  param_1[0x46] = uVar13;
  piVar14 = param_1;
  do {
    pbVar10 = pbVar10 + 1;
    if ((int)uVar13 <= local_30) {
      iVar6 = iVar7 + -2;
      if (iVar7 == 1) {
        iVar7 = (*(code *)puVar11[3])(param_1);
        if (iVar7 == 0) {
          return 0;
        }
        pbVar10 = (byte *)*puVar11;
        iVar6 = puVar11[1] + -1;
      }
      bVar4 = *pbVar10;
      pbVar10 = pbVar10 + 1;
      if (iVar6 == 0) {
        iVar7 = (*(code *)puVar11[3])(param_1);
        if (iVar7 == 0) {
          return 0;
        }
        pbVar10 = (byte *)*puVar11;
        iVar6 = puVar11[1];
      }
      iVar6 = iVar6 + -1;
      bVar5 = *pbVar10;
      pbVar10 = pbVar10 + 1;
      if (iVar6 == 0) {
        iVar7 = (*(code *)puVar11[3])(param_1);
        if (iVar7 == 0) {
          return 0;
        }
        pbVar10 = (byte *)*puVar11;
        iVar6 = puVar11[1];
      }
      if (((bVar4 != 0) || (bVar5 != 0x3f)) || (*pbVar10 != 0)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x6c;
        (**(code **)(*param_1 + 4))(param_1,0xffffffff);
      }
      *(undefined4 *)(param_1[0x5d] + 0x58) = 0;
      *puVar11 = pbVar10 + 1;
      puVar11[1] = iVar6 + -1;
      return 1;
    }
    bVar1 = iVar7 == 1;
    iVar7 = iVar7 + -2;
    if (bVar1) {
      iVar7 = (*(code *)puVar11[3])(param_1);
      if (iVar7 == 0) {
        return 0;
      }
      pbVar10 = (byte *)*puVar11;
      iVar7 = puVar11[1] + -1;
    }
    uVar12 = (uint)*pbVar10;
    pbVar10 = pbVar10 + 1;
    if (iVar7 == 0) {
      iVar7 = (*(code *)puVar11[3])(param_1);
      if (iVar7 == 0) {
        return 0;
      }
      pbVar10 = (byte *)*puVar11;
      iVar7 = puVar11[1];
    }
    bVar4 = *pbVar10;
    puVar8 = (uint *)param_1[0x2c];
    iVar6 = 0;
    if (0 < param_1[8]) {
      do {
        iVar6 = iVar6 + 1;
        if (uVar12 == *puVar8) goto LAB_8002b6a8;
        puVar8 = puVar8 + 0x14;
      } while (iVar6 < param_1[8]);
    }
    *(undefined4 *)(*param_1 + 0x14) = 5;
    *(uint *)(*param_1 + 0x18) = uVar12;
    (**(code **)*param_1)(param_1);
LAB_8002b6a8:
    piVar14[0x47] = (int)puVar8;
    puVar8[5] = (uint)(bVar4 >> 4);
    puVar8[6] = bVar4 & 0xf;
    iVar6 = *param_1;
    *(uint *)(iVar6 + 0x18) = uVar12;
    *(uint *)(iVar6 + 0x1c) = puVar8[5];
    *(uint *)(iVar6 + 0x20) = puVar8[6];
    *(undefined4 *)(*param_1 + 0x14) = 0x60;
    (**(code **)(*param_1 + 4))(param_1,1);
    piVar14 = piVar14 + 1;
    local_30 = local_30 + 1;
  } while( true );
}
