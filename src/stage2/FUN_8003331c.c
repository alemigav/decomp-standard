/* FUN_8003331c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003331c  body 0x8003331c..0x80033403  size 232 B
 * body sha256 167bf3c37dcb12746033174fd839e6356cb539ae1c5ca9486b59bc2f1a8841ae
 * provider record sha256 5aecf81a49d6851bb873965baa2fdbce1776de6bb62e990e25e04d6a6f38c3fc
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003331c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  short local_18;
  short local_16;
  short local_14;
  
  FUN_80033404(&local_18,param_4,param_2,param_3);
  local_38 = 0x10000000;
  local_34 = 0;
  local_30 = 0x10000000;
  local_2c = 0;
  local_28 = 0x10000000;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  FUN_80041454((int)*(short *)(param_1 + 0x66),&local_38);
  FUN_8004276c(&local_38,&local_18,&local_18);
  *(int *)(param_1 + 0x28) = (int)*(short *)(param_1 + 0x200) + (int)local_18;
  *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x202) + (int)local_16;
  *(int *)(param_1 + 0x30) = (int)*(short *)(param_1 + 0x204) + (int)local_14;
  return;
}
