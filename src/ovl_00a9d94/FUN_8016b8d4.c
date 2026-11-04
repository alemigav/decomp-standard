/* FUN_8016b8d4
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016b8d4  body 0x8016b8d4..0x8016b9c7  size 244 B
 * body sha256 2d683d58032f7b77c6ef3881fd6746cc655faa35d32df623d796f48cd26c64bf
 * provider record sha256 eed854e756ef5f8d3a7c63aafdcbf569b4df91c5560868dadacb4bb252281dac
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b8d4(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined2 local_18;
  short local_16;
  short local_14;
  ushort local_10 [4];
  
  *(undefined1 **)(param_1 + 0x250) = &DAT_800e1130;
  func_0x800349d0(param_1,(int)*(short *)(param_1 + 0x66),local_10);
  local_10[0] = local_10[0] & 0xfff;
  if (0x800 < local_10[0]) {
    local_10[0] = local_10[0] - 0xfff;
  }
  iVar4 = 0;
  iVar5 = 0;
  if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
    piVar3 = &DAT_8016c57c;
    iVar2 = *(int *)(*(int *)(param_1 + 0x234) + 0xfd0);
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + (iVar1 * 0x10 * (int)*(short *)(iVar2 + 0xc) >> 0x10);
      iVar2 = iVar2 + 4;
    } while (iVar4 < 4);
    if (iVar5 < -0x2c8) {
      iVar5 = -0x2c8;
    }
    if (0 < iVar5) {
      iVar5 = 0;
    }
  }
  iVar4 = *(int *)(param_1 + 0x234);
  local_18 = *(undefined2 *)(iVar4 + 0x2688);
  local_16 = *(short *)(iVar4 + 0x268a) + local_10[0];
  local_14 = *(short *)(iVar4 + 0x268c) + (short)iVar5;
  func_0x80040e58(&local_18,iVar4 + 0x2638);
  return;
}
