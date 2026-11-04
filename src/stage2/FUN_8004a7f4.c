/* FUN_8004a7f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a7f4  body 0x8004a7f4..0x8004ac03  size 1040 B
 * body sha256 1462f788961de536fbe070e785ed81a063bb092760f8fc01ef8de4c127b4b769
 * provider record sha256 82acdae942ec45bff210c677455f38f77da8452d24181f73a91ccc587d5a6b90
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
byte * FUN_8004a7f4(short param_1,short param_2,short param_3,undefined4 *param_4)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  puVar2 = DAT_8010b290;
  pbVar10 = (byte *)*param_4;
  if ((*pbVar10 == 0) || (&UNK_8010b24f < DAT_8010b290)) {
    pbVar10 = (byte *)0x0;
  }
  else {
    uVar3 = FUN_800844cc((int)param_1);
    *puVar2 = uVar3;
    uVar3 = FUN_800844cc((int)param_2);
    puVar2[1] = uVar3;
    uVar3 = FUN_800844cc((int)param_3);
    puVar2[2] = uVar3;
    pbVar9 = (byte *)(puVar2 + 3);
    puVar12 = param_4 + 1;
    iVar8 = 0;
    do {
      if (*pbVar10 == 0x25) {
        iVar14 = iVar8 + 1;
        puVar13 = puVar12 + 1;
        pbVar11 = pbVar10 + 1;
        pbVar4 = (byte *)*puVar12;
        iVar6 = 0;
        bVar1 = pbVar10[1];
        while (bVar1 - 0x30 < 10) {
          bVar1 = *pbVar11;
          pbVar11 = pbVar11 + 1;
          iVar6 = iVar6 * 10 + -0x30 + (uint)bVar1;
          bVar1 = *pbVar11;
        }
        bVar1 = *pbVar11;
        pbVar10 = pbVar11 + 1;
        if (bVar1 == 100) {
          iVar8 = 1;
          if ((int)pbVar4 < 0) {
            iVar8 = -1;
            *pbVar9 = 0x2d;
            pbVar9 = pbVar9 + 1;
          }
          iVar16 = (int)pbVar4 * iVar8;
          iVar7 = 1;
          iVar5 = 1;
          iVar15 = iVar16;
          while (9 < iVar15) {
            iVar5 = iVar5 * 10;
            iVar15 = iVar16 / iVar5;
            if (iVar5 == 0) {
              trap(0x1c00);
            }
            if ((iVar5 == -1) && (iVar16 == -0x80000000)) {
              trap(0x1800);
            }
            iVar7 = iVar7 + 1;
          }
          if (iVar6 == 0) {
            do {
              iVar6 = (int)pbVar4 / iVar5;
              pbVar11 = (byte *)((int)pbVar4 % iVar5);
              if (iVar5 == 0) {
                trap(0x1c00);
              }
              if ((iVar5 == -1) && (pbVar4 == (byte *)0x80000000)) {
                trap(0x1800);
              }
              iVar5 = iVar5 / 10;
              iVar7 = iVar7 + -1;
              *pbVar9 = "0123456789ABCDEF"[(iVar6 % 10) * iVar8];
              pbVar9 = pbVar9 + 1;
              pbVar4 = pbVar11;
            } while (iVar7 != 0);
          }
          else {
            iVar7 = iVar6 - iVar7;
            if (iVar8 == -1) {
              while( true ) {
                iVar7 = iVar7 + -1;
                iVar6 = iVar6 + -1;
                if (iVar7 < 1) break;
                *pbVar9 = 0x2d;
                pbVar9[-1] = 0x20;
                pbVar9 = pbVar9 + 1;
              }
            }
            else {
              for (; 0 < iVar7; iVar7 = iVar7 + -1) {
                *pbVar9 = 0x20;
                pbVar9 = pbVar9 + 1;
                iVar6 = iVar6 + -1;
              }
            }
            for (; iVar6 != 0; iVar6 = iVar6 + -1) {
              iVar16 = (int)pbVar4 / iVar5;
              pbVar11 = (byte *)((int)pbVar4 % iVar5);
              if (iVar5 == 0) {
                trap(0x1c00);
              }
              if ((iVar5 == -1) && (pbVar4 == (byte *)0x80000000)) {
                trap(0x1800);
              }
              iVar5 = iVar5 / 10;
              *pbVar9 = "0123456789ABCDEF"[(iVar16 % 10) * iVar8];
              pbVar9 = pbVar9 + 1;
              pbVar4 = pbVar11;
            }
          }
        }
        else {
          if (bVar1 < 0x65) {
            if (bVar1 != 99) goto LAB_8004ab70;
            *pbVar9 = (byte)pbVar4;
            puVar12 = puVar13;
            iVar8 = iVar14;
            goto LAB_8004ab9c;
          }
          if (bVar1 != 0x73) {
LAB_8004ab70:
            puVar12 = param_4 + 1;
            pbVar10 = (byte *)0x0;
            if (0 < iVar8) {
              do {
                pbVar10 = pbVar10 + 1;
                puVar12 = puVar12 + 1;
              } while ((int)pbVar10 < iVar8);
            }
            goto LAB_8004ab90;
          }
          bVar1 = *pbVar4;
          while (bVar1 != 0) {
            pbVar4 = pbVar4 + 1;
            *pbVar9 = bVar1;
            pbVar9 = pbVar9 + 1;
            bVar1 = *pbVar4;
          }
        }
      }
      else {
LAB_8004ab90:
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        *pbVar9 = bVar1;
LAB_8004ab9c:
        pbVar9 = pbVar9 + 1;
        puVar13 = puVar12;
        iVar14 = iVar8;
      }
      puVar12 = puVar13;
      iVar8 = iVar14;
    } while (*pbVar10 != 0);
    *pbVar9 = 0;
    pbVar10 = pbVar9 + (-6 - (int)DAT_8010b290);
    DAT_8010b290 = (undefined2 *)((uint)(pbVar9 + 2) & 0xfffffffe);
  }
  return pbVar10;
}
