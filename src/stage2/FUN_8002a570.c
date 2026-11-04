/* FUN_8002a570
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002a570  body 0x8002a570..0x8002a7b3  size 580 B
 * body sha256 3b20a857431dd69a79110aabe3aec81ef513798526540c8a6fde155b0a006d3a
 * provider record sha256 dcf05c90d08275220c27c7f3826feeead245beb09cd1c0a1b138d2ae5612e33e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002a570(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  
  iVar14 = *(int *)(param_1 + 0x168);
  iVar16 = *(int *)(param_1 + 0x10c);
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,*(int *)(param_1 + 0x20) << 3);
  *(int *)(iVar14 + 0x3c) = iVar1;
  *(int *)(iVar14 + 0x40) = iVar1 + *(int *)(param_1 + 0x20) * 4;
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    piVar13 = (int *)(*(int *)(param_1 + 0xb0) + 0x24);
    iVar15 = iVar14;
    do {
      iVar2 = *(int *)(param_1 + 0x10c);
      iVar17 = (piVar13[-6] * *piVar13) / iVar2;
      if (iVar2 == 0) {
        trap(0x1c00);
      }
      if ((iVar2 == -1) && (piVar13[-6] * *piVar13 == -0x80000000)) {
        trap(0x1800);
      }
      iVar2 = iVar17 * (iVar16 + 4);
      iVar3 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,iVar2 * 8);
      puVar10 = (undefined4 *)(iVar3 + iVar17 * 4);
      *(undefined4 **)(iVar1 * 4 + *(int *)(iVar14 + 0x3c)) = puVar10;
      iVar3 = iVar17 * (iVar16 + 2);
      puVar11 = puVar10 + iVar2;
      *(undefined4 **)(iVar1 * 4 + *(int *)(iVar14 + 0x40)) = puVar11;
      puVar12 = *(undefined4 **)(iVar15 + 0xc);
      iVar2 = 0;
      if (0 < iVar3) {
        puVar5 = puVar12;
        puVar7 = puVar11;
        puVar9 = puVar10;
        do {
          uVar4 = *puVar5;
          puVar5 = puVar5 + 1;
          iVar2 = iVar2 + 1;
          *puVar7 = uVar4;
          *puVar9 = uVar4;
          puVar9 = puVar9 + 1;
          puVar7 = puVar7 + 1;
        } while (iVar2 < iVar3);
      }
      iVar2 = 0;
      if (0 < iVar17 << 1) {
        iVar3 = iVar17 * (iVar16 + -2);
        iVar6 = iVar3;
        do {
          iVar8 = iVar17 * iVar16 + iVar2;
          iVar2 = iVar2 + 1;
          puVar11[iVar6] = puVar12[iVar8];
          puVar11[iVar8] = puVar12[iVar6];
          iVar6 = iVar3 + iVar2;
        } while (iVar2 < iVar17 << 1);
      }
      iVar2 = 0;
      if (0 < iVar17) {
        iVar3 = -iVar17;
        do {
          iVar2 = iVar2 + 1;
          puVar10[iVar3] = *puVar10;
          iVar3 = iVar2 - iVar17;
        } while (iVar2 < iVar17);
      }
      iVar15 = iVar15 + 4;
      iVar1 = iVar1 + 1;
      piVar13 = piVar13 + 0x14;
    } while (iVar1 < *(int *)(param_1 + 0x20));
  }
  return;
}
