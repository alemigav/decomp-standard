/* FUN_80165bc4
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165bc4  body 0x80165bc4..0x80165c57  size 148 B
 * body sha256 72cfc06af5313d0d42337bd796193c91ccc03a61849619f7cfb0bdd60381be8d
 * provider record sha256 c812a0cd0568657d1e4695044d1013f4153ee4e3df6fc0848ad2edb7728ecd2f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165bc4(int param_1)

{
  int iVar1;
  undefined1 auStack_30 [20];
  int local_1c;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,auStack_30);
  func_0x800424ec(auStack_30,iVar1 + 0x1030,auStack_30);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (local_1c - *(int *)(iVar1 + 0x1074));
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (local_14 - *(int *)(iVar1 + 0x107c));
  return;
}
