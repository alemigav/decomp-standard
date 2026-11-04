/* FUN_80162694
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162694  body 0x80162694..0x801626c3  size 48 B
 * body sha256 8cfedd339d2bd13f60f3ac8ebdffdeed60593feb8e43c179e2ef45f43f712f08
 * provider record sha256 c5ee51dad451689c5bd34dd9a86563bb5df7bad35c2d3f20b4d947ca129b1e70
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162694(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = func_0x80059e00(param_1,0);
  if ((uVar1 & 2) != 0) {
    _DAT_800e1134 = 0x3000000;
  }
  return;
}
