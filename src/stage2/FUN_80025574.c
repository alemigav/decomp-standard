/* FUN_80025574
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025574  body 0x80025574..0x800255ff  size 140 B
 * body sha256 eb5d0f2f3785ca6d92612eab9373cacd07d13e8978d4dbcb1e9c5d3df248a277
 * provider record sha256 fcc6d0d81e4413aa74cccbe9b9cc90f1a04de6cf92481a4934f2adb47b45a656
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025574(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_800c7648 = param_1;
  *param_1 = 1;
  param_1[3] = 0xd0;
  param_1[5] = 0x1000;
  param_1[7] = 0x800;
  param_1[4] = &DAT_8001b740;
  param_1[2] = entry;
  param_1[6] = &DAT_800bb680;
  uVar2 = DAT_800c56e4;
  uVar1 = DAT_800c4ea0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xc] = &DAT_800c6378;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[10] = uVar1;
  param_1[0xb] = uVar2;
  return;
}
