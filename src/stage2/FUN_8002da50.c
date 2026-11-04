/* FUN_8002da50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002da50  body 0x8002da50..0x8002dbdb  size 396 B
 * body sha256 77ef26da23fefea4362a1ac76ffac594cb60f4599603ea6d2d26b39f18ca1c5c
 * provider record sha256 4aa52b8469a8d495e9664e395f88172010e9c4326110242bd33956f94e0997b4
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002da50(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[0x59];
  FUN_8002d330();
  FUN_8002d918(param_1);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  if (param_1[0x46] == param_1[8]) {
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined4 *)(iVar2 + 0x1c) = 1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)(param_1);
  }
  uVar1 = FUN_8002d260(param_1);
  *(undefined4 *)(iVar2 + 0x10) = uVar1;
  if (param_1[0x11] != 0) {
    if (param_1[0x10] != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x27;
      (**(code **)*param_1)(param_1);
    }
    param_1[0x12] = 0;
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x10] == 0) {
    if (*(int *)(iVar2 + 0x10) == 0) {
      FUN_80029390(param_1);
      FUN_8002e808(param_1);
    }
    else {
      FUN_8002e4fc(param_1);
    }
    FUN_8002e6fc(param_1,*(undefined4 *)(iVar2 + 0x20));
  }
  FUN_800296e8(param_1);
  if (param_1[0x39] == 0) {
    FUN_8002a4f8(param_1);
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 1;
    (**(code **)*param_1)(param_1);
  }
  FUN_80029298(param_1,*(int *)(iVar2 + 0x14) == 1);
  FUN_8002ad5c(param_1,0);
  (**(code **)(param_1[1] + 0x18))(param_1);
  return;
}
