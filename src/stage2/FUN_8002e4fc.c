/* FUN_8002e4fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e4fc  body 0x8002e4fc..0x8002e5c3  size 200 B
 * body sha256 393739b555105a702f0072d71ba6879f9b33bd0fa5d7652df22e99d7b87c2a3c
 * provider record sha256 fa4d56aa623a70fdee4710e55f80a3ac18a8827e7af4e10556be34ad03b366b5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e4fc(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  *(undefined4 **)(param_1 + 0x180) = puVar2;
  *puVar2 = &LAB_8002de10;
  puVar2[2] = 0;
  iVar1 = *(int *)(param_1 + 0x5c) * *(int *)(param_1 + 100);
  puVar2[10] = iVar1;
  if (*(int *)(param_1 + 0x108) == 2) {
    puVar2[1] = FUN_8002df14;
    puVar2[3] = FUN_8002e264;
    uVar3 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,iVar1);
    puVar2[8] = uVar3;
  }
  else {
    puVar2[1] = FUN_8002e044;
    puVar2[3] = FUN_8002e0a8;
    puVar2[8] = 0;
  }
  return;
}
