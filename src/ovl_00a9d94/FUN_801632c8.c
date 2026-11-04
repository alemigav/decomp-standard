/* FUN_801632c8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801632c8  body 0x801632c8..0x80163bdf  size 2328 B
 * body sha256 7145b04ac85d00c35844367bc98ea7804ee504d283d1ea18734002c7fa454b69
 * provider record sha256 95cda13a5bc779d2ea3f13765312205d1f29ca5b450f7ecb407226c9d1556c03
 * callees 18 direct (18 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801632c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar5;
  int iVar4;
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
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    break;
  case 1:
    goto switchD_8016330c_caseD_1;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000f00;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    if (*(char *)(param_1 + 0x1ea) != '\0') {
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    }
    if ((0x19 < *(byte *)(param_1 + 0x1e9)) &&
       ((iVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x338), iVar4 != 0 ||
        (5000 < *(uint *)(param_1 + 0x28c))))) {
      if (_DAT_800e1322 < 0) goto LAB_80163ba0;
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(undefined1 *)(param_1 + 0x2ba) = 5;
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar4 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar4 != 0) {
      if (_DAT_800e1322 < 0) {
LAB_80163ba0:
        *(undefined1 *)(param_1 + 6) = 4;
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(undefined1 *)(param_1 + 0x2ba) = 10;
    }
    goto LAB_80163bbc;
  default:
    goto switchD_8016330c_caseD_4;
  }
  uVar3 = func_0x80033604();
  uVar2 = func_0x80033604();
  *(byte *)(param_1 + 0x206) = (byte)((int)(uVar3 & 0xff) >> (uVar2 & 7)) & 1;
  if (*(uint *)(param_1 + 0x28c) < 0x9c4) {
    *(undefined1 *)(param_1 + 0x206) = 1;
  }
  *(undefined1 *)(param_1 + 0x207) = 0;
  *(undefined1 *)(param_1 + 6) = 1;
  *(int *)(param_1 + 0x1e8) = (*(char *)(param_1 + 0x206) + 3) * 0x1000000 + 0xf00;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  *(undefined2 *)(param_1 + 0x1f6) = 0;
  *(undefined2 *)(param_1 + 500) = 0;
  *(undefined1 *)(param_1 + 0x2ce) = 0;
  *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffd;
  func_0x80077d18(0,param_1);
switchD_8016330c_caseD_1:
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar4 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar4 != 0) {
    if (((*(ushort *)(param_1 + 0x2b6) & 2) != 0) || (_DAT_800e1322 < 0)) {
      *(undefined1 *)(param_1 + 6) = 2;
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2ba) = 10;
  }
  if ((((*(short *)(param_1 + 0x1f6) == 0) && (*(uint *)(param_1 + 0x28c) < 4000)) &&
      (iVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200), iVar4 == 0)) &&
     ((*(char *)(param_1 + 0x1e9) == (&DAT_8016c4d8)[*(char *)(param_1 + 0x206) * 2] &&
      (-1 < _DAT_800e1322)))) {
    *(undefined2 *)(param_1 + 0x1f6) = 1;
    uVar3 = ~(uint)*(byte *)(param_1 + 0x206) & 1;
    *(char *)(param_1 + 0x206) = (char)uVar3;
    *(uint *)(param_1 + 0x1e8) =
         (uVar3 + 3) * 0x1000000 + (uint)(byte)(&DAT_8016c4d9)[(uVar3 ^ 1) * 2] * 0x10000 + 0xf00;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    if (-1 < _DAT_800e1322) {
      DAT_800e139f = DAT_800e139f & 0x7f;
    }
  }
  if ((**(uint **)(param_1 + 0x214) & 0x10000) == 0) {
LAB_801638bc:
    if (*(char *)(param_1 + 0x2ce) != '\0') goto LAB_801638c8;
  }
  else {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x80);
    local_48 = 0;
    local_46 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3e = 600;
    local_3c = 0;
    if (*(char *)(param_1 + 0x206) == '\0') {
      FUN_8016a8c0(param_1,&local_38);
    }
    else {
      FUN_8016a978(param_1,&local_38);
    }
    bVar1 = false;
    iVar4 = func_0x8003307c(&local_38,&DAT_800e1158,0x6a4,&local_48);
    if (iVar4 == 0) {
      iVar4 = func_0x8003307c(&local_38,&DAT_800e1158,0x5dc,&local_40);
      if (iVar4 != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_800e139f == 0)) {
      iVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      uVar3 = (uint)((((int)_DAT_800e1196 - ((iVar4 + -0x400) * 0x10000 >> 0x10)) + 0x400U & 0xfff)
                    < 0x800);
      if (*(char *)(param_1 + 0x206) != '\0') {
        uVar3 = uVar3 ^ 1;
      }
      iVar4 = func_0x80059e00(0xf,0);
      if (iVar4 == 2) {
        _DAT_800e1134 = *(char *)(param_1 + 0x206) * 0x10000 + 0x6000000;
        *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
        _DAT_800e10ec = _DAT_800e10ec | 0x100;
      }
      else {
        _DAT_800e1134 = (uVar3 | 2) * 0x10000 + 0x2000000;
      }
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1380 = param_1;
      *(undefined1 *)(param_1 + 0x207) = 6;
      *(short *)(param_1 + 500) = (short)*(char *)(param_1 + 0x206);
      func_0x80077d18(3,param_1);
      FUN_801671dc(param_1,(int)*(char *)(param_1 + 0x206));
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 2;
      func_0x80052bd0(8,0);
      func_0x80052c6c(8,0xfa,4);
    }
    local_48 = 0;
    local_46 = -500;
    local_44 = 0;
    func_0x8004276c(&local_38,&local_48,&local_48);
    local_24 = local_24 + local_48;
    local_20 = local_20 + local_46;
    local_1c = local_1c + local_44;
    func_0x80069f1c(&local_24,600,0x8000,1);
    if (_DAT_8011270c == 0) goto LAB_801638bc;
    local_48 = 0;
    local_46 = -500;
    local_44 = 0;
    iVar4 = *(int *)(param_1 + 0x234) + (*(char *)(param_1 + 0x206) * -5 + 0x13) * 0x178 + 0x38;
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar4,&local_48);
    uVar5 = func_0x80033604();
    local_48 = local_48 - ((uVar5 & 0x7f) - 0x40);
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar4,&local_48);
    uVar5 = func_0x80033604();
    local_46 = local_46 - ((uVar5 & 0xff) - 0x80);
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar4,&local_48);
    uVar5 = func_0x80033604();
    local_44 = local_44 - ((uVar5 & 0x7f) - 0x40);
    func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar4,&local_48);
    if (*(char *)(param_1 + 0x2ce) == '\0') {
      func_0x80077d18(4,param_1);
      *(undefined1 *)(param_1 + 0x2ce) = 7;
      goto LAB_801638bc;
    }
LAB_801638c8:
    *(char *)(param_1 + 0x2ce) = *(char *)(param_1 + 0x2ce) + -1;
  }
  if (*(char *)(param_1 + 0x207) != '\0') {
    *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
    if (*(short *)(param_1 + 500) == 0) {
      FUN_8016a8c0(param_1,&local_38);
    }
    else {
      FUN_8016a978(param_1,&local_38);
    }
    uVar5 = func_0x80033604();
    local_48 = (uVar5 & 0xff) * -2 + 0x100;
    uVar5 = func_0x80033604();
    local_46 = (uVar5 & 0xff) * -2 + 0x4e8;
    uVar5 = func_0x80033604();
    local_44 = (uVar5 & 0xff) * -2 + 0x100;
    iVar4 = *(int *)(param_1 + 0x234) + (*(short *)(param_1 + 500) * -5 + 0x13) * 0x178;
    *(undefined4 *)(iVar4 + 0x38) = local_38;
    *(undefined4 *)(iVar4 + 0x3c) = local_34;
    *(undefined4 *)(iVar4 + 0x40) = local_30;
    *(undefined4 *)(iVar4 + 0x44) = local_2c;
    *(undefined4 *)(iVar4 + 0x48) = local_28;
    *(int *)(iVar4 + 0x4c) = local_24;
    *(int *)(iVar4 + 0x50) = local_20;
    *(int *)(iVar4 + 0x54) = local_1c;
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) << 2 | 0x1000,(int)*(short *)(param_1 + 0x66),iVar4 + 0x38,
                    &local_48);
    iVar4 = _DAT_800e1364;
    uVar5 = func_0x80033604();
    local_48 = (uVar5 & 0xff) * -2 + 0x100;
    local_46 = 0xff38;
    uVar5 = func_0x80033604();
    local_44 = (uVar5 & 0xff) * -2 + 0x100;
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) << 2 | 0x1000,0,iVar4 + 0x38,&local_48);
    iVar4 = _DAT_800e1364;
    uVar5 = func_0x80033604();
    local_48 = (uVar5 & 0xff) * -2 + 0x100;
    local_46 = 0;
    uVar5 = func_0x80033604();
    local_44 = (uVar5 & 0xff) * -2 + 0x100;
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) << 2 | 0x1000,0,iVar4 + 0xbf8,&local_48);
  }
LAB_80163bbc:
  func_0x80032b5c(param_1,0);
switchD_8016330c_caseD_4:
  return;
}
