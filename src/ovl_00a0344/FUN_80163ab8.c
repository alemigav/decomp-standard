/* FUN_80163ab8
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163ab8  body 0x80163ab8..0x80163b0b  size 84 B
 * body sha256 59e9d66cfa38ceed3105229dde9f93827b85a5590bc2eb3a6b31f0b900541a65
 * provider record sha256 a46c0f781106ea0a65bc779babc6678c92a222e3cb629aabb1a77f0141548841
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163ab8(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = param_2;
  *(undefined1 *)(param_1 + 4) = 2;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  func_0x80052bd0(3,0);
  func_0x80052c6c(4,200,3);
  return;
}
