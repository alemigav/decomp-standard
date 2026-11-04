/* FUN_80091a70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091a70  body 0x80091a70..0x80091c33  size 452 B
 * body sha256 84e2c2aa5542506e669508733d1b773de46c8bfbf8ff6c43c138573d361694b8
 * provider record sha256 4e45002ecd847635d97cf7a8b6bc81df036665f344910c263ffc3b0f1fceb202
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80091a70(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  switch(param_1) {
  case 0:
    if (param_2 < 0x18) {
      return param_2;
    }
    return param_2 - 0x14;
  case 2:
    uVar1 = 0x11;
    uVar2 = 0x16;
    break;
  case 3:
    if (param_2 == 0x1b) {
      return 0xe;
    }
    if (0x11 < param_2) {
      param_2 = param_2 - 1;
    }
    return param_2 - 8;
  case 4:
    if (param_2 != 0x17) {
      return param_2 - 0x10;
    }
    param_2 = 0x10;
    goto LAB_80091b0c;
  case 5:
    if (param_2 == 8) {
      return 2;
    }
    if (param_2 < 0x19) {
      if (param_2 < 0x11) {
        return param_2;
      }
      return param_2 - 0xe;
    }
LAB_80091b0c:
    return param_2 - 0x10;
  case 6:
    if (param_2 < 9) {
LAB_80091b78:
      return param_2 - 2;
    }
  case 10:
switchD_80091a8c_caseD_a:
    return param_2 - 3;
  case 7:
    uVar1 = 5;
    if (param_2 == 9) {
      return 4;
    }
    uVar2 = 0xb;
    break;
  case 8:
    if (param_2 < 2) {
      return param_2;
    }
    if (param_2 < 6) {
      return param_2 - 1;
    }
    if (param_2 < 9) goto LAB_80091b78;
    if (param_2 < 0xb) goto switchD_80091a8c_caseD_a;
    if (0x10 < param_2) {
      return param_2;
    }
  case 1:
    return param_2 - 4;
  case 9:
    uVar1 = 3;
    uVar2 = 8;
    break;
  case 0xb:
    if (param_2 == 3) {
      return 0;
    }
    return param_2 - 5;
  case 0xc:
    return (uint)(param_2 != 9);
  case 0xd:
  case 0x12:
    goto switchD_80091a8c_caseD_d;
  case 0xe:
  case 0xf:
    return 0;
  case 0x10:
    if (param_2 == 5) {
      return 0xc;
    }
    if (param_2 == 1) {
      return 0xb;
    }
    if (param_2 == 0x11) {
      return 2;
    }
    return param_2 - 6;
  case 0x11:
    if (param_2 == 0xe) {
      return 6;
    }
    return param_2 - 0x12;
  case 0x13:
    return (uint)(param_2 != 3);
  default:
    return 0;
  }
  if (param_2 == uVar2) {
    return uVar1;
  }
switchD_80091a8c_caseD_d:
  return param_2;
}
