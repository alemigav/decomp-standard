/* FUN_80029fa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80029fa8  body 0x80029fa8..0x8002a4f7  size 1360 B
 * body sha256 e9f72e0b9cb84c114fa2f2759c850aaa2b872925e620091449631c476062b557
 * provider record sha256 4a3e35402eacc900179f86274b5b92d6942bd3489cafa648b45daba9e6f51224
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80029fa8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  uint local_40;
  int local_3c [4];
  int local_2c;
  
  iVar10 = *(int *)(param_1 + 0x178);
  if (((*(int *)(param_1 + 0xe8) != 0) && (*(int *)(iVar10 + 0x20) == 0)) &&
     (iVar1 = FUN_80029f08(), iVar1 == 0)) {
    return 0;
  }
  local_50 = *(undefined4 *)(param_1 + 0x160);
  iVar1 = 0;
  local_4c = **(undefined4 **)(param_1 + 0x14);
  local_48 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
  local_44 = *(int *)(iVar10 + 8);
  local_40 = *(uint *)(iVar10 + 0xc);
  local_3c[0] = *(int *)(iVar10 + 0x10);
  local_3c[1] = *(undefined4 *)(iVar10 + 0x14);
  local_3c[2] = *(undefined4 *)(iVar10 + 0x18);
  local_3c[3] = *(undefined4 *)(iVar10 + 0x1c);
  local_2c = param_1;
LAB_8002a070:
  do {
    if (*(int *)(param_1 + 0x134) <= iVar1) {
      *(undefined4 *)(param_1 + 0x160) = local_50;
      **(undefined4 **)(param_1 + 0x14) = local_4c;
      *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = local_48;
      *(int *)(iVar10 + 8) = local_44;
      *(uint *)(iVar10 + 0xc) = local_40;
      *(int *)(iVar10 + 0x10) = local_3c[0];
      *(int *)(iVar10 + 0x14) = local_3c[1];
      *(int *)(iVar10 + 0x18) = local_3c[2];
      *(int *)(iVar10 + 0x1c) = local_3c[3];
      *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + -1;
      return 1;
    }
    iVar9 = *(int *)(param_1 + iVar1 * 4 + 0x138);
    iVar7 = *(int *)(param_1 + iVar9 * 4 + 0x11c);
    puVar11 = *(undefined2 **)(iVar1 * 4 + param_2);
    iVar6 = *(int *)(iVar10 + *(int *)(iVar7 + 0x14) * 4 + 0x28);
    iVar8 = *(int *)(iVar10 + *(int *)(iVar7 + 0x18) * 4 + 0x38);
    if ((int)local_40 < 8) {
      iVar2 = FUN_80029c20(&local_50,0);
      if (iVar2 == 0) {
        return 0;
      }
      if (7 < (int)local_40) goto LAB_8002a0fc;
      uVar5 = 1;
LAB_8002a130:
      uVar3 = FUN_80029db4(&local_50,iVar6,uVar5);
      if ((int)uVar3 < 0) {
        return 0;
      }
    }
    else {
LAB_8002a0fc:
      uVar3 = local_44 >> (local_40 - 8 & 0x1f) & 0xff;
      iVar2 = *(int *)(iVar6 + uVar3 * 4 + 0xd4);
      if (iVar2 == 0) {
        uVar5 = 9;
        goto LAB_8002a130;
      }
      uVar3 = (uint)*(byte *)(iVar6 + uVar3 + 0x4d4);
      local_40 = local_40 - iVar2;
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      if (((int)local_40 < (int)uVar3) && (iVar6 = FUN_80029c20(&local_50,uVar3), iVar6 == 0)) {
        return 0;
      }
      local_40 = local_40 - uVar3;
      uVar4 = local_44 >> (local_40 & 0x1f) & (1 << (uVar3 & 0x1f)) - 1U;
      if ((int)uVar4 < *(int *)(&LAB_800b6d00 + uVar3 * 4)) {
        uVar4 = uVar4 + *(int *)(&DAT_800b6d40 + uVar3 * 4);
      }
    }
    if (*(int *)(iVar7 + 0x30) == 0) {
      iVar6 = 1;
LAB_8002a368:
      for (; iVar6 < 0x40; iVar6 = iVar6 + 1) {
        if ((int)local_40 < 8) {
          iVar7 = FUN_80029c20(&local_50,0);
          if (iVar7 == 0) {
            return 0;
          }
          if (7 < (int)local_40) goto LAB_8002a3b0;
          uVar5 = 1;
LAB_8002a3e4:
          uVar3 = FUN_80029db4(&local_50,iVar8,uVar5);
          if ((int)uVar3 < 0) {
            return 0;
          }
        }
        else {
LAB_8002a3b0:
          uVar3 = local_44 >> (local_40 - 8 & 0x1f) & 0xff;
          iVar7 = *(int *)(iVar8 + uVar3 * 4 + 0xd4);
          if (iVar7 == 0) {
            uVar5 = 9;
            goto LAB_8002a3e4;
          }
          uVar3 = (uint)*(byte *)(iVar8 + uVar3 + 0x4d4);
          local_40 = local_40 - iVar7;
        }
        uVar4 = uVar3 & 0xf;
        if (uVar4 == 0) {
          iVar6 = iVar6 + 0xf;
          if ((int)uVar3 >> 4 != 0xf) goto LAB_8002a460;
        }
        else {
          iVar6 = iVar6 + ((int)uVar3 >> 4);
          if (((int)local_40 < (int)uVar4) && (iVar7 = FUN_80029c20(&local_50,uVar4), iVar7 == 0)) {
            return 0;
          }
          local_40 = local_40 - uVar4;
        }
      }
      iVar1 = iVar1 + 1;
      goto LAB_8002a070;
    }
    iVar6 = local_3c[iVar9];
    local_3c[iVar9] = uVar4 + iVar6;
    *puVar11 = (short)(uVar4 + iVar6);
    iVar6 = 1;
    if (*(int *)(iVar7 + 0x24) < 2) goto LAB_8002a368;
    for (; iVar6 < 0x40; iVar6 = iVar6 + 1) {
      if ((int)local_40 < 8) {
        iVar7 = FUN_80029c20(&local_50,0);
        if (iVar7 == 0) {
          return 0;
        }
        if (7 < (int)local_40) goto LAB_8002a250;
        uVar5 = 1;
LAB_8002a284:
        uVar3 = FUN_80029db4(&local_50,iVar8,uVar5);
        if ((int)uVar3 < 0) {
          return 0;
        }
      }
      else {
LAB_8002a250:
        uVar3 = local_44 >> (local_40 - 8 & 0x1f) & 0xff;
        iVar7 = *(int *)(iVar8 + uVar3 * 4 + 0xd4);
        if (iVar7 == 0) {
          uVar5 = 9;
          goto LAB_8002a284;
        }
        uVar3 = (uint)*(byte *)(iVar8 + uVar3 + 0x4d4);
        local_40 = local_40 - iVar7;
      }
      uVar4 = uVar3 & 0xf;
      if (uVar4 == 0) {
        iVar6 = iVar6 + 0xf;
        if ((int)uVar3 >> 4 != 0xf) goto LAB_8002a460;
      }
      else {
        iVar6 = iVar6 + ((int)uVar3 >> 4);
        if (((int)local_40 < (int)uVar4) && (iVar7 = FUN_80029c20(&local_50,uVar4), iVar7 == 0)) {
          return 0;
        }
        local_40 = local_40 - uVar4;
        uVar3 = local_44 >> (local_40 & 0x1f) & (1 << uVar4) - 1U;
        if ((int)uVar3 < *(int *)(&LAB_800b6d00 + uVar4 * 4)) {
          uVar3 = uVar3 + *(int *)(&DAT_800b6d40 + uVar4 * 4);
        }
        puVar11[*(int *)(&LAB_800b6d80 + iVar6 * 4)] = (short)uVar3;
      }
    }
    iVar1 = iVar1 + 1;
  } while( true );
LAB_8002a460:
  iVar1 = iVar1 + 1;
  goto LAB_8002a070;
}
