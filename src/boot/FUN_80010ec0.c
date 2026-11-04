/* FUN_80010ec0
 * image   boot (boot), base 0x80000480
 * address 0x80010ec0  body 0x80010ec0..0x80011387  size 1224 B
 * body sha256 b60b979a1bd5a7b6faefd0a767e953f7327007b2f1b3d022af6a5f1bf6245a40
 * provider record sha256 25ec70df6be721346586e233375f00bb2abfeea499fe82b48cefbf6c447856f8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined8 FUN_80010ec0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined1 auStackX_0 [16];
  uint local_8;
  uint local_4;
  
  if (param_3 == 0) {
    if (param_1 < param_4) {
      if (param_4 < 0x10000) {
        iVar3 = (param_4 < 0x100 ^ 1) << 3;
      }
      else {
        iVar3 = 0x18;
        if (param_4 < 0x1000000) {
          iVar3 = 0x10;
        }
      }
      uVar10 = 0x20 - ((uint)*(byte *)((param_4 >> iVar3) + 0x80012000) + iVar3);
      if (uVar10 != 0) {
        param_4 = param_4 << (uVar10 & 0x1f);
        param_1 = param_1 << (uVar10 & 0x1f) | param_2 >> (0x20 - uVar10 & 0x1f);
        param_2 = param_2 << (uVar10 & 0x1f);
      }
    }
    else {
      if (param_4 == 0) {
        param_4 = 1 / 0;
        trap(0x1c00);
      }
      if (param_4 < 0x10000) {
        iVar3 = (param_4 < 0x100 ^ 1) << 3;
      }
      else {
        iVar3 = 0x18;
        if (param_4 < 0x1000000) {
          iVar3 = 0x10;
        }
      }
      uVar10 = 0x20 - ((uint)*(byte *)((param_4 >> iVar3) + 0x80012000) + iVar3);
      if (uVar10 == 0) {
        param_1 = param_1 - param_4;
      }
      else {
        param_4 = param_4 << (uVar10 & 0x1f);
        uVar7 = param_1 >> (0x20 - uVar10 & 0x1f);
        uVar4 = param_1 << (uVar10 & 0x1f) | param_2 >> (0x20 - uVar10 & 0x1f);
        uVar6 = param_4 >> 0x10;
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        uVar8 = (uVar7 / uVar6) * (param_4 & 0xffff);
        uVar7 = uVar7 % uVar6 << 0x10 | uVar4 >> 0x10;
        param_2 = param_2 << (uVar10 & 0x1f);
        if (uVar7 < uVar8) {
          uVar7 = uVar7 + param_4;
          if (param_4 <= uVar7) {
            if (uVar7 < uVar8) {
              uVar7 = uVar7 + param_4;
            }
            goto LAB_8001104c;
          }
          uVar7 = uVar7 - uVar8;
        }
        else {
LAB_8001104c:
          uVar7 = uVar7 - uVar8;
        }
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        uVar8 = (uVar7 / uVar6) * (param_4 & 0xffff);
        param_1 = uVar7 % uVar6 << 0x10 | uVar4 & 0xffff;
        if (param_1 < uVar8) {
          uVar7 = param_1 + param_4;
          param_1 = uVar7 - uVar8;
          if (param_4 <= uVar7) {
            if (uVar7 < uVar8) {
              uVar7 = uVar7 + param_4;
            }
            param_1 = uVar7 - uVar8;
          }
        }
        else {
          param_1 = param_1 - uVar8;
        }
      }
    }
    uVar7 = param_4 >> 0x10;
    if (uVar7 == 0) {
      trap(0x1c00);
    }
    uVar6 = (param_1 / uVar7) * (param_4 & 0xffff);
    uVar4 = param_1 % uVar7 << 0x10 | param_2 >> 0x10;
    if (uVar4 < uVar6) {
      uVar4 = uVar4 + param_4;
      if (uVar4 < param_4) {
        uVar4 = uVar4 - uVar6;
      }
      else {
        if (uVar4 < uVar6) {
          uVar4 = uVar4 + param_4;
        }
        uVar4 = uVar4 - uVar6;
      }
    }
    else {
      uVar4 = uVar4 - uVar6;
    }
    if (uVar7 == 0) {
      trap(0x1c00);
    }
    uVar6 = (uVar4 / uVar7) * (param_4 & 0xffff);
    uVar7 = uVar4 % uVar7 << 0x10 | param_2 & 0xffff;
    if (uVar7 < uVar6) {
      uVar7 = uVar7 + param_4;
      if ((param_4 <= uVar7) && (uVar7 < uVar6)) {
        uVar7 = uVar7 + param_4;
      }
    }
    if (auStackX_0 == (undefined1 *)0x8) goto LAB_80011374;
    param_2 = uVar7 - uVar6 >> (uVar10 & 0x1f);
    param_1 = 0;
  }
  else {
    if (param_1 < param_3) {
      local_8 = param_1;
      local_4 = param_2;
      goto LAB_80011374;
    }
    if (param_3 < 0x10000) {
      iVar3 = (param_3 < 0x100 ^ 1) << 3;
    }
    else {
      iVar3 = 0x18;
      if (param_3 < 0x1000000) {
        iVar3 = 0x10;
      }
    }
    uVar10 = 0x20 - ((uint)*(byte *)((param_3 >> iVar3) + 0x80012000) + iVar3);
    uVar7 = 0x20 - uVar10;
    if (uVar10 == 0) {
      if ((param_3 < param_1) || (param_4 <= param_2)) {
        param_1 = (param_1 - param_3) - (uint)(param_2 < param_2 - param_4);
        param_2 = param_2 - param_4;
      }
      if (auStackX_0 == (undefined1 *)0x8) goto LAB_80011374;
      goto LAB_8001136c;
    }
    uVar8 = param_3 << (uVar10 & 0x1f) | param_4 >> (uVar7 & 0x1f);
    param_4 = param_4 << (uVar10 & 0x1f);
    uVar6 = param_1 >> (uVar7 & 0x1f);
    uVar9 = param_1 << (uVar10 & 0x1f) | param_2 >> (uVar7 & 0x1f);
    uVar4 = uVar8 >> 0x10;
    uVar11 = uVar6 / uVar4;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    uVar1 = uVar11 * (uVar8 & 0xffff);
    uVar5 = uVar6 % uVar4 << 0x10 | uVar9 >> 0x10;
    param_2 = param_2 << (uVar10 & 0x1f);
    uVar6 = uVar11;
    if (uVar5 < uVar1) {
      uVar5 = uVar5 + uVar8;
      uVar6 = uVar11 - 1;
      if (uVar5 < uVar8) goto LAB_800112a4;
      if (uVar5 < uVar1) {
        uVar6 = uVar11 - 2;
        uVar5 = uVar5 + uVar8;
        goto LAB_800112a4;
      }
      uVar5 = uVar5 - uVar1;
    }
    else {
LAB_800112a4:
      uVar5 = uVar5 - uVar1;
    }
    uVar11 = uVar5 / uVar4;
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    uVar1 = uVar11 * (uVar8 & 0xffff);
    uVar4 = uVar5 % uVar4 << 0x10 | uVar9 & 0xffff;
    if (uVar4 < uVar1) {
      uVar5 = uVar4 + uVar8;
      uVar9 = uVar11 - 1;
      if (uVar8 <= uVar5) {
        uVar4 = uVar5 - uVar1;
        if (uVar1 <= uVar5) goto LAB_80011308;
        uVar9 = uVar11 - 2;
        uVar5 = uVar5 + uVar8;
      }
      uVar4 = uVar5 - uVar1;
    }
    else {
      uVar4 = uVar4 - uVar1;
      uVar9 = uVar11;
    }
LAB_80011308:
    lVar2 = (ulonglong)(uVar6 << 0x10 | uVar9) * (ulonglong)param_4;
    uVar9 = (uint)lVar2;
    uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
    if ((uVar4 < uVar6) || ((uVar6 == uVar4 && (param_2 < uVar9)))) {
      param_4 = uVar9 - param_4;
      lVar2 = CONCAT44((uVar6 - uVar8) - (uint)(uVar9 < param_4),param_4);
    }
    uVar6 = param_2 - (int)lVar2;
    if (auStackX_0 == (undefined1 *)0x8) goto LAB_80011374;
    param_1 = (uVar4 - (int)((ulonglong)lVar2 >> 0x20)) - (uint)(param_2 < uVar6);
    param_2 = param_1 << (uVar7 & 0x1f) | uVar6 >> (uVar10 & 0x1f);
    param_1 = param_1 >> (uVar10 & 0x1f);
  }
LAB_8001136c:
  local_8 = param_1;
  local_4 = param_2;
LAB_80011374:
  return CONCAT44(local_4,local_8);
}
