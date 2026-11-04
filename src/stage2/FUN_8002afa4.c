/* FUN_8002afa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002afa4  body 0x8002afa4..0x8002b48f  size 1260 B
 * body sha256 d9fc564502d094a3bbd75e685852c6dec4375d99d4ff63e13927644376014929
 * provider record sha256 3a5e096ff6ec7f7814d5fcf642b5dc1d5e0a379e5928fd8e255f4b8999465f47
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002afa4(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  
  puVar9 = (undefined4 *)param_1[5];
  puVar6 = (undefined1 *)*puVar9;
  iVar5 = puVar9[1];
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])();
    if (iVar5 == 0) {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar9;
    iVar5 = puVar9[1];
  }
  iVar5 = iVar5 + -1;
  uVar1 = *puVar6;
  puVar6 = puVar6 + 1;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar9;
    iVar5 = puVar9[1];
  }
  iVar5 = iVar5 + -1;
  uVar2 = *puVar6;
  pbVar7 = puVar6 + 1;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar7 = (byte *)*puVar9;
    iVar5 = puVar9[1];
  }
  iVar5 = iVar5 + -1;
  pbVar8 = pbVar7 + 1;
  param_1[0x2b] = (uint)*pbVar7;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar8 = (byte *)*puVar9;
    iVar5 = puVar9[1];
  }
  iVar5 = iVar5 + -1;
  pbVar7 = pbVar8 + 1;
  param_1[7] = (uint)*pbVar8 << 8;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar7 = (byte *)*puVar9;
    iVar5 = puVar9[1];
  }
  iVar5 = iVar5 + -1;
  pbVar8 = pbVar7 + 1;
  param_1[7] = param_1[7] + (uint)*pbVar7;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar8 = (byte *)*puVar9;
    iVar5 = puVar9[1];
  }
  iVar5 = iVar5 + -1;
  pbVar7 = pbVar8 + 1;
  param_1[6] = (uint)*pbVar8 << 8;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar7 = (byte *)*puVar9;
    iVar5 = puVar9[1];
  }
  iVar5 = iVar5 + -1;
  pbVar8 = pbVar7 + 1;
  param_1[6] = param_1[6] + (uint)*pbVar7;
  if (iVar5 == 0) {
    iVar5 = (*(code *)puVar9[3])(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    pbVar8 = (byte *)*puVar9;
    iVar5 = puVar9[1];
  }
  param_1[8] = (uint)*pbVar8;
  iVar4 = *param_1;
  *(int *)(iVar4 + 0x18) = param_1[0x58];
  *(int *)(iVar4 + 0x1c) = param_1[6];
  *(int *)(iVar4 + 0x20) = param_1[7];
  *(int *)(iVar4 + 0x24) = param_1[8];
  *(undefined4 *)(*param_1 + 0x14) = 0x5c;
  (**(code **)(*param_1 + 4))(param_1,1);
  if (*(int *)(param_1[0x5d] + 0x54) != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x32;
    (**(code **)*param_1)(param_1);
  }
  if (((param_1[7] == 0) || (param_1[6] == 0)) || (param_1[8] < 1)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1a;
    (**(code **)*param_1)(param_1);
  }
  if ((0xffdc < param_1[7]) || (0xffdc < param_1[6])) {
    *(undefined4 *)(*param_1 + 0x14) = 0x23;
    *(undefined4 *)(*param_1 + 0x18) = 0xffdc;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x2b] != 8) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    *(int *)(*param_1 + 0x18) = param_1[0x2b];
    (**(code **)*param_1)(param_1);
  }
  if (10 < param_1[8]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x13;
    *(int *)(*param_1 + 0x18) = param_1[8];
    *(undefined4 *)(*param_1 + 0x1c) = 10;
    (**(code **)*param_1)(param_1);
  }
  if (CONCAT11(uVar1,uVar2) - 8 != param_1[8] * 3) {
    *(undefined4 *)(*param_1 + 0x14) = 9;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x2c] == 0) {
    iVar4 = (**(code **)param_1[1])(param_1,1,param_1[8] * 0x50);
    param_1[0x2c] = iVar4;
  }
  puVar11 = (uint *)param_1[0x2c];
  uVar12 = 0;
  puVar10 = puVar11 + 4;
  do {
    pbVar7 = pbVar8 + 1;
    iVar5 = iVar5 + -1;
    if (param_1[8] <= (int)uVar12) {
      *(undefined4 *)(param_1[0x5d] + 0x54) = 1;
      *puVar9 = pbVar7;
      puVar9[1] = iVar5;
      return 1;
    }
    puVar10[-3] = uVar12;
    if (iVar5 == 0) {
      iVar5 = (*(code *)puVar9[3])(param_1);
      if (iVar5 == 0) {
        return 0;
      }
      pbVar7 = (byte *)*puVar9;
      iVar5 = puVar9[1];
    }
    iVar5 = iVar5 + -1;
    pbVar8 = pbVar7 + 1;
    *puVar11 = (uint)*pbVar7;
    if (iVar5 == 0) {
      iVar5 = (*(code *)puVar9[3])(param_1);
      if (iVar5 == 0) {
        return 0;
      }
      pbVar8 = (byte *)*puVar9;
      iVar5 = puVar9[1];
    }
    iVar5 = iVar5 + -1;
    bVar3 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    puVar10[-2] = (uint)(bVar3 >> 4);
    puVar10[-1] = bVar3 & 0xf;
    if (iVar5 == 0) {
      iVar5 = (*(code *)puVar9[3])(param_1);
      if (iVar5 == 0) {
        return 0;
      }
      pbVar8 = (byte *)*puVar9;
      iVar5 = puVar9[1];
    }
    *puVar10 = (uint)*pbVar8;
    iVar4 = *param_1;
    *(uint *)(iVar4 + 0x18) = *puVar11;
    *(uint *)(iVar4 + 0x1c) = puVar10[-2];
    *(uint *)(iVar4 + 0x20) = puVar10[-1];
    *(uint *)(iVar4 + 0x24) = *puVar10;
    *(undefined4 *)(*param_1 + 0x14) = 0x5d;
    (**(code **)(*param_1 + 4))(param_1,1);
    uVar12 = uVar12 + 1;
    puVar10 = puVar10 + 0x14;
    puVar11 = puVar11 + 0x14;
  } while( true );
}
