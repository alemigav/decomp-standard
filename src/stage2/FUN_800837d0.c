/* FUN_800837d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800837d0  body 0x800837d0..0x8008383b  size 108 B
 * body sha256 0b99dc5096622b103634972e35447ac746be68eb2eef156c8d0de6281d2f7470
 * provider record sha256 fb3ba6007752bbfcfea9e46b6e2bba0aafeab29a038d6ffe6a6be21cfd486f9e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800837d0(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_38 [2];
  undefined2 local_36;
  undefined1 auStack_30 [32];
  
  FUN_80082200(auStack_38,0,8);
  local_36 = param_1;
  FUN_80040e58(auStack_38,auStack_30);
  FUN_8004276c(auStack_30,param_2,param_3);
  return;
}
