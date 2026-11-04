/* FUN_8016b9c8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016b9c8  body 0x8016b9c8..0x8016ba27  size 96 B
 * body sha256 0fd3e0a257c842f1c9e8f93b96b3fc9abdce9a4089b261a29139968820b71c2f
 * provider record sha256 720f69696bd150b848dbd799a80333aea3ec93da541661473d0cee8329df2920
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b9c8(int param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined1 auStack_30 [32];
  
  local_38 = 0;
  local_34 = 0;
  local_36 = param_2;
  func_0x80040e58(&local_38,auStack_30);
  func_0x8004276c(auStack_30,param_3,param_1 + 0x1e0);
  return;
}
