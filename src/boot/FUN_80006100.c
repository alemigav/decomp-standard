/* FUN_80006100
 * image   boot (boot), base 0x80000480
 * address 0x80006100  body 0x80006100..0x8000664f  size 1360 B
 * body sha256 af3516d7b5184f1be746976678c882f0d7d80ed696f698e005f8f7b10b34831b
 * provider record sha256 6d086065e807e3cae41303e8031f78a34855d69a66c6914a6237a4b02f73c8d7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined8 FUN_80006100(uint param_1,uint param_2,uint param_3,uint param_4)

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
  
  if (param_3 == 0) {
    if (param_4 <= param_1) {
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
      uVar5 = 0x20 - ((uint)*(byte *)((param_4 >> iVar3) + 0x800119c0) + iVar3);
      if (uVar5 == 0) {
        param_1 = param_1 - param_4;
        uVar8 = 1;
      }
      else {
        param_4 = param_4 << (uVar5 & 0x1f);
        uVar10 = param_1 >> (0x20 - uVar5 & 0x1f);
        uVar9 = param_1 << (uVar5 & 0x1f) | param_2 >> (0x20 - uVar5 & 0x1f);
        param_2 = param_2 << (uVar5 & 0x1f);
        uVar5 = param_4 >> 0x10;
        uVar4 = uVar10 / uVar5;
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        uVar8 = uVar4 * (param_4 & 0xffff);
        uVar10 = uVar10 % uVar5 << 0x10 | uVar9 >> 0x10;
        if (uVar10 < uVar8) {
          uVar10 = uVar10 + param_4;
          uVar6 = uVar4 - 1;
          if (param_4 <= uVar10) {
            if (uVar8 <= uVar10) {
              uVar10 = uVar10 - uVar8;
              goto LAB_80006358;
            }
            uVar6 = uVar4 - 2;
            uVar10 = uVar10 + param_4;
          }
          uVar10 = uVar10 - uVar8;
        }
        else {
          uVar10 = uVar10 - uVar8;
          uVar6 = uVar4;
        }
LAB_80006358:
        uVar4 = uVar10 / uVar5;
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        uVar1 = uVar4 * (param_4 & 0xffff);
        param_1 = uVar10 % uVar5 << 0x10 | uVar9 & 0xffff;
        uVar8 = uVar4;
        if (param_1 < uVar1) {
          param_1 = param_1 + param_4;
          uVar8 = uVar4 - 1;
          if ((param_4 <= param_1) && (param_1 < uVar1)) {
            uVar8 = uVar4 - 2;
            param_1 = param_1 + param_4;
          }
        }
        uVar8 = uVar6 << 0x10 | uVar8;
        param_1 = param_1 - uVar1;
      }
      uVar5 = param_4 >> 0x10;
      uVar9 = param_1 / uVar5;
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      uVar10 = uVar9 * (param_4 & 0xffff);
      uVar4 = param_1 % uVar5 << 0x10 | param_2 >> 0x10;
      if (uVar4 < uVar10) {
        uVar4 = uVar4 + param_4;
        uVar6 = uVar9 - 1;
        if (param_4 <= uVar4) {
          if (uVar10 <= uVar4) {
            uVar4 = uVar4 - uVar10;
            goto LAB_80006428;
          }
          uVar6 = uVar9 - 2;
          uVar4 = uVar4 + param_4;
        }
        uVar4 = uVar4 - uVar10;
      }
      else {
        uVar4 = uVar4 - uVar10;
        uVar6 = uVar9;
      }
LAB_80006428:
      uVar10 = uVar4 / uVar5;
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      uVar1 = uVar10 * (param_4 & 0xffff);
      uVar5 = uVar4 % uVar5 << 0x10 | param_2 & 0xffff;
      uVar9 = uVar10;
      if (uVar5 < uVar1) {
        uVar5 = uVar5 + param_4;
        uVar9 = uVar10 - 1;
        if ((param_4 <= uVar5) && (uVar5 < uVar1)) {
          uVar9 = uVar10 - 2;
        }
      }
      uVar9 = uVar6 << 0x10 | uVar9;
      goto LAB_80006640;
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
    uVar5 = 0x20 - ((uint)*(byte *)((param_4 >> iVar3) + 0x800119c0) + iVar3);
    if (uVar5 != 0) {
      param_4 = param_4 << (uVar5 & 0x1f);
      param_1 = param_1 << (uVar5 & 0x1f) | param_2 >> (0x20 - uVar5 & 0x1f);
      param_2 = param_2 << (uVar5 & 0x1f);
    }
    uVar5 = param_4 >> 0x10;
    uVar9 = param_1 / uVar5;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    uVar10 = uVar9 * (param_4 & 0xffff);
    uVar4 = param_1 % uVar5 << 0x10 | param_2 >> 0x10;
    if (uVar4 < uVar10) {
      uVar4 = uVar4 + param_4;
      uVar8 = uVar9 - 1;
      if (param_4 <= uVar4) {
        if (uVar10 <= uVar4) {
          uVar4 = uVar4 - uVar10;
          goto LAB_800061f0;
        }
        uVar8 = uVar9 - 2;
        uVar4 = uVar4 + param_4;
      }
      uVar4 = uVar4 - uVar10;
    }
    else {
      uVar4 = uVar4 - uVar10;
      uVar8 = uVar9;
    }
LAB_800061f0:
    uVar10 = uVar4 / uVar5;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    uVar6 = uVar10 * (param_4 & 0xffff);
    uVar5 = uVar4 % uVar5 << 0x10 | param_2 & 0xffff;
    uVar9 = uVar10;
    if (uVar5 < uVar6) {
      uVar5 = uVar5 + param_4;
      uVar9 = uVar10 - 1;
      if ((param_4 <= uVar5) && (uVar5 < uVar6)) {
        uVar9 = uVar10 - 2;
      }
    }
    uVar9 = uVar8 << 0x10 | uVar9;
  }
  else if (param_1 < param_3) {
    uVar9 = 0;
  }
  else {
    if (param_3 < 0x10000) {
      iVar3 = (param_3 < 0x100 ^ 1) << 3;
    }
    else {
      iVar3 = 0x18;
      if (param_3 < 0x1000000) {
        iVar3 = 0x10;
      }
    }
    uVar5 = 0x20 - ((uint)*(byte *)((param_3 >> iVar3) + 0x800119c0) + iVar3);
    if (uVar5 == 0) {
      uVar9 = 1;
      if ((param_1 <= param_3) && (uVar9 = 0, param_4 <= param_2)) {
        uVar9 = 1;
      }
    }
    else {
      uVar9 = 0x20 - uVar5;
      uVar8 = param_3 << (uVar5 & 0x1f) | param_4 >> (uVar9 & 0x1f);
      uVar4 = param_1 >> (uVar9 & 0x1f);
      uVar9 = param_1 << (uVar5 & 0x1f) | param_2 >> (uVar9 & 0x1f);
      uVar10 = uVar8 >> 0x10;
      uVar6 = uVar4 / uVar10;
      if (uVar10 == 0) {
        trap(0x1c00);
      }
      uVar1 = uVar6 * (uVar8 & 0xffff);
      uVar4 = uVar4 % uVar10 << 0x10 | uVar9 >> 0x10;
      if (uVar4 < uVar1) {
        uVar4 = uVar4 + uVar8;
        uVar7 = uVar6 - 1;
        if (uVar8 <= uVar4) {
          if (uVar1 <= uVar4) {
            uVar4 = uVar4 - uVar1;
            goto LAB_800065a0;
          }
          uVar7 = uVar6 - 2;
          uVar4 = uVar4 + uVar8;
        }
        uVar4 = uVar4 - uVar1;
      }
      else {
        uVar4 = uVar4 - uVar1;
        uVar7 = uVar6;
      }
LAB_800065a0:
      uVar6 = uVar4 / uVar10;
      if (uVar10 == 0) {
        trap(0x1c00);
      }
      uVar1 = uVar6 * (uVar8 & 0xffff);
      uVar10 = uVar4 % uVar10 << 0x10 | uVar9 & 0xffff;
      uVar9 = uVar6;
      if (uVar10 < uVar1) {
        uVar10 = uVar10 + uVar8;
        uVar9 = uVar6 - 1;
        if ((uVar8 <= uVar10) && (uVar10 < uVar1)) {
          uVar9 = uVar6 - 2;
          uVar10 = uVar10 + uVar8;
        }
      }
      uVar9 = uVar7 << 0x10 | uVar9;
      lVar2 = (ulonglong)uVar9 * (ulonglong)(param_4 << (uVar5 & 0x1f));
      uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
      if (uVar10 - uVar1 < uVar4) {
        uVar9 = uVar9 - 1;
      }
      else {
        uVar8 = 0;
        if ((uVar4 != uVar10 - uVar1) || ((uint)lVar2 <= param_2 << (uVar5 & 0x1f)))
        goto LAB_80006640;
        uVar9 = uVar9 - 1;
      }
    }
  }
  uVar8 = 0;
LAB_80006640:
  return CONCAT44(uVar9,uVar8);
}
