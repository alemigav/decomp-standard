/* FUN_8006fea4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fea4  body 0x8006fea4..0x8006feeb  size 72 B
 * body sha256 bd83b99689fd019edd7ee65dd1a5b3ed2620749a4f427a0e06a6529574d79195
 * provider record sha256 768a239bafb2e5107531c361f7eefa5420bc85f47e9b99287cfe883af4c43241
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006fea4(int param_1)

{
  FUN_8006ff48(*(undefined4 *)(param_1 + 0x154),*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),
               (int)*(short *)(*(int *)(param_1 + 0x1c) + 2));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
