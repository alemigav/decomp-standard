/* FUN_8002ab80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002ab80  body 0x8002ab80..0x8002ad5b  size 476 B
 * body sha256 49b05ae4722ff7e71d2651811196a8803edf5cfce57b577df149699217811b9a
 * provider record sha256 2dccbb3532a8d45466bb1d71af1da7bb937bb430673d3381d3386ef34c8dd3c3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002ab80(int param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x168);
  if (*(int *)(iVar2 + 0x34) == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x16c) + 4))
                      (param_1,*(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x44) * 4 + 0x3c));
    if (iVar1 == 0) {
      return;
    }
    *(undefined4 *)(iVar2 + 0x34) = 1;
    *(int *)(iVar2 + 0x50) = *(int *)(iVar2 + 0x50) + 1;
  }
  iVar1 = *(int *)(iVar2 + 0x48);
  if (iVar1 != 1) {
    if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      *(undefined4 *)(iVar2 + 0x38) = 0;
    }
    else {
      if (iVar1 != 2) {
        return;
      }
      (**(code **)(*(int *)(param_1 + 0x170) + 4))
                (param_1,*(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x44) * 4 + 0x3c),iVar2 + 0x38,
                 *(undefined4 *)(iVar2 + 0x4c),param_2,param_3,param_4);
      if (*(uint *)(iVar2 + 0x38) < *(uint *)(iVar2 + 0x4c)) {
        return;
      }
      *(undefined4 *)(iVar2 + 0x48) = 0;
      if (param_4 <= *param_3) {
        return;
      }
      *(undefined4 *)(iVar2 + 0x38) = 0;
    }
    *(int *)(iVar2 + 0x4c) = *(int *)(param_1 + 0x10c) + -1;
    if (*(int *)(iVar2 + 0x50) == *(int *)(param_1 + 0x110)) {
      FUN_8002a900(param_1);
    }
    *(undefined4 *)(iVar2 + 0x48) = 1;
  }
  (**(code **)(*(int *)(param_1 + 0x170) + 4))
            (param_1,*(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x44) * 4 + 0x3c),iVar2 + 0x38,
             *(undefined4 *)(iVar2 + 0x4c),param_2,param_3,param_4);
  if (*(uint *)(iVar2 + 0x4c) <= *(uint *)(iVar2 + 0x38)) {
    if (*(int *)(iVar2 + 0x50) == 1) {
      FUN_8002a7b4(param_1);
    }
    *(undefined4 *)(iVar2 + 0x34) = 0;
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) ^ 1;
    *(int *)(iVar2 + 0x38) = *(int *)(param_1 + 0x10c) + 1;
    iVar1 = *(int *)(param_1 + 0x10c);
    *(undefined4 *)(iVar2 + 0x48) = 2;
    *(int *)(iVar2 + 0x4c) = iVar1 + 2;
  }
  return;
}
