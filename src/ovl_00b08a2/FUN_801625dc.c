/* FUN_801625dc
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801625dc  body 0x801625dc..0x8016283f  size 612 B
 * body sha256 bbf9563dfda9e7f4710eef0eca0e71b7519a820c41a252e57811f1bb7db8e8b4
 * provider record sha256 1aceb08b59614a3d1cb00a1d842e0379f3c0d92f06e175fdbef1ba534fc4258c
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801625dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  int iVar6;
  uint *puVar7;
  
  puVar7 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    puVar7 = *(uint **)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000000;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    *puVar7 = *puVar7 | 1;
    iVar6 = _DAT_800e1364;
    iVar1 = *(int *)(_DAT_800e1364 + 0x50) - *(int *)(param_1 + 0x2c);
    iVar2 = *(int *)(_DAT_800e1364 + 0x54) - *(int *)(param_1 + 0x30);
    iVar1 = func_0x80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
    iVar6 = *(int *)(iVar6 + 0x4c) - *(int *)(param_1 + 0x28);
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (iVar1 << 0xc == -0x80000000)) {
      trap(0x1800);
    }
    uVar3 = func_0x80040a14((iVar1 << 0xc) / iVar6);
    *(undefined2 *)(param_1 + 0x68) = uVar3;
    uVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2e),
                            (int)((uint)*(ushort *)(param_1 + 0x32) * -0x10000) >> 0x10,
                            (int)*(short *)(_DAT_800e1364 + 0x52),
                            (int)((uint)*(ushort *)(_DAT_800e1364 + 0x56) * -0x10000) >> 0x10);
    *(undefined2 *)(param_1 + 100) = uVar3;
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar5 = *(short *)(puVar7 + 0x49);
    *(short *)(puVar7 + 0x49) = sVar5 + 0x100;
    if (0x800 < (short)(sVar5 + 0x100)) {
      *(undefined1 *)(param_1 + 6) = 2;
LAB_801627dc:
      *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    }
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x100);
    sVar5 = *(short *)(puVar7 + 0x49);
    *(short *)(puVar7 + 0x49) = sVar5 + 0x100;
    if (0x1000 < (short)(sVar5 + 0x100)) {
      *(undefined2 *)(puVar7 + 0x49) = 0x1000;
      *(undefined1 *)(param_1 + 6) = 3;
      uVar4 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar4 & 0xf) + 10;
    }
    break;
  case 3:
    sVar5 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar5;
    if (sVar5 != -1) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 4;
    goto LAB_801627dc;
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x7d);
    sVar5 = *(short *)(puVar7 + 0x49);
    *(ushort *)(puVar7 + 0x49) = sVar5 - 0x200U;
    if ((int)((uint)(ushort)(sVar5 - 0x200U) << 0x10) < 0) {
      *(undefined2 *)(puVar7 + 0x49) = 0;
      *(undefined4 *)(param_1 + 4) = 0x1000000;
    }
  }
  return;
}
