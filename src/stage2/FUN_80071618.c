/* FUN_80071618
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071618  body 0x80071618..0x8007166f  size 88 B
 * body sha256 901022a730594351761f28982bf6ab81e823bc0585d5e44501e6101b99c444d8
 * provider record sha256 fadee924ea85a02a0b78b81dbb5713b3d92e3aa4080b8455d79174e8842fac07
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071618(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800717a0((int)*(char *)(*(int *)(param_1 + 0x1c) + 3),
                       (int)*(char *)(*(int *)(param_1 + 0x1c) + 4));
  FUN_80038e98(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),
               *(undefined1 *)(*(int *)(param_1 + 0x1c) + 2),uVar1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 5;
  return 1;
}
