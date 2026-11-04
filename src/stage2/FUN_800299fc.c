/* FUN_800299fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800299fc  body 0x800299fc..0x80029c1f  size 548 B
 * body sha256 edcd6f6361cf12e43df10c1cae8865958a1d0fa0741b4bae5f80cd7a9a22c626
 * provider record sha256 79975d1793eb5a2db3fc400785b0dea9a07827f8cbf8ed5fe7501ac7726362f5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800299fc(int param_1,byte *param_2,int *param_3)

{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  byte local_520 [264];
  int local_418 [258];
  
  if (*param_3 == 0) {
    iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x5d4);
    *param_3 = iVar1;
  }
  iVar1 = 0;
  iVar9 = 1;
  param_3 = (int *)*param_3;
  param_3[0x34] = (int)param_2;
  pbVar2 = param_2;
  do {
    pbVar2 = pbVar2 + 1;
    iVar8 = 1;
    if (*pbVar2 != 0) {
      do {
        local_520[iVar1] = (byte)iVar9;
        iVar8 = iVar8 + 1;
        iVar1 = iVar1 + 1;
      } while (iVar8 <= (int)(uint)*pbVar2);
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 0x11);
  iVar9 = 0;
  local_520[iVar1] = 0;
  uVar6 = (uint)local_520[0];
  iVar1 = 0;
  if (uVar6 != 0) {
    do {
      if (local_520[iVar1] == uVar6) {
        piVar3 = local_418 + iVar1;
        iVar8 = iVar1;
        do {
          *piVar3 = iVar9;
          piVar3 = piVar3 + 1;
          iVar1 = iVar8 + 1;
          iVar4 = iVar8 + 1;
          iVar9 = iVar9 + 1;
          iVar8 = iVar1;
        } while (local_520[iVar4] == uVar6);
        iVar9 = iVar9 * 2;
      }
      else {
        iVar9 = iVar9 << 1;
      }
      uVar6 = uVar6 + 1;
    } while (local_520[iVar1] != 0);
  }
  iVar1 = 0;
  iVar9 = 1;
  piVar3 = param_3;
  do {
    if (param_2[iVar9] == 0) {
      piVar3[0x12] = -1;
    }
    else {
      piVar3[0x24] = iVar1;
      piVar3[1] = local_418[iVar1];
      iVar1 = iVar1 + (uint)param_2[iVar9];
      piVar3[0x12] = local_418[iVar1 + -1];
    }
    iVar9 = iVar9 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar9 < 0x11);
  param_3[0x22] = 0xfffff;
  FUN_8002fc00(param_3 + 0x35,0,0x400);
  iVar1 = 0;
  iVar9 = 1;
  pbVar2 = param_2;
  do {
    pbVar2 = pbVar2 + 1;
    iVar8 = 1;
    if (*pbVar2 != 0) {
      piVar3 = local_418 + iVar1;
      do {
        iVar5 = 1 << (8U - iVar9 & 0x1f);
        iVar4 = *piVar3 << (8U - iVar9 & 0x1f);
        if (0 < iVar5) {
          piVar7 = param_3 + iVar4;
          do {
            piVar7[0x35] = iVar9;
            piVar7 = piVar7 + 1;
            iVar5 = iVar5 + -1;
            *(byte *)((int)param_3 + iVar4 + 0x4d4) = param_2[iVar1 + 0x11];
            iVar4 = iVar4 + 1;
          } while (0 < iVar5);
        }
        iVar8 = iVar8 + 1;
        piVar3 = piVar3 + 1;
        iVar1 = iVar1 + 1;
      } while (iVar8 <= (int)(uint)*pbVar2);
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 9);
  return;
}
