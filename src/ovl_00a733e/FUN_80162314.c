/* FUN_80162314
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162314  body 0x80162314..0x8016238f  size 124 B
 * body sha256 12c586a02878bc169fb5fc28481327fdb49785f8871f8a19e888040024cf6cf0
 * provider record sha256 caf6e543574d8b15b29a922a7c2852fee3adc09e2fec242bbd4561536d6e1517
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162314(int param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x800334c8();
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80032b5c(param_1,0);
  if (*(short *)(param_1 + 0x270) == 2) {
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  func_0x80033648(param_1);
  return;
}
