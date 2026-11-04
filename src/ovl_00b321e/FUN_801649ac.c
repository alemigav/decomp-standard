/* FUN_801649ac
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801649ac  body 0x801649ac..0x80164a37  size 140 B
 * body sha256 359a19c40bf71617340644f06858ff276b7568e21de05a74252e848f3dfc5285
 * provider record sha256 40450e787171ee4c4a6594599b342baa8c484aee73a35ad202d0c07029a5fe77
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801649ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_801667b8)[*(byte *)(param_1 + 6)])();
  if (*(char *)(param_1 + 6) != '\x03') {
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  *(undefined2 *)(param_1 + 0x2d0) = *(undefined2 *)(param_1 + 0x1e0);
  *(undefined2 *)(param_1 + 0x2d2) = *(undefined2 *)(param_1 + 0x1e2);
  *(undefined2 *)(param_1 + 0x2d4) = *(undefined2 *)(param_1 + 0x1e4);
  return;
}
