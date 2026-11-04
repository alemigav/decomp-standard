/* FUN_80164204
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80164204  body 0x80164204..0x80164893  size 1680 B
 * body sha256 08307d569e41e9df48601fdeb05c78f82b806d5c5e8f941edf7c7142959d7b22
 * provider record sha256 d5350d07d37a66aafacd3752b8bae1e1b45357e9359e2137d9b7b277a3487717
 * callees 14 direct (14 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164204(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  short sVar5;
  ushort uVar6;
  uint uVar4;
  undefined4 uVar7;
  int iVar8;
  short unaff_s2;
  short unaff_s3;
  undefined4 local_40;
  undefined4 local_3c;
  short local_38;
  short local_36;
  short local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_40 = 0x32ce28d8;
  local_3c = 0x50b0;
  *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x40;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x40);
    uVar4 = func_0x80033604();
    uVar3 = func_0x80033604();
    uVar1 = *(undefined1 *)((int)&local_40 + ((int)(uVar4 & 0xff) >> (uVar3 & 3) & 7U));
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffd;
    *(undefined1 *)(param_1 + 0x207) = uVar1;
    DAT_8016c31e = 0;
    uVar4 = func_0x80033604();
    if ((uVar4 & 1) != 0) {
      func_0x80077d18(10,param_1);
    }
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_80164748;
  if ((*(ushort *)(param_1 + 0x2b6) & 2) == 0) {
    if (DAT_8016c31e == 0) {
      sVar5 = *(short *)(param_1 + 0x260);
      sVar2 = *(short *)(param_1 + 0x262);
      uVar7 = 0x40;
    }
    else {
      uVar7 = 0xffffffe0;
      DAT_8016c31e = DAT_8016c31e + -1;
      sVar5 = DAT_8016c31a;
      sVar2 = DAT_8016c31c;
    }
    func_0x80032dbc(param_1,(int)sVar5,(int)sVar2,uVar7);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar8 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          0x200);
  if ((iVar8 != 0) || ((*(byte *)(param_1 + 0x206) & 0x40) != 0)) {
    unaff_s3 = (short)(((int)*(short *)(param_1 + 0x1e0) << 4) / 3 >> 4);
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - unaff_s3;
    unaff_s2 = (short)(((int)*(short *)(param_1 + 0x1e4) << 4) / 3 >> 4);
    *(short *)(param_1 + 0x1e4) = *(short *)(param_1 + 0x1e4) - unaff_s2;
  }
  iVar8 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          0x400);
  if ((iVar8 != 0) || ((*(byte *)(param_1 + 0x206) & 0x40) != 0)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - unaff_s3;
    *(short *)(param_1 + 0x1e4) = *(short *)(param_1 + 0x1e4) - unaff_s2;
  }
  if ((*(ushort *)(param_1 + 0x2b6) & 0x200) != 0) {
    *(undefined1 *)(param_1 + 0x206) = 0xc0;
    func_0x80077d18(0xb,param_1);
  }
  iVar8 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar8 != 0) {
    uVar4 = func_0x80033604();
    uVar3 = func_0x80033604();
    *(undefined1 *)(param_1 + 0x207) =
         *(undefined1 *)((int)&local_40 + ((int)(uVar4 & 0xff) >> (uVar3 & 3) & 7U));
    if (((int)*(char *)(param_1 + 0x206) & 0x80U) != 0) {
      if ((*(byte *)(param_1 + 0x206) & 0xf) == 0) {
        *(undefined4 *)(param_1 + 4) = 0x1030000;
        uVar4 = func_0x80033604();
        if ((uVar4 & 1) != 0) {
          *(undefined4 *)(param_1 + 4) = 0x10b0000;
          *(undefined1 *)(param_1 + 0x2c2) = 4;
        }
        *(undefined1 *)(param_1 + 0x2ce) = 0x5a;
        if (((*(byte *)(param_1 + 0x206) & 0x40) != 0) &&
           (*(undefined1 *)(param_1 + 0x2ba) = 0x1e, _DAT_800e1322 < 0x1e)) {
          *(undefined1 *)(param_1 + 0x2ba) = 0;
        }
      }
      *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
    }
  }
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 10;
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
    *(undefined2 *)(param_1 + 500) = 0;
  }
  else {
    sVar5 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar5;
    if (0x5a < sVar5) {
      local_30 = *(undefined4 *)(param_1 + 0x120);
      local_2c = *(undefined4 *)(param_1 + 0x124);
      local_28 = *(undefined4 *)(param_1 + 0x128);
      func_0x800667d4(&local_30,0x6a4,1,0x500);
      if (_DAT_800e1068 != (short *)0x0) {
        DAT_8016c31e = 4;
        DAT_8016c31a = *_DAT_800e1068 + ((ushort)_DAT_800e1068[2] >> 1);
        DAT_8016c31c = _DAT_800e1068[1] + ((ushort)_DAT_800e1068[3] >> 1);
      }
    }
  }
  if ((200 < *(short *)(param_1 + 0x1e0)) && ((*(byte *)(param_1 + 0x206) & 0x40) == 0)) {
    local_38 = 0x578;
    local_36 = 0;
    local_34 = 0;
    iVar8 = func_0x8003307c(*(int *)(param_1 + 0x234) + 0xee8,&DAT_800e1158,0x5dc,&local_38);
    if ((iVar8 != 0) && (DAT_800e139f == 0)) {
      sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      iVar8 = (int)_DAT_800e1196;
      func_0x80059e00(0x14,1);
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1380 = param_1;
      *(undefined2 *)(param_1 + 0x1f6) = 6;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 2;
      _DAT_800e1134 = (((iVar8 - sVar5) + 0x400U & 0xfff) < 0x800 | 2) * 0x10000 + 0x2000000;
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0xffffff80);
      func_0x80077d18(7,param_1);
      func_0x80052bd0(3,0);
      func_0x80052c6c(0xf,0xfa,0);
    }
  }
  if ((*(uint *)(param_1 + 0x28c) < 0x1194) && (((int)*(char *)(param_1 + 0x206) & 0x80U) == 0)) {
    *(undefined1 *)(param_1 + 0x206) = 0x81;
  }
  func_0x80032b5c(param_1,0);
LAB_80164748:
  if (*(short *)(param_1 + 0x1f6) != 0) {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0xfffffff0);
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -1;
    local_38 = 0x76c;
    uVar6 = func_0x80033604();
    local_36 = (uVar6 & 0xff) * -2 + 0x100;
    uVar6 = func_0x80033604();
    local_34 = (uVar6 & 0xff) * -2 + 0x100;
    iVar8 = *(int *)(param_1 + 0x234) + 0xee8;
    uVar4 = func_0x80033604();
    func_0x80037780((uVar4 & 0xff) * 4 + 0xc18,(int)*(short *)(param_1 + 0x66),iVar8,&local_38);
    local_38 = 2000;
    uVar4 = func_0x80033604();
    func_0x80037780((uVar4 & 0xff) * 4 + 0xc18 | 0x10000,(int)*(short *)(param_1 + 0x66),iVar8,
                    &local_38);
    iVar8 = _DAT_800e1364;
    uVar6 = func_0x80033604();
    local_38 = (uVar6 & 0xff) * -2 + 0x100;
    local_36 = 0xff38;
    uVar6 = func_0x80033604();
    local_34 = (uVar6 & 0xff) * -2 + 0x100;
    uVar4 = func_0x80033604();
    func_0x80037780((uVar4 & 0xff) * 4 + 0xc18,0,iVar8 + 0x38,&local_38);
  }
  return;
}
