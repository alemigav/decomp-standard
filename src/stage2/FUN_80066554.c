/* FUN_80066554
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80066554  body 0x80066554..0x800666eb  size 408 B
 * body sha256 7dfa70cc57f03ead2379b2e27381bfdc5ef90f8031a416dd27ca176b4da0f963
 * provider record sha256 0320b9292a9fd81d3a4345c45ce41129f8993b0ae82e2024e7dd38e117417924
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80066554(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  short *psVar13;
  uint uVar14;
  int iVar15;
  
  iVar8 = *(int *)(param_1 + 600);
  iVar15 = *(int *)(param_1 + 0x234);
  uVar14 = (uint)*(ushort *)(*(int *)(param_1 + 0x1a4) + 6);
  psVar13 = (short *)(*(int *)(iVar8 + 4) + iVar8);
  iVar6 = *(int *)(param_2 + 0x120);
  iVar7 = uVar14 - 2;
  if ((*(byte *)(param_2 + 0x110) + 1 < uVar14) && (iVar7 != -1)) {
    piVar4 = (int *)(iVar15 + 0x19c);
    psVar5 = psVar13;
    do {
      piVar4[-2] = (int)psVar5[3];
      iVar7 = iVar7 + -1;
      piVar4[-1] = (int)psVar5[4];
      *piVar4 = (int)psVar5[5];
      piVar4 = piVar4 + 0x5e;
      psVar5 = psVar5 + 3;
    } while (iVar7 != -1);
  }
  uVar12 = (uint)*(ushort *)(iVar6 + 10);
  iVar7 = *(int *)(iVar8 + 8);
  do {
    sVar1 = *(short *)(iVar6 + 0xe);
    iVar8 = uVar14 - 1;
    iVar11 = 3;
    iVar9 = (int)*(short *)(iVar6 + 0xc);
    piVar4 = (int *)(iVar15 + 0x19c);
    iVar10 = 0x1000 - iVar9;
    while( true ) {
      iVar8 = iVar8 + -1;
      if (iVar8 == -1) break;
      psVar5 = (short *)((int)psVar13 + iVar11 * 2 + iVar7 * sVar1);
      sVar2 = psVar5[1];
      iVar11 = iVar11 + 3;
      sVar3 = psVar5[2];
      piVar4[-2] = piVar4[-2] * iVar10 + *psVar5 * iVar9 >> 0xc;
      piVar4[-1] = piVar4[-1] * iVar10 + sVar2 * iVar9 >> 0xc;
      *piVar4 = *piVar4 * iVar10 + sVar3 * iVar9 >> 0xc;
      piVar4 = piVar4 + 0x5e;
    }
    uVar12 = uVar12 - 1;
    iVar6 = iVar6 + 4;
  } while (uVar12 != 0);
  return;
}
