/* FUN_80073018
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073018  body 0x80073018..0x80073057  size 64 B
 * body sha256 65603fde82a76da3205ce3deac6eb3011f2effe6ed8694f9d80df3cdaefe4574
 * provider record sha256 251b0e377f8b6f5138834ae6050c61c3910f8a70c2e3ec3b3b5ba937a25f50b3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073018(int param_1)

{
  FUN_8009f320(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
