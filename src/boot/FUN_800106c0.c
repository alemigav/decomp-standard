/* FUN_800106c0
 * image   boot (boot), base 0x80000480
 * address 0x800106c0  body 0x800106c0..0x80010c6f  size 1456 B
 * body sha256 f22b47d260891f52df1fd3969571bd2620b07cf2c2e28498da9cc17144e08a08
 * provider record sha256 0b3588ca2fc91276d976632174c865c7c3cea62ab16cd8c8219364531adbd4c2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined8 FUN_800106c0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar9 = 0;
  if ((int)param_1 < 0) {
    uVar9 = 0xffffffff;
    param_2 = -param_2;
    param_1 = -(uint)(param_2 != 0) - param_1;
  }
  if ((int)param_3 < 0) {
    uVar9 = ~uVar9;
    param_4 = -param_4;
    param_3 = -(uint)(param_4 != 0) - param_3;
  }
  if (param_3 == 0) {
    if (param_4 <= param_1) {
      if (param_4 == 0) {
        param_4 = 1 / 0;
        trap(0x1c00);
      }
      if (param_4 < 0x10000) {
        iVar6 = (param_4 < 0x100 ^ 1) << 3;
      }
      else {
        iVar6 = 0x18;
        if (param_4 < 0x1000000) {
          iVar6 = 0x10;
        }
      }
      uVar4 = 0x20 - ((uint)*(byte *)((param_4 >> iVar6) + 0x80011f00) + iVar6);
      if (uVar4 == 0) {
        param_1 = param_1 - param_4;
        uVar8 = 1;
      }
      else {
        param_4 = param_4 << (uVar4 & 0x1f);
        uVar11 = param_1 >> (0x20 - uVar4 & 0x1f);
        uVar10 = param_1 << (uVar4 & 0x1f) | param_2 >> (0x20 - uVar4 & 0x1f);
        param_2 = param_2 << (uVar4 & 0x1f);
        uVar4 = param_4 >> 0x10;
        uVar3 = uVar11 / uVar4;
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        uVar8 = uVar3 * (param_4 & 0xffff);
        uVar11 = uVar11 % uVar4 << 0x10 | uVar10 >> 0x10;
        if (uVar11 < uVar8) {
          uVar11 = uVar11 + param_4;
          uVar5 = uVar3 - 1;
          if (param_4 <= uVar11) {
            if (uVar8 <= uVar11) {
              uVar11 = uVar11 - uVar8;
              goto LAB_8001095c;
            }
            uVar5 = uVar3 - 2;
            uVar11 = uVar11 + param_4;
          }
          uVar11 = uVar11 - uVar8;
        }
        else {
          uVar11 = uVar11 - uVar8;
          uVar5 = uVar3;
        }
LAB_8001095c:
        uVar3 = uVar11 / uVar4;
        if (uVar4 == 0) {
          trap(0x1c00);
        }
        uVar1 = uVar3 * (param_4 & 0xffff);
        param_1 = uVar11 % uVar4 << 0x10 | uVar10 & 0xffff;
        uVar8 = uVar3;
        if (param_1 < uVar1) {
          param_1 = param_1 + param_4;
          uVar8 = uVar3 - 1;
          if ((param_4 <= param_1) && (param_1 < uVar1)) {
            uVar8 = uVar3 - 2;
            param_1 = param_1 + param_4;
          }
        }
        uVar8 = uVar5 << 0x10 | uVar8;
        param_1 = param_1 - uVar1;
      }
      uVar4 = param_4 >> 0x10;
      uVar10 = param_1 / uVar4;
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      uVar11 = uVar10 * (param_4 & 0xffff);
      uVar3 = param_1 % uVar4 << 0x10 | param_2 >> 0x10;
      if (uVar3 < uVar11) {
        uVar3 = uVar3 + param_4;
        uVar5 = uVar10 - 1;
        if (param_4 <= uVar3) {
          if (uVar11 <= uVar3) {
            uVar3 = uVar3 - uVar11;
            goto LAB_80010a2c;
          }
          uVar5 = uVar10 - 2;
          uVar3 = uVar3 + param_4;
        }
        uVar3 = uVar3 - uVar11;
      }
      else {
        uVar3 = uVar3 - uVar11;
        uVar5 = uVar10;
      }
LAB_80010a2c:
      uVar11 = uVar3 / uVar4;
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      uVar1 = uVar11 * (param_4 & 0xffff);
      uVar4 = uVar3 % uVar4 << 0x10 | param_2 & 0xffff;
      uVar3 = uVar4 + param_4;
      uVar10 = uVar11;
      if (((uVar4 < uVar1) && (uVar10 = uVar11 - 1, param_4 <= uVar3)) && (uVar3 < uVar1)) {
        uVar10 = uVar11 - 2;
      }
      uVar10 = uVar5 << 0x10 | uVar10;
      goto LAB_80010c40;
    }
    if (param_4 < 0x10000) {
      iVar6 = (param_4 < 0x100 ^ 1) << 3;
    }
    else {
      iVar6 = 0x18;
      if (param_4 < 0x1000000) {
        iVar6 = 0x10;
      }
    }
    uVar4 = 0x20 - ((uint)*(byte *)((param_4 >> iVar6) + 0x80011f00) + iVar6);
    if (uVar4 != 0) {
      param_4 = param_4 << (uVar4 & 0x1f);
      param_1 = param_1 << (uVar4 & 0x1f) | param_2 >> (0x20 - uVar4 & 0x1f);
      param_2 = param_2 << (uVar4 & 0x1f);
    }
    uVar4 = param_4 >> 0x10;
    uVar10 = param_1 / uVar4;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    uVar11 = uVar10 * (param_4 & 0xffff);
    uVar3 = param_1 % uVar4 << 0x10 | param_2 >> 0x10;
    if (uVar3 < uVar11) {
      uVar3 = uVar3 + param_4;
      uVar8 = uVar10 - 1;
      if (param_4 <= uVar3) {
        if (uVar11 <= uVar3) {
          uVar3 = uVar3 - uVar11;
          goto LAB_800107f8;
        }
        uVar8 = uVar10 - 2;
        uVar3 = uVar3 + param_4;
      }
      uVar3 = uVar3 - uVar11;
    }
    else {
      uVar3 = uVar3 - uVar11;
      uVar8 = uVar10;
    }
LAB_800107f8:
    uVar11 = uVar3 / uVar4;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    uVar5 = uVar11 * (param_4 & 0xffff);
    uVar4 = uVar3 % uVar4 << 0x10 | param_2 & 0xffff;
    uVar3 = uVar4 + param_4;
    uVar10 = uVar11;
    if (((uVar4 < uVar5) && (uVar10 = uVar11 - 1, param_4 <= uVar3)) && (uVar3 < uVar5)) {
      uVar10 = uVar11 - 2;
    }
    uVar10 = uVar8 << 0x10 | uVar10;
  }
  else if (param_1 < param_3) {
    uVar10 = 0;
  }
  else {
    if (param_3 < 0x10000) {
      iVar6 = (param_3 < 0x100 ^ 1) << 3;
    }
    else {
      iVar6 = 0x18;
      if (param_3 < 0x1000000) {
        iVar6 = 0x10;
      }
    }
    uVar4 = 0x20 - ((uint)*(byte *)((param_3 >> iVar6) + 0x80011f00) + iVar6);
    if (uVar4 == 0) {
      uVar10 = 1;
      if ((param_1 <= param_3) && (uVar10 = 0, param_4 <= param_2)) {
        uVar10 = 1;
      }
    }
    else {
      uVar10 = 0x20 - uVar4;
      uVar8 = param_3 << (uVar4 & 0x1f) | param_4 >> (uVar10 & 0x1f);
      uVar3 = param_1 >> (uVar10 & 0x1f);
      uVar10 = param_1 << (uVar4 & 0x1f) | param_2 >> (uVar10 & 0x1f);
      uVar11 = uVar8 >> 0x10;
      uVar5 = uVar3 / uVar11;
      if (uVar11 == 0) {
        trap(0x1c00);
      }
      uVar1 = uVar5 * (uVar8 & 0xffff);
      uVar3 = uVar3 % uVar11 << 0x10 | uVar10 >> 0x10;
      if (uVar3 < uVar1) {
        uVar3 = uVar3 + uVar8;
        uVar7 = uVar5 - 1;
        if (uVar8 <= uVar3) {
          if (uVar1 <= uVar3) {
            uVar3 = uVar3 - uVar1;
            goto LAB_80010ba0;
          }
          uVar7 = uVar5 - 2;
          uVar3 = uVar3 + uVar8;
        }
        uVar3 = uVar3 - uVar1;
      }
      else {
        uVar3 = uVar3 - uVar1;
        uVar7 = uVar5;
      }
LAB_80010ba0:
      uVar5 = uVar3 / uVar11;
      if (uVar11 == 0) {
        trap(0x1c00);
      }
      uVar1 = uVar5 * (uVar8 & 0xffff);
      uVar11 = uVar3 % uVar11 << 0x10 | uVar10 & 0xffff;
      uVar10 = uVar5;
      if (uVar11 < uVar1) {
        uVar11 = uVar11 + uVar8;
        uVar10 = uVar5 - 1;
        if ((uVar8 <= uVar11) && (uVar11 < uVar1)) {
          uVar10 = uVar5 - 2;
          uVar11 = uVar11 + uVar8;
        }
      }
      uVar10 = uVar7 << 0x10 | uVar10;
      lVar2 = (ulonglong)uVar10 * (ulonglong)(param_4 << (uVar4 & 0x1f));
      uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
      if (uVar11 - uVar1 < uVar3) {
        uVar10 = uVar10 - 1;
      }
      else {
        uVar8 = 0;
        if ((uVar3 != uVar11 - uVar1) || ((uint)lVar2 <= param_2 << (uVar4 & 0x1f)))
        goto LAB_80010c40;
        uVar10 = uVar10 - 1;
      }
    }
  }
  uVar8 = 0;
LAB_80010c40:
  if (uVar9 != 0) {
    uVar10 = -uVar10;
    uVar8 = -(uint)(uVar10 != 0) - uVar8;
  }
  return CONCAT44(uVar10,uVar8);
}
