/* FUN_8002904c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002904c  body 0x8002904c..0x80029297  size 588 B
 * body sha256 f57bf4992b36ea2ffb349435959163a0d7e9c8ba7bbfa0451ef7fe98e10041b7
 * provider record sha256 28ff2ca894b38a3e306094474da4fdcefd2c1f3e307400506b8a806a8015e3a0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002904c(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  
  iVar15 = *(int *)(param_1 + 0x16c);
  iVar4 = *(int *)(param_1 + 0x130);
  uVar1 = *(int *)(param_1 + 300) - 1;
  uVar16 = *(uint *)(iVar15 + 8);
  while( true ) {
    if (uVar1 < uVar16) {
      *(undefined4 *)(iVar15 + 8) = 0;
      *(int *)(iVar15 + 0xc) = *(int *)(iVar15 + 0xc) + 1;
      return 1;
    }
    FUN_80030fa4(*(undefined4 *)(iVar15 + 0x10),*(int *)(param_1 + 0x134) << 7);
    iVar2 = (**(code **)(*(int *)(param_1 + 0x178) + 4))(param_1,iVar15 + 0x10);
    iVar13 = 0;
    if (iVar2 == 0) break;
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x118)) {
      iVar6 = param_1;
      piVar7 = param_2;
      do {
        iVar9 = *(int *)(iVar6 + 0x11c);
        if (*(int *)(iVar9 + 0x30) == 0) {
          iVar13 = iVar13 + *(int *)(iVar9 + 0x3c);
        }
        else {
          pcVar5 = *(code **)(*(int *)(param_1 + 0x17c) + *(int *)(iVar9 + 4) * 4 + 8);
          if (uVar16 < uVar1) {
            iVar14 = *(int *)(iVar9 + 0x34);
          }
          else {
            iVar14 = *(int *)(iVar9 + 0x44);
          }
          iVar3 = *(int *)(iVar9 + 0x40);
          iVar12 = *piVar7;
          iVar11 = 0;
          if (0 < *(int *)(iVar9 + 0x38)) {
            do {
              if (((*(uint *)(iVar15 + 0xc) < iVar4 - 1U) || (iVar11 < *(int *)(iVar9 + 0x48))) &&
                 (iVar8 = 0, iVar10 = uVar16 * iVar3, 0 < iVar14)) {
                do {
                  (*pcVar5)(param_1,iVar9,*(undefined4 *)(iVar15 + (iVar13 + iVar8) * 4 + 0x10),
                            iVar12,iVar10);
                  iVar8 = iVar8 + 1;
                  iVar10 = iVar10 + *(int *)(iVar9 + 0x24);
                } while (iVar8 < iVar14);
              }
              iVar11 = iVar11 + 1;
              iVar13 = iVar13 + *(int *)(iVar9 + 0x34);
              iVar12 = iVar12 + *(int *)(iVar9 + 0x24) * 4;
            } while (iVar11 < *(int *)(iVar9 + 0x38));
          }
        }
        piVar7 = piVar7 + 1;
        iVar2 = iVar2 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar2 < *(int *)(param_1 + 0x118));
    }
    uVar16 = uVar16 + 1;
  }
  *(uint *)(iVar15 + 8) = uVar16;
  return 0;
}
