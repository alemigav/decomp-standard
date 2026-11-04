/* FUN_800267a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800267a4  body 0x800267a4..0x8002681f  size 124 B
 * body sha256 697bcc1813337a84cbbb8e6fba5c0961592e81a6f7e38761df7ffbdd2d917bde
 * provider record sha256 80acff13ed7d3dc195ea187a5cd8f3bee0ba7c5e923732f94fdc30144d2e855e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800267a4(int param_1,code *param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x800072e0();
  DAT_80112780 = (undefined1)param_1;
  (&DAT_80112968)[param_1] = 1;
  func_0x80007300(uVar1);
  (*param_2)();
  uVar1 = func_0x800072e0();
  (&DAT_80112968)[param_1] = param_3;
  func_0x80007300(uVar1);
  return;
}
