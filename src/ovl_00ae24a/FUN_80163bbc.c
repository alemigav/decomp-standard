/* FUN_80163bbc
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80163bbc  body 0x80163bbc..0x80163ddb  size 544 B
 * body sha256 9fbcd81483c06374cb9acc9d28e24e0ebf710da17ab2bbe7acec2751a93a3f42
 * provider record sha256 b78d4ff9a07db868397c991966bb8fc4f48443e97416bde433e6112c27d21abd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163bbc(int param_1)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  short local_18;
  short local_16;
  short local_14;
  
  iVar3 = *(int *)(param_1 + 0x234);
  local_18 = _DAT_800e10fe - *(short *)(iVar3 + 0x33e);
  local_16 = _DAT_800e1102 - *(short *)(iVar3 + 0x342);
  local_14 = _DAT_800e1106 - *(short *)(iVar3 + 0x346);
  uVar1 = func_0x80033604();
  iVar3 = iVar3 + 0x328;
  func_0x80037780((uVar1 & 0xff) * 4 + 0x2770 | 0x40f0000,(int)*(short *)(param_1 + 0x66),iVar3,
                  &local_18);
  local_18 = local_18 + 800;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 10000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),iVar3,
                  &local_18);
  local_18 = local_18 + -800;
  local_14 = local_14 + -0x264;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 8000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),iVar3,
                  &local_18);
  local_14 = local_14 + 0x4c8;
  uVar2 = func_0x80033604();
  local_16 = local_16 + 0x100 + (uVar2 & 0xff) * -2;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 8000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),iVar3,
                  &local_18);
  uVar2 = func_0x80033604();
  local_14 = local_14 + -0x364 + (uVar2 & 0xff) * 2;
  uVar2 = func_0x80033604();
  local_16 = local_16 + 0x100 + (uVar2 & 0xff) * -2;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 6000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),iVar3,
                  &local_18);
  uVar2 = func_0x80033604();
  local_14 = local_14 + 0x100 + (uVar2 & 0xff) * -2;
  uVar2 = func_0x80033604();
  local_16 = local_16 + 0x100 + (uVar2 & 0xff) * -2;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 6000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),iVar3,
                  &local_18);
  return;
}
