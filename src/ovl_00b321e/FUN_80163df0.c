/* FUN_80163df0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163df0  body 0x80163df0..0x80163e5f  size 112 B
 * body sha256 54f0bcd04c3e28486e2bbabc77f61124b5b3a90b4f6055836a92f03e4ae18025
 * provider record sha256 8b725d1324acf181952d040c6f05c9529eedcef478a4439552bdac60f2ec6a6c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163df0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80166724)[*(byte *)(param_1 + 6)])();
  func_0x80089d54(param_1,param_2,param_3,0x200);
  func_0x80033648(param_1);
  return;
}
