/* FUN_801664c4
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801664c4  body 0x801664c4..0x801664eb  size 40 B
 * body sha256 3f094030a93b2d52f9e13f39623cc777970aeefb7dcfa84b6e57bb11bd833ae1
 * provider record sha256 9662d9ae8f2678d7410d2d126db261b494cbd6812354ba7e83845d16f58d6239
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801664c4(uint *param_1)

{
  *(undefined2 *)(param_1 + 0xb5) = 0;
  *param_1 = *param_1 | 0x42;
  FUN_801664ec();
  return;
}
