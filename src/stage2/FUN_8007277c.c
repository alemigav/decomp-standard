/* FUN_8007277c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007277c  body 0x8007277c..0x800727af  size 52 B
 * body sha256 40fba3b19106573557ab1051967cf36b3f4fc79daf2c2910f2ce752c3cdc375b
 * provider record sha256 e0e7a2349089839e4a1fef5676317ffc5e73e9176f9fa79bbd6b729d42f519d9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8007277c(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x1c) + 1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  uVar2 = FUN_8008c51c(uVar1);
  return ~uVar2 >> 0x1f;
}
