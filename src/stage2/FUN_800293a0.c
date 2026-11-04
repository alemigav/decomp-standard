/* FUN_800293a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800293a0  body 0x800293a0..0x80029647  size 680 B
 * body sha256 3a697268277f29035f98a2bc6dcfbe8ff93d76cd4fd1ddd333d6c050655fafee
 * provider record sha256 9a4c16312343734e055e3eb820ce4dcea3a679db4341b7acdb56f3adfcbfd941
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800293a0(int *param_1)

{
  short sVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  int *piVar8;
  double *pdVar9;
  short *psVar10;
  double *pdVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  double dVar18;
  double dVar19;
  
  iVar16 = 0;
  iVar17 = param_1[0x5f];
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_1[0x46] <= iVar16) {
            return;
          }
          iVar15 = param_1[iVar16 + 0x47];
          uVar13 = *(uint *)(iVar15 + 0x10);
          if ((3 < uVar13) || (param_1[uVar13 + 0x1f] == 0)) {
            *(undefined4 *)(*param_1 + 0x14) = 0x2c;
            *(uint *)(*param_1 + 0x18) = uVar13;
            (**(code **)*param_1)(param_1);
          }
          iVar14 = param_1[uVar13 + 0x1f];
          if (*(int *)(iVar15 + 0x4c) == 0) break;
          iVar16 = iVar16 + 1;
        }
        iVar4 = *(int *)(iVar17 + *(int *)(iVar15 + 4) * 4 + 0x30);
        if (iVar4 != 1) break;
        piVar5 = (int *)(**(code **)param_1[1])(param_1,1,0x100);
        iVar4 = 0;
        psVar10 = &DAT_800b6b40;
        piVar8 = &DAT_800b6c00;
        *(int **)(iVar15 + 0x4c) = piVar5;
        do {
          iVar15 = *piVar8;
          sVar1 = *psVar10;
          piVar8 = piVar8 + 1;
          iVar4 = iVar4 + 1;
          psVar10 = psVar10 + 1;
          *piVar5 = (int)((uint)*(ushort *)(iVar14 + iVar15 * 2) * (int)sVar1 + 0x800) >> 0xc;
          piVar5 = piVar5 + 1;
        } while (iVar4 < 0x40);
        iVar16 = iVar16 + 1;
      }
      if (1 < iVar4) break;
      if (iVar4 == 0) {
        puVar2 = (uint *)(**(code **)param_1[1])(param_1,1,0x100);
        iVar4 = 0;
        piVar5 = &DAT_800b6c00;
        *(uint **)(iVar15 + 0x4c) = puVar2;
        do {
          iVar15 = *piVar5;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 1;
          *puVar2 = (uint)*(ushort *)(iVar14 + iVar15 * 2);
          puVar2 = puVar2 + 1;
        } while (iVar4 < 0x40);
        iVar16 = iVar16 + 1;
      }
      else {
LAB_80029600:
        *(undefined4 *)(*param_1 + 0x14) = 0x28;
        (**(code **)*param_1)(param_1);
        iVar16 = iVar16 + 1;
      }
    }
    if (iVar4 != 2) goto LAB_80029600;
    iVar4 = (**(code **)param_1[1])(param_1,1,0x100);
    iVar7 = 0;
    iVar12 = 0;
    pdVar11 = (double *)&DAT_800b6bc0;
    *(int *)(iVar15 + 0x4c) = iVar4;
    do {
      iVar15 = 0;
      dVar19 = *pdVar11;
      pdVar9 = (double *)&DAT_800b6bc0;
      pfVar6 = (float *)(iVar7 * 4 + iVar4);
      piVar5 = &DAT_800b6c00 + iVar7;
      do {
        iVar3 = *piVar5;
        dVar18 = *pdVar9;
        piVar5 = piVar5 + 1;
        iVar7 = iVar7 + 1;
        pdVar9 = pdVar9 + 1;
        iVar15 = iVar15 + 1;
        *pfVar6 = (float)((double)*(ushort *)(iVar14 + iVar3 * 2) * dVar19 * dVar18);
        pfVar6 = pfVar6 + 1;
      } while (iVar15 < 8);
      iVar12 = iVar12 + 1;
      pdVar11 = pdVar11 + 1;
    } while (iVar12 < 8);
    iVar16 = iVar16 + 1;
  } while( true );
}
