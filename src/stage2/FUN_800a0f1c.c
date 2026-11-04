/* FUN_800a0f1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a0f1c  body 0x800a0f1c..0x800a1133  size 536 B
 * body sha256 8c03e600b9303c5465aeada8a566927d30dc286a8d333898489e98ad0135926f
 * provider record sha256 5b1e5a77bf699dff9547eea3ad3823ea31569e90b476f51e8cdfff123781f0c3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a0f1c(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  
  uVar2 = 0;
  puVar4 = (uint *)&DAT_8013bc90;
  while ((*(char *)((int)puVar4 + 0xfc1) != '\0' || (*puVar4 != (param_1 & 0x7fffffff)))) {
    uVar2 = uVar2 + 1;
    puVar4 = puVar4 + 0x3fe;
    if (7 < uVar2) {
      uVar2 = 0xffffffff;
LAB_800a0f78:
      if (uVar2 != 0xffffffff) {
        if ((int)uVar2 < 0) {
          iVar3 = (uVar2 * 0x200 - (uVar2 & 0x7fffffff)) * 8;
          if (((&DAT_8013cc50)[iVar3] != '\0') && ((&DAT_8013cc51)[iVar3] == '\0')) {
            *(undefined4 *)(iVar3 + -0x7fec3380) = 0;
          }
        }
        else {
          iVar3 = uVar2 * 0xff8;
          if (((&DAT_8013cc50)[iVar3] != '\0') && ((&DAT_8013cc51)[iVar3] == '\0')) {
            (&DAT_8013cc50)[iVar3] = 0;
            for (piVar5 = *(int **)(iVar3 + -0x7fec33f8); piVar5 != (int *)0x0;
                piVar5 = (int *)*piVar5) {
              FUN_800aee80(piVar5[2]);
            }
            for (piVar5 = *(int **)(&DAT_8013cc0c + iVar3); piVar5 != (int *)0x0;
                piVar5 = (int *)*piVar5) {
              FUN_800aee80(piVar5[2]);
            }
            iVar3 = uVar2 * 0xff8;
            piVar5 = *(int **)(iVar3 + -0x7fec33f8);
            if (piVar5 != (int *)0x0) {
              iVar1 = *piVar5;
              while (iVar1 != 0) {
                piVar5 = (int *)*piVar5;
                iVar1 = *piVar5;
              }
              if (_DAT_8013bc80 != 0) {
                *piVar5 = _DAT_8013bc80;
                *(int **)(_DAT_8013bc80 + 4) = piVar5;
              }
              _DAT_8013bc80 = *(int *)(iVar3 + -0x7fec33f8);
              *(undefined4 *)(iVar3 + -0x7fec33f8) = 0;
            }
            piVar5 = *(int **)(&DAT_8013cc0c + iVar3);
            if (piVar5 != (int *)0x0) {
              iVar1 = *piVar5;
              while (iVar1 != 0) {
                piVar5 = (int *)*piVar5;
                iVar1 = *piVar5;
              }
              if (_DAT_8013bc80 != 0) {
                *piVar5 = _DAT_8013bc80;
                *(int **)(_DAT_8013bc80 + 4) = piVar5;
              }
              _DAT_8013bc80 = *(int *)(&DAT_8013cc0c + iVar3);
              *(undefined4 *)(&DAT_8013cc0c + iVar3) = 0;
            }
          }
          (&DAT_8013cc51)[uVar2 * 0xff8] = 1;
        }
      }
      return;
    }
  }
  uVar2 = uVar2 | param_1 & 0x80000000;
  goto LAB_800a0f78;
}
