/* FUN_80010584
 * image   boot (boot), base 0x80000480
 * address 0x80010584  body 0x80010584..0x800106b7  size 308 B
 * body sha256 c9e27990e41d5edd70ae98ef8426dbc6273b44c8d73fe046946103cd5361a4d3
 * provider record sha256 923e15ea440d191c2e226e8a4a678c739ec5cd508214ce61a2423e59adbca9e8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
longlong *
FUN_80010584(longlong *param_1,undefined4 param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  bool bVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  int local_20;
  uint local_1c;
  
  lVar5 = FUN_800106c0(param_3,param_4,param_5,param_6);
  lVar3 = lVar5 * CONCAT44(param_5,param_6);
  uVar2 = (uint)lVar3;
  local_1c = param_4 - uVar2;
  local_20 = (param_3 - (int)((ulonglong)lVar3 >> 0x20)) - (uint)(param_4 < uVar2);
  if ((lVar5 < 0) && ((0 < local_20 || ((local_20 == 0 && (local_1c != 0)))))) {
    iVar4 = (int)lVar5 + 1;
    lVar5 = CONCAT44((int)((ulonglong)lVar5 >> 0x20) + (uint)(iVar4 == 0),iVar4);
    bVar1 = local_1c < param_6;
    local_1c = local_1c - param_6;
    local_20 = (local_20 - param_5) - (uint)bVar1;
  }
  *param_1 = lVar5;
  *(int *)(param_1 + 1) = local_20;
  *(uint *)((int)param_1 + 0xc) = local_1c;
  return param_1;
}
