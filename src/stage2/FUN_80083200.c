/* FUN_80083200
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083200  body 0x80083200..0x80083747  size 1352 B
 * body sha256 f6759952bbf7c5004ecdf05d41957ea32f6e5b5621430be487ae58a1d516dec3
 * provider record sha256 1bc10dfdc89ea807e1fa3e2494833698692e67b829c2ad18bea52f2b0bf3836e
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80083610) */
/* WARNING: Removing unreachable block (ram,0x80083554) */

void FUN_80083200(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  
  iVar16 = 0;
  iVar18 = 0;
  iVar17 = 0;
  iVar15 = 0;
  uVar24 = 0x3f800000;
  uVar23 = 0x42f00000;
  iVar13 = *(int *)(DAT_800df92c + 0x2c) + DAT_800e8cac * 0x28;
  iVar11 = param_1;
  iVar12 = iVar13;
  iVar14 = iVar13;
  do {
    if (2 < iVar18) {
      iVar12 = 0;
      iVar11 = iVar13;
      do {
        puVar8 = (undefined1 *)(param_1 + iVar12);
        *puVar8 = *(undefined1 *)(iVar11 + 0xd);
        iVar12 = iVar12 + 1;
        puVar8[4] = *(undefined1 *)(iVar11 + 0xd);
        iVar11 = iVar13 + iVar12;
      } while (iVar12 < 3);
      if (iVar16 == 0) {
        iVar11 = 0;
        do {
          iVar12 = iVar11 + 1;
          *(undefined1 *)(param_1 + iVar11 + 8) = 0;
          *(undefined1 *)(param_1 + iVar11 + 0xc) = 0;
          iVar11 = iVar12;
        } while (iVar12 < 3);
        *(undefined1 *)(param_1 + 0x10) = 0;
        *(undefined1 *)(param_1 + 0x11) = 0;
        *(undefined1 *)(param_1 + 0x12) = 0;
        *(undefined4 *)(param_1 + 0x38) = 1;
      }
      else {
        *(int *)(param_1 + 0x38) = iVar16;
      }
      return;
    }
    iVar9 = 0;
    if (*(char *)(iVar13 + iVar18 + 1) == '\0') {
      iVar4 = *param_2 - (int)*(short *)(iVar12 + 0x10) >> 4;
      iVar9 = param_2[1] - (int)*(short *)(iVar12 + 0x12) >> 4;
      iVar2 = param_2[2] - (int)*(short *)(iVar12 + 0x14) >> 4;
      iVar3 = FUN_80040bb4(iVar4 * iVar4 + iVar2 * iVar2);
      uVar5 = (uint)(*(ushort *)(iVar14 + 0x22) >> 4);
      iVar3 = uVar5 - iVar3;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      iVar6 = iVar13 + iVar17;
      if (uVar5 != 0) {
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if ((uVar5 == 0xffffffff) && ((uint)*(byte *)(iVar6 + 4) * iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        uVar5 = (uint)(*(ushort *)(iVar14 + 0x22) >> 4);
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if ((uVar5 == 0xffffffff) && ((uint)*(byte *)(iVar6 + 5) * iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        uVar5 = (uint)(*(ushort *)(iVar14 + 0x22) >> 4);
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if ((uVar5 == 0xffffffff) && ((uint)*(byte *)(iVar6 + 6) * iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        iVar10 = 0;
        iVar6 = iVar17;
        do {
          iVar1 = (uint)*(byte *)(iVar13 + iVar6 + 4) * iVar3;
          uVar5 = (uint)(*(ushort *)(iVar14 + 0x22) >> 4);
          if (uVar5 == 0) {
            trap(0x1c00);
          }
          if ((uVar5 == 0xffffffff) && (iVar1 == -0x80000000)) {
            trap(0x1800);
          }
          iVar7 = param_1 + iVar10 + iVar15;
          *(char *)(iVar7 + 8) = (char)(iVar1 / (int)uVar5);
          iVar6 = (uint)*(byte *)(iVar13 + iVar6 + 4) * iVar3;
          uVar5 = (uint)(*(ushort *)(iVar14 + 0x22) >> 4);
          if (uVar5 == 0) {
            trap(0x1c00);
          }
          if ((uVar5 == 0xffffffff) && (iVar6 == -0x80000000)) {
            trap(0x1800);
          }
          iVar10 = iVar10 + 1;
          *(char *)(iVar7 + 0xc) = (char)(iVar6 / (int)uVar5);
          iVar6 = iVar10 + iVar17;
        } while (iVar10 < 3);
        *(char *)(iVar11 + 0x10) = (char)(-iVar4 >> 4);
        *(char *)(iVar11 + 0x11) = (char)(-iVar9 >> 4);
        *(char *)(iVar11 + 0x12) = (char)(-iVar2 >> 4);
        fVar22 = (float)-iVar4;
        fVar21 = (float)-iVar9;
        fVar20 = (float)-iVar2;
        fVar19 = SQRT(fVar22 * fVar22 + fVar21 * fVar21 + fVar20 * fVar20);
        if (fVar19 <= (float)uVar24) goto LAB_80083634;
        fVar19 = (float)uVar23 / fVar19;
        goto LAB_80083638;
      }
    }
    else {
      iVar2 = iVar15;
      do {
        iVar3 = iVar13 + iVar9 + iVar17;
        *(undefined1 *)(param_1 + iVar2 + 8) = *(undefined1 *)(iVar3 + 4);
        iVar9 = iVar9 + 1;
        *(undefined1 *)(param_1 + iVar2 + 0xc) = *(undefined1 *)(iVar3 + 4);
        iVar2 = iVar9 + iVar15;
      } while (iVar9 < 3);
      fVar22 = (float)-(int)*(short *)(iVar12 + 0x10);
      fVar21 = (float)-(int)*(short *)(iVar12 + 0x12);
      fVar20 = (float)-(int)*(short *)(iVar12 + 0x14);
      fVar19 = SQRT(fVar22 * fVar22 + fVar21 * fVar21 + fVar20 * fVar20);
      if ((float)uVar24 < fVar19) {
        fVar19 = (float)uVar23 / fVar19;
      }
      else {
LAB_80083634:
        fVar19 = 0.0;
      }
LAB_80083638:
      iVar15 = iVar15 + 0x10;
      iVar16 = iVar16 + 1;
      *(char *)(iVar11 + 0x10) = (char)(int)(fVar19 * fVar22);
      *(char *)(iVar11 + 0x11) = (char)(int)(fVar19 * fVar21);
      *(char *)(iVar11 + 0x12) = (char)(int)(fVar19 * fVar20);
      iVar11 = iVar11 + 0x10;
    }
    iVar12 = iVar12 + 6;
    iVar17 = iVar17 + 3;
    iVar14 = iVar14 + 2;
    iVar18 = iVar18 + 1;
  } while( true );
}
