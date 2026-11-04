/* FUN_80165d88
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165d88  body 0x80165d88..0x80165e1f  size 152 B
 * body sha256 3d444842ebf9bc931b9f6e3ed274a3b2d561f1153afc3e31c262526fc7dffbcd
 * provider record sha256 2776057ea886aaa24a57f1652169010e8ef82c700649c51dbd6582bfabeb8dd5
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165d88(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80165980();
    *(undefined1 *)(param_1 + 0x2c1) = 0x46;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) == 0) {
      FUN_80165770(param_1,0x14,0x1a);
      uVar2 = 0x14;
    }
    else {
      FUN_80165770(param_1,0xe,0x14);
      uVar2 = 0xe;
    }
    FUN_80166b98(param_1,uVar2,0);
  }
  else {
    FUN_801656c0(param_1);
  }
  return;
}
