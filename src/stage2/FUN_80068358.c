/* FUN_80068358
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80068358  body 0x80068358..0x80068e4b  size 2804 B
 * body sha256 fabf9f54fd9da0fce36914ea0d13db3fa93257312ade9fa68dabcabe927ccd6e
 * provider record sha256 73a7ec51dd034966393d997b620dc5ab16df120b1a9435baa792f9409b107401
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80068358(int param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  uVar1 = *param_3;
  uVar2 = param_3[1];
  iVar6 = *(int *)(param_1 + 0x128);
  iVar8 = *(int *)(param_1 + 0x120);
  iVar10 = (uint)param_3[2] + (uint)uVar1;
  iVar4 = (uint)param_3[3] + (uint)uVar2;
  iVar9 = (int)(((uint)uVar2 + (uint)(param_3[3] >> 1)) * 0x10000) >> 0x10;
  iVar7 = (int)(((uint)uVar1 + (uint)(param_3[2] >> 1)) * 0x10000) >> 0x10;
  uVar3 = (uint)(iVar6 - iVar9) >> 0x1e & 2 | (uint)(iVar8 - iVar7) >> 0x1f;
  if (uVar3 == 1) {
    iVar11 = iVar4 * 0x10000 >> 0x10;
    iVar5 = (iVar11 + param_2) - iVar9;
    iVar4 = iVar5 * ((iVar8 + *(short *)(param_1 + 0x13c)) - ((short)uVar1 - param_2));
    iVar10 = iVar7 - ((short)uVar1 - param_2);
    iVar12 = iVar4 / iVar10;
    if (iVar10 == 0) {
      trap(0x1c00);
    }
    if ((iVar10 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = (iVar6 + *(short *)(param_1 + 0x13e)) - iVar9;
    iVar4 = iVar6 - iVar12;
    if (iVar12 <= iVar6) {
      return 0;
    }
    iVar6 = (iVar10 * iVar4) / iVar5;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar10 * iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    iVar10 = iVar6 * iVar4 * iVar4;
    iVar5 = iVar6 * iVar6 + iVar4 * iVar4;
    iVar12 = iVar10 / iVar5;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar10 == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = iVar6 * iVar6 * iVar4;
    iVar6 = iVar4 / iVar5;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = iVar12;
    if (iVar12 < 0) {
      iVar4 = -iVar12;
    }
    if (400 < iVar4) goto LAB_80068e1c;
    iVar4 = iVar6;
    if (iVar6 < 0) {
      iVar4 = -iVar6;
    }
    if (400 < iVar4) goto LAB_80068e1c;
    *(int *)(param_1 + 0x120) = iVar8 + iVar12;
    iVar6 = *(int *)(param_1 + 0x128) - iVar6;
    *(int *)(param_1 + 0x128) = iVar6;
    iVar8 = (iVar9 / 0x12) * 0x10000 >> 0x10;
    iVar4 = ((int)(short)*param_3 / 0x12) * 0x10000 >> 0x10;
    iVar4 = ((*(int *)(param_1 + 0x120) + (int)*(short *)(param_1 + 0x13c)) / 0x12 - iVar4) *
            (((iVar11 / 0x12) * 0x10000 >> 0x10) - iVar8) -
            ((iVar6 + *(short *)(param_1 + 0x13e)) / 0x12 - iVar8) *
            (((iVar7 / 0x12) * 0x10000 >> 0x10) - iVar4);
  }
  else {
    if (1 < uVar3) {
      if (uVar3 == 2) {
        iVar11 = iVar9 - ((short)uVar2 - param_2);
        iVar4 = iVar11 * ((iVar8 + *(short *)(param_1 + 0x13c)) - iVar7);
        iVar10 = iVar10 * 0x10000 >> 0x10;
        iVar5 = (iVar10 + param_2) - iVar7;
        iVar12 = iVar4 / iVar5;
        if (iVar5 == 0) {
          trap(0x1c00);
        }
        if ((iVar5 == -1) && (iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        iVar6 = (iVar6 + *(short *)(param_1 + 0x13e)) - ((short)uVar2 - param_2);
        iVar4 = iVar6 - iVar12;
        if (iVar6 <= iVar12) {
          return 0;
        }
        iVar6 = (iVar5 * iVar4) / iVar11;
        if (iVar11 == 0) {
          trap(0x1c00);
        }
        if ((iVar11 == -1) && (iVar5 * iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        iVar5 = iVar6 * iVar4 * iVar4;
        iVar11 = iVar6 * iVar6 + iVar4 * iVar4;
        iVar12 = iVar5 / iVar11;
        if (iVar11 == 0) {
          trap(0x1c00);
        }
        if ((iVar11 == -1) && (iVar5 == -0x80000000)) {
          trap(0x1800);
        }
        iVar4 = iVar6 * iVar6 * iVar4;
        iVar6 = iVar4 / iVar11;
        if (iVar11 == 0) {
          trap(0x1c00);
        }
        if ((iVar11 == -1) && (iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        iVar4 = iVar12;
        if (iVar12 < 0) {
          iVar4 = -iVar12;
        }
        if (400 < iVar4) goto LAB_80068e1c;
        iVar4 = iVar6;
        if (iVar6 < 0) {
          iVar4 = -iVar6;
        }
        if (400 < iVar4) goto LAB_80068e1c;
        *(int *)(param_1 + 0x120) = iVar8 + iVar12;
        iVar6 = *(int *)(param_1 + 0x128) - iVar6;
        *(int *)(param_1 + 0x128) = iVar6;
        iVar11 = (int)(short)param_3[1];
        iVar12 = *(int *)(param_1 + 0x120) + (int)*(short *)(param_1 + 0x13c);
        iVar4 = (int)((ulonglong)((longlong)iVar12 * 0x38e38e39) >> 0x20);
        iVar8 = iVar9;
        iVar5 = iVar7;
      }
      else {
        if (uVar3 != 3) goto LAB_80068e1c;
        iVar4 = (((short)uVar2 - param_2) - iVar9) *
                ((iVar8 + *(short *)(param_1 + 0x13c)) - ((short)uVar1 - param_2));
        iVar10 = iVar7 - ((short)uVar1 - param_2);
        iVar5 = iVar4 / iVar10;
        if (iVar10 == 0) {
          trap(0x1c00);
        }
        if ((iVar10 == -1) && (iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        iVar6 = (iVar6 + *(short *)(param_1 + 0x13e)) - iVar9;
        iVar4 = iVar6 - iVar5;
        if (iVar6 <= iVar5) {
          return 0;
        }
        iVar6 = iVar9 - ((short)uVar2 - param_2);
        iVar5 = (iVar10 * iVar4) / iVar6;
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar10 * iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        iVar6 = iVar5 * iVar4 * iVar4;
        iVar10 = iVar5 * iVar5 + iVar4 * iVar4;
        iVar11 = iVar6 / iVar10;
        if (iVar10 == 0) {
          trap(0x1c00);
        }
        if ((iVar10 == -1) && (iVar6 == -0x80000000)) {
          trap(0x1800);
        }
        iVar4 = iVar5 * iVar5 * iVar4;
        iVar6 = iVar4 / iVar10;
        if (iVar10 == 0) {
          trap(0x1c00);
        }
        if ((iVar10 == -1) && (iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        iVar4 = iVar11;
        if (iVar11 < 0) {
          iVar4 = -iVar11;
        }
        if (400 < iVar4) goto LAB_80068e1c;
        iVar4 = iVar6;
        if (iVar6 < 0) {
          iVar4 = -iVar6;
        }
        if (400 < iVar4) goto LAB_80068e1c;
        *(int *)(param_1 + 0x120) = iVar8 - iVar11;
        iVar6 = *(int *)(param_1 + 0x128) - iVar6;
        *(int *)(param_1 + 0x128) = iVar6;
        iVar12 = *(int *)(param_1 + 0x120) + (int)*(short *)(param_1 + 0x13c);
        iVar4 = (int)((ulonglong)((longlong)iVar12 * 0x38e38e39) >> 0x20);
        iVar8 = (int)(short)param_3[1];
        iVar5 = (int)(short)*param_3;
        iVar11 = iVar9;
        iVar10 = iVar7;
      }
      iVar9 = (iVar11 / 0x12) * 0x10000 >> 0x10;
      iVar7 = (iVar5 / 0x12) * 0x10000 >> 0x10;
      if (-1 < (((iVar4 >> 2) - (iVar12 >> 0x1f)) - iVar7) *
               (((iVar8 / 0x12) * 0x10000 >> 0x10) - iVar9) -
               ((iVar6 + *(short *)(param_1 + 0x13e)) / 0x12 - iVar9) *
               (((iVar10 / 0x12) * 0x10000 >> 0x10) - iVar7)) {
        return 1;
      }
      goto LAB_80068e1c;
    }
    if (uVar3 != 0) goto LAB_80068e1c;
    iVar12 = iVar4 * 0x10000 >> 0x10;
    iVar5 = iVar12 + param_2;
    iVar4 = (iVar9 - iVar5) * ((iVar8 + *(short *)(param_1 + 0x13c)) - iVar7);
    iVar11 = iVar10 * 0x10000 >> 0x10;
    iVar10 = (iVar11 + param_2) - iVar7;
    iVar13 = iVar4 / iVar10;
    if (iVar10 == 0) {
      trap(0x1c00);
    }
    if ((iVar10 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = (iVar6 + *(short *)(param_1 + 0x13e)) - iVar5;
    iVar4 = iVar6 - iVar13;
    if (iVar13 <= iVar6) {
      return 0;
    }
    iVar5 = iVar5 - iVar9;
    iVar6 = (iVar10 * iVar4) / iVar5;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar10 * iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    iVar10 = iVar6 * iVar4 * iVar4;
    iVar5 = iVar6 * iVar6 + iVar4 * iVar4;
    iVar13 = iVar10 / iVar5;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar10 == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = iVar6 * iVar6 * iVar4;
    iVar6 = iVar4 / iVar5;
    if (iVar5 == 0) {
      trap(0x1c00);
    }
    if ((iVar5 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = iVar13;
    if (iVar13 < 0) {
      iVar4 = -iVar13;
    }
    if (400 < iVar4) goto LAB_80068e1c;
    iVar4 = iVar6;
    if (iVar6 < 0) {
      iVar4 = -iVar6;
    }
    if (400 < iVar4) goto LAB_80068e1c;
    *(int *)(param_1 + 0x120) = iVar8 - iVar13;
    iVar4 = (iVar7 / 0x12) * 0x10000 >> 0x10;
    iVar7 = (iVar12 / 0x12) * 0x10000 >> 0x10;
    iVar6 = *(int *)(param_1 + 0x128) - iVar6;
    *(int *)(param_1 + 0x128) = iVar6;
    iVar4 = ((*(int *)(param_1 + 0x120) + (int)*(short *)(param_1 + 0x13c)) / 0x12 - iVar4) *
            (((iVar9 / 0x12) * 0x10000 >> 0x10) - iVar7) -
            ((iVar6 + *(short *)(param_1 + 0x13e)) / 0x12 - iVar7) *
            (((iVar11 / 0x12) * 0x10000 >> 0x10) - iVar4);
  }
  if (iVar4 < 1) {
    return 1;
  }
LAB_80068e1c:
  *(int *)(param_1 + 0x120) = (int)*(short *)(param_1 + 0x1b4);
  *(int *)(param_1 + 0x128) = (int)*(short *)(param_1 + 0x1b6);
  return 1;
}
