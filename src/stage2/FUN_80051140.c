/* FUN_80051140
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80051140  body 0x80051140..0x8005280b  size 5836 B
 * body sha256 d192921b58f8d498befce78e8432618946724bf046c41b8dc748aabec7b4addd
 * provider record sha256 4f1a944931b9b335748e6219944af4a3209f5bee415f5f9e24078d855f1f84d8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80051140(void)

{
  undefined4 *puVar1;
  uint uVar2;
  ushort uVar4;
  byte *pbVar3;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 uVar9;
  uint uVar8;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ushort uVar14;
  
  uVar14 = 0;
  FUN_8004d030(DAT_8010b6d0);
  puVar1 = (undefined4 *)FUN_8004d138(DAT_8010b6d0,0);
  if (puVar1 != (undefined4 *)0x0) {
    if (((DAT_8010bfa8 & 1) == 0) && (DAT_800fe284 == 0)) {
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      puVar6 = (undefined1 *)(piVar10[1] + (iVar5 + -1) * 4);
      DAT_800df8c0 = 0;
      if (puVar6 != (undefined1 *)0x0) {
        DAT_800df8c0 = *puVar6;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      iVar5 = piVar10[1] + (iVar5 + -1) * 4;
      if (iVar5 == 0) {
        DAT_800df8c1 = 0;
      }
      else {
        DAT_800df8c1 = *(undefined1 *)(iVar5 + 1);
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x200;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      uVar9 = 0xd8;
      if (uVar11 != 0) {
        if (DAT_800e8b3e < 2) {
          uVar9 = 0xb0;
        }
        DAT_800df8c0 = uVar9;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x100;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      uVar9 = 0x28;
      if (uVar11 != 0) {
        if (DAT_800e8b3e < 2) {
          uVar9 = 0x50;
        }
        DAT_800df8c0 = uVar9;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x800;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        DAT_800df8c1 = 0x28;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x400;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        DAT_800df8c1 = 0xd8;
      }
    }
    else {
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x200;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = 0x8000;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x100;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x2000;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x800;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x1000;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x400;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x4000;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      iVar5 = piVar10[1] + (iVar5 + -1) * 4;
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*(byte *)(iVar5 + 1) << 0x18;
      }
      if (0x28 < iVar5 >> 0x18) {
        uVar14 = uVar14 | 0x1000;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      iVar5 = piVar10[1] + (iVar5 + -1) * 4;
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*(byte *)(iVar5 + 1) << 0x18;
      }
      if (iVar5 >> 0x18 < -0x28) {
        uVar14 = uVar14 | 0x4000;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      pbVar3 = (byte *)(piVar10[1] + (iVar5 + -1) * 4);
      if (pbVar3 == (byte *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*pbVar3 << 0x18;
      }
      if (0x28 < iVar5 >> 0x18) {
        uVar14 = uVar14 | 0x2000;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      pbVar3 = (byte *)(piVar10[1] + (iVar5 + -1) * 4);
      if (pbVar3 == (byte *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*pbVar3 << 0x18;
      }
      if (iVar5 >> 0x18 < -0x28) {
        uVar14 = uVar14 | 0x8000;
      }
      DAT_800fe284 = 0;
    }
    piVar10 = (int *)*puVar1;
    iVar5 = piVar10[3];
    uVar11 = 0;
    if (iVar5 == 0) {
      iVar5 = *piVar10;
    }
    iVar5 = piVar10[1] + (iVar5 + -1) * 4;
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (uint)*(byte *)(iVar5 + 1) << 0x18;
    }
    if (0x28 < iVar5 >> 0x18) {
      uVar11 = 0x1000;
    }
    piVar10 = (int *)*puVar1;
    iVar5 = piVar10[3];
    if (iVar5 == 0) {
      iVar5 = *piVar10;
    }
    iVar5 = piVar10[1] + (iVar5 + -1) * 4;
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (uint)*(byte *)(iVar5 + 1) << 0x18;
    }
    if (iVar5 >> 0x18 < -0x28) {
      uVar11 = uVar11 | 0x4000;
    }
    piVar10 = (int *)*puVar1;
    iVar5 = piVar10[3];
    if (iVar5 == 0) {
      iVar5 = *piVar10;
    }
    pbVar3 = (byte *)(piVar10[1] + (iVar5 + -1) * 4);
    if (pbVar3 == (byte *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (uint)*pbVar3 << 0x18;
    }
    if (0x28 < iVar5 >> 0x18) {
      uVar11 = uVar11 | 0x2000;
    }
    piVar10 = (int *)*puVar1;
    iVar5 = piVar10[3];
    if (iVar5 == 0) {
      iVar5 = *piVar10;
    }
    pbVar3 = (byte *)(piVar10[1] + (iVar5 + -1) * 4);
    if (pbVar3 == (byte *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (uint)*pbVar3 << 0x18;
    }
    if (iVar5 >> 0x18 < -0x28) {
      uVar11 = uVar11 | 0x8000;
    }
    uVar12 = 0;
    piVar10 = (int *)*puVar1;
    uVar2 = piVar10[3];
    uVar13 = piVar10[2];
    DAT_8010c274 = (DAT_8010c278 ^ uVar11) & uVar11;
    while( true ) {
      uVar7 = 0;
      if ((uVar2 != uVar13) && (uVar7 = uVar2 - uVar13, uVar2 <= uVar13)) {
        uVar7 = *piVar10 - (uVar13 - uVar2);
      }
      iVar5 = 0;
      if (uVar12 <= uVar7) {
        uVar8 = piVar10[3];
        uVar7 = uVar12 + 1;
        if (uVar8 < uVar7) {
          iVar5 = *piVar10 - (uVar7 - uVar8);
        }
        else {
          iVar5 = uVar8 - uVar7;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 0x20;
      }
      if (uVar4 == 0) break;
      uVar12 = uVar12 + 1;
    }
    DAT_8010c278 = uVar11;
    if (uVar12 != 0) {
      FUN_8006b380();
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 0x1000;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 0x20;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 0x8000;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 0x40;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 0x4000;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 0x90;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 8;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 0x100;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 4;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 4;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 2;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 2;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 0x10;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 8;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 0x20;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 1;
    }
    piVar10 = (int *)*puVar1;
    uVar13 = piVar10[3];
    uVar12 = piVar10[2];
    uVar11 = 0;
    while( true ) {
      uVar2 = 0;
      if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
        uVar2 = *piVar10 - (uVar12 - uVar13);
      }
      iVar5 = 0;
      if (uVar11 <= uVar2) {
        uVar7 = piVar10[3];
        uVar2 = uVar11 + 1;
        if (uVar7 < uVar2) {
          iVar5 = *piVar10 - (uVar2 - uVar7);
        }
        else {
          iVar5 = uVar7 - uVar2;
        }
        iVar5 = piVar10[1] + iVar5 * 4;
      }
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(ushort *)(iVar5 + 2) & 0x2000;
      }
      if (uVar4 == 0) break;
      uVar11 = uVar11 + 1;
    }
    if (uVar11 != 0) {
      uVar14 = uVar14 | 0x40;
    }
    DAT_800df8bc._3_1_ = ~(byte)uVar14;
    DAT_800df8bc._2_1_ = ~(byte)(uVar14 >> 8);
    puVar1 = (undefined4 *)FUN_8004d138(DAT_8010b6d0,1);
    if (puVar1 != (undefined4 *)0x0) {
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      uVar14 = 0;
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      iVar5 = piVar10[1] + (iVar5 + -1) * 4;
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*(byte *)(iVar5 + 1) << 0x18;
      }
      if (0x3c < iVar5 >> 0x18) {
        uVar14 = 0x1000;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      iVar5 = piVar10[1] + (iVar5 + -1) * 4;
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*(byte *)(iVar5 + 1) << 0x18;
      }
      if (iVar5 >> 0x18 < -0x3c) {
        uVar14 = uVar14 | 0x4000;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      pbVar3 = (byte *)(piVar10[1] + (iVar5 + -1) * 4);
      if (pbVar3 == (byte *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*pbVar3 << 0x18;
      }
      if (0x3c < iVar5 >> 0x18) {
        uVar14 = uVar14 | 0x2000;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      pbVar3 = (byte *)(piVar10[1] + (iVar5 + -1) * 4);
      if (pbVar3 == (byte *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (uint)*pbVar3 << 0x18;
      }
      if (iVar5 >> 0x18 < -0x3c) {
        uVar14 = uVar14 | 0x8000;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 2;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x80;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 1;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x20;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 8;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x10;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 4;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x40;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x1000;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x800;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x4000;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 0x100;
      }
      piVar10 = (int *)*puVar1;
      uVar13 = piVar10[3];
      uVar12 = piVar10[2];
      uVar11 = 0;
      while( true ) {
        uVar2 = 0;
        if ((uVar13 != uVar12) && (uVar2 = uVar13 - uVar12, uVar13 <= uVar12)) {
          uVar2 = *piVar10 - (uVar12 - uVar13);
        }
        iVar5 = 0;
        if (uVar11 <= uVar2) {
          uVar7 = piVar10[3];
          uVar2 = uVar11 + 1;
          if (uVar7 < uVar2) {
            iVar5 = *piVar10 - (uVar2 - uVar7);
          }
          else {
            iVar5 = uVar7 - uVar2;
          }
          iVar5 = piVar10[1] + iVar5 * 4;
        }
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(ushort *)(iVar5 + 2) & 0x10;
        }
        if (uVar4 == 0) break;
        uVar11 = uVar11 + 1;
      }
      if (uVar11 != 0) {
        uVar14 = uVar14 | 8;
      }
      DAT_800df8e0._3_1_ = ~(byte)uVar14;
      DAT_800df8e0._2_1_ = ~(byte)(uVar14 >> 8);
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      puVar6 = (undefined1 *)(piVar10[1] + (iVar5 + -1) * 4);
      DAT_800df8e4 = 0;
      if (puVar6 != (undefined1 *)0x0) {
        DAT_800df8e4 = *puVar6;
      }
      piVar10 = (int *)*puVar1;
      iVar5 = piVar10[3];
      if (iVar5 == 0) {
        iVar5 = *piVar10;
      }
      iVar5 = piVar10[1] + (iVar5 + -1) * 4;
      DAT_800df8e5 = 0;
      if (iVar5 != 0) {
        DAT_800df8e5 = *(undefined1 *)(iVar5 + 1);
      }
    }
  }
  return;
}
