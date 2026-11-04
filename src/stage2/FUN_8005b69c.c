/* FUN_8005b69c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b69c  body 0x8005b69c..0x8005b92f  size 660 B
 * body sha256 fcb187c871694478bbd04ddc018d77e3a31b4fd70809020774175392274c1b0d
 * provider record sha256 ee6914b35dd62ffdeece640f6d577e01c61ec515a7143a83095216d6cc499a7c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8005b69c(int param_1,int param_2,short *param_3)

{
  undefined4 uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int local_90;
  int local_8c;
  ushort local_88 [2];
  short local_84;
  short local_80 [2];
  ushort local_7c;
  short local_78;
  undefined2 local_76;
  short local_74;
  undefined2 local_70;
  undefined2 local_6e;
  short local_6c;
  undefined2 local_68;
  undefined2 local_66;
  short local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined2 local_36;
  short local_34;
  short local_32;
  short local_30;
  int local_2c;
  int local_24;
  
  param_1 = param_1 + 4;
  local_60 = 0x10000000;
  local_5c = 0;
  local_58 = 0x10000000;
  local_54 = 0;
  local_50 = 0x10000000;
  local_4c = (int)*param_3;
  local_48 = 0;
  local_44 = param_3[3] * -4 - (int)param_3[1];
  FUN_800424ec(param_1,&local_60,&local_40);
  local_76 = 0;
  local_78 = (short)(local_2c >> 2);
  local_74 = (short)(local_24 >> 2);
  local_8c = 0;
  local_90 = (uint)(ushort)param_3[2] << 0x10;
  FUN_8004276c(param_1,&local_90,local_88);
  local_90 = 0;
  local_8c = (uint)(ushort)(param_3[3] << 1) << 0x10;
  FUN_8004276c(param_1,&local_90,local_80);
  sVar2 = local_78 + local_88[0];
  local_84 = local_74 + local_84;
  sVar3 = local_78 + local_80[0];
  local_64 = local_74 + local_7c;
  iVar4 = (*(int *)(param_2 + 0x18) >> 2) - (int)local_78;
  local_78 = (short)iVar4;
  local_76 = (undefined2)((uint)iVar4 >> 0x10);
  local_74 = (short)(*(int *)(param_2 + 0x20) >> 2) - local_74;
  iVar4 = (*(int *)(param_2 + 0x18) >> 2) - (int)sVar2;
  local_70 = (undefined2)iVar4;
  local_6e = (undefined2)((uint)iVar4 >> 0x10);
  local_6c = (short)(*(int *)(param_2 + 0x20) >> 2) - local_84;
  iVar4 = (*(int *)(param_2 + 0x18) >> 2) - (int)sVar3;
  local_68 = (undefined2)iVar4;
  local_66 = (undefined2)((uint)iVar4 >> 0x10);
  local_60 = (uint)local_88[0] << 0x10;
  local_5c._2_2_ = local_80[0];
  local_58 = (uint)local_7c;
  local_64 = (short)(*(int *)(param_2 + 0x20) >> 2) - local_64;
  local_3a = 0;
  local_38 = 0;
  local_36 = 0;
  local_40 = local_78;
  local_3e = local_70;
  local_3c = local_68;
  local_34 = local_74;
  local_32 = local_6c;
  local_30 = local_64;
  FUN_8004226c(&local_60,&local_40,&local_60);
  uVar1 = 0;
  if ((((int)local_60._0_2_ & 0x8000U) != ((int)local_60._2_2_ & 0x8000U)) &&
     (uVar1 = 1, ((int)local_5c._2_2_ & 0x8000U) == ((int)local_58._2_2_ & 0x8000U))) {
    uVar1 = 0;
  }
  return uVar1;
}
