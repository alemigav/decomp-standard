/* FUN_80088548
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088548  body 0x80088548..0x8008857b  size 52 B
 * body sha256 5cc7eaad5efbae18b7e77cc8f5b30a24b3ca207776733fa0cb29b4418e4953c0
 * provider record sha256 9dbf5ab34ae9b244983add3c9bd00cbcaf9c77d5e8dd97fdf7f85340872d201e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80088548(undefined2 *param_1,int param_2)

{
  DAT_8012bae0 = param_1;
  *param_1 = 1;
  param_1[1] = 0;
  *(int *)(param_1 + 2) = param_2 + -0x20;
  *(undefined2 *)((int)param_1 + param_2 + -0x10) = 8;
  *(undefined2 *)((int)param_1 + param_2 + -0xe) = 0;
  *(undefined4 *)((int)param_1 + param_2 + -0xc) = 0;
  return;
}
