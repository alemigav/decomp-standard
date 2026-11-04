/* FUN_8002e6fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e6fc  body 0x8002e6fc..0x8002e7bf  size 196 B
 * body sha256 54ab64e4a5dbe4af6a759a60f21d8996be60a4c787cca90091cdd52ff2c51f2a
 * provider record sha256 ccc1d4c52f304854c82e2efbfe23b4435a7161d2b0e63ec34fca244947c982b5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e6fc(int *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x1c);
  param_1[0x5c] = (int)puVar1;
  *puVar1 = FUN_8002e5d0;
  puVar1[2] = 0;
  if (param_1[0x11] != 0) {
    puVar1[4] = param_1[0x42];
    if (param_2 == 0) {
      uVar2 = (**(code **)(param_1[1] + 8))(param_1,1,param_1[0x17] * param_1[0x19]);
      puVar1[3] = uVar2;
    }
    else {
      *(undefined4 *)(*param_1 + 0x14) = 4;
      (**(code **)*param_1)(param_1);
    }
  }
  return;
}
