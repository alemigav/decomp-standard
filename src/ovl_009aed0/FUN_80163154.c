/* FUN_80163154
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80163154  body 0x80163154..0x801631c7  size 116 B
 * body sha256 cf46c621cd5ada9004db5753b6a332a41381e725857a5019a5b148c5dd43eaa3
 * provider record sha256 835644aa48a38551ecb1518fb1d5be53b8300c3f47d27aa98379762b74724f7b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163154(int param_1,undefined2 param_2)

{
  short local_38;
  undefined2 local_36;
  short local_34;
  undefined1 auStack_30 [32];
  
  local_38 = 0;
  local_34 = 0;
  local_36 = param_2;
  func_0x80040e58(&local_38,auStack_30);
  func_0x8004276c(auStack_30,param_1 + 0x1e0,&local_38);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_38;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_34;
  return;
}
