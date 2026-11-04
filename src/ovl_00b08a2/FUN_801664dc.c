/* FUN_801664dc
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801664dc  body 0x801664dc..0x8016650f  size 52 B
 * body sha256 9fe1f6ac21460c678172d75ac37ee907ed830bf93f89b66127ff20a59735511d
 * provider record sha256 bb8f719dc30358940e9e877f9325896fec4f37d386f29c8549f01f58d8f0cdf7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801664dc(int param_1)

{
  (**(code **)(&DAT_801672c8 + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
