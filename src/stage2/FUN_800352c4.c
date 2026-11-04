/* FUN_800352c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800352c4  body 0x800352c4..0x80035873  size 1456 B
 * body sha256 d478985d0939b49c288855648df372b736a839f378cb8246d5fc039c61de55ad
 * provider record sha256 4004a82450c37a1d02c401711ffe0eee2dc76d4961b90a55446f08a21f3f7c17
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800352c4(int param_1,int param_2,uint param_3,short param_4,undefined4 param_5,
                 short param_6,int param_7,int param_8,short param_9,undefined4 param_10,
                 undefined4 param_11,undefined4 param_12,undefined4 param_13)

{
  short sVar2;
  short sVar3;
  uint uVar1;
  int iVar4;
  ushort uVar5;
  int iVar6;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  short local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined1 auStack_70 [32];
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  int local_30;
  
  local_38 = &local_c8;
  local_50 = param_5;
  local_4c = param_7;
  local_c8 = ((uint)*(ushort *)(param_1 + 0x58) + (uint)*(ushort *)(param_1 + 0x132)) * 0x10000;
  local_48 = param_10;
  local_44 = param_11;
  local_40 = param_12;
  local_3c = param_13;
  local_c4 = *(short *)(param_1 + 0x5c) + *(short *)(param_1 + 0x130);
  FUN_80041018(local_38,&local_e8);
  FUN_80041454((int)*(short *)(param_1 + 0x5a),&local_e8);
  local_c8 = param_3 & 0xffff;
  local_c4 = 0;
  FUN_80042824(&local_e8,local_38,&local_c0);
  iVar6 = (int)((param_8 - param_3) * 0x10000) >> 0x10;
  local_c0 = local_c0 + *(int *)(param_1 + 0x4c);
  local_b0 = local_c0 + (iVar6 * local_e8._2_2_ >> 0xc);
  iVar4 = local_bc + *(int *)(param_1 + 0x50);
  local_bc = iVar4 + param_4;
  local_ac = iVar4 + param_9 + (iVar6 * local_e0._0_2_ >> 0xc);
  local_c8 = CONCAT22(local_c8._0_2_,(short)param_8);
  local_b8 = local_b8 + *(int *)(param_1 + 0x54);
  local_a8 = local_b8 + (iVar6 * local_dc._2_2_ >> 0xc);
  FUN_800424ec(&DAT_800e1144,8,&local_90);
  FUN_800424ec(&local_90,0xbc8,0xbf8);
  local_90 = 0x10000000;
  local_8c = 0;
  local_88 = 0x10000000;
  local_84 = 0;
  local_80 = 0x10000000;
  local_7c = local_c0;
  local_78 = local_bc;
  local_74 = local_b8;
  FUN_80049ff8(0xbf8,&local_90,auStack_70);
  local_c8 = CONCAT22(*(short *)(param_1 + 0x1e) << 4,*(short *)(param_1 + 0x22) << 4);
  local_c4 = *(short *)(param_1 + 0x26) << 4;
  FUN_80042824(param_2,local_38,&local_a0);
  *(int *)(param_1 + 0x4c) = (local_a0 >> 4) + *(int *)(param_2 + 0x14);
  *(int *)(param_1 + 0x50) = (local_9c >> 4) + *(int *)(param_2 + 0x18);
  *(int *)(param_1 + 0x54) = (local_98 >> 4) + *(int *)(param_2 + 0x1c);
  local_e8 = 0x10000000;
  local_e4 = 0;
  local_e0 = 0x10000000;
  local_dc = 0;
  local_d8 = 0x10000000;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  FUN_80041454(-(int)*(short *)(param_1 + 0x5a),&local_e8);
  local_c8 = CONCAT22((*(short *)(param_1 + 0x4e) - local_c0._2_2_) * 4,
                      (*(short *)(param_1 + 0x52) - local_bc._2_2_) * 4);
  local_c4 = (*(short *)(param_1 + 0x56) - local_b8._2_2_) * 4;
  FUN_80042824(&local_e8,local_38,&local_a0);
  sVar2 = FUN_80035874((int)local_a0._2_2_,(int)local_9c._2_2_);
  local_c8 = CONCAT22((*(short *)(param_1 + 0x52) - local_ac._2_2_) * 4,(short)local_c8);
  local_c4 = (*(short *)(param_1 + 0x56) - local_a8._2_2_) * 4;
  FUN_80041588(-((int)*(short *)(param_1 + 0x5c) + (int)*(short *)(param_1 + 0x130)),&local_e8);
  FUN_80042824(&local_e8,local_38,&local_a0);
  sVar3 = FUN_8003590c(local_98 * -0x10000 >> 0x10,(int)local_9c._2_2_);
  local_30 = local_4c << 0x10;
  iVar4 = FUN_80040968((int)sVar2 - (local_30 >> 0x10));
  iVar6 = (int)param_6;
  if (iVar6 == 0) {
    trap(0x1c00);
  }
  if ((iVar6 == -1) && (*(short *)(param_1 + 0x130) == -0x80000000)) {
    trap(0x1800);
  }
  uVar1 = ((uint)*(ushort *)(param_1 + 0x130) - (int)*(short *)(param_1 + 0x130) / iVar6) -
          ((short)local_50 * iVar4 >> 0xc);
  uVar5 = (ushort)uVar1 & 0xfff;
  *(ushort *)(param_1 + 0x130) = uVar5;
  if ((uVar1 & 0x800) != 0) {
    *(ushort *)(param_1 + 0x130) = uVar5 - 0x1000;
  }
  iVar4 = FUN_80040968((int)sVar3 - (int)(short)local_40);
  iVar6 = (int)(short)local_44;
  if (iVar6 == 0) {
    trap(0x1c00);
  }
  if ((iVar6 == -1) && (*(short *)(param_1 + 0x132) == -0x80000000)) {
    trap(0x1800);
  }
  uVar1 = ((uint)*(ushort *)(param_1 + 0x132) - (int)*(short *)(param_1 + 0x132) / iVar6) -
          ((short)local_48 * iVar4 >> 0xc);
  uVar5 = (ushort)uVar1 & 0xfff;
  *(ushort *)(param_1 + 0x132) = uVar5;
  if ((uVar1 & 0x800) != 0) {
    *(ushort *)(param_1 + 0x132) = uVar5 - 0x1000;
  }
  *(short *)(param_1 + 0x5c) = sVar2;
  *(int *)(param_1 + 0x58) = (int)sVar3 << 0x10;
  local_e8 = 0x10000000;
  local_e4 = 0;
  local_e0 = 0x10000000;
  local_dc = 0;
  local_d8 = 0x10000000;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  FUN_80041018(param_1 + 0x58,param_1 + 0x38);
  *(short *)(param_1 + 0x5a) = local_3c._2_2_;
  FUN_80041454((int)local_3c._2_2_,param_1 + 0x38);
  return;
}
