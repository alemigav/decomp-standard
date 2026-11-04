/* FUN_801638e0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801638e0  body 0x801638e0..0x8016394b  size 108 B
 * body sha256 51ecb70832e789fa17fa1db56ea97026ed4bc63d0d356140daf22988d8981201
 * provider record sha256 37f96eae3a6069884b53b270196cbe0614e7e766fbd54113852076574d9d016e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801638e0(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x60);
  if ((iVar1 != 0) || ((*(ushort *)(param_1 + 0x2c6) & 2) == 0)) {
    FUN_80165c68(param_1,4);
  }
  FUN_80165f80(param_1);
  return;
}
