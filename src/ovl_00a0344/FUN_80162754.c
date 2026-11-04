/* FUN_80162754
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162754  body 0x80162754..0x801627a7  size 84 B
 * body sha256 d5cf1f8d747d9639939d2685ab5ec89f94843e47e76ef900d06ccd66524a8184
 * provider record sha256 9a315a963e2f479b3b724a01b2bb3f623aab1ecb7dbc4598a4a9c02ee87f6f09
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162754(int param_1)

{
  undefined1 uVar1;
  
  *(undefined1 *)(param_1 + 0x2c6) = 1;
  func_0x80089d54();
  *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) & 0x7f;
  uVar1 = 8;
  if (*(char *)(param_1 + 0x2c7) == '\0') {
    uVar1 = 2;
  }
  *(undefined1 *)(param_1 + 5) = uVar1;
  *(undefined2 *)(param_1 + 6) = 0;
  return;
}
