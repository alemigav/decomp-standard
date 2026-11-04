/* FUN_80163f50
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80163f50  body 0x80163f50..0x80163fe7  size 152 B
 * body sha256 5c1b6597f1a86ef2e7c3a9f21cd25b83e1479b68a22c40b432f1a2d88ce51d9e
 * provider record sha256 4e5d744847efe1f94b1554f45dc2616480cc7b82c50d1b9b0760e0d5e5664be3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163f50(int param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x338);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if ((sVar1 == 0) && (0x9c4 < uVar2)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
