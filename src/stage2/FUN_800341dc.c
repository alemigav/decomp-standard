/* FUN_800341dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800341dc  body 0x800341dc..0x800341eb  size 16 B
 * body sha256 85aaeff67b3ad34af02baba59994bcebff92e08c909c7e411f8dd45cc1c7beff
 * provider record sha256 2a9dc91d5881e45df748cd58029c66647a5c5e9ec46bf3fb231291d6e4da8352
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800341dc(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x18) = *(byte *)(param_1 + 0x1b) | param_2;
  return;
}
