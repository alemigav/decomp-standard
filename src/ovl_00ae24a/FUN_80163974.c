/* FUN_80163974
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80163974  body 0x80163974..0x80163bbb  size 584 B
 * body sha256 b93b0542941c783cb58dac874404d69a7a6d442163258d130497543b627d6acd
 * provider record sha256 ddfe8ab3e2ec3e2e714426fb1c97a875d15bfcfdc08abf4a36e1a68850026ee8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163974(int param_1)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  short local_18;
  short local_16;
  short local_14;
  
  iVar3 = *(int *)(param_1 + 0x234);
  local_18 = _DAT_800e10fe - *(short *)(iVar3 + 0x33e);
  local_16 = _DAT_800e1102 - *(short *)(iVar3 + 0x342);
  iVar4 = iVar3 + 0x328;
  local_14 = _DAT_800e1106 - *(short *)(iVar3 + 0x346);
  func_0x80037780(0x5042710,(int)*(short *)(param_1 + 0x66),iVar4,&local_18);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) << 2 | 0x40f1000,(int)*(short *)(param_1 + 0x66),iVar4,&local_18);
  local_18 = local_18 + 800;
  func_0x80037780(0x5042710,(int)*(short *)(param_1 + 0x66),iVar4,&local_18);
  local_18 = local_18 + -800;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 8000 | 0x5040000,(int)*(short *)(param_1 + 0x66),iVar4,
                  &local_18);
  local_14 = local_14 + -0x32c;
  uVar2 = func_0x80033604();
  local_16 = local_16 + 0x100 + (uVar2 & 0xff) * -2;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 8000 | 0x5040000,(int)*(short *)(param_1 + 0x66),iVar4,
                  &local_18);
  local_14 = local_14 + -0x19c;
  uVar2 = func_0x80033604();
  local_16 = local_16 + 0x100 + (uVar2 & 0xff) * -2;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 4000 | 0x5040000,(int)*(short *)(param_1 + 0x66),iVar4,
                  &local_18);
  local_14 = local_14 + 0x7f4;
  uVar2 = func_0x80033604();
  local_16 = local_16 + 0x100 + (uVar2 & 0xff) * -2;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 8000 | 0x5040000,(int)*(short *)(param_1 + 0x66),iVar4,
                  &local_18);
  local_14 = local_14 + 0x19c;
  uVar2 = func_0x80033604();
  local_16 = local_16 + 0x100 + (uVar2 & 0xff) * -2;
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 4000 | 0x5040000,(int)*(short *)(param_1 + 0x66),iVar4,
                  &local_18);
  return;
}
