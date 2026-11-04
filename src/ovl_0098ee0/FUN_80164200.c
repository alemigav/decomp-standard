/* FUN_80164200
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164200  body 0x80164200..0x80164477  size 632 B
 * body sha256 0e9274876e03521c4e0d5e1aac577d80c6da548d7ff82a2ef3c20ff375764b16
 * provider record sha256 3cea07dbcab6a0771480977aecbb43761d78c9981ca12bbd3be9ead2efb2cbaf
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164200(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  
  bVar1 = *(byte *)(param_1 + 6);
  iVar3 = *(int *)(param_1 + 0x234);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      *(undefined1 *)(param_1 + 0x1e8) = 0xf;
      iVar2 = func_0x80036c68(param_1,0xf,0,1);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
      }
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
      if (*(char *)(param_1 + 0x1e9) == '\x16') {
        func_0x80077d18(2,param_1);
        func_0x80032dbc(0x800e1130,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30),
                        0x100);
        FUN_80162228(param_1);
        local_18 = *(undefined2 *)(iVar3 + 0x1656);
        local_16 = *(undefined2 *)(iVar3 + 0x165a);
        local_14 = *(undefined2 *)(iVar3 + 0x165e);
        func_0x80037780(0x2400,0,0x800e9028,&local_18);
        func_0x80052bd0(3,0);
        func_0x80052d10(0xc,0xa0,0x28,0);
        FUN_80162114(10);
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 500) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  iVar2 = func_0x80036c68(param_1,0xf,0xf,0);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
  iVar2 = FUN_80161e10(param_1,0xf,0xe,0x13,0x3b6);
  if (iVar2 != 0) {
    func_0x80077d18(2,param_1);
    func_0x80032dbc(0x800e1130,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30),0x100
                   );
    local_18 = *(undefined2 *)(iVar3 + 0x1656);
    local_14 = *(undefined2 *)(iVar3 + 0x165e);
    _DAT_800e1134 = 0x2000000;
    local_16 = *(short *)(iVar3 + 0x165a);
    if ((int)*(short *)(iVar3 + 0x165a) < *(short *)(param_1 + 0x25e) + -3000) {
      local_16 = *(short *)(param_1 + 0x25e) + -3000;
    }
    func_0x80037780(0x2400,0,0x800e9028,&local_18);
    func_0x80052bd0(3,0);
    func_0x80052c6c(8,0xdc,0);
    func_0x80052d10(6,0xdc,0x28,8);
    FUN_80162114(10);
    *(ushort *)(param_1 + 0x2c0) = *(ushort *)(param_1 + 0x2c0) | 0x20;
  }
  return;
}
