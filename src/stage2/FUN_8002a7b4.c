/* FUN_8002a7b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002a7b4  body 0x8002a7b4..0x8002a8ff  size 332 B
 * body sha256 e3e6ff2c1614a022ec91f859e3f060a908ae93f9272564e7a6a15cdc6bc2b911
 * provider record sha256 9480d2c0075568cc1826c191e63cad3b791e506da0410a2032a4694663ea3e79
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002a7b4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar13 = *(int *)(param_1 + 0x168);
  iVar2 = *(int *)(param_1 + 0x10c);
  iVar12 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    piVar11 = (int *)(*(int *)(param_1 + 0xb0) + 0x24);
    do {
      iVar1 = *(int *)(param_1 + 0x10c);
      iVar14 = (piVar11[-6] * *piVar11) / iVar1;
      if (iVar1 == 0) {
        trap(0x1c00);
      }
      if ((iVar1 == -1) && (piVar11[-6] * *piVar11 == -0x80000000)) {
        trap(0x1800);
      }
      puVar9 = *(undefined4 **)(iVar12 * 4 + *(int *)(iVar13 + 0x3c));
      puVar7 = *(undefined4 **)(iVar12 * 4 + *(int *)(iVar13 + 0x40));
      iVar1 = 0;
      if (0 < iVar14) {
        puVar8 = puVar9;
        puVar10 = puVar7;
        do {
          iVar5 = iVar1 - iVar14;
          iVar3 = iVar14 * (iVar2 + 1) + iVar1;
          iVar6 = iVar14 * (iVar2 + 2) + iVar1;
          iVar1 = iVar1 + 1;
          puVar9[iVar5] = puVar9[iVar3];
          puVar7[iVar5] = puVar7[iVar3];
          uVar4 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9[iVar6] = uVar4;
          puVar7[iVar6] = *puVar10;
          puVar10 = puVar10 + 1;
        } while (iVar1 < iVar14);
      }
      iVar12 = iVar12 + 1;
      piVar11 = piVar11 + 0x14;
    } while (iVar12 < *(int *)(param_1 + 0x20));
  }
  return;
}
