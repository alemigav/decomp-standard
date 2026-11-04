/* FUN_8005b930
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b930  body 0x8005b930..0x8005bc03  size 724 B
 * body sha256 ae63b40f477fc23ec685406500e4d0e689e1042d7f732d6f3dd59b893e794654
 * provider record sha256 5d7005f1a28df07271b31aef74f7f44eb71291f84a3598e38431d149f35dbd17
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8005b930(undefined4 *param_1,undefined2 param_2,int *param_3,short *param_4)

{
  undefined4 uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  short local_c0 [6];
  short local_b4;
  short local_b0 [2];
  ushort local_ac;
  short local_a8;
  undefined2 local_a6;
  short local_a4;
  undefined2 local_a0;
  undefined2 local_9e;
  short local_9c;
  undefined2 local_98;
  undefined2 local_96;
  short local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  int local_74;
  undefined2 local_70;
  undefined2 local_6e;
  undefined2 local_6c;
  undefined2 local_6a;
  undefined2 local_68;
  undefined2 local_66;
  short local_64;
  short local_62;
  short local_60;
  int local_5c;
  int local_54;
  undefined1 auStack_50 [20];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  
  local_90 = 0x10000000;
  local_8c = 0;
  local_88 = 0x10000000;
  local_84 = 0;
  local_80 = 0x10000000;
  local_7c = (int)*param_4;
  local_78 = 0;
  local_30 = 0;
  local_2c = 0;
  local_74 = param_4[3] * -4 - (int)param_4[1];
  local_2e = param_2;
  FUN_80040e58(&local_30,auStack_50);
  local_3c = *param_1;
  local_38 = 0;
  local_34 = param_1[2];
  FUN_800424ec(auStack_50,&local_90,&local_70);
  local_a6 = 0;
  local_a8 = (short)(local_5c >> 2);
  local_a4 = (short)(local_54 >> 2);
  local_c0[0] = param_4[2];
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  FUN_8004276c(auStack_50,local_c0,local_c0 + 4);
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[3] = 0;
  local_c0[2] = param_4[3] << 1;
  FUN_8004276c(auStack_50,local_c0,local_b0);
  sVar2 = local_a8 + local_c0[4];
  local_b4 = local_a4 + local_b4;
  sVar3 = local_a8 + local_b0[0];
  local_94 = local_a4 + local_ac;
  iVar4 = (*param_3 >> 2) - (int)local_a8;
  local_a8 = (short)iVar4;
  local_a6 = (undefined2)((uint)iVar4 >> 0x10);
  local_a4 = (short)(param_3[2] >> 2) - local_a4;
  iVar4 = (*param_3 >> 2) - (int)sVar2;
  local_a0 = (undefined2)iVar4;
  local_9e = (undefined2)((uint)iVar4 >> 0x10);
  local_9c = (short)(param_3[2] >> 2) - local_b4;
  iVar4 = (*param_3 >> 2) - (int)sVar3;
  local_98 = (undefined2)iVar4;
  local_96 = (undefined2)((uint)iVar4 >> 0x10);
  local_90 = (uint)(ushort)local_c0[4] << 0x10;
  local_8c._2_2_ = local_b0[0];
  local_88 = (uint)local_ac;
  local_94 = (short)(param_3[2] >> 2) - local_94;
  local_6a = 0;
  local_68 = 0;
  local_66 = 0;
  local_70 = local_a8;
  local_6e = local_a0;
  local_6c = local_98;
  local_64 = local_a4;
  local_62 = local_9c;
  local_60 = local_94;
  FUN_8004226c(&local_90,&local_70,&local_90);
  uVar1 = 0;
  if ((((int)local_90._0_2_ & 0x8000U) != ((int)local_90._2_2_ & 0x8000U)) &&
     (uVar1 = 1, ((int)local_8c._2_2_ & 0x8000U) == ((int)local_88._2_2_ & 0x8000U))) {
    uVar1 = 0;
  }
  return uVar1;
}
