/* FUN_8004a328
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a328  body 0x8004a328..0x8004a3df  size 184 B
 * body sha256 d5377f88da1931b9d5dbdc9f9faa5230878df2cd0bf6f420212efaa00d3200d9
 * provider record sha256 e55fa9b1530db131b0cf707e773300a114514cbf24abfadf10e8ca4942ad9d94
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8004a328(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  param_2 = param_2 & 0x7f;
  uVar5 = *(int *)(param_3 + param_2 * -8 + 8) - (int)DAT_800e10f2;
  uVar4 = *(int *)(param_1 + param_2 * -8 + 0xc) - (int)DAT_800e10f2;
  if ((int)(uVar5 ^ uVar4) < 0) {
    return false;
  }
  iVar3 = *(int *)(param_2 * 8 + param_1 + 4);
  iVar1 = (*(int *)(param_2 * 8 + param_3) - iVar3) * uVar4;
  iVar2 = uVar5 + uVar4;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return (uint)((iVar1 / iVar2 + iVar3) - (int)DAT_800e10f6) <
         (uint)((int)DAT_800e10f4 - (int)DAT_800e10f6);
}
