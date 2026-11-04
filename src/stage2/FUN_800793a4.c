/* FUN_800793a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800793a4  body 0x800793a4..0x80079417  size 116 B
 * body sha256 31fae6d3f07e96177df2f77f9a5e30659b8ddbc15509a81dac6d0846cf6f5f8e
 * provider record sha256 c0c4ae81427ee54e5d99aa1a1996fd7a3eeb9ac05bee5db63fc72bb60ae53514
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800793a4(short param_1)

{
  FUN_800b2098((int)((uint)DAT_80119e73 * (int)param_1) >> 7 & 0xff,0,0,1);
  FUN_800b2098((int)((uint)DAT_80119e74 * (int)param_1) >> 7 & 0xff,0,1,0);
  return;
}
