/* FUN_801659ac
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801659ac  body 0x801659ac..0x80165a53  size 168 B
 * body sha256 7a96cb7ea947cdc3f1437312e229f0fe7174a60fea974011df8b199c49a1d19d
 * provider record sha256 6ea8d000efd7a43f50e0c7d34ca9127451bbc72589fafa1e4579afa87bbcad5f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801659ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0xa000f00;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1030000;
  }
  func_0x80032b5c(param_1,0);
  return;
}
