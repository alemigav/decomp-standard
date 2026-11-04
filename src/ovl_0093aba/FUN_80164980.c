/* FUN_80164980
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80164980  body 0x80164980..0x80164a1f  size 160 B
 * body sha256 f10ea2629b57912ad78a0c6e14c7c9f76275ae9e4cbc5bc73898ff1a44b56179
 * provider record sha256 d5d0796118334c7674d98b4133fb46395cb691eb559e2a54701271b37cee3e6e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164980(int param_1,short param_2,undefined2 param_3)

{
  short local_38;
  undefined2 local_36;
  short local_34;
  undefined1 auStack_30 [32];
  
  local_38 = 0;
  local_34 = 0;
  local_36 = param_3;
  func_0x80040e58(&local_38,auStack_30);
  local_36 = 0;
  local_34 = 0;
  local_38 = param_2;
  func_0x8004276c(auStack_30,&local_38,&local_38);
  *(int *)(param_1 + 0x28) = local_38 + _DAT_800e1158;
  *(int *)(param_1 + 0x30) = local_34 + _DAT_800e1160;
  return;
}
