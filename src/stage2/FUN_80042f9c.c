/* FUN_80042f9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042f9c  body 0x80042f9c..0x80043373  size 984 B
 * body sha256 bf05be2dca4687f85ca6593bcdeb038335abb32b2e8d454362debadf37441fbd
 * provider record sha256 8a83b9175360e5910dc8ae492b52675e87c3d3797f1292d9d60b6cccb26a7385
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80042f9c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short local_28;
  short local_26;
  short local_24;
  
  _DAT_80139a70 = *param_3;
  _DAT_80139a74 = param_3[1];
  FUN_8004276c(&DAT_80139a50,&DAT_80139a70,&local_28);
  local_28 = local_28 + _DAT_80139a66;
  local_26 = local_26 + _DAT_80139a6a;
  local_24 = local_24 + _DAT_80139a6e;
  if (local_24 == 0) {
    local_24 = 1;
  }
  iVar2 = (int)local_24;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && ((int)local_28 * (uint)DAT_800efc50 == -0x80000000)) {
    trap(0x1800);
  }
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && ((int)local_26 * (uint)DAT_800efc52 == -0x80000000)) {
    trap(0x1800);
  }
  _DAT_80139a94 = local_24;
  _DAT_80139a90 = (short)((int)((int)local_28 * (uint)DAT_800efc50) / iVar2) + 0xa0;
  _DAT_80139a92 = (short)((int)((int)local_26 * (uint)DAT_800efc52) / iVar2) + 0x78;
  _DAT_80139a70 = *param_2;
  _DAT_80139a74 = param_2[1];
  FUN_8004276c(&DAT_80139a50,&DAT_80139a70,&local_28);
  local_28 = local_28 + _DAT_80139a66;
  local_26 = local_26 + _DAT_80139a6a;
  local_24 = local_24 + _DAT_80139a6e;
  if (local_24 == 0) {
    local_24 = 1;
  }
  iVar2 = (int)local_24;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && ((int)local_28 * (uint)DAT_800efc50 == -0x80000000)) {
    trap(0x1800);
  }
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && ((int)local_26 * (uint)DAT_800efc52 == -0x80000000)) {
    trap(0x1800);
  }
  _DAT_80139a8c = local_24;
  _DAT_80139a88 = (short)((int)((int)local_28 * (uint)DAT_800efc50) / iVar2) + 0xa0;
  _DAT_80139a8a = (short)((int)((int)local_26 * (uint)DAT_800efc52) / iVar2) + 0x78;
  _DAT_80139a70 = *param_1;
  _DAT_80139a74 = param_1[1];
  FUN_8004276c(&DAT_80139a50,&DAT_80139a70,&local_28);
  local_24 = local_24 + _DAT_80139a6e;
  if (local_24 == 0) {
    local_24 = 1;
  }
  iVar2 = (int)(short)(local_28 + _DAT_80139a66) * (uint)DAT_800efc50;
  iVar3 = (int)local_24;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar2 == -0x80000000)) {
    trap(0x1800);
  }
  iVar1 = (int)(short)(local_26 + _DAT_80139a6a) * (uint)DAT_800efc52;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  _DAT_80139a84 = local_24;
  _DAT_80139a80 = (short)(iVar2 / iVar3) + 0xa0;
  _DAT_80139a82 = (short)(iVar1 / iVar3) + 0x78;
  return;
}
