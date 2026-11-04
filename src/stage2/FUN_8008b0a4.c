/* FUN_8008b0a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b0a4  body 0x8008b0a4..0x8008b0eb  size 72 B
 * body sha256 57af4efb85683654b3faa53fbeab121971034f5b59300a20450396f4ccd77c99
 * provider record sha256 b74abd0b14dff20352260bad67716d6a4fdffdd9f6de98d6181bc194d19fdca4
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008b0a4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x8000cd40(1);
  if (param_1 != 0) {
    FUN_8008b040(param_1);
  }
  func_0x8000cd40(uVar1);
  return;
}
