/* FUN_801675bc
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801675bc  body 0x801675bc..0x801675eb  size 48 B
 * body sha256 41823351bff80038461eb81bd7a3c49cf96b325c81a03cf7e5c05cfe8dc44fba
 * provider record sha256 eae30b51599bc8725927facafc849032ced11ace2b244ee424b340113d90f6e7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801675bc(int param_1,char param_2,char param_3)

{
  _DAT_800e1380 = param_1;
  _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
  _DAT_800e1134 = CONCAT13(5,(uint3)(byte)(param_2 + param_3) << 0x10);
  _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
  return;
}
