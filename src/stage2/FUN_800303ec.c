/* FUN_800303ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800303ec  body 0x800303ec..0x800306a7  size 700 B
 * body sha256 8c9a1341d5dcb0bcb6c4b958113021d2ec293b7af7e3b0edcc4e4e6c46ea7331
 * provider record sha256 4bfb87381f21e1d13541c6c976bc8d516118492db696c8d23f68681bb5ca1438
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800303ec(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 4);
  iVar4 = 0;
  iVar5 = 0;
  for (piVar3 = *(int **)(iVar6 + 0x40); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[9]) {
    if (*piVar3 == 0) {
      iVar4 = iVar4 + piVar3[3] * piVar3[2];
      iVar5 = iVar5 + piVar3[1] * piVar3[2];
    }
  }
  for (piVar3 = *(int **)(iVar6 + 0x44); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[9]) {
    if (*piVar3 == 0) {
      iVar4 = iVar4 + piVar3[3] * piVar3[2] * 0x80;
      iVar5 = iVar5 + piVar3[1] * piVar3[2] * 0x80;
    }
  }
  if (0 < iVar4) {
    iVar1 = FUN_8002fcc0(param_1,iVar4,iVar5,*(undefined4 *)(iVar6 + 0x48));
    if (iVar1 < iVar5) {
      iVar5 = iVar1 / iVar4;
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      if (iVar5 < 1) {
        iVar5 = 1;
      }
    }
    else {
      iVar5 = 1000000000;
    }
    for (piVar3 = *(int **)(iVar6 + 0x40); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[9]) {
      if (*piVar3 == 0) {
        uVar2 = piVar3[3];
        if (uVar2 == 0) {
          trap(0x1c00);
        }
        if (iVar5 < (int)((piVar3[1] - 1U) / uVar2 + 1)) {
          piVar3[4] = iVar5 * uVar2;
          FUN_8002fcd0(param_1,piVar3 + 10,piVar3[1] * piVar3[2]);
          piVar3[8] = 1;
        }
        else {
          piVar3[4] = piVar3[1];
        }
        iVar4 = FUN_8002ffec(param_1,1,piVar3[2],piVar3[4]);
        *piVar3 = iVar4;
        iVar4 = *(int *)(iVar6 + 0x4c);
        piVar3[6] = 0;
        piVar3[7] = 0;
        piVar3[5] = iVar4;
      }
    }
    for (piVar3 = *(int **)(iVar6 + 0x44); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[9]) {
      if (*piVar3 == 0) {
        uVar2 = piVar3[3];
        if (uVar2 == 0) {
          trap(0x1c00);
        }
        if (iVar5 < (int)((piVar3[1] - 1U) / uVar2 + 1)) {
          piVar3[4] = iVar5 * uVar2;
          FUN_8002fcd0(param_1,piVar3 + 10,piVar3[1] * piVar3[2] * 0x80);
          piVar3[8] = 1;
        }
        else {
          piVar3[4] = piVar3[1];
        }
        iVar4 = FUN_8003011c(param_1,1,piVar3[2],piVar3[4]);
        *piVar3 = iVar4;
        iVar4 = *(int *)(iVar6 + 0x4c);
        piVar3[6] = 0;
        piVar3[7] = 0;
        piVar3[5] = iVar4;
      }
    }
  }
  return;
}
