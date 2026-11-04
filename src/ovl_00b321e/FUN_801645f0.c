/* FUN_801645f0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801645f0  body 0x801645f0..0x80164683  size 148 B
 * body sha256 c4fe2b1f0432b47eab97f4d2bc1fe3a1ddc649f16ea31118106af5ab17de3641
 * provider record sha256 8edf5f6259c14d2090bee1bb9a6d6d0fb53e350dddac9ae232e588b2d09211e0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801645f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_801667a8)[*(byte *)(param_1 + 6)])();
  if (*(char *)(param_1 + 6) != '\0') {
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  *(undefined2 *)(param_1 + 0x2d0) = *(undefined2 *)(param_1 + 0x1e0);
  *(undefined2 *)(param_1 + 0x2d2) = *(undefined2 *)(param_1 + 0x1e2);
  *(undefined2 *)(param_1 + 0x2d4) = *(undefined2 *)(param_1 + 0x1e4);
  return;
}
