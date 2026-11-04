/* FUN_8006eae0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eae0  body 0x8006eae0..0x8006eb07  size 40 B
 * body sha256 f6a11040f86170726b45ec1ed171c48d0e0b9b7e9dadec3cc151429b9bf69789
 * provider record sha256 3a9c1d3d2e380ddab26ecd45acbcbc33a4e0ff27d2900af1555a42a5bc961ce3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006eae0(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  FUN_8006d284();
  return 1;
}
