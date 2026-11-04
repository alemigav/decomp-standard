/* FUN_80164f14
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164f14  body 0x80164f14..0x80164f9f  size 140 B
 * body sha256 d8e6053daff110ad1e53cbd479dde25d136f6e46e58babe9e2aadac95e5bfa73
 * provider record sha256 72bbb977860155a2743f99edc1d14c800564e18c5e72e516a005ab07c4a56da3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164f14(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_801667d4)[*(byte *)(param_1 + 6)])();
  if (*(char *)(param_1 + 6) != '\x03') {
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  *(undefined2 *)(param_1 + 0x2d0) = *(undefined2 *)(param_1 + 0x1e0);
  *(undefined2 *)(param_1 + 0x2d2) = *(undefined2 *)(param_1 + 0x1e2);
  *(undefined2 *)(param_1 + 0x2d4) = *(undefined2 *)(param_1 + 0x1e4);
  return;
}
