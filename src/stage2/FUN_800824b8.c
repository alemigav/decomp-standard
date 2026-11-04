/* FUN_800824b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800824b8  body 0x800824b8..0x80082673  size 444 B
 * body sha256 bba6bd2ee3e681cf29c1c1e4974540347a591fe34e4e5343ea95d26ed307cad5
 * provider record sha256 d2ca73c4f9a28c41da75972875ed4a026b764fdef6f851c4b240e752697ace29
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800824b8(short *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  if (param_1[1] == 0) {
    *(int *)(param_1 + 4) = (int)param_1 + *(int *)(param_1 + 4);
    if (300 < *param_1) {
      iVar6 = 0;
      if (*(int *)(param_1 + 6) != 0) {
        iVar6 = (int)param_1 + *(int *)(param_1 + 6);
      }
      piVar1 = (int *)0x0;
      *(int *)(param_1 + 6) = iVar6;
      if (*(int *)(param_1 + 8) != 0) {
        piVar1 = (int *)((int)param_1 + *(int *)(param_1 + 8));
      }
      iVar6 = *(int *)(param_1 + 10);
      *(int **)(param_1 + 8) = piVar1;
      if (piVar1 != (int *)0x0) {
        while (iVar6 = iVar6 + -1, iVar6 != -1) {
          *piVar1 = (int)param_1 + *piVar1;
          piVar1 = piVar1 + 1;
        }
      }
    }
    piVar8 = *(int **)(param_1 + 4);
    iVar6 = *(int *)(param_1 + 2);
    piVar1 = piVar8 + 2;
    while (iVar6 = iVar6 + -1, iVar6 != -1) {
      if (0x13f < *param_1) {
        iVar2 = 0;
        if (piVar1[1] != 0) {
          iVar2 = (int)param_1 + piVar1[1];
        }
        piVar1[1] = iVar2;
      }
      piVar3 = (int *)((int)param_1 + piVar1[-1]);
      piVar1[-1] = (int)piVar3;
      iVar2 = *piVar8 + -1;
      if (iVar2 != -1) {
        piVar7 = piVar3 + 2;
        do {
          iVar4 = 0;
          if (*piVar3 != 0) {
            iVar4 = (int)param_1 + *piVar3;
          }
          *piVar3 = iVar4;
          iVar4 = 0;
          if (piVar7[-1] != 0) {
            iVar4 = (int)param_1 + piVar7[-1];
          }
          iVar5 = 0;
          piVar7[-1] = iVar4;
          if (*piVar7 != 0) {
            iVar5 = (int)param_1 + *piVar7;
          }
          *piVar7 = iVar5;
          piVar7 = piVar7 + 4;
          iVar2 = iVar2 + -1;
          piVar3 = piVar3 + 4;
        } while (iVar2 != -1);
      }
      piVar3 = (int *)((int)param_1 + *piVar1);
      if (*piVar1 != 0) {
        *piVar1 = (int)piVar3;
        iVar2 = *piVar8 + -1;
        if (iVar2 != -1) {
          piVar7 = piVar3 + 2;
          do {
            iVar4 = 0;
            if (*piVar3 != 0) {
              iVar4 = (int)param_1 + *piVar3;
            }
            *piVar3 = iVar4;
            iVar4 = 0;
            if (piVar7[-1] != 0) {
              iVar4 = (int)param_1 + piVar7[-1];
            }
            iVar5 = 0;
            piVar7[-1] = iVar4;
            if (*piVar7 != 0) {
              iVar5 = (int)param_1 + *piVar7;
            }
            *piVar7 = iVar5;
            piVar7 = piVar7 + 4;
            iVar2 = iVar2 + -1;
            piVar3 = piVar3 + 4;
          } while (iVar2 != -1);
        }
      }
      piVar1 = piVar1 + 4;
      piVar8 = piVar8 + 4;
    }
    param_1[1] = 1;
  }
  return;
}
