/* FUN_80050364
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80050364  body 0x80050364..0x80050963  size 1536 B
 * body sha256 52b7d8d5d841e0c21acf3d7743e88f5646abca1b2475006fd8efdf5f3f57bedf
 * provider record sha256 c6d80fd2036bc1a6dc912a079bddd34e095265db3c0829e9da0fe40672993b05
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80050364(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  short *psVar11;
  int iVar12;
  ushort *puVar13;
  ushort *puVar14;
  int iVar15;
  int iVar16;
  ushort *puVar17;
  ushort *puVar18;
  short *psVar19;
  uint uVar20;
  int iVar21;
  ushort *puVar22;
  uint *puVar23;
  uint *puVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  undefined1 auStack_50 [32];
  uint local_30;
  
  uVar25 = (DAT_800e8ca8 + 1) * 0x1000 | (int)DAT_800e8caa << 4 | (int)DAT_800e8cac;
  local_30 = (uint)*(byte *)(DAT_800df92c + 2);
  if (uVar25 == 0x5076) {
    uVar8 = 0;
    if (DAT_8010bc28 < 5) {
      uVar8 = DAT_8010bc28 + 1;
    }
    DAT_8010bc28 = uVar8;
  }
  uVar8 = 0;
  iVar27 = 0;
  do {
    while( true ) {
      do {
        iVar26 = iVar27;
        if (local_30 <= uVar8) {
          return;
        }
        puVar24 = (uint *)((int)&DAT_800e18f8 + iVar26);
        iVar27 = iVar26 + 0x368;
        uVar8 = uVar8 + 1;
      } while (((*puVar24 & 1) == 0) || ((*puVar24 & 0x80000) != 0));
      if ((uVar25 == 0x615c) && ((DAT_80115280 != 0 && (uVar8 == 7)))) {
        iVar12 = **(int **)((int)&DAT_800e19b0 + iVar26);
        puVar13 = (ushort *)(iVar12 + 0x10);
        puVar22 = (ushort *)(iVar12 + 0x20);
        puVar17 = (ushort *)(iVar12 + 0x200);
        if (DAT_80115280 == 1) {
          iVar12 = 7;
          do {
            puVar18 = puVar17;
            puVar14 = puVar13;
            iVar12 = iVar12 + -1;
            *puVar18 = *puVar14;
            puVar13 = puVar14 + 1;
            puVar17 = puVar18 + 1;
          } while (iVar12 != -1);
          puVar13 = puVar14 + -7;
          puVar17 = puVar18 + -7;
        }
        uVar20 = DAT_80115280 << 5;
        DAT_80115280 = DAT_80115280 + 1;
        if (0x1000 < uVar20) {
          uVar20 = 0x1000;
        }
        iVar21 = 0x1000 - uVar20;
        iVar12 = 0;
        while (bVar7 = iVar12 < 8, iVar12 = iVar12 + 1, bVar7) {
          uVar1 = *puVar17;
          uVar2 = *puVar22;
          puVar17 = puVar17 + 1;
          puVar22 = puVar22 + 1;
          *puVar13 = (ushort)(((uint)(uVar1 >> 0xb) * iVar21 + (uVar2 >> 0xb) * uVar20 >> 0xc & 0xff
                              ) << 0xb) |
                     (ushort)(((uVar1 >> 6 & 0x1f) * iVar21 + (uVar2 >> 6 & 0x1f) * uVar20 >> 0xc &
                              0xff) << 6) |
                     (ushort)(((uVar1 >> 1 & 0x1f) * iVar21 + (uVar2 >> 1 & 0x1f) * uVar20 >> 0xc &
                              0xff) << 1) | 1;
          puVar13 = puVar13 + 1;
        }
      }
      FUN_80040e58(&DAT_800e195c + iVar26,&DAT_800e190c + iVar26);
      FUN_800424ec(*(undefined4 *)((int)&DAT_800e1968 + iVar26),&DAT_800e190c + iVar26,
                   &DAT_800e193c + iVar26);
      if ((&DAT_800e1900)[iVar26] == '\x02') {
        *(int *)((int)&DAT_800e1954 + iVar26) = *(int *)((int)&DAT_800e1954 + iVar26) + -900;
      }
      FUN_80083200(&DAT_800e1970 + iVar26,&DAT_800e1950 + iVar26);
      FUN_8004226c(&DAT_800e905c,&DAT_800e193c + iVar26,auStack_50);
      if (uVar8 == 2) {
        DAT_8010bc2c = DAT_8010bc2c + 1;
      }
      if ((&DAT_800e1900)[iVar26] == '\x01') break;
      if ((*(int *)((int)&DAT_800e19bc + iVar26) != 0) &&
         ((iVar12 = FUN_80083d2c(&DAT_800e1950 + iVar26,DAT_800df940), iVar12 != 0 ||
          ((*puVar24 & 0x10) != 0)))) {
        puVar23 = (uint *)((int)&DAT_800e1ae0 + iVar26);
        if ((uVar25 == 0x5076) && ((3 < uVar8 && (uVar20 = 3, uVar8 < 7)))) {
          DAT_80124830 = DAT_80124830 | 8;
          if ((DAT_8010bc28 & 1) == 0) {
            uVar20 = DAT_8010bc28 >> 1;
          }
          FUN_800878fc(&DAT_800e1970 + iVar26,puVar23,uVar20);
        }
        if ((*(uint *)((int)&DAT_800e1908 + iVar26) & 0x10) != 0) {
          DAT_80124830 = DAT_80124830 | 4;
        }
        if ((*puVar23 & 8) != 0) {
          FUN_8004a5bc(&DAT_800e1970 + iVar26,puVar23);
          sVar10 = *(short *)((int)&DAT_800e1c18 + iVar26) + 1;
          *(short *)((int)&DAT_800e1c18 + iVar26) = sVar10;
          if (sVar10 == 0x1e) {
            *puVar24 = 0;
          }
        }
        FUN_800411b8(&DAT_800e193c + iVar26,&DAT_800e1bb0 + iVar26);
        FUN_8008548c(puVar23,&DAT_800e1970 + iVar26,0);
        uVar20 = 0xfffffff3;
        goto LAB_800508f8;
      }
LAB_80050900:
      uVar3 = *(undefined2 *)((int)&DAT_800e1924 + iVar26 + 2);
      uVar4 = *(undefined2 *)((int)&DAT_800e1a18 + iVar26 + 2);
      uVar5 = *(undefined2 *)((int)&DAT_800e1a1c + iVar26 + 2);
      uVar6 = *(undefined2 *)((int)&DAT_800e1a20 + iVar26 + 2);
      *(undefined2 *)((int)&DAT_800e192c + iVar26) = *(undefined2 *)((int)&DAT_800e1922 + iVar26);
      *(undefined2 *)((int)&DAT_800e192e + iVar26) = uVar3;
      *(undefined2 *)((int)&DAT_800e1930 + iVar26) = *(undefined2 *)((int)&DAT_800e192a + iVar26);
      *(undefined2 *)((int)&DAT_800e1932 + iVar26) = uVar4;
      *(undefined2 *)((int)&DAT_800e1934 + iVar26) = uVar5;
      *(undefined2 *)((int)&DAT_800e1936 + iVar26) = uVar6;
    }
    DAT_80124830 = DAT_80124830 | 2;
    if (*(int *)((int)&DAT_800e19bc + iVar26) == 0) {
LAB_800507fc:
      uVar20 = 0xfffffffd;
LAB_800508f8:
      DAT_80124830 = DAT_80124830 & uVar20;
      goto LAB_80050900;
    }
    uVar20 = (uint)(*(short **)((int)&DAT_800e1c5c + iVar26))[1];
    iVar12 = (int)**(short **)((int)&DAT_800e1c5c + iVar26);
    if (((uVar20 & 4) == 0) || (uVar8 < 2)) {
      if ((uVar20 & 2) != 0) {
        iVar12 = -iVar12;
      }
      if (*(int *)((int)&DAT_800e1c58 + iVar26) != 0) {
        psVar11 = (short *)(*(int *)((int)&DAT_800e19b8 + iVar26) + (uVar20 & 1) * 2 + 8);
        psVar19 = psVar11 + 0x10;
        for (iVar21 = (int)*(short *)(*(int *)(*(int *)(*(int *)((int)&DAT_800e19bc + iVar26) + 8) +
                                              8) + 0xe); iVar21 != 0; iVar21 = iVar21 + -3) {
          iVar9 = *psVar11 + iVar12;
          iVar15 = psVar19[-8] + iVar12;
          iVar16 = *psVar19 + iVar12;
          sVar10 = (short)iVar9;
          if (((iVar9 < 0x8000) && (iVar15 < 0x8000)) && (iVar16 < 0x8000)) {
            if (((iVar9 < -0x7fff) || (iVar15 < -0x7fff)) || (iVar16 < -0x7fff)) {
              sVar10 = sVar10 + 0x4000;
              iVar15 = iVar15 + 0x4000;
              iVar16 = iVar16 + 0x4000;
              goto LAB_8005072c;
            }
            *psVar11 = sVar10;
          }
          else {
            sVar10 = sVar10 + -0x4000;
            iVar15 = iVar15 + -0x4000;
            iVar16 = iVar16 + -0x4000;
LAB_8005072c:
            *psVar11 = sVar10;
          }
          psVar19[-8] = (short)iVar15;
          *psVar19 = (short)iVar16;
          psVar19 = psVar19 + 0x18;
          psVar11 = psVar11 + 0x18;
        }
      }
      bVar7 = false;
      if (2 < uVar25 - 0x40a0) {
        if ((((uVar25 & 0xfff0) == 0x4080) || (uVar25 == 0x4052)) ||
           ((uVar25 == 0x4000 || (((uVar25 == 0x400a || (uVar25 == 0x4091)) || (uVar25 == 0x40ac))))
           )) {
LAB_800507b8:
          bVar7 = true;
        }
        else {
          iVar12 = FUN_80083d2c(&DAT_800e1950 + iVar26,DAT_800df940);
          if (iVar12 == 0) {
            if ((*puVar24 & 0x10) != 0) goto LAB_800507b8;
          }
          else {
            bVar7 = true;
          }
        }
      }
      if (bVar7) {
        FUN_800411b8(&DAT_800e193c + iVar26,&DAT_800e1bb0 + iVar26);
        *(uint *)((int)&DAT_800e1ae0 + iVar26) = *(uint *)((int)&DAT_800e1ae0 + iVar26) | 8;
        FUN_8008548c((int)&DAT_800e1ae0 + iVar26,&DAT_800e1970 + iVar26,0);
        *(uint *)((int)&DAT_800e1ae0 + iVar26) = *(uint *)((int)&DAT_800e1ae0 + iVar26) & 0xfffffff7
        ;
      }
      goto LAB_800507fc;
    }
    *puVar24 = *puVar24 | 0x80000;
  } while( true );
}
