/* FUN_801805f0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801805f0  body 0x801805f0..0x801806cb  size 220 B
 * body sha256 2e05f139178d38ee0f208be3717a75491a76c58c19c3924249ea3d3591bc7e61
 * provider record sha256 60111f4605038b6c15e8db9c313a290596e2cc01ffc567fbb1f86ad76165e6de
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801805f0(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  func_0x80004cfc(param_1,_DAT_800c52dc + 0x3b807U & 0xfffffff8,0,0);
  func_0x800752dc(param_2,8,1);
  uVar1 = func_0x800a8bc8(param_2,param_3,_DAT_800c52dc + 0x3b807U & 0xfffffff8,0);
  func_0x800a2218(((uint)DAT_80119e74 * 0x7f) / 100 & 0xff,0,uVar1,0);
  return uVar1;
}
