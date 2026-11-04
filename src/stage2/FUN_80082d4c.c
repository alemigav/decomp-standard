/* FUN_80082d4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082d4c  body 0x80082d4c..0x800831ff  size 1204 B
 * body sha256 f8a01e3dff6760fe1c20e0c703fd3b621c4d6931392641c36a213c9f464b75a2
 * provider record sha256 bba268006884abb72029af28dcc61351eb9b9d43154e156bd1b788b96bad5b38
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082d4c(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
  
  DAT_800e9154._2_2_ = 0;
  DAT_800e9154._0_2_ = 0x1000;
  DAT_800e9158 = 0;
  DAT_800e915c._2_2_ = 0;
  DAT_800e915c._0_2_ = 0x1000;
  DAT_800e9160 = 0;
  DAT_800e9164 = 0x10000000;
  DAT_800e9168 = 0;
  DAT_800e916c = 0;
  DAT_800e9170 = 0;
  iVar4 = *param_2 - *param_1;
  iVar2 = param_2[1] - param_1[1];
  iVar3 = param_2[2] - param_1[2];
  iVar1 = FUN_80040bb4(iVar4 * iVar4 + iVar2 * iVar2 + iVar3 * iVar3);
  local_8c = (iVar2 * 0x1000) / iVar1;
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (iVar2 * 0x1000 == -0x80000000)) {
    trap(0x1800);
  }
  DAT_8011c854 = iVar1;
  iVar2 = FUN_80040bb4(iVar4 * iVar4 + iVar3 * iVar3);
  iVar5 = (iVar2 << 0xc) / iVar1;
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
  local_88 = iVar5 << 0x10;
  local_90 = CONCAT22((short)iVar5,-(short)local_8c);
  local_8c = local_8c & 0xffff;
  FUN_80041fe0(&DAT_800e9154,&local_98);
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
    FUN_80041fe0(&DAT_800e9154,&local_98);
  }
  local_78 = -*param_1;
  local_74 = -param_1[1];
  local_70 = -param_1[2];
  FUN_800421b4(&DAT_800e9154,&local_78,&DAT_800e9168);
  if (DAT_800e10f1 == '\x02') {
    DAT_800e9158._2_2_ = -DAT_800e9158._2_2_;
    DAT_800e915c._0_2_ = -DAT_800e915c._0_2_;
    DAT_800e915c._2_2_ = -DAT_800e915c._2_2_;
    DAT_800e916c = -DAT_800e916c;
  }
  else {
    DAT_800e9154._0_2_ = -DAT_800e9154._0_2_;
    DAT_800e9154._2_2_ = -DAT_800e9154._2_2_;
    DAT_800e9158._0_2_ = -DAT_800e9158._0_2_;
    DAT_800e9168 = -DAT_800e9168;
  }
  local_c8 = (float)(int)DAT_800e9154._0_2_ * 0.00024414062;
  local_b4 = (float)-(int)DAT_800e9160._2_2_ * 0.00024414062;
  local_c4 = (float)-(int)DAT_800e9158._2_2_ * 0.00024414062;
  local_c0 = (float)-(int)DAT_800e9160._0_2_ * 0.00024414062;
  local_a4 = (float)DAT_800e9168;
  local_bc = (float)(int)DAT_800e9154._2_2_ * 0.00024414062;
  local_a0 = (float)-DAT_800e916c;
  local_b8 = (float)-(int)DAT_800e915c._0_2_ * 0.00024414062;
  local_9c = (float)-DAT_800e9170;
  local_b0 = (float)(int)DAT_800e9158._0_2_ * 0.00024414062;
  local_ac = (float)-(int)DAT_800e915c._2_2_ * 0.00024414062;
  local_a8 = (float)-(int)DAT_800e9164._0_2_ * 0.00024414062;
  FUN_80049b94(&local_c8,&DAT_80131738,1);
  return;
}
