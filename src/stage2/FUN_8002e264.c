/* FUN_8002e264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e264  body 0x8002e264..0x8002e4fb  size 664 B
 * body sha256 acf6cb475393d284e63d3802322c89683d4fa89c61ab77d74ee8705945ee4b82
 * provider record sha256 aaad50b2af40ba2c2bf3c519503f5a7747c65614b4ad095def418f87c5f24529
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e264(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  
  puVar9 = (undefined1 *)*param_4;
  puVar10 = (undefined1 *)param_4[1];
  iVar6 = *(int *)(param_1 + 0x114);
  uVar19 = *(uint *)(param_1 + 0x5c) >> 1;
  puVar1 = (undefined4 *)(param_3 * 8 + *param_2);
  pbVar13 = (byte *)*puVar1;
  pbVar14 = (byte *)puVar1[1];
  pbVar18 = *(byte **)(param_3 * 4 + param_2[1]);
  iVar2 = *(int *)(param_1 + 0x180);
  pbVar5 = *(byte **)(param_3 * 4 + param_2[2]);
  iVar15 = *(int *)(iVar2 + 0x10);
  iVar17 = *(int *)(iVar2 + 0x14);
  iVar16 = *(int *)(iVar2 + 0x18);
  iVar2 = *(int *)(iVar2 + 0x1c);
  if (uVar19 != 0) {
    puVar8 = puVar10 + 2;
    puVar7 = puVar9 + 2;
    do {
      uVar4 = (uint)*pbVar13;
      iVar11 = *(int *)((uint)*pbVar5 * 4 + iVar15);
      iVar12 = *(int *)((uint)*pbVar18 * 4 + iVar17);
      iVar3 = *(int *)((uint)*pbVar18 * 4 + iVar2) + *(int *)((uint)*pbVar5 * 4 + iVar16) >> 0x10;
      *puVar9 = *(undefined1 *)(iVar6 + uVar4 + iVar11);
      pbVar18 = pbVar18 + 1;
      puVar7[-1] = *(undefined1 *)(iVar6 + uVar4 + iVar3);
      *puVar7 = *(undefined1 *)(iVar6 + uVar4 + iVar12);
      uVar4 = (uint)pbVar13[1];
      pbVar5 = pbVar5 + 1;
      puVar9[3] = *(undefined1 *)(iVar6 + uVar4 + iVar11);
      puVar7[2] = *(undefined1 *)(iVar6 + uVar4 + iVar3);
      uVar19 = uVar19 - 1;
      puVar7[3] = *(undefined1 *)(iVar6 + uVar4 + iVar12);
      uVar4 = (uint)*pbVar14;
      pbVar13 = pbVar13 + 2;
      puVar9 = puVar9 + 6;
      *puVar10 = *(undefined1 *)(iVar6 + uVar4 + iVar11);
      puVar7 = puVar7 + 6;
      puVar8[-1] = *(undefined1 *)(iVar6 + uVar4 + iVar3);
      *puVar8 = *(undefined1 *)(iVar6 + uVar4 + iVar12);
      uVar4 = (uint)pbVar14[1];
      puVar10[3] = *(undefined1 *)(iVar6 + uVar4 + iVar11);
      pbVar14 = pbVar14 + 2;
      puVar8[2] = *(undefined1 *)(iVar6 + uVar4 + iVar3);
      puVar10 = puVar10 + 6;
      puVar8[3] = *(undefined1 *)(iVar6 + uVar4 + iVar12);
      puVar8 = puVar8 + 6;
    } while (uVar19 != 0);
  }
  if ((*(uint *)(param_1 + 0x5c) & 1) != 0) {
    uVar19 = (uint)*pbVar13;
    iVar15 = *(int *)((uint)*pbVar5 * 4 + iVar15);
    iVar17 = *(int *)((uint)*pbVar18 * 4 + iVar17);
    iVar2 = *(int *)((uint)*pbVar18 * 4 + iVar2) + *(int *)((uint)*pbVar5 * 4 + iVar16) >> 0x10;
    *puVar9 = *(undefined1 *)(iVar6 + uVar19 + iVar15);
    puVar9[1] = *(undefined1 *)(iVar6 + uVar19 + iVar2);
    puVar9[2] = *(undefined1 *)(iVar6 + uVar19 + iVar17);
    uVar19 = (uint)*pbVar14;
    *puVar10 = *(undefined1 *)(iVar6 + uVar19 + iVar15);
    puVar10[1] = *(undefined1 *)(iVar6 + uVar19 + iVar2);
    puVar10[2] = *(undefined1 *)(iVar6 + uVar19 + iVar17);
  }
  return;
}
