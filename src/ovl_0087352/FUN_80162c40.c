/* FUN_80162c40
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162c40  body 0x80162c40..0x80162d53  size 276 B
 * body sha256 f42259a0d2636ca03252361e6effe38afc8237fa0e7b1ccb9b4b82cc1657f20f
 * provider record sha256 8f62b296f8e606d9a434746f11d2bb667f486f36f5659e09a7a6154030c13ed9
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162c40(int param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  if (0x1c20 < *(uint *)(param_1 + 0x28c)) {
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) == 0) {
      uVar3 = 8;
    }
    else {
      uVar3 = 7;
    }
    FUN_80165c68(param_1,uVar3);
  }
  uVar1 = func_0x80033604();
  if ((uVar1 & 0xf) == 0) {
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = uVar2 & 0x3f;
    uVar3 = 5;
    if (*(int *)(param_1 + 0x2c) <= _DAT_800e138e + -0xe10) {
      uVar3 = 6;
    }
    FUN_80165c68(param_1,uVar3);
  }
  FUN_80165c74(param_1);
  if ((_DAT_800e1322 < 0) && (*(char *)(param_1 + 0x2bd) < '\x01')) {
    FUN_80165ff0(param_1);
  }
  else {
    FUN_80165da8(param_1);
    FUN_80165f80(param_1);
  }
  return;
}
