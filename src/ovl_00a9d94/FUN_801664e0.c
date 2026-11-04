/* FUN_801664e0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801664e0  body 0x801664e0..0x8016687f  size 928 B
 * body sha256 de3ae90a73bd2b29ddc07653576d40313647278c1b9e995257e3241c4abcbf1c
 * provider record sha256 92f42d3381edb3d988cd5a348928bd71b4619fe2eabd6fb1c1d285e303dd5386
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801664e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar4;
  uint uVar2;
  ushort uVar3;
  short local_18;
  short local_16;
  short local_14;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1a000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1030000;
    *(undefined1 *)(param_1 + 0x2ba) = 0xf;
    if ((*(ushort *)(param_1 + 0x2b6) & 2) != 0) {
      bVar4 = func_0x80033604();
      *(byte *)(param_1 + 0x2ba) = (bVar4 & 0xf) + 0xf;
      *(undefined1 *)(param_1 + 0x2ce) = 0x5a;
      uVar2 = func_0x80033604();
      if ((((uVar2 & 1) != 0) && (*(uint *)(param_1 + 0x28c) < 0xe10)) &&
         (1 < *(byte *)(param_1 + 0x2d6))) {
        *(undefined4 *)(param_1 + 4) = 0x10b0000;
        bVar4 = func_0x80033604();
        *(byte *)(param_1 + 0x2c2) = (bVar4 & 1) + 3;
      }
    }
  }
  if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    local_18 = 0x578;
    local_16 = 0;
    local_14 = 0;
    iVar1 = func_0x8003307c(*(int *)(param_1 + 0x234) + 0xee8,&DAT_800e1158,0x5dc,&local_18);
    if ((iVar1 != 0) && (DAT_800e139f == 0)) {
      iVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      uVar2 = (uint)((((int)_DAT_800e1196 - ((iVar1 + -0x400) * 0x10000 >> 0x10)) + 0x400U & 0xfff)
                    < 0x800);
      if (*(char *)(param_1 + 0x206) != '\0') {
        uVar2 = uVar2 ^ 1;
      }
      iVar1 = func_0x80059e00(0x14,0);
      if (iVar1 == 2) {
        _DAT_800e1134 = 0x3000000;
        *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
      }
      else {
        _DAT_800e1134 = (uVar2 | 2) * 0x10000 + 0x2000000;
      }
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1380 = param_1;
      *(undefined1 *)(param_1 + 0x207) = 6;
      *(short *)(param_1 + 500) = (short)*(char *)(param_1 + 0x206);
      func_0x80077d18(6,param_1);
      func_0x80052bd0(8,0);
      func_0x80052c6c(5,0x96,4);
    }
  }
  if (*(char *)(param_1 + 0x207) != '\0') {
    *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
    local_18 = 0x76c;
    uVar3 = func_0x80033604();
    local_16 = (uVar3 & 0xff) * -2 + 0x100;
    uVar3 = func_0x80033604();
    local_14 = (uVar3 & 0xff) * -2 + 0x100;
    iVar1 = *(int *)(param_1 + 0x234) + 0xee8;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x1000,(int)*(short *)(param_1 + 0x66),iVar1,&local_18);
    local_18 = 2000;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x11000,(int)*(short *)(param_1 + 0x66),iVar1,&local_18);
    iVar1 = _DAT_800e1364;
    uVar3 = func_0x80033604();
    local_18 = (uVar3 & 0xff) * -2 + 0x100;
    local_16 = 0xff38;
    uVar3 = func_0x80033604();
    local_14 = (uVar3 & 0xff) * -2 + 0x100;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x1000,0,iVar1 + 0x38,&local_18);
  }
  func_0x80032b5c(param_1,0);
  return;
}
