/* FUN_80036008
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036008  body 0x80036008..0x8003628f  size 648 B
 * body sha256 5c3f21141591a4bd8b64c9965e7aab0e7b19ffee7c940f1cfc4b3747a3f2efa7
 * provider record sha256 ba9e96187e4a2925d39fdbcc19c6a740f9dee23d5962802c024a5035070deaf8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
short * FUN_80036008(undefined4 param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  short *psVar10;
  uint *puVar11;
  short *psVar12;
  short *psVar13;
  ushort *puVar14;
  uint uVar15;
  int local_20 [8];
  
  uVar15 = (uint)*(ushort *)(param_3 + 2);
  *(int *)(param_3 + 4) = param_4;
  iVar2 = uVar15 * 8;
  *(int *)(param_3 + 8) = param_4 + iVar2;
  iVar9 = param_4 + iVar2 + iVar2;
  *(int *)(param_3 + 0x1c) = iVar9;
  iVar9 = iVar9 + iVar2;
  *(int *)(param_3 + 0x20) = iVar9;
  puVar11 = *(uint **)(param_2 + 200);
  piVar5 = local_20;
  piVar4 = (int *)puVar11[3];
  psVar10 = (short *)(iVar9 + iVar2);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined4 *)puVar11[1];
    uVar8 = 0;
    if (*puVar11 != 0) {
      do {
        uVar3 = *puVar6;
        puVar6 = puVar6 + 4;
        uVar8 = uVar8 + 1;
        *piVar5 = uVar3;
        piVar5 = piVar5 + 1;
      } while (uVar8 < *puVar11);
    }
    if (uVar8 < 8) {
      piVar5 = local_20 + uVar8;
      do {
        *piVar5 = 0;
        uVar8 = uVar8 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar8 < 8);
    }
    iVar2 = *piVar4;
    puVar14 = *(ushort **)(param_3 + 0x34);
    psVar12 = psVar10 + 2;
    *(short **)(param_3 + 0xc) = psVar10;
    psVar13 = psVar10 + uVar15 * 4;
    uVar8 = uVar15;
    do {
      psVar7 = (short *)(local_20[*(short *)(piVar4 + iVar2 + *(short *)((int)piVar4 +
                                                                        (uint)*puVar14 * 4 + 6) + 1)
                                 ] +
                        (short)piVar4[iVar2 + *(short *)((int)piVar4 + (uint)*puVar14 * 4 + 6) + 1]
                        * 0x10);
      puVar14 = puVar14 + 2;
      *psVar10 = *psVar7 + *(short *)(param_3 + 0x14);
      uVar8 = uVar8 - 1;
      psVar12[-1] = psVar7[1] + *(short *)(param_3 + 0x16);
      psVar10 = psVar10 + 4;
      *psVar12 = psVar7[2] + *(short *)(param_3 + 0x18);
      psVar12 = psVar12 + 4;
    } while (uVar8 != 0);
    *(short **)(param_3 + 0x24) = psVar13;
    psVar12 = psVar13 + uVar15 * 4;
    psVar10 = psVar13 + 2;
    puVar14 = *(ushort **)(param_3 + 0x34);
    uVar8 = uVar15;
    do {
      psVar7 = (short *)(local_20[*(short *)(piVar4 + iVar2 + *(short *)((int)piVar4 +
                                                                        (uint)*puVar14 * 4 + 6) + 1)
                                 ] +
                        (short)piVar4[iVar2 + *(short *)((int)piVar4 + (uint)*puVar14 * 4 + 6) + 1]
                        * 0x10);
      puVar14 = puVar14 + 2;
      *psVar13 = *psVar7 + *(short *)(param_3 + 0x2c);
      uVar8 = uVar8 - 1;
      psVar10[-1] = psVar7[1] + *(short *)(param_3 + 0x2e);
      psVar13 = psVar13 + 4;
      *psVar10 = psVar7[2] + *(short *)(param_3 + 0x30);
      psVar10 = psVar10 + 4;
    } while (uVar8 != 0);
    *(short **)(param_3 + 0x10) = psVar12;
    psVar10 = psVar12 + uVar15 * 4;
    psVar13 = psVar12 + 2;
    puVar14 = *(ushort **)(param_3 + 0x34);
    do {
      uVar1 = *puVar14;
      puVar14 = puVar14 + 2;
      uVar15 = uVar15 - 1;
      iVar9 = local_20[*(short *)(piVar4 + iVar2 + *(short *)((int)piVar4 + (uint)uVar1 * 4 + 6) + 1
                                 )] +
              (short)piVar4[iVar2 + *(short *)((int)piVar4 + (uint)uVar1 * 4 + 6) + 1] * 0x10;
      *psVar12 = *(short *)(param_3 + 0x2c) + *(char *)(iVar9 + 0xc) * 0x100;
      psVar12 = psVar12 + 4;
      psVar13[-1] = *(short *)(param_3 + 0x2e) + *(char *)(iVar9 + 0xd) * 0x100;
      *psVar13 = *(short *)(param_3 + 0x30) + *(char *)(iVar9 + 0xe) * 0x100;
      psVar13 = psVar13 + 4;
    } while (uVar15 != 0);
  }
  return psVar10;
}
