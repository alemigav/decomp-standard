/* FUN_80163280
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163280  body 0x80163280..0x80163337  size 184 B
 * body sha256 ea0d15c02e208bdf2bd8d3221dd5cdc49b352e8e6d5093c2e6bb57e2b943fd80
 * provider record sha256 5b6d551c57c0fd13753c1ec90fb6966792a14388a2b1d0a6fb316d2db59b5ca6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163280(int param_1)

{
  int iVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar1 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 6) == '\0') {
    func_0x80077d18(2,param_1);
    local_18 = *(undefined2 *)(param_1 + 0x2a);
    local_16 = *(undefined2 *)(param_1 + 0x2e);
    local_14 = *(undefined2 *)(param_1 + 0x32);
    *(undefined4 *)(iVar1 + 0x2f0) = 1;
    *(undefined4 *)(iVar1 + 0x468) = 1;
    func_0x80037780(0x100c00,0,&DAT_800e9028,&local_18);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    *(undefined1 *)(param_1 + 0x1e9) = 0;
  }
  else {
    if (*(char *)(param_1 + 6) != '\x01') {
      return;
    }
    *(undefined1 *)(param_1 + 0x1e9) = 0;
  }
  func_0x80036b84(param_1,4,0,0);
  return;
}
