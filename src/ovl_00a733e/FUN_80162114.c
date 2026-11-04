/* FUN_80162114
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162114  body 0x80162114..0x80162193  size 128 B
 * body sha256 51c5c7a9aca1014a5c8dc34b75934eeec1232cb6f6f563668102de0feab6b409
 * provider record sha256 8ca7984095acf0532c9080d12fa0da4f6539641486718b16aae224237907363d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162114(int param_1)

{
  (*(code *)(&PTR_FUN_80167de4)[*(byte *)(param_1 + 5)])();
  *(undefined1 *)(param_1 + 0x2ba) = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(param_1 + 699) = *(undefined1 *)(param_1 + 6);
  *(undefined1 *)(param_1 + 700) = *(undefined1 *)(param_1 + 7);
  *(undefined2 *)(param_1 + 0x2d2) = *(undefined2 *)(param_1 + 0x1e0);
  *(undefined2 *)(param_1 + 0x2d4) = *(undefined2 *)(param_1 + 0x1e2);
  *(undefined2 *)(param_1 + 0x2d6) = *(undefined2 *)(param_1 + 0x1e4);
  FUN_80167c1c(param_1);
  return;
}
