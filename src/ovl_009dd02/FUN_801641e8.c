/* FUN_801641e8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801641e8  body 0x801641e8..0x80164233  size 76 B
 * body sha256 cd06504e162389f0ba61d7d7c4582c35eab1026ddd0c71e054dae7cc60dcdcd0
 * provider record sha256 ddc2b37d81ebd11324c40234697f65940a55e3ebd63db428530a7ad9c7d953f5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801641e8(int param_1)

{
  (*(code *)(&PTR_FUN_801672d0)[*(byte *)(param_1 + 6)])();
  *(undefined1 *)(param_1 + 0x2d6) = 1;
  *(undefined1 *)(param_1 + 0x2d7) = 1;
  return;
}
