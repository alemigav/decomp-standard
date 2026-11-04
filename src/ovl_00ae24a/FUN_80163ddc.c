/* FUN_80163ddc
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80163ddc  body 0x80163ddc..0x80163e97  size 188 B
 * body sha256 42e4b52efb10ac2bfc3c154682557e50256cbd9884ff7b33ceab76c40086f7d5
 * provider record sha256 14d93c821dc622966891ec5011b6cbf4c8710136f95e30a4f6536b1ee254ad0a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163ddc(int param_1)

{
  uint uVar1;
  int iVar2;
  short local_18;
  short local_16;
  short local_14;
  
  iVar2 = *(int *)(param_1 + 0x234);
  local_18 = _DAT_800e10fe - *(short *)(iVar2 + 0x33e);
  local_16 = _DAT_800e1102 - *(short *)(iVar2 + 0x342);
  local_14 = _DAT_800e1106 - *(short *)(iVar2 + 0x346);
  func_0x80037780(0x5042710,(int)*(short *)(param_1 + 0x66),iVar2 + 0x328,&local_18);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) << 2 | 0x40f1000,(int)*(short *)(param_1 + 0x66),iVar2 + 0x328,
                  &local_18);
  return;
}
