/* FUN_8004a5bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a5bc  body 0x8004a5bc..0x8004a793  size 472 B
 * body sha256 93f2e39e9d2c41e0f3c5c734743bb7f36a3109946ed526d0489a8bf713e8b2bd
 * provider record sha256 582055b78f1190d4132927e112a89bdca6e3f0505ae7bc8ef2f7a7d4634a07f7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a5bc(int param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  short *psVar14;
  int iVar15;
  int iVar16;
  short sStack_e;
  short sStack_a;
  short sStack_6;
  
  piVar5 = *(int **)(param_2 + 200);
  iVar16 = *(int *)(param_1 + 0x48);
  puVar13 = (undefined4 *)piVar5[2];
  if ((iVar16 == 0) || (puVar13 == (undefined4 *)0x0)) {
    if (puVar13 != (undefined4 *)0x0) {
      piVar5[2] = 0;
    }
  }
  else {
    psVar14 = (short *)(puVar13 + 3);
    iVar15 = *piVar5;
    iVar12 = (int)*(short *)(&DAT_800f9e40 +
                            (*(ushort *)(param_2 + 0x138) & 0x7fff) * 2 +
                            (uint)(*(ushort *)(param_2 + 0x138) >> 0xf) * 0x3c);
    while (iVar15 = iVar15 + -1, iVar15 != -1) {
      psVar10 = (short *)*puVar13;
      iVar11 = (int)psVar14[1];
      psVar9 = (short *)(iVar16 + *psVar14 * 0x10);
      psVar6 = psVar10 + 3;
      psVar8 = psVar9 + 3;
      while (bVar1 = iVar11 != 0, iVar11 = iVar11 + -3, bVar1) {
        cVar2 = *(char *)(psVar6 + 3);
        cVar3 = *(char *)((int)psVar6 + 7);
        cVar4 = *(char *)(psVar6 + 4);
        *(undefined4 *)(psVar8 + -1) = *(undefined4 *)(psVar6 + -1);
        sStack_e = (short)(cVar2 * iVar12 >> 6);
        *psVar9 = *psVar10 + sStack_e;
        sStack_a = (short)(cVar3 * iVar12 >> 6);
        psVar8[-2] = psVar6[-2] + sStack_a;
        sStack_6 = (short)(cVar4 * iVar12 >> 6);
        psVar8[-1] = psVar6[-1] + sStack_6;
        *psVar8 = *psVar6;
        *(undefined4 *)(psVar8 + 7) = *(undefined4 *)(psVar6 + 7);
        psVar9[8] = psVar10[8] + sStack_e;
        psVar8[6] = psVar6[6] + sStack_a;
        psVar8[7] = psVar6[7] + sStack_6;
        psVar7 = psVar6 + 0x10;
        psVar8[8] = psVar6[8];
        *(undefined4 *)(psVar8 + 0xf) = *(undefined4 *)(psVar6 + 0xf);
        psVar9[0x10] = psVar10[0x10] + sStack_e;
        psVar10 = psVar10 + 0x18;
        psVar8[0xe] = psVar6[0xe] + sStack_a;
        psVar9 = psVar9 + 0x18;
        psVar8[0xf] = psVar6[0xf] + sStack_6;
        psVar6 = psVar6 + 0x18;
        psVar8[0x10] = *psVar7;
        psVar8 = psVar8 + 0x18;
      }
      psVar14 = psVar14 + 8;
      puVar13 = puVar13 + 4;
    }
  }
  return;
}
