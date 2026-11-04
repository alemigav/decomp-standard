/* FUN_80028a20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028a20  body 0x80028a20..0x80028b1b  size 252 B
 * body sha256 0f12f888322b26355eb45ff19c4e23012609211491be1a8b27f36414833425cd
 * provider record sha256 77a720e4afd6362deed6b05c169c1177ef67a1c1af89985da72a95d5d45d1e3c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028a20(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int local_18 [2];
  
  if (param_1[4] != 0xcb) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_1[4];
    (**(code **)*param_1)();
  }
  if ((uint)param_1[0x18] <= (uint)param_1[0x1e]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x6d;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
  }
  if (param_1[2] != 0) {
    *(int *)(param_1[2] + 4) = param_1[0x1e];
    *(int *)(param_1[2] + 8) = param_1[0x18];
    (**(code **)param_1[2])(param_1);
  }
  local_18[0] = 0;
  (**(code **)(param_1[0x5a] + 4))(param_1,param_2,local_18,param_3);
  param_1[0x1e] = param_1[0x1e] + local_18[0];
  return;
}
