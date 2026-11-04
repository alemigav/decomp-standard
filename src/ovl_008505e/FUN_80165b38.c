/* FUN_80165b38
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165b38  body 0x80165b38..0x80165bb3  size 124 B
 * body sha256 3bb33bacf1a763ed24943305a0ef99472d35d8b2be09f773e9cb6ba6907d39ac
 * provider record sha256 0e61a12e26f38ea38fc1a729892f1ae2c41c8708d00c7316e20d9280869d6e15
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165b38(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  
  func_0x80035b84();
  bVar1 = *(byte *)(param_1 + 0x2bf);
  *(undefined1 *)(param_1 + 0x2bf) = 0;
  FUN_80164d90(param_1,param_2,param_3);
  if (*(char *)(param_1 + 0x2cd) == '\0') {
    func_0x80077d18(7,param_1);
  }
  if ((bVar1 & 0x3f) == 2) {
    *(undefined2 *)(param_1 + 0x1e0) = 0;
  }
  return;
}
