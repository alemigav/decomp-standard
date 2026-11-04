/* FUN_8006db98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006db98  body 0x8006db98..0x8006dbbf  size 40 B
 * body sha256 05eaca03a0d4e572f2f073a3915ee35c21200d062f10230e73ea266fa5fd1e6b
 * provider record sha256 dd70fe2e56c190523e238190b696865d1d9f3362597c4d2bc498c3b4a0d22246
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006db98(int param_1)

{
  FUN_8006d5dc(param_1,*(undefined1 *)(*(int *)(param_1 + 0x1c) + 3));
  return 1;
}
