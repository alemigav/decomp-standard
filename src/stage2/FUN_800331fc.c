/* FUN_800331fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800331fc  body 0x800331fc..0x8003331b  size 288 B
 * body sha256 202dc27f408b505a0fca6171cd9186fac9636abecd5e43059ed7d9e459b7de6d
 * provider record sha256 f03cbffcfc5c692d6042e74befd67a58ffe3f0a9f78c8f168d30cfde8415facb
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800331fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar1 = DAT_800df938;
  FUN_80033404(&local_20,param_4,param_2,param_3);
  local_40 = 0x10000000;
  local_3c = 0;
  local_38 = 0x10000000;
  local_34 = 0;
  local_30 = 0x10000000;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  FUN_80041454((int)*(short *)(iVar1 + 0x66),&local_40);
  FUN_8004276c(&local_40,&local_20,&local_20);
  *(short *)(iVar1 + 0x200) = *(short *)(iVar1 + 0x2a) - local_20;
  *(short *)(iVar1 + 0x202) = *(short *)(iVar1 + 0x2e) - local_1e;
  *(short *)(iVar1 + 0x204) = *(short *)(iVar1 + 0x32) - local_1c;
  *(undefined2 *)(param_1 + 0x200) = *(undefined2 *)(iVar1 + 0x200);
  *(undefined2 *)(param_1 + 0x202) = *(undefined2 *)(iVar1 + 0x202);
  *(undefined2 *)(param_1 + 0x204) = *(undefined2 *)(iVar1 + 0x204);
  return;
}
