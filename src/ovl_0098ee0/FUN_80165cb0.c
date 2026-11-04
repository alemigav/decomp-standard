/* FUN_80165cb0
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165cb0  body 0x80165cb0..0x80165d23  size 116 B
 * body sha256 45bfa7b2c7892823433d2f819a3f5ebb3ae03f8e3e70ffa2d4132a365e0dcc90
 * provider record sha256 81f74708e8e74c87cb5bf714a70b1c145c6593a85580e3037fe6d72c65710108
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165cb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    *(undefined1 *)(param_1 + 5) = 0xff;
    FUN_80165ca8();
  }
  (*(code *)(&PTR_FUN_801668f0)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
