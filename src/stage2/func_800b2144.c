/* func_800b2144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2144  body 0x800b2144..0x800b21a7  size 100 B
 * body sha256 5b2b37d8d92c8ccd67b31bcc6590e5df12f62aeafee64456d87d19b4032c4e35
 * provider record sha256 1a832aecdef631246f8ed60634539c7f4ae15355d097e12c785701edf4f94de2
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800b2144(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a7e30(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return;
}
