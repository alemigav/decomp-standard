/* FUN_800828ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800828ac  body 0x800828ac..0x80082d0f  size 1124 B
 * body sha256 a10b7e35cbd34a827eea2a5d652ebf0b2f2fbeb2f4a7188682c66dd53753e262
 * provider record sha256 99aae82b3d3c291763f384c94d02ff453da2d519c2eb853c9f161697e5db8e46
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800828ac(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  int local_98;
  int local_94;
  undefined4 local_90;
  uint local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  int local_70;
  
  DAT_801315d0 = *param_1;
  DAT_801315d4 = param_1[1];
  DAT_801315d8 = param_1[2];
  DAT_801315dc = *param_2;
  DAT_801315e0 = param_2[1];
  DAT_801315e4 = param_2[2];
  DAT_800e9134 = 0x10000000;
  DAT_800e9138 = 0;
  DAT_800e913c = 0x10000000;
  DAT_800e9140 = 0;
  DAT_800e9144 = 0x10000000;
  DAT_800e9148 = 0;
  DAT_800e914c = 0;
  DAT_800e9150 = 0;
  iVar4 = *param_2 - *param_1;
  iVar2 = param_2[1] - param_1[1];
  iVar3 = param_2[2] - param_1[2];
  iVar1 = FUN_80040bb4(iVar4 * iVar4 + iVar2 * iVar2 + iVar3 * iVar3);
  uVar5 = (iVar2 * 0x1000) / iVar1;
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (iVar2 * 0x1000 == -0x80000000)) {
    trap(0x1800);
  }
  DAT_8011c854 = iVar1;
  iVar2 = FUN_80040bb4(iVar4 * iVar4 + iVar3 * iVar3);
  iVar6 = (iVar2 << 0xc) / iVar1;
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (iVar2 << 0xc == -0x80000000)) {
    trap(0x1800);
  }
  local_98 = 0x10000000;
  local_94 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_88 = iVar6 << 0x10;
  local_8c = uVar5 & 0xffff;
  local_90 = CONCAT22((short)iVar6,-(short)uVar5);
  FUN_80041fe0(&DAT_800e9134,&local_98);
  if (iVar2 != 0) {
    local_88 = (iVar3 * 0x1000) / iVar2;
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (iVar3 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = (iVar4 * 0x1000) / iVar2;
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    if ((iVar2 == -1) && (iVar4 * 0x1000 == -0x80000000)) {
      trap(0x1800);
    }
    local_90 = 0x10000000;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_98 = local_88 << 0x10;
    local_88 = local_88 << 0x10;
    local_94 = (uint)(ushort)-(short)iVar1 << 0x10;
    local_8c = iVar1 << 0x10;
    FUN_80041fe0(&DAT_800e9134,&local_98);
  }
  local_78 = -*param_1;
  local_74 = -param_1[1];
  local_70 = -param_1[2];
  FUN_800421b4(&DAT_800e9134,&local_78,&DAT_800e9148);
  local_c8 = (float)(int)DAT_800e9134._0_2_ * 0.00024414062;
  local_b4 = (float)-(int)DAT_800e9140._2_2_ * 0.00024414062;
  local_c4 = (float)-(int)DAT_800e9138._2_2_ * 0.00024414062;
  local_c0 = (float)-(int)DAT_800e9140._0_2_ * 0.00024414062;
  local_a4 = (float)DAT_800e9148;
  local_bc = (float)(int)DAT_800e9134._2_2_ * 0.00024414062;
  local_a0 = (float)-DAT_800e914c;
  local_b8 = (float)-(int)DAT_800e913c._0_2_ * 0.00024414062;
  local_9c = (float)-DAT_800e9150;
  local_b0 = (float)(int)DAT_800e9138._0_2_ * 0.00024414062;
  local_ac = (float)-(int)DAT_800e913c._2_2_ * 0.00024414062;
  local_a8 = (float)-(int)DAT_800e9144._0_2_ * 0.00024414062;
  FUN_80049b94(&local_c8,&DAT_80131590,1);
  return;
}
