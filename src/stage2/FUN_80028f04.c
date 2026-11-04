/* FUN_80028f04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028f04  body 0x80028f04..0x80028fc3  size 192 B
 * body sha256 94540565ddc2c12264a76df68db6817003cd01649cd847b8c85824e57c9a0cbb
 * provider record sha256 c638a27eccc90037b8e4786dbefd2800fe8e1f64e507ed5e7f0d251e7c7a713c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028f04(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x28);
    *(int *)(param_1 + 0x14) = iVar1;
    uVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0xa000);
    *(undefined4 *)(iVar1 + 0x20) = uVar2;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  puVar3[2] = &LAB_80028db0;
  puVar3[3] = FUN_80028dc0;
  puVar3[4] = FUN_80028e84;
  puVar3[5] = FUN_8002cfdc;
  puVar3[6] = &LAB_80028efc;
  puVar3[7] = param_2;
  puVar3[1] = 0;
  *puVar3 = 0;
  return;
}
