/* FUN_8007c084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c084  body 0x8007c084..0x8007c0ff  size 124 B
 * body sha256 bb12be3cac78620a91481a4800cdef0c3ea138917012a23e57b458507a6564b5
 * provider record sha256 79e6c1025b80c0e8e3d52f31f28bbbbe2817704514cebed4286c5d0a36884ff2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c084(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b108)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
