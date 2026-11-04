/* FUN_80162cac
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80162cac  body 0x80162cac..0x8016342f  size 1924 B
 * body sha256 a9aab21898009faa0a2f7934475f6477f1f5c49f50daa9eac0d9e80e9964e1bc
 * provider record sha256 fa1e3b2b799ff6cc132e30aa0c1935fc2f128895718d8147f6637620a3527b30
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162cac(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  undefined2 uVar7;
  undefined4 uVar6;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    uVar3 = param_1[0x8d];
    param_1[0x7a] = 0x1001f00;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfd;
    *(undefined2 *)(*(int *)(uVar3 + 0x410) + 0xc) = 0;
    *(undefined2 *)(*(int *)(uVar3 + 0x410) + 0x10) = 0;
    *(undefined2 *)(*(int *)(uVar3 + 0x410) + 0x14) = 0;
    *(undefined2 *)(*(int *)(uVar3 + 0x410) + 0x18) = 0;
    uVar6 = 10;
    if ((param_1[0x9c] & 0x10000) == 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[10] = 0xffffdcd8;
    param_1[0xc] = 0xffffa498;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *param_1 = *param_1 & 0xfffffffd;
    DAT_80167500 = *(short *)(param_1[0x8d] + 0x22);
    *(undefined1 *)(param_1 + 0xad) = 3;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0;
    break;
  case 1:
    sVar4 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar4 + 1;
    if ((short)(sVar4 + 1) == 10) {
      piVar1 = (int *)(_DAT_800e13f4 + 0x234);
      *(undefined1 *)(_DAT_800e13f4 + 6) = 1;
      *(undefined2 *)(*piVar1 + 0x124) = 0;
    }
    sVar4 = *(short *)(param_1 + 0x7d);
    if (sVar4 == 0x1e) {
      piVar1 = (int *)(_DAT_800e13fc + 0x234);
      *(undefined1 *)(_DAT_800e13fc + 6) = 1;
      *(undefined2 *)(*piVar1 + 0x124) = 0;
      sVar4 = *(short *)(param_1 + 0x7d);
    }
    if (sVar4 == 0x28) {
      piVar1 = (int *)(_DAT_800e1400 + 0x234);
      *(undefined1 *)(_DAT_800e1400 + 6) = 1;
      *(undefined2 *)(*piVar1 + 0x124) = 0;
      func_0x80077d18(9,param_1);
    }
    if (*(short *)(param_1 + 0x7d) != 0x5a) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(undefined1 *)(_DAT_800e13f4 + 6) = 6;
    *(undefined1 *)(_DAT_800e13f8 + 6) = 6;
    *(undefined1 *)(_DAT_800e13fc + 6) = 6;
    *(undefined1 *)(_DAT_800e1400 + 6) = 6;
    func_0x80077d18(0xb,param_1);
    uVar6 = 10;
    break;
  case 2:
    func_0x800334c8(param_1,param_2,param_3,0);
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    func_0x80032b5c(param_1,0);
    *(short *)(*(int *)(param_1[0x8d] + 0x410) + 0x10) =
         (short)((uint)((*(int *)(param_1[0x8d] + 0x20) - (int)DAT_80167500) * 0x113f) >> 0xb);
    return;
  case 3:
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined1 *)((int)param_1 + 6) = 4;
    param_1[0x7a] = 0x3001f00;
    func_0x80077d18(9,param_1);
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    if (*(short *)(param_1 + 0x7d) == 0x1e) {
      *(undefined1 *)(_DAT_800e13f4 + 6) = 8;
      *(undefined1 *)(_DAT_800e13f8 + 6) = 8;
      *(undefined1 *)(_DAT_800e13fc + 6) = 8;
      *(undefined1 *)(_DAT_800e1400 + 6) = 8;
      func_0x80077d18(0,param_1);
    }
    sVar4 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar4 + 1;
    uVar6 = 10;
    if ((short)(sVar4 + 1) != 0x5a) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 5;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    break;
  case 5:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    sVar4 = *(short *)(param_1 + 0x7d);
    if (sVar4 == 0x14) {
      *(undefined4 *)(_DAT_800e13f4 + 4) = 0x1090000;
      func_0x80077d18(0,param_1);
      sVar4 = *(short *)(param_1 + 0x7d);
    }
    if (sVar4 == 0x28) {
      *(undefined4 *)(_DAT_800e13f8 + 4) = 0x1090000;
      func_0x80077d18(0,param_1);
    }
    sVar4 = *(short *)(param_1 + 0x7d);
    if (sVar4 == 0x2d) {
      *(undefined4 *)(_DAT_800e13fc + 4) = 0x1090000;
      func_0x80077d18(0,param_1);
      sVar4 = *(short *)(param_1 + 0x7d);
    }
    if (sVar4 == 0x38) {
      *(undefined4 *)(_DAT_800e1400 + 4) = 0x1090000;
      func_0x80077d18(0,param_1);
    }
    sVar4 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar4 + 1;
    if ((short)(sVar4 + 1) != 0x6e) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 6;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    param_1[0x7a] = 0x4001f00;
    *(undefined1 *)(_DAT_800e13f4 + 6) = 7;
    *(undefined1 *)(_DAT_800e13f8 + 6) = 7;
    uVar6 = 0xb;
    *(undefined1 *)(_DAT_800e13fc + 6) = 7;
    *(undefined1 *)(_DAT_800e1400 + 6) = 7;
    break;
  case 6:
    func_0x800334c8(param_1,param_2,param_3,0);
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    func_0x80032b5c(param_1,0);
    iVar5 = *(int *)(param_1[0x8d] + 0x20) - (int)DAT_80167500;
    uVar7 = 0;
    if (iVar5 != 0) {
      uVar7 = (undefined2)(iVar5 * 0x227e >> 0xc);
    }
    *(undefined2 *)(*(int *)(param_1[0x8d] + 0x410) + 0x10) = uVar7;
    return;
  case 7:
    *(undefined2 *)(*(int *)(param_1[0x8d] + 0x410) + 0x10) = 0;
    param_1[0x7a] = 0x2001f00;
    *(undefined1 *)((int)param_1 + 6) = 8;
    *(undefined1 *)(_DAT_800e13f4 + 6) = 9;
    *(undefined1 *)(_DAT_800e13f8 + 6) = 9;
    *(undefined1 *)(_DAT_800e13fc + 6) = 9;
    *(undefined1 *)(_DAT_800e1400 + 6) = 9;
    goto LAB_8016335c;
  case 8:
  case 0xc:
    goto switchD_80162cf8_caseD_8;
  case 9:
    param_1[0x7a] = 0x1f00;
    *(undefined1 *)((int)param_1 + 6) = 10;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    func_0x80077d18(9,param_1);
  case 10:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    sVar4 = *(short *)(param_1 + 0x7d);
    if (sVar4 == 0x14) {
      *(undefined4 *)(_DAT_800e13f4 + 4) = 0x10a0000;
      func_0x80077d18(0,param_1);
      sVar4 = *(short *)(param_1 + 0x7d);
    }
    if (sVar4 == 0x23) {
      *(undefined4 *)(_DAT_800e13fc + 4) = 0x10a0000;
      func_0x80077d18(0,param_1);
    }
    sVar4 = *(short *)(param_1 + 0x7d);
    if (sVar4 == 0x28) {
      *(undefined4 *)(_DAT_800e13f8 + 4) = 0x10a0000;
      func_0x80077d18(0,param_1);
      sVar4 = *(short *)(param_1 + 0x7d);
    }
    if (sVar4 == 0x32) {
      *(undefined4 *)(_DAT_800e1400 + 4) = 0x10a0000;
      func_0x80077d18(0,param_1);
    }
    sVar4 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar4 + 1;
    if ((short)(sVar4 + 1) == 0x6e) {
      *(undefined1 *)((int)param_1 + 6) = 0xb;
      return;
    }
    return;
  case 0xb:
    param_1[0x7a] = 0x2001f00;
    *(undefined1 *)((int)param_1 + 6) = 0xc;
    *(undefined4 *)(_DAT_800e13f4 + 4) = 0x10a0400;
    *(undefined4 *)(_DAT_800e13fc + 4) = 0x10a0400;
LAB_8016335c:
    func_0x80077d18(10,param_1);
switchD_80162cf8_caseD_8:
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    return;
  case 0xd:
    param_1[0x7a] = 0x1f00;
    *(undefined1 *)((int)param_1 + 6) = 0xe;
    *(undefined1 *)(param_1 + 0xad) = 0;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0;
    *(undefined2 *)(param_1 + 0x7d) = 0x3c;
    func_0x80077d18(9,param_1);
    FUN_8016676c(0x601);
  case 0xe:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    sVar4 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar4 + -1;
    if ((short)(sVar4 + -1) != -1) {
      return;
    }
    param_1[1] = 0x1010000;
    *(undefined1 *)(param_1 + 0x97) = 0;
    func_0x80077d18(10,param_1);
    uVar6 = 9;
    break;
  default:
    goto switchD_80162cf8_default;
  }
  func_0x80077d18(uVar6,param_1);
switchD_80162cf8_default:
  return;
}
