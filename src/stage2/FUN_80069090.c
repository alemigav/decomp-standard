/* FUN_80069090
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069090  body 0x80069090..0x800691bf  size 304 B
 * body sha256 721099f0b52e12cccb7c95cf1f436c3a7e418341dba006d9d0872b3d08c63823
 * provider record sha256 ba49b3fa7321a820a329f9ca6a21e06b5fd5fe437ecfb4ee35180e9787221da1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80069090(int param_1,int param_2,short *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = (uint)((ushort)param_3[2] >> 1);
  iVar6 = *(int *)(param_1 + 0x120) - ((int)*param_3 + uVar3);
  iVar5 = *(int *)(param_1 + 0x128) - ((int)param_3[1] + uVar3);
  iVar1 = FUN_80040bb4(iVar6 * iVar6 + iVar5 * iVar5);
  iVar4 = (uVar3 + param_2) - iVar1;
  if (iVar4 < 1) {
    uVar2 = 0;
  }
  else {
    iVar6 = (iVar6 + 8) * iVar4;
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar6 == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = (iVar5 + 8) * iVar4;
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    uVar2 = 1;
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + iVar6 / iVar1;
    *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + iVar4 / iVar1;
  }
  return uVar2;
}
