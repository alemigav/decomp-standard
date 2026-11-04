/* FUN_80164618
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80164618  body 0x80164618..0x801649a3  size 908 B
 * body sha256 dc340ddd92a128b7d247f71a9561be8141fed3f98841ba1c3c973a137ec5318a
 * provider record sha256 4d2297fe3a016900440dbacb6ee2913a4583a47648937742281b3388e1173e3e
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164618(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  ushort uVar4;
  uint uVar3;
  int iVar5;
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
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar3 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = ((uVar3 & 1) + 0xc) * 0x1000000 + 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 0;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 0x14;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xff7f;
  }
  func_0x80032b5c(param_1,0);
  if ((**(uint **)(param_1 + 0x214) & 0x30000) != 0) {
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x80;
    bVar1 = false;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    local_48 = 0;
    local_46 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3e = 500;
    local_3c = 0;
    iVar5 = *(int *)(param_1 + 0x234) + 0x908;
    iVar2 = func_0x8003307c(iVar5,&DAT_800e1158,800,&local_48);
    if (iVar2 == 0) {
      iVar2 = func_0x8003307c(iVar5,&DAT_800e1158,800,&local_40);
      if (iVar2 != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_800e139f == 0)) {
      func_0x80059e00(5,0);
      iVar2 = func_0x80059e00(5,0);
      if (iVar2 == 2) {
        _DAT_800e1134 = 0x3000000;
      }
      else {
        _DAT_800e1134 = 0x2000000;
      }
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1380 = param_1;
      *(undefined1 *)(param_1 + 0x206) = 2;
      func_0x80077d18(6,param_1);
      FUN_80166c64(param_1);
      func_0x80052bd0(6,0);
      func_0x80052c6c(8,0x96,4);
    }
  }
  if (*(char *)(param_1 + 0x206) != '\0') {
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
    FUN_80169528(param_1,&local_38);
    uVar4 = func_0x80033604();
    local_48 = (uVar4 & 0xff) * -2 + 0x100;
    uVar4 = func_0x80033604();
    local_46 = 0x274 - (uVar4 & 0xff);
    uVar4 = func_0x80033604();
    local_44 = (uVar4 & 0xff) * -2 + 0x100;
    iVar2 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar2 + 0x908) = local_38;
    *(undefined4 *)(iVar2 + 0x90c) = local_34;
    *(undefined4 *)(iVar2 + 0x910) = local_30;
    *(undefined4 *)(iVar2 + 0x914) = local_2c;
    *(undefined4 *)(iVar2 + 0x918) = local_28;
    *(undefined4 *)(iVar2 + 0x91c) = local_24;
    *(undefined4 *)(iVar2 + 0x920) = local_20;
    *(undefined4 *)(iVar2 + 0x924) = local_1c;
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) * 4 + 0xc18,(int)*(short *)(param_1 + 0x66),iVar2 + 0x908,
                    &local_48);
    iVar2 = _DAT_800e1364;
    uVar4 = func_0x80033604();
    local_48 = (uVar4 & 0xff) * -2 + 0x100;
    local_46 = 0;
    uVar4 = func_0x80033604();
    local_44 = (uVar4 & 0xff) * -2 + 0x100;
    uVar3 = func_0x80033604();
    func_0x80037780((uVar3 & 0xff) << 2 | 0x1000,0,iVar2 + 0x38,&local_48);
  }
  return;
}
