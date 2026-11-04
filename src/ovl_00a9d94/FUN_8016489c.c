/* FUN_8016489c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016489c  body 0x8016489c..0x8016514f  size 2228 B
 * body sha256 f3db349906715ed82e225f2fdaa6f1e92e0519bd48362550c4dc1ee5a32aa8ea
 * provider record sha256 f6ae4900cdaf056013b0637bfc97691146f15eefb1f89aa36cb5be6758c1e3a6
 * callees 19 direct (18 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016489c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar6;
  byte bVar7;
  undefined2 uVar3;
  short sVar4;
  ushort uVar5;
  uint uVar2;
  int iVar8;
  int iVar9;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  short local_28 [4];
  short local_20;
  short local_1e;
  short local_1c;
  
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x2c0) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 0x2d4) = 0;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffd;
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 4;
    }
    func_0x80052c6c(8,100,0xf);
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if (*(char *)(param_1 + 0x1e9) == '\x13') {
      *(undefined1 *)(param_1 + 6) = 2;
      uVar2 = FUN_8016bdc4(param_1,&DAT_8016c280,0x5dc,*(ushort *)(param_1 + 0x2b6) & 0x20);
      local_28[0] = (short)(uVar2 >> 4);
      if ((local_28[0] < 400) && (uVar1 = func_0x80033604(), (uVar1 & 1) != 0)) {
        local_28[0] = 400;
      }
      if (600 < local_28[0]) {
        local_28[0] = 600;
      }
      if ((((0x396c < *(int *)(param_1 + 0x28) + 0x51a4U) || (-0x1e14 < *(int *)(param_1 + 0x30)))
          || (*(int *)(param_1 + 0x30) < -0x5fb4)) && (uVar1 = func_0x80033604(), (uVar1 & 3) == 0))
      {
        local_28[0] = local_28[0] + 300;
        func_0x80032dbc(param_1,0,0,0xffffffc0);
      }
      if ((*(ushort *)(param_1 + 0x2b6) & 0x20) != 0) {
        local_28[0] = (short)(uVar2 / 0x15);
      }
      local_28[2] = 0;
      local_28[1] = 0xfc7c;
      sVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),0,0);
      FUN_8016b9c8(param_1,(int)sVar4,local_28);
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x84;
      func_0x80032dbc(param_1,0,0,0x20);
      *(undefined2 *)(param_1 + 500) = 0;
      func_0x80077d18(2,param_1);
    }
    if ((0xf < *(byte *)(param_1 + 0x1e9)) && (-0x5dc < *(int *)(param_1 + 0x2c))) {
      local_20 = 0x578;
      local_1e = 0;
      local_1c = 0;
      iVar9 = func_0x8003307c(*(int *)(param_1 + 0x234) + 0xee8,&DAT_800e1158,0x5dc,&local_20);
      if ((iVar9 != 0) && (DAT_800e139f == 0)) {
        sVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                                (int)_DAT_800e115a,(int)_DAT_800e1162);
        iVar9 = (int)_DAT_800e1196;
        func_0x80059e00(0xf,1);
        _DAT_800e1134 = (uint)(((iVar9 - sVar4) + 0x400U & 0xfff) < 0x800) * 0x10000 + 0x2000000;
        DAT_800e139f = DAT_800e139f | 0x80;
        _DAT_800e1380 = param_1;
        *(undefined1 *)(param_1 + 0x206) = 6;
        func_0x80077d18(7,param_1);
        func_0x80052bd0(10,0);
        func_0x80052c6c(5,200,4);
      }
    }
    break;
  case 2:
    cVar6 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x1e2) = (*(short *)(param_1 + 0x1e2) + 0x78) - *(short *)(param_1 + 0x2c0)
    ;
    *(short *)(param_1 + 0x2c0) = *(short *)(param_1 + 0x2c0) + 2;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000f00;
    *(undefined1 *)(param_1 + 6) = 4;
  case 4:
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    if ((*(ushort *)(param_1 + 0x2b6) & 0x10) != 0) {
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x80);
    }
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x1e2) = (*(short *)(param_1 + 0x1e2) + 0x78) - *(short *)(param_1 + 0x2c0)
    ;
    *(short *)(param_1 + 0x2c0) = *(short *)(param_1 + 0x2c0) + 2;
    if ((0 < *(short *)(param_1 + 0x1e2)) && ((*(ushort *)(param_1 + 0x2b6) & 0x10) == 0)) {
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x10;
      *(undefined4 *)(param_1 + 0x1e8) = 0xe000f00;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
    func_0x8004dcb8(param_1,0x400);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x1e4);
    if ((int)*(short *)(param_1 + 0x25e) < *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined4 *)(param_1 + 4) = 0x1060000;
    }
    local_38 = *(undefined4 *)(param_1 + 0x120);
    local_34 = *(undefined4 *)(param_1 + 0x124);
    local_30 = *(undefined4 *)(param_1 + 0x128);
    func_0x800667d4(&local_38,0x6a4,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x1100);
    if ((((_DAT_800e1068 != 0) && ((*(ushort *)(param_1 + 0x2b6) & 8) == 0)) &&
        (*(int *)(param_1 + 0x2c) < -0xc80)) &&
       (iVar9 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x40), iVar9 != 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1070000;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 8;
      bVar7 = func_0x8006a42c(param_1 + 0x28,_DAT_800e1068);
      *(byte *)(param_1 + 699) = bVar7;
      uVar3 = FUN_8016a87c(param_1,bVar7 & 1);
      *(undefined2 *)(param_1 + 0x2b4) = uVar3;
    }
    if (((*(ushort *)(param_1 + 0x2b6) & 0x10) != 0) && (-2000 < *(int *)(param_1 + 0x2c))) {
      local_20 = 1000;
      local_1e = 0;
      local_1c = 0;
      iVar9 = func_0x8003307c(*(int *)(param_1 + 0x234) + 0xee8,&DAT_800e1158,2000,&local_20);
      if ((iVar9 != 0) && (DAT_800e139f == 0)) {
        sVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                                (int)_DAT_800e115a,(int)_DAT_800e1162);
        iVar8 = (int)_DAT_800e1196;
        iVar9 = func_0x80059e00(0x1e,0);
        if (iVar9 == 2) {
          _DAT_800e1134 = 0x3000000;
          *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
        }
        else {
          _DAT_800e1134 = (((iVar8 - sVar4) + 0x400U & 0xfff) < 0x800 | 2) * 0x10000 + 0x2000000;
        }
        DAT_800e139f = DAT_800e139f | 0x80;
        _DAT_800e1380 = param_1;
        *(undefined1 *)(param_1 + 0x206) = 6;
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 2;
        func_0x80077d18(7,param_1);
        func_0x80052bd0(8,0);
        func_0x80052c6c(0xd,0xfa,2);
      }
    }
    sVar4 = func_0x80069f1c(&local_38,0x578,0x400,0);
    if (_DAT_8011270c != 0) {
      sVar4 = _DAT_80112712;
    }
    if (sVar4 == 0) {
      *(undefined1 *)(param_1 + 0x1a2) = 0;
    }
    if (-0xe10 < *(int *)(param_1 + 0x2c)) {
      *(undefined1 *)(param_1 + 0x1a2) = 0;
    }
  }
  if (*(char *)(param_1 + 0x206) != '\0') {
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
    local_20 = 0x76c;
    uVar5 = func_0x80033604();
    local_1e = (uVar5 & 0xff) * -2 + 0x100;
    uVar5 = func_0x80033604();
    local_1c = (uVar5 & 0xff) * -2 + 0x100;
    iVar9 = *(int *)(param_1 + 0x234) + 0xee8;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x1000,(int)*(short *)(param_1 + 0x66),iVar9,&local_20);
    local_20 = 2000;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x11000,(int)*(short *)(param_1 + 0x66),iVar9,&local_20);
    iVar9 = _DAT_800e1364;
    uVar5 = func_0x80033604();
    local_20 = (uVar5 & 0xff) * -2 + 0x100;
    local_1e = 0xff38;
    uVar5 = func_0x80033604();
    local_1c = (uVar5 & 0xff) * -2 + 0x100;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x1000,0,iVar9 + 0x38,&local_20);
  }
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
  return;
}
