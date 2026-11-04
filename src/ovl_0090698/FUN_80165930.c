/* FUN_80165930
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165930  body 0x80165930..0x8016598b  size 92 B
 * body sha256 a2851a68b6de0bd2ce76a7e8db679576fe5197519de4e74d4002d69548d613bc
 * provider record sha256 d1c8404cef9df7fdc061f2ca0f454c85be1a4405e5d94ba31295803a137c5580
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165930(int param_1)

{
  *(undefined1 *)(param_1 + 6) = 1;
  *(undefined2 *)(param_1 + 0x1e2) = 0x28;
  *(undefined4 *)(param_1 + 0x1e8) = 0xc090000;
  *(undefined2 *)(param_1 + 0x1e0) = 0;
  *(undefined2 *)(param_1 + 0x1e4) = 0;
  *(undefined2 *)(param_1 + 0x68) = 0;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 800;
  if (*(char *)(param_1 + 0x2d8) != '\x01') {
    FUN_8016703c(param_1,0,0);
  }
  return;
}
