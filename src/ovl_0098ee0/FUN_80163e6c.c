/* FUN_80163e6c
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80163e6c  body 0x80163e6c..0x80163ff7  size 396 B
 * body sha256 d171e05a4fbdc0c016d536162bd9f9e0bd0f07a84af18e3bcc885d108464149a
 * provider record sha256 66652f9ef3e1d840957ffdba8895231c5b89ec3a281fc3c4122bc879177991ee
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163e6c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 local_20 [2];
  undefined2 local_1c;
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  
  iVar2 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined2 *)(param_1 + 500) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar1 = func_0x80036c68(param_1,7,3,0);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x2c6) = 0x23;
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
  local_20[0] = *(undefined2 *)(param_1 + 0x2b8);
  local_1c = *(undefined2 *)(param_1 + 0x2ba);
  iVar1 = FUN_80161f0c(param_1,0xf,5,0xe,600,(uint)_DAT_800e1266 << 1);
  if (iVar1 != 0) {
    func_0x80077d18(2,param_1);
    func_0x80052bd0(3,0);
    func_0x80052c6c(5,0xdc,0);
    func_0x80052d10(4,0xdc,0x28,5);
    FUN_8016227c(param_1,local_20,0xf);
    local_18 = *(undefined2 *)(iVar2 + 0x1656);
    local_14 = *(undefined2 *)(iVar2 + 0x165e);
    local_16 = *(short *)(iVar2 + 0x165a);
    if ((int)*(short *)(iVar2 + 0x165a) < *(short *)(param_1 + 0x25e) + -3000) {
      local_16 = *(short *)(param_1 + 0x25e) + -3000;
    }
    func_0x80037780(0x2400,0,0x800e9028,&local_18);
    FUN_80162114(0x14);
  }
  return;
}
