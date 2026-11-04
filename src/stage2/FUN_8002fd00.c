/* FUN_8002fd00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fd00  body 0x8002fd00..0x8002fd37  size 56 B
 * body sha256 40561dfd3346577beaa154ba2d4ae9a78f48a9e30bd822c9a38c2415bb07f51b
 * provider record sha256 5dff6795a5fe8878042dee78a5411c4ba009f0b4b9c182d4123554ff94c417a5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002fd00(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x14) = 0x2e;
  *(undefined4 *)(*param_1 + 0x18) = param_2;
  (**(code **)*param_1)();
  return;
}
