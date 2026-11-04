/* FUN_80165f9c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165f9c  body 0x80165f9c..0x80166017  size 124 B
 * body sha256 7fb725551e741d9523933e7d45148d56fd153453e5ed00d0d1336323ebc1c4bf
 * provider record sha256 9c7f2636ee64883975705b6d481230e08af84229e9bf034fc33e5e5b05bf1c61
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165f9c(int param_1)

{
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166f58)[*(byte *)(param_1 + 6)])();
  FUN_80166980(param_1,3,0);
  FUN_80166980(param_1,2,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,2,(uVar1 & 1) + 1);
  return;
}
