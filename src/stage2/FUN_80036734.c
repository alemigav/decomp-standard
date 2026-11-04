/* FUN_80036734
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036734  body 0x80036734..0x80036a2b  size 760 B
 * body sha256 84fc3f5806a9e5e26285d4534ce0ab2834fb7adcce3f5adebe46b9c5ce7c1c84
 * provider record sha256 7bbcf6a8cb7a3a21a4fda167e9d25d70932e99d5116277536e37af704f734243
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80036734(uint *param_1,uint *param_2)

{
  int iVar1;
  undefined1 auStack_108 [64];
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_28;
  int local_24;
  int local_20;
  
  if ((*param_2 & 1) != 0) {
    FUN_80083748(param_1[0x8d] + 0x4c);
    FUN_80042454(&DAT_800e9028,auStack_108);
    if ((*param_2 & 0x400) != 0) {
      local_c8 = param_2[0xe];
      local_c4 = param_2[0xf];
      local_c0 = param_2[0x10];
      local_bc = param_2[0x11];
      local_b8 = param_2[0x12];
      local_b4 = param_2[0x13];
      local_b0 = param_2[0x14];
      local_ac = param_2[0x15];
      local_28 = (int)*(short *)(param_2 + 0x49);
      local_24 = (int)*(short *)((int)param_2 + 0x126);
      local_20 = (int)*(short *)(param_2 + 0x4a);
      FUN_80040d2c(&local_c8,&local_28);
      FUN_800416bc(param_2 + 0xe,&local_a8);
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_88 = 0x10000000;
      local_84 = 0;
      local_80 = 0x10000000;
      local_7c = 0;
      local_78 = 0x10000000;
      local_74 = -local_b4;
      local_6c = -local_ac;
      local_70 = -local_b0;
      FUN_800424ec(&local_a8,&local_88,&local_a8);
      FUN_800424ec(&local_c8,&local_a8,&local_c8);
      FUN_80042454(&local_c8,auStack_108);
    }
    if ((*param_2 & 0x2000) != 0) {
      local_c8 = 0x10000000;
      local_c4 = 0;
      local_c0 = 0x10000000;
      local_bc = 0;
      local_b8 = 0x10000000;
      local_b4 = param_2[0x13];
      local_b0 = param_2[0x14];
      local_ac = param_2[0x15];
      local_28 = (int)*(short *)(param_2 + 0x49);
      local_24 = (int)*(short *)((int)param_2 + 0x126);
      local_20 = (int)*(short *)(param_2 + 0x4a);
      FUN_80040d2c(&local_c8,&local_28);
      local_a8 = 0x10000000;
      local_a4 = 0;
      local_a0 = 0x10000000;
      local_9c = 0;
      local_98 = 0x10000000;
      local_94 = -local_b4;
      local_8c = -local_ac;
      local_90 = -local_b0;
      FUN_800424ec(&local_c8,&local_a8,&local_c8);
      FUN_80042454(&local_c8,auStack_108);
    }
    iVar1 = FUN_80083d2c(param_1 + 10,DAT_800df940);
    if ((iVar1 != 0) && ((*param_1 & 0x80000) == 0)) {
      FUN_800411b8(auStack_108,param_2 + 0x34);
      FUN_8008548c(param_2,param_1 + 0x1e,0);
    }
  }
  return;
}
