/* FUN_80001510
 * image   boot (boot), base 0x80000480
 * address 0x80001510  body 0x80001510..0x800015df  size 208 B
 * body sha256 9e000c603ee06a96806d54b7c44986bbdbce963dd7b13ba81a094a8aee473974
 * provider record sha256 8f1f6c6aa4ac9915e4ff928865a28ca208bb2c40eae2e814f1ecfe1a8d8b858d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80001510(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_1[0xd] != 0) {
    *param_3 = param_1[0xe];
  }
  if (*param_1 - 4U < 2) {
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[3]);
  }
  if (*param_1 == 6) {
    FUN_80002b8c(param_1[3],param_2);
    FUN_800042f4(param_1[2],param_2);
    FUN_800042f4(param_1[1],param_2);
  }
  *param_1 = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xc] = param_1[9];
  param_1[0xb] = param_1[9];
  if ((code *)param_1[0xd] != (code *)0x0) {
    iVar1 = (*(code *)param_1[0xd])(0,0,0);
    param_1[0xe] = iVar1;
    *(int *)(param_2 + 0x30) = iVar1;
  }
  return;
}
