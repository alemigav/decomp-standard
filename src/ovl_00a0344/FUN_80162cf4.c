/* FUN_80162cf4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162cf4  body 0x80162cf4..0x80162e13  size 288 B
 * body sha256 dbe53b7bdcf91190642e52c4cff0e21f56c0df48ff388d4ace24cdd361ec105b
 * provider record sha256 0bd0ea941e5e61ca32f17ff39a174e206f2a29cae5a59c2b46e6e2ccd9b0cd3c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162cf4(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined2 uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(short *)(param_1 + 700) = *(short *)(param_1 + 0x2c0) + 0x400;
    uVar1 = func_0x80033604();
    uVar2 = 0xfc00;
    if ((uVar1 & 1) != 0) {
      uVar2 = 0x400;
    }
    *(undefined2 *)(param_1 + 0x2c2) = uVar2;
    *(undefined2 *)(param_1 + 0x1e2) = 0x28;
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) * 0x10000 + 0x5000700;
    FUN_80163bb8(param_1,0,1);
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_80162df0;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
  *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x28;
  if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c)) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 0x1f) * 0x10000 + 0x2000700;
  }
LAB_80162df0:
  func_0x80089d54(param_1,param_2,param_3,0x200);
  return;
}
