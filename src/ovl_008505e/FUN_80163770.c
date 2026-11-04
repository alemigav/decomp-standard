/* FUN_80163770
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163770  body 0x80163770..0x8016387b  size 268 B
 * body sha256 ae602917c0c0c4ec36a9ea9fa59420f10bfcaf98f86ac042833745cd325048f7
 * provider record sha256 e6dbf16d4d23ed865194c91a928c83cfa8975d918787c0d0e8a21c17f0fe05b1
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163770(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x2c3) == '\0') {
    iVar1 = -0x7ff1eed0;
  }
  else {
    iVar1 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0x32;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000300;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  if (*(byte *)(param_1 + 0x1e9) < 0xf) {
    if (7 < *(byte *)(param_1 + 0x1e9)) {
      FUN_8016655c(param_1,0x20,0x1e);
    }
    func_0x80032b5c(param_1,0x800);
    func_0x80032dbc(param_1,*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x30),0x40);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  FUN_801664d8(param_1);
  return;
}
