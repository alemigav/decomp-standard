/* FUN_80034280
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80034280  body 0x80034280..0x800347af  size 1328 B
 * body sha256 7fd7abf1982cdae99c639430f663f684a72a769b6794efc87645e913ddb4e01e
 * provider record sha256 fe7913f69c2cd0169abadf5464b8586f3172a2d1fa9102e9b435b9c8e8ac809b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80034280(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  undefined2 local_30;
  ushort local_2e;
  ushort local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  if ((*(byte *)(param_1 + 0x25c) & 1) == 0) {
    iVar8 = *(int *)(param_1 + 0x254);
    uVar1 = *(ushort *)(*(int *)(param_1 + 0x234) + 0x5a);
    iVar2 = *(int *)(iVar8 + 0x234) + (uint)*(byte *)(iVar8 + 0x25d) * 0x178;
    local_28 = *(int *)(iVar2 + 0x4c);
    local_24 = *(int *)(iVar2 + 0x50);
    local_20 = *(int *)(iVar2 + 0x54);
    local_1c = *(undefined4 *)(iVar2 + 0x58);
    iVar2 = *(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178;
    if ((*(byte *)(param_1 + 0x25c) & 4) != 0) {
      local_24 = (int)*(short *)(param_1 + 0x20e);
      local_28 = (int)*(short *)(param_1 + 0x20c);
      local_20 = (int)*(short *)(param_1 + 0x210);
      if (*(short *)(param_1 + 0x20e) == -0x8000) {
        iVar3 = *(int *)((&DAT_800e13e8)[local_28] + 0x234) +
                (uint)*(byte *)((&DAT_800e13e8)[local_28] + 0x25d) * 0x178;
        if (local_28 == 0x15) {
          iVar3 = *(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178;
        }
        local_28 = *(int *)(iVar3 + 0x4c);
        local_24 = *(int *)(iVar3 + 0x50);
        local_20 = *(int *)(iVar3 + 0x54);
        local_1c = *(undefined4 *)(iVar3 + 0x58);
      }
    }
    FUN_80034bdc(iVar2 + 0x4c,&local_28,&local_30,(int)((param_2 + (uint)uVar1) * 0x10000) >> 0x10);
    sVar7 = (short)param_2;
    if ((*(byte *)(param_1 + 0x25c) & 8) != 0) {
      local_30 = 0;
      local_2e = uVar1 + *(short *)(param_1 + 0x20e) + sVar7;
      local_2c = *(ushort *)(param_1 + 0x210);
    }
    if ((*(byte *)(param_1 + 0x25c) & 0x40) != 0) {
      if (*(short *)(param_1 + 0x210) == 0) {
        *(undefined2 *)(param_1 + 0x210) = 1;
        *(ushort *)(param_1 + 0x20e) = uVar1 + *(short *)(iVar2 + 0x138) + sVar7 + -0x80;
      }
      local_2e = *(ushort *)(param_1 + 0x20e);
    }
    if ((*(byte *)(param_1 + 0x25c) & 2) != 0) {
      local_2e = uVar1 + sVar7 + *(short *)(iVar2 + 0x5a);
    }
    if ((*(byte *)(param_1 + 0x25c) & 0x10) != 0) {
      local_2c = *(ushort *)(iVar2 + 0x5c);
    }
    if ((param_1 == iVar8) && ((*(byte *)(param_1 + 0x25c) & 0x80) == 0)) {
      local_2e = uVar1 + sVar7 + *(short *)(iVar2 + 0x5a);
      local_2c = *(ushort *)(iVar2 + 0x5c);
    }
    uVar4 = (uint)*(ushort *)(iVar2 + 0x134);
    sVar6 = *(short *)(iVar2 + 0x138);
    if ((*(byte *)(param_1 + 0x25c) & 0x80) != 0) {
      uVar4 = (uint)*(byte *)(iVar2 + 0x13c);
    }
    uVar5 = ((int)(short)local_2e - (int)sVar7) - (int)(short)uVar1;
    if ((int)sVar6 << 1 < (int)(uVar5 + (int)sVar6 & 0xfff)) {
      if ((uVar5 & 0x800) != 0) {
        sVar6 = -sVar6;
      }
      local_2e = sVar7 + uVar1 + sVar6;
    }
    sVar6 = *(ushort *)(iVar2 + 0x130) - (short)uVar4;
    uVar5 = uVar4 + ((uint)local_2e -
                    ((uint)*(ushort *)(iVar2 + 0x130) +
                    (uint)uVar1 + param_2 + (uint)*(ushort *)(iVar2 + 0x5a)));
    *(short *)(iVar2 + 0x130) = sVar6;
    if ((uVar5 & 0x800) == 0) {
      *(short *)(iVar2 + 0x130) = sVar6 + (short)uVar4 * 2;
    }
    if (((int)(uVar5 & 0xfff) < (int)(uVar4 << 0x10) >> 0xf) &&
       (*(ushort *)(iVar2 + 0x130) = local_2e - (uVar1 + sVar7 + *(short *)(iVar2 + 0x5a)),
       (*(byte *)(param_1 + 0x25c) & 0x40) != 0)) {
      sVar6 = *(short *)(param_1 + 0x20c);
      *(short *)(param_1 + 0x20c) = sVar6 + -1;
      if (sVar6 == 1) {
        *(undefined1 *)(param_1 + 0x25c) = 0x12;
      }
      *(ushort *)(param_1 + 0x20e) = uVar1 * 2 + ((sVar7 * 2 + 0x80) - *(short *)(param_1 + 0x20e));
    }
    *(short *)(iVar2 + 0x5a) = *(short *)(iVar2 + 0x5a) + *(short *)(iVar2 + 0x130);
    if ((*(byte *)(param_1 + 0x25c) & 0x20) != 0) {
      if (*(short *)(param_1 + 0x210) == 0) {
        *(undefined2 *)(param_1 + 0x210) = 1;
        *(undefined2 *)(param_1 + 0x20e) = *(undefined2 *)(iVar2 + 0x13a);
      }
      local_2c = *(ushort *)(param_1 + 0x20e);
    }
    uVar4 = (uint)*(ushort *)(iVar2 + 0x136);
    uVar1 = *(ushort *)(iVar2 + 0x13a);
    if ((*(byte *)(param_1 + 0x25c) & 0x80) != 0) {
      uVar4 = (uint)*(byte *)(iVar2 + 0x13d);
    }
    if ((int)(short)uVar1 << 1 < (int)((int)(short)local_2c + (int)(short)uVar1 & 0xfffU)) {
      if ((local_2c & 0x800) == 0) {
        local_2c = uVar1;
      }
      else {
        local_2c = -uVar1;
      }
    }
    sVar7 = *(ushort *)(iVar2 + 0x132) - (short)uVar4;
    uVar5 = uVar4 + ((uint)local_2c -
                    ((uint)*(ushort *)(iVar2 + 0x5c) + (uint)*(ushort *)(iVar2 + 0x132)));
    *(short *)(iVar2 + 0x132) = sVar7;
    if ((uVar5 & 0x800) == 0) {
      *(short *)(iVar2 + 0x132) = sVar7 + (short)uVar4 * 2;
    }
    if (((int)(uVar5 & 0xfff) < (int)(uVar4 << 0x10) >> 0xf) &&
       (*(ushort *)(iVar2 + 0x132) = local_2c - *(short *)(iVar2 + 0x5c),
       (*(byte *)(param_1 + 0x25c) & 0x20) != 0)) {
      if (local_2c != 0) {
        sVar7 = *(short *)(param_1 + 0x20c);
        *(short *)(param_1 + 0x20c) = sVar7 + -1;
        if (sVar7 == 1) {
          *(undefined1 *)(param_1 + 0x25c) = 0x12;
          *(undefined2 *)(param_1 + 0x20e) = 0;
        }
        else {
          *(undefined2 *)(param_1 + 0x20e) = 0;
        }
      }
      if (((*(byte *)(param_1 + 0x25c) & 0x20) != 0) && (local_2c == 0)) {
        *(undefined2 *)(param_1 + 0x20e) = *(undefined2 *)(iVar2 + 0x13a);
      }
    }
    *(short *)(iVar2 + 0x5c) = *(short *)(iVar2 + 0x5c) + *(short *)(iVar2 + 0x132);
    FUN_80040e58(iVar2 + 0x58,iVar2 + 8);
    *(short *)(iVar2 + 0x5a) = *(short *)(iVar2 + 0x5a) - *(short *)(iVar2 + 0x130);
    *(short *)(iVar2 + 0x5c) = *(short *)(iVar2 + 0x5c) - *(short *)(iVar2 + 0x132);
  }
  return;
}
