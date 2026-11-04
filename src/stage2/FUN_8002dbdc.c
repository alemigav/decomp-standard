/* FUN_8002dbdc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002dbdc  body 0x8002dbdc..0x8002dd33  size 344 B
 * body sha256 23c2dd12e9e149f394905ac51b27b8214941d202f1f9487d358acb4556e68d07
 * provider record sha256 a1fdc172f3059176bb046c37c6f22fa362b0efdfeef740887fb598ed761d4a4b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002dbdc(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x59];
  if (*(int *)(iVar1 + 0x14) == 0) {
    FUN_8002d710();
    *(uint *)(iVar1 + 8) = (uint)(*(int *)(iVar1 + 0x20) == 0);
    if (param_1[0x10] == 0) {
      if (*(int *)(iVar1 + 0x10) == 0) {
        (**(code **)param_1[0x61])(param_1);
      }
      (**(code **)param_1[0x60])(param_1);
      if (param_1[0x11] != 0) {
        (**(code **)param_1[0x62])(param_1,*(undefined4 *)(iVar1 + 0x20));
      }
      (**(code **)param_1[0x5c])(param_1,(uint)(*(int *)(iVar1 + 0x20) != 0) << 2);
    }
    (**(code **)param_1[0x5f])(param_1);
    (**(code **)(param_1[0x5f] + 4))(param_1);
    (**(code **)param_1[0x5e])(param_1);
    (**(code **)param_1[0x5b])(param_1,0);
    (**(code **)param_1[0x5a])(param_1,0);
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[2] != 0) {
    *(undefined4 *)(param_1[2] + 0xc) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined4 *)(param_1[2] + 0x10) = *(undefined4 *)(iVar1 + 0x1c);
  }
  return;
}
