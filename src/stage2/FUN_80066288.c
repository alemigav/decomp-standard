/* FUN_80066288
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80066288  body 0x80066288..0x80066553  size 716 B
 * body sha256 8dd5a2b8c0351a7545c0b7b908010c1c5e9f4cb88622df2b0db180e71517066b
 * provider record sha256 a0c8b7079637a7d05a65e966ab10be723f9e02b54d537f3b182a6f990a69e1ca
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80066288(int param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint local_40;
  
  iVar21 = 1;
  if (*(int *)(*(int *)(param_2 + 200) + 0xc) == 0) {
    if (DAT_80112560 == 0) {
      DAT_80112560 = 1;
    }
  }
  else {
    piVar16 = *(int **)(param_2 + 0x120);
    iVar17 = *(int *)(param_1 + 600);
    iVar5 = *piVar16;
    FUN_80065f50(param_2);
    iVar9 = *(int *)(param_1 + 0x1a4);
    uVar11 = (uint)*(byte *)(param_2 + 0x110);
    iVar6 = iVar9 + (*(ushort *)(iVar9 + 2) & 0xfffc);
    uVar12 = *(uint *)(iVar6 + uVar11 * 4);
    uVar22 = (uint)*(ushort *)((int)piVar16 + 10);
    uVar8 = piVar16[1];
    uVar14 = iVar6 + (uVar12 >> 0x10);
    uVar2 = *(ushort *)(iVar9 + 6);
    iVar6 = *(int *)(param_1 + 0x234);
    iVar9 = *(int *)(iVar17 + 4) + iVar17;
    if (uVar11 < uVar2) {
      local_40 = uVar12 & 0xffff;
      uVar12 = uVar14;
      uVar13 = local_40;
      while (uVar13 = uVar13 - 1, uVar13 != 0xffffffff) {
        psVar7 = (short *)((uint)*(byte *)(uVar12 ^ 3) * 6 + iVar9);
        iVar18 = iVar6 + (uint)*(byte *)(uVar12 ^ 3) * 0x178;
        *(int *)(iVar18 + 0x1c) = (int)*psVar7;
        uVar12 = uVar12 + 1;
        *(int *)(iVar18 + 0x20) = (int)psVar7[1];
        *(int *)(iVar18 + 0x24) = (int)psVar7[2];
      }
    }
    iVar18 = *(int *)(iVar17 + 8);
    uVar12 = uVar8 >> 1;
    do {
      iVar19 = (int)*(short *)(piVar16 + iVar21 + 2);
      iVar20 = 0x1000 - iVar19;
      if ((iVar19 != 0) &&
         (FUN_80066048(param_2,iVar5 + iVar17 + uVar12 * 2,iVar20,iVar19), uVar11 + 1 <= (uint)uVar2
         )) {
        sVar1 = *(short *)((int)piVar16 + iVar21 * 4 + 10);
        uVar13 = local_40;
        uVar15 = uVar14;
        while( true ) {
          uVar13 = uVar13 - 1;
          if (uVar13 == 0xffffffff) break;
          iVar10 = iVar6 + (uint)*(byte *)(uVar15 ^ 3) * 0x178;
          psVar7 = (short *)(iVar9 + iVar18 * sVar1 + (uint)*(byte *)(uVar15 ^ 3) * 6);
          sVar3 = psVar7[1];
          uVar15 = uVar15 + 1;
          sVar4 = psVar7[2];
          *(int *)(iVar10 + 0x1c) = *(int *)(iVar10 + 0x1c) * iVar20 + *psVar7 * iVar19 >> 0xc;
          *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) * iVar20 + sVar3 * iVar19 >> 0xc;
          *(int *)(iVar10 + 0x24) = *(int *)(iVar10 + 0x24) * iVar20 + sVar4 * iVar19 >> 0xc;
        }
      }
      uVar12 = uVar12 + (uVar8 >> 1);
      uVar22 = uVar22 - 1;
      iVar21 = iVar21 + 1;
    } while (uVar22 != 0);
  }
  return;
}
