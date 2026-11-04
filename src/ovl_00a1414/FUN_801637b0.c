/* FUN_801637b0
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x801637b0  body 0x801637b0..0x80163f4f  size 1952 B
 * body sha256 d46c3901ee1ab265bf9b17713698f494e2445dfe2a73618cf96cff25bb4d5114
 * provider record sha256 d0f4caba122f41504037ae93c6fe104c27dfb8911238f7fa15c94d85751b5f4f
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801637b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  short sVar4;
  uint uVar2;
  ushort uVar5;
  int iVar3;
  char cVar6;
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
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    if ((*(ushort *)(param_1 + 0x2b8) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xc001f00;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined2 *)(param_1 + 0x1f6) = 0x5a;
    *(undefined1 *)(param_1 + 0x207) = 0;
  case 1:
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    func_0x800334c8(param_1,param_2,param_3,1);
    if (0x14 < *(byte *)(param_1 + 0x1ea)) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
    }
    func_0x80089d54(param_1,param_2,param_3,0x10080);
    uVar2 = *(uint *)(param_1 + 0x28c);
    if (0x960 < uVar2) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
    }
    sVar4 = *(short *)(param_1 + 500);
    if ((((*(short *)(param_1 + 500) == 0) || (*(short *)(param_1 + 500) = sVar4 + -1, sVar4 == 1))
        && (2000 < uVar2)) &&
       ((uVar2 < 0xce4 &&
        (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100), iVar3 == 0)))) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    if ((uVar2 - 0x7d1 < 0x513) &&
       (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100), iVar3 == 0)) {
      *(undefined1 *)(param_1 + 0x207) = 1;
    }
    sVar4 = *(short *)(param_1 + 0x1f6) + -1;
    *(short *)(param_1 + 0x1f6) = sVar4;
    if (sVar4 == -1) {
      if (*(char *)(param_1 + 0x207) == '\0') {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        uVar2 = func_0x80033604(param_1);
        if ((uVar2 & 1) == 0) {
          *(undefined4 *)(param_1 + 4) = 0x1080000;
        }
      }
      else {
        *(undefined1 *)(param_1 + 6) = 2;
      }
      *(undefined1 *)(param_1 + 0x2b6) = 10;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
    if ((*(ushort *)(param_1 + 0x2b8) & 1) != 0) {
      *(undefined1 *)(param_1 + 0x1e9) = 10;
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)(param_1 + 6) = 3;
    *(undefined1 *)(param_1 + 0x207) = 0;
  case 3:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if ((iVar3 != 0) && (*(undefined1 *)(param_1 + 6) = 4, *(char *)(param_1 + 0x207) == '\0')) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(undefined1 *)(param_1 + 0x2b6) = 10;
      uVar2 = func_0x80033604();
      if ((uVar2 & 1) == 0) {
        *(undefined4 *)(param_1 + 4) = 0x1080000;
      }
    }
    func_0x80032b5c(param_1,0);
    if ((**(uint **)(param_1 + 0x214) & 0x30000) == 0) {
      return;
    }
    FUN_80168cb4(param_1,&local_38);
    if (((**(uint **)(param_1 + 0x214) & 0x10000) != 0) &&
       (func_0x80069f1c(&local_24,200,0x8000,1), _DAT_8011270c != 0)) {
      iVar3 = *(int *)(param_1 + 0x234);
      *(undefined4 *)(param_1 + 4) = 0x1060000;
      *(undefined1 *)(param_1 + 0x2b6) = 0x1e;
      local_48 = 800;
      local_46 = 0x183;
      local_44 = 0;
      *(undefined4 *)(iVar3 + 0x908) = local_38;
      *(undefined4 *)(iVar3 + 0x90c) = local_34;
      *(undefined4 *)(iVar3 + 0x910) = local_30;
      *(undefined4 *)(iVar3 + 0x914) = local_2c;
      *(undefined4 *)(iVar3 + 0x918) = local_28;
      *(undefined4 *)(iVar3 + 0x91c) = local_24;
      *(undefined4 *)(iVar3 + 0x920) = local_20;
      *(undefined4 *)(iVar3 + 0x924) = local_1c;
      iVar3 = iVar3 + 0x908;
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_48);
      uVar5 = func_0x80033604();
      local_48 = local_48 - ((uVar5 & 0x7f) - 0x40);
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_48);
      uVar5 = func_0x80033604();
      local_46 = local_46 - ((uVar5 & 0xff) - 0x80);
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_48);
      uVar5 = func_0x80033604();
      local_44 = local_44 - ((uVar5 & 0x7f) - 0x40);
      func_0x80037780(0x1061fa0,(int)*(short *)(param_1 + 0x66),iVar3,&local_48);
      return;
    }
    bVar1 = false;
    local_48 = 300;
    local_46 = 0x183;
    local_44 = 0;
    local_40 = 0x44c;
    local_3e = 0x183;
    local_3c = 0;
    iVar3 = func_0x8003307c(&local_38,&DAT_800e1158,600,&local_48);
    if (iVar3 == 0) {
      iVar3 = func_0x8003307c(&local_38,&DAT_800e1158,600,&local_40);
      if (iVar3 != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return;
    }
    if (_DAT_800e1322 < 0) {
      return;
    }
    func_0x80059e00(500,0);
    _DAT_800e10ec = _DAT_800e10ec | 0x100;
    DAT_800e139f = DAT_800e139f | 0x80;
    _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
    _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
    _DAT_800e1134 = 0x6000000;
    _DAT_800e1380 = param_1;
    *(undefined1 *)(param_1 + 0x207) = 1;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffe;
    func_0x80077d18();
    return;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined2 *)(param_1 + 500) = 0x3c;
  case 5:
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    func_0x800334c8(param_1,param_2,param_3,1);
    if (0x14 < *(byte *)(param_1 + 0x1ea)) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
    }
    func_0x80089d54(param_1,param_2,param_3,0x10080);
    sVar4 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar4;
    if (sVar4 == -1) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
    *(undefined1 *)(param_1 + 6) = 7;
    *(undefined1 *)(param_1 + 0x207) = 0;
  case 7:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 6) = 8;
    }
    if (((**(uint **)(param_1 + 0x214) & 0x20000) != 0) && (*(char *)(param_1 + 0x207) == '\0')) {
      func_0x80077d18(1,param_1);
      *(undefined1 *)(param_1 + 0x207) = 1;
      func_0x80037780(0x21000,(int)*(short *)(param_1 + 0x66),_DAT_800e1364 + 0x38,0);
      func_0x80037780(0x21000,(int)*(short *)(param_1 + 0x66),_DAT_800e1364 + 0xbf8,0);
    }
    break;
  case 8:
    *(undefined1 *)(param_1 + 6) = 9;
    *(undefined4 *)(param_1 + 0x1e8) = 0x13001f00;
  case 9:
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)(param_1 + 0x1ea) = 0x1c;
    cVar6 = func_0x80089d54(param_1,param_2,param_3,0x80);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6;
    break;
  case 10:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    *(undefined1 *)(param_1 + 6) = 0xb;
  case 0xb:
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                    0xffffffe0);
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    break;
  default:
    goto switchD_801637f4_default;
  }
  func_0x80032b5c(param_1,0);
switchD_801637f4_default:
  return;
}
