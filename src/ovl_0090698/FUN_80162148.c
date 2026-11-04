/* FUN_80162148
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162148  body 0x80162148..0x80162217  size 208 B
 * body sha256 6188d4a7adea219e5dafe1572f62a91a5287ed9b09292595152b43b44cc91fb1
 * provider record sha256 4d3c41b6ebc51779e7380aa0dc1bef07d95282949766e426e3629f3ea3109964
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162148(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_801678c8();
  (*(code *)(&PTR_FUN_80167db0)[*(byte *)(param_1 + 0x2be)])(param_1,param_2,param_3);
  FUN_80167b1c(param_1);
  if (*(short *)(param_1 + 0x2b4) != 0) {
    *(short *)(param_1 + 0x2b4) = *(short *)(param_1 + 0x2b4) + -1;
  }
  if (*(char *)(param_1 + 0x2ce) != '\0') {
    *(char *)(param_1 + 0x2ce) = *(char *)(param_1 + 0x2ce) + -1;
  }
  if (*(short *)(param_1 + 0x2b8) == 0) {
    *(undefined2 *)(param_1 + 0x2ba) = 0;
    *(undefined1 *)(param_1 + 0x2cf) = *(undefined1 *)(param_1 + 5);
    *(undefined1 *)(param_1 + 0x2d0) = *(undefined1 *)(param_1 + 6);
    *(undefined1 *)(param_1 + 0x2d1) = *(undefined1 *)(param_1 + 7);
  }
  else {
    *(short *)(param_1 + 0x2ba) = *(short *)(param_1 + 0x2ba) + 1;
  }
  return;
}
