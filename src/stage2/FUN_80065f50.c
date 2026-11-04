/* FUN_80065f50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80065f50  body 0x80065f50..0x80066047  size 248 B
 * body sha256 b2b3037445cbeb14117730773f38e1cec9bfc14a268884a7d387d0874bf3764a
 * provider record sha256 276cd01fdc386ece81b391b1eefb72153170cc3c1589f607ccd7038ad843d626
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80065f50(int param_1,undefined2 *param_2)

{
  bool bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  short sVar11;
  int iVar12;
  ushort *puVar13;
  ushort *puVar14;
  int *piVar15;
  int local_28 [10];
  
  piVar15 = *(int **)(param_1 + 200);
  piVar6 = (int *)piVar15[3];
  piVar9 = local_28;
  if (piVar6 != (int *)0x0) {
    puVar10 = (undefined4 *)piVar15[1];
    iVar12 = 0;
    if (0 < *piVar15) {
      do {
        uVar7 = *puVar10;
        puVar10 = puVar10 + 4;
        iVar12 = iVar12 + 1;
        *piVar9 = uVar7;
        piVar9 = piVar9 + 1;
      } while (iVar12 < *piVar15);
    }
    if (iVar12 < 10) {
      piVar9 = local_28 + iVar12;
      do {
        *piVar9 = 0;
        iVar12 = iVar12 + 1;
        piVar9 = piVar9 + 1;
      } while (iVar12 < 10);
    }
    iVar12 = *piVar6;
    puVar13 = (ushort *)(piVar6 + iVar12 + 1);
    do {
      piVar6 = piVar6 + 1;
      uVar2 = *param_2;
      uVar3 = param_2[1];
      uVar4 = param_2[2];
      param_2 = param_2 + 3;
      sVar11 = *(short *)piVar6;
      while (bVar1 = sVar11 != 0, sVar11 = sVar11 + -1, bVar1) {
        uVar5 = *puVar13;
        puVar14 = puVar13 + 1;
        puVar13 = puVar13 + 2;
        puVar8 = (undefined2 *)(local_28[uVar5] + (uint)*puVar14 * 0x10);
        *puVar8 = uVar2;
        puVar8[1] = uVar3;
        puVar8[2] = uVar4;
      }
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  return;
}
