/* FUN_800a2218
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2218  body 0x800a2218..0x800a228b  size 116 B
 * body sha256 2a67801442a74e37dde186738c187a779b92f3c4c2db710c2339f36264fdaf9c
 * provider record sha256 59524d6e7bf73e9393b6dfb3b94e6a465aaaeac3b87aa86b0b2fdf2e6cf53086
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a2218(undefined1 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a13c4(param_1,param_2,param_3,param_4);
    FUN_800a56c0();
  }
  return;
}
