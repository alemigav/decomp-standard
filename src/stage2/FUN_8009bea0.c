/* FUN_8009bea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009bea0  body 0x8009bea0..0x8009bec7  size 40 B
 * body sha256 4757b54ff222a3535ca15ded4bf13a81c12c814abd3051839053cec99005a5b7
 * provider record sha256 7e03c75b37a86fe6406aa929d3e61f25903113b107fc2ea3af2612009ddaca01
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8009bea0(int param_1)

{
  FUN_8009bf04();
  return *(undefined4 *)(param_1 + 4);
}
