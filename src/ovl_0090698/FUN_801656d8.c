/* FUN_801656d8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801656d8  body 0x801656d8..0x8016577b  size 164 B
 * body sha256 3f09b5c4a5f37035d4425319fc27cc7a68b257450cd183c60769fb6883796904
 * provider record sha256 8fd1ce122b80bb254f3f391588a19f6f335b4f43f8f4b1c98c7e16044babd7b9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801656d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x2d8) = *(undefined1 *)(param_1 + 5);
  }
  if (*(short *)(param_1 + 0x1a8) == 0) {
    uVar1 = func_0x80074d64(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
    *(undefined2 *)(param_1 + 0x1a8) = uVar1;
  }
  (*(code *)(&PTR_FUN_80167f1c)[*(byte *)(param_1 + 5) - 1])(param_1,param_2,param_3);
  FUN_801668b4(param_1);
  func_0x80035b84(param_1);
  return;
}
