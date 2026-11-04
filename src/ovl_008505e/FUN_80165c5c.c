/* FUN_80165c5c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165c5c  body 0x80165c5c..0x80165cd7  size 124 B
 * body sha256 b42ae13bbf717a210ae672508cb28555bb95418c54a7949948f0d722ded09d0a
 * provider record sha256 3c78eac0363d27ff64a1300f67c519e08a6066b87c970648fa9254d338118bf8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c5c(int param_1)

{
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166f48)[*(byte *)(param_1 + 6)])();
  FUN_80166980(param_1,3,0);
  FUN_80166980(param_1,2,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,2,(uVar1 & 1) + 1);
  return;
}
