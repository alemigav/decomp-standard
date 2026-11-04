/* FUN_80071670
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071670  body 0x80071670..0x800716af  size 64 B
 * body sha256 fdc817403cf33fa9f19b9b26d5c684d6b064cdec49d70939d000ee5613064364
 * provider record sha256 906bd48dab722ddc5e09e4c62097deb92f63bb4be672be5f3d4010b82349b093
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071670(int param_1)

{
  FUN_80038f40(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
