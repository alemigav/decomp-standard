/* FUN_80162db4
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80162db4  body 0x80162db4..0x8016353b  size 1928 B
 * body sha256 993314aff14d800caac63c52557fec8d1fe32251ca88c0bd29f9114bb8484038
 * provider record sha256 3dfa53abdd87d71c2d56f64e079b613e9456ba02617ec1058fff3ce4e0ebcc91
 * callees 16 direct (16 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162db4(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  byte bVar6;
  ushort uVar5;
  short sVar7;
  short local_68;
  short local_66;
  short local_64;
  undefined2 local_60;
  undefined2 local_5e;
  undefined2 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  byte local_38 [8];
  ushort local_30 [12];
  
  local_38[0] = 0x1e;
  local_38[1] = 0x14;
  local_30[0] = 0xf;
  local_30[1] = 0;
  local_30[2] = 0x100;
  local_30[3] = 3;
  local_30[4] = 0x21;
  local_30[5] = 0x400;
  local_30[6] = 0xf;
  local_30[7] = 0;
  local_30[8] = 0x100;
  local_30[9] = 3;
  local_30[10] = 0x11;
  local_30[0xb] = 0x400;
  if (*(char *)(param_1 + 6) == '\0') {
    uVar4 = *(ushort *)(param_1 + 0x2b8) & 1;
    *(uint *)(param_1 + 0x1e8) =
         (uint)local_30[uVar4 * 3 + 1] * 0x10000 + (uint)local_30[uVar4 * 3] * 0x100 + 0x4000000;
    if ((*(ushort *)(param_1 + 0x2b8) & 1) != 0) {
      func_0x80077d18(3,param_1);
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 0;
    if (*(char *)(param_1 + 5) == '\a') {
      iVar3 = (*(ushort *)(param_1 + 0x2b8) & 1) + 2;
      uVar5 = local_30[iVar3 * 3 + 1];
      uVar1 = local_30[iVar3 * 3];
      *(undefined1 *)(param_1 + 0x206) = 1;
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xffdf;
      *(uint *)(param_1 + 0x1e8) = (uint)uVar5 * 0x10000 + (uint)uVar1 * 0x100 + 0xb000000;
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  if (*(char *)(param_1 + 0x1ea) != '\0') {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
    *(short *)(param_1 + 0x1e4) = *(short *)(param_1 + 0x1e4) >> 1;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,
                          local_30[(*(ushort *)(param_1 + 0x2b8) & 1) * 3 + 2]);
  if (iVar3 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(char *)(param_1 + 0x2b6) = *(char *)(param_1 + 0x1f7) + '\x1e';
  }
  func_0x80032b5c(param_1,0);
  if ((((5 < *(byte *)(param_1 + 0x1e9)) &&
       (*(byte *)(param_1 + 0x1e9) < local_38[*(char *)(param_1 + 0x206)])) &&
      (*(char *)(param_1 + 0x207) == '\0')) &&
     ((func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20), 0xed8 < *(uint *)(param_1 + 0x28c)
      || (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x52c), iVar3 != 0)))) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 10;
    uVar4 = func_0x80033604();
    if ((uVar4 & 3) == 0) {
      *(undefined4 *)(param_1 + 4) = 0x1080000;
    }
  }
  if (*(char *)(param_1 + 0x206) == '\0') {
    if (*(char *)(param_1 + 0x1e9) == '.') {
      if (*(char *)(param_1 + 0x207) != '\0') {
        bVar6 = func_0x80033604();
        bVar6 = bVar6 & 3;
        goto LAB_801630b8;
      }
LAB_801630c0:
      uVar5 = local_30[(*(ushort *)(param_1 + 0x2b8) & 1) * 3];
      *(undefined1 *)(param_1 + 0x207) = 1;
      *(uint *)(param_1 + 0x1e8) = (uint)uVar5 * 0x100 + 0x8000000;
    }
  }
  else if (*(char *)(param_1 + 0x1e9) == '\x1e') {
    bVar6 = *(byte *)(param_1 + 0x207);
LAB_801630b8:
    if (bVar6 == 0) goto LAB_801630c0;
  }
  if ((**(uint **)(param_1 + 0x214) & 0x30000) == 0) {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  if ((*(char *)(param_1 + 0x207) != '\0') &&
     (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400), iVar3 != 0)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x80;
  }
  local_68 = 500;
  local_66 = 0x183;
  local_64 = 0;
  local_60 = 0x44c;
  local_5e = 0x183;
  local_5c = 0;
  FUN_80168cb4(param_1,&local_58);
  bVar2 = false;
  iVar3 = func_0x8003307c(&local_58,&DAT_800e1158,900,&local_68);
  if (iVar3 == 0) {
    iVar3 = func_0x8003307c(&local_58,&DAT_800e1158,900,&local_60);
    if (iVar3 != 0) {
      bVar2 = true;
    }
  }
  else {
    bVar2 = true;
  }
  if ((!bVar2) || (DAT_800e139f != 0)) goto LAB_80163394;
  iVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  sVar7 = (short)(iVar3 + -0x400);
  uVar4 = (uint)((((int)_DAT_800e1196 - ((iVar3 + -0x400) * 0x10000 >> 0x10)) + 0x400U & 0xfff) <
                0x800);
  if (*(char *)(param_1 + 0x207) != '\0') {
    uVar4 = uVar4 ^ 1;
    sVar7 = (short)iVar3 + -0xc00;
  }
  func_0x80059e00(0x1e,1);
  if (*(char *)(param_1 + 0x206) == '\0') {
    _DAT_800e1134 = (uVar4 + 4) * 0x10000 + 0x2000000;
    if (uVar4 == 0) {
      _DAT_800e1196 = sVar7 + 0x800;
    }
  }
  else {
    _DAT_800e1134 = (uVar4 + 4) * 0x10000 + 0x2000000;
    if (uVar4 == 0) {
      if (*(char *)(param_1 + 0x207) == '\0') {
        _DAT_800e1134 = 0x2050100;
        DAT_800e1318 = 5;
        DAT_800e1319 = 5;
        DAT_800e131a = 3;
        _DAT_800e1310 = 0x96;
        _DAT_800e1312 = 0;
        _DAT_800e1314 = 0;
      }
      else {
LAB_801632f8:
        if (uVar4 == 0) {
          _DAT_800e1196 = sVar7 + 0x800;
        }
      }
    }
    else if (*(char *)(param_1 + 0x207) != '\0') goto LAB_801632f8;
  }
  DAT_800e139f = DAT_800e139f | 0x80;
  _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
  _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
  _DAT_800e1380 = param_1;
  *(undefined1 *)(param_1 + 0x207) = 1;
  *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffe;
  func_0x80077d18(6,param_1);
  *(undefined2 *)(param_1 + 0x1f6) = 0xf;
  func_0x80052bd0(2,0);
  func_0x80052c6c(6,0xfa,0);
LAB_80163394:
  local_68 = 800;
  local_66 = 0x183;
  local_64 = 0;
  func_0x8004276c(&local_58,&local_68,&local_68);
  local_44 = local_44 + local_68;
  local_40 = local_40 + 0x96 + (int)local_66;
  local_3c = local_3c + local_64;
  func_0x80069f1c(&local_44,400,0x8000,1);
  if (_DAT_8011270c != 0) {
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 4) = 0x1060000;
    *(undefined1 *)(param_1 + 0x2b6) = 0x1e;
    local_68 = 800;
    local_66 = 0x183;
    local_64 = 0;
    *(undefined4 *)(iVar3 + 0x908) = local_58;
    *(undefined4 *)(iVar3 + 0x90c) = local_54;
    *(undefined4 *)(iVar3 + 0x910) = local_50;
    *(undefined4 *)(iVar3 + 0x914) = local_4c;
    *(undefined4 *)(iVar3 + 0x918) = local_48;
    *(int *)(iVar3 + 0x91c) = local_44;
    *(int *)(iVar3 + 0x920) = local_40;
    *(int *)(iVar3 + 0x924) = local_3c;
    iVar3 = iVar3 + 0x908;
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_68);
    uVar5 = func_0x80033604();
    local_68 = local_68 - ((uVar5 & 0x7f) - 0x40);
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_68);
    uVar5 = func_0x80033604();
    local_66 = local_66 - ((uVar5 & 0xff) - 0x80);
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_68);
    uVar5 = func_0x80033604();
    local_64 = local_64 - ((uVar5 & 0x7f) - 0x40);
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_68);
  }
  return;
}
