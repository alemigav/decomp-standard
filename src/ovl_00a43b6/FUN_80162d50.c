/* FUN_80162d50
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80162d50  body 0x80162d50..0x8016345b  size 1804 B
 * body sha256 da71ab3ce7663ca73050af3881e23fb0612f03fb9c693d6a5dd48b3313b50868
 * provider record sha256 a8b1980377025736d4ffb8259f8ece5258c3718e754d3e2f615742957fe84144
 * callees 17 direct (17 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162d50(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  short local_48;
  short local_46;
  short local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    if (0x3c < _DAT_800e1322) {
      *(undefined1 *)(param_1 + 0x1e9) = 0xf;
      func_0x800334c8(param_1,param_2,param_3,0);
    }
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  if (*(char *)(param_1 + 0x1ea) != '\0') {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
    *(short *)(param_1 + 0x1e4) = *(short *)(param_1 + 0x1e4) >> 1;
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 0x14;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xff7f;
  }
  func_0x80032b5c(param_1,0);
  if (((*(byte *)(param_1 + 0x1e9) - 6 < 0xd) && (*(char *)(param_1 + 0x207) == '\0')) &&
     ((func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8), 0xed8 < *(uint *)(param_1 + 0x28c) ||
      (iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x590), iVar2 != 0)))) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 10;
  }
  if (((*(char *)(param_1 + 0x1e9) == '(') && (*(uint *)(param_1 + 0x28c) < 3000)) &&
     (*(char *)(param_1 + 0x207) == '\0')) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
    *(undefined1 *)(param_1 + 0x207) = 1;
    if (((DAT_800e139f & 0x80) != 0) && (0 < _DAT_800e1322)) {
      DAT_800e139f = 0;
    }
  }
  if ((**(uint **)(param_1 + 0x214) & 0x30000) != 0) {
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x80;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    if ((*(char *)(param_1 + 0x207) != '\0') &&
       (iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400), iVar2 != 0)) {
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x80;
    }
    local_46 = 0xfed4;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3e = 400;
    local_3c = 0;
    FUN_80169528(param_1,&local_38);
    bVar1 = false;
    iVar2 = func_0x8003307c(&local_38,&DAT_800e1158,0x4b0,&local_48);
    if (iVar2 == 0) {
      iVar2 = func_0x8003307c(&local_38,&DAT_800e1158,0x4b0,&local_40);
      if (iVar2 != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_800e139f == 0)) {
      iVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      uVar4 = (uint)((((int)_DAT_800e1196 - ((iVar2 + -0x400) * 0x10000 >> 0x10)) + 0x400U & 0xfff)
                    < 0x800);
      if (*(char *)(param_1 + 0x207) != '\0') {
        uVar4 = uVar4 ^ 1;
      }
      func_0x80059e00(0x14,1);
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1134 = (uVar4 | 2) * 0x10000 + 0x2000000;
      _DAT_800e1380 = param_1;
      *(undefined1 *)(param_1 + 0x206) = 6;
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffe;
      func_0x80077d18(3,param_1);
      FUN_80166c64(param_1);
      func_0x80052bd0(8,0);
      func_0x80052c6c(8,0xfa,4);
    }
    local_48 = 0;
    local_46 = 1000;
    local_44 = 0;
    func_0x8004276c(&local_38,&local_48,&local_48);
    local_24 = local_24 + local_48;
    local_20 = local_20 + local_46;
    local_1c = local_1c + local_44;
    func_0x80069f1c(&local_24,600,0x8000,1);
    if (_DAT_8011270c != 0) {
      iVar2 = *(int *)(param_1 + 0x234);
      local_48 = 0;
      local_46 = 1000;
      local_44 = 0;
      *(undefined4 *)(iVar2 + 0x908) = local_38;
      *(undefined4 *)(iVar2 + 0x90c) = local_34;
      *(undefined4 *)(iVar2 + 0x910) = local_30;
      *(undefined4 *)(iVar2 + 0x914) = local_2c;
      *(undefined4 *)(iVar2 + 0x918) = local_28;
      *(int *)(iVar2 + 0x91c) = local_24;
      *(int *)(iVar2 + 0x920) = local_20;
      *(int *)(iVar2 + 0x924) = local_1c;
      iVar2 = iVar2 + 0x908;
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar2,&local_48);
      uVar3 = func_0x80033604();
      local_48 = local_48 - ((uVar3 & 0x7f) - 0x40);
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar2,&local_48);
      uVar3 = func_0x80033604();
      local_46 = local_46 - ((uVar3 & 0xff) - 0x80);
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar2,&local_48);
      uVar3 = func_0x80033604();
      local_44 = local_44 - ((uVar3 & 0x7f) - 0x40);
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar2,&local_48);
      if (*(short *)(param_1 + 0x1f6) == 0) {
        func_0x80077d18(7,param_1);
        *(undefined2 *)(param_1 + 0x1f6) = 7;
      }
    }
  }
  _DAT_800e110c = _DAT_800e110c & 0xfffffff7;
  if (*(short *)(param_1 + 0x1f6) != 0) {
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -1;
    _DAT_800e110c = _DAT_800e110c | 8;
  }
  if (*(char *)(param_1 + 0x206) != '\0') {
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
    FUN_80169528(param_1,&local_38);
    uVar3 = func_0x80033604();
    local_48 = (uVar3 & 0xff) * -2 + 0x100;
    uVar3 = func_0x80033604();
    local_46 = (uVar3 & 0xff) * -2 + 0x4e8;
    uVar3 = func_0x80033604();
    local_44 = (uVar3 & 0xff) * -2 + 0x100;
    iVar2 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar2 + 0x908) = local_38;
    *(undefined4 *)(iVar2 + 0x90c) = local_34;
    *(undefined4 *)(iVar2 + 0x910) = local_30;
    *(undefined4 *)(iVar2 + 0x914) = local_2c;
    *(undefined4 *)(iVar2 + 0x918) = local_28;
    *(int *)(iVar2 + 0x91c) = local_24;
    *(int *)(iVar2 + 0x920) = local_20;
    *(int *)(iVar2 + 0x924) = local_1c;
    uVar4 = func_0x80033604();
    func_0x80037780((uVar4 & 0xff) << 2 | 0x1000,(int)*(short *)(param_1 + 0x66),iVar2 + 0x908,
                    &local_48);
    iVar2 = _DAT_800e1364;
    uVar3 = func_0x80033604();
    local_48 = (uVar3 & 0xff) * -2 + 0x100;
    local_46 = 0;
    uVar3 = func_0x80033604();
    local_44 = (uVar3 & 0xff) * -2 + 0x100;
    uVar4 = func_0x80033604();
    func_0x80037780((uVar4 & 0xff) << 2 | 0x1000,0,iVar2 + 0x38,&local_48);
  }
  return;
}
