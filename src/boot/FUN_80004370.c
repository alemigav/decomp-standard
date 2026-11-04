/* FUN_80004370
 * image   boot (boot), base 0x80000480
 * address 0x80004370  body 0x80004370..0x800044eb  size 380 B
 * body sha256 2ac9352e97346e8b5556f8aabe251903044d63967f116e5c7ad550d469d39329
 * provider record sha256 d07fcd1bde7039952757b95f4c588229a4093d48b160cad5b5c4b83118f9d5b6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80004370(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 0x2c);
  iVar5 = *(int *)(param_2 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x30) - uVar3;
  if (*(uint *)(param_1 + 0x30) < uVar3) {
    uVar2 = *(int *)(param_1 + 0x28) - uVar3;
  }
  if (*(uint *)(param_2 + 0x10) < uVar2) {
    uVar2 = *(uint *)(param_2 + 0x10);
  }
  if ((uVar2 != 0) && (param_3 == -5)) {
    param_3 = 0;
  }
  *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) - uVar2;
  *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar2;
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x38),uVar3,uVar2);
    *(undefined4 *)(param_1 + 0x38) = uVar1;
    *(undefined4 *)(param_2 + 0x30) = uVar1;
  }
  FUN_8000de9c(iVar5,uVar3,uVar2);
  iVar4 = uVar3 + uVar2;
  iVar5 = iVar5 + uVar2;
  if (iVar4 == *(int *)(param_1 + 0x28)) {
    iVar4 = *(int *)(param_1 + 0x24);
    if (*(int *)(param_1 + 0x30) == *(int *)(param_1 + 0x28)) {
      *(int *)(param_1 + 0x30) = iVar4;
    }
    uVar2 = *(int *)(param_1 + 0x30) - iVar4;
    if (*(uint *)(param_2 + 0x10) < uVar2) {
      uVar2 = *(uint *)(param_2 + 0x10);
    }
    if ((uVar2 != 0) && (param_3 == -5)) {
      param_3 = 0;
    }
    *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) - uVar2;
    *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar2;
    if (*(code **)(param_1 + 0x34) != (code *)0x0) {
      uVar1 = (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x38),iVar4,uVar2);
      *(undefined4 *)(param_1 + 0x38) = uVar1;
      *(undefined4 *)(param_2 + 0x30) = uVar1;
    }
    FUN_8000de9c(iVar5,iVar4,uVar2);
    iVar5 = iVar5 + uVar2;
    iVar4 = iVar4 + uVar2;
  }
  *(int *)(param_2 + 0xc) = iVar5;
  *(int *)(param_1 + 0x2c) = iVar4;
  return param_3;
}
