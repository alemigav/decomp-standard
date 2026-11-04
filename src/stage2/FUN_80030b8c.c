/* FUN_80030b8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030b8c  body 0x80030b8c..0x80030d0b  size 384 B
 * body sha256 1dec5d3d007de4845459d95733cc9832c39b83fe83834644aa479383042ca5bd
 * provider record sha256 6c58d0da51590ce232d74975cdcd31a278eff03798df6e1be5926df4113c5b92
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80030b8c(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1[1];
  if (1 < param_2) {
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    *(uint *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)();
  }
  if (param_2 == 1) {
    for (iVar2 = *(int *)(iVar4 + 0x40); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x24)) {
      if (*(int *)(iVar2 + 0x20) != 0) {
        *(undefined4 *)(iVar2 + 0x20) = 0;
        (**(code **)(iVar2 + 0x30))(param_1,iVar2 + 0x28);
      }
    }
    iVar2 = *(int *)(iVar4 + 0x44);
    *(undefined4 *)(iVar4 + 0x40) = 0;
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x24)) {
      if (*(int *)(iVar2 + 0x20) != 0) {
        *(undefined4 *)(iVar2 + 0x20) = 0;
        (**(code **)(iVar2 + 0x30))(param_1,iVar2 + 0x28);
      }
    }
    *(undefined4 *)(iVar4 + 0x44) = 0;
  }
  iVar2 = iVar4 + param_2 * 4;
  piVar1 = *(int **)(iVar2 + 0x38);
  *(undefined4 *)(iVar2 + 0x38) = 0;
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    iVar3 = piVar1[1] + piVar1[2] + 0x10;
    FUN_8002fcb8(param_1,piVar1,iVar3);
    *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) - iVar3;
    piVar1 = (int *)iVar2;
  }
  iVar2 = iVar4 + param_2 * 4;
  piVar1 = *(int **)(iVar2 + 0x30);
  *(undefined4 *)(iVar2 + 0x30) = 0;
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    iVar3 = piVar1[1] + piVar1[2] + 0x10;
    FUN_8002fc94(param_1,piVar1,iVar3);
    *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) - iVar3;
    piVar1 = (int *)iVar2;
  }
  return;
}
