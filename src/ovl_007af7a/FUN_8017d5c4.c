/* FUN_8017d5c4
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017d5c4  body 0x8017d5c4..0x8017d99f  size 988 B
 * body sha256 713d4d1170c13020f40934c49e0d4be87e545ceeb9b4a59a7b3f9aef4b9517c1
 * provider record sha256 67283eeba0fad6b89e8b9d3b8cf467ac36e8d2c27522666714361324c9dab075
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017d5c4(void)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  short sVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int in_t2;
  short sVar10;
  short sVar11;
  char cVar12;
  char cVar13;
  char *pcVar14;
  byte *pbVar15;
  short sVar16;
  short *psVar17;
  byte *local_38;
  
  if ((DAT_8017e5ca & 0x20) == 0) {
    iVar9 = -0x20202;
  }
  else {
    iVar9 = 0x20202;
  }
  DAT_8017e5d0 = DAT_8017e5d0 + iVar9;
  local_38 = &DAT_8017e210;
  DAT_8017e5ca = DAT_8017e5ca + 1;
  func_0x80043620();
  psVar17 = (short *)&UNK_8017e216;
  do {
    local_38 = local_38 + -8;
    if ((*local_38 & 1) != 0) {
      uVar8 = (uint)*(byte *)((int)psVar17 + -0xd);
      uVar6 = (uint)DAT_8017e5cc;
      iVar9 = 0;
      if (uVar8 == uVar6) {
        (&DAT_8017df58)
        [((uint)(byte)(&DAT_8017de20)[uVar6 * 2] + (uint)(byte)(&DAT_8017e5c4)[uVar6]) * 8] =
             (&DAT_8017df58)
             [((uint)(byte)(&DAT_8017de20)[uVar6 * 2] + (uint)(byte)(&DAT_8017e5c4)[uVar6]) * 8] |
             0x22;
        bVar1 = *local_38;
        in_t2 = 0x2c808080;
        if ((bVar1 & 4) != 0) {
          in_t2 = 0x2ea07070;
        }
        if ((bVar1 & 0x20) != 0) {
          in_t2 = DAT_8017e5d0;
        }
        if ((bVar1 & 0x40) != 0) {
          in_t2 = 0x2eff5858;
        }
        iVar9 = (uint)((DAT_8017e5bf & 2) == 0) << 0xf;
      }
      else {
        if (4 < uVar8) {
          in_t2 = 0x2c606060;
          iVar9 = 0x200;
          if (DAT_800dfbe8 != '\0') {
            if ((uVar8 == 6) &&
               (sVar16 = psVar17[-5], psVar17[-5] = sVar16 + 1, 0x168 < (short)(sVar16 + 1))) {
              psVar17[-5] = -0x77;
            }
            if ((*(char *)((int)psVar17 + -0xd) == '\a') &&
               (sVar16 = psVar17[-5], psVar17[-5] = sVar16 + -1, (short)(sVar16 + -1) < -0x78)) {
              psVar17[-5] = 0x167;
            }
          }
        }
        if ((DAT_8017e5bf & 1) != 0) {
          iVar9 = 0;
        }
      }
      if (iVar9 != 0) {
        pbVar15 = &DAT_8017e210;
        uVar6 = 0;
        if (*(byte *)((int)psVar17 + -0xb) != 0) {
          do {
            if (*pbVar15 == 0xff) {
              uVar6 = uVar6 + 1;
            }
            pbVar15 = pbVar15 + 1;
          } while (*(byte *)((int)psVar17 + -0xb) != uVar6);
        }
        sVar16 = psVar17[-5];
        sVar4 = psVar17[-4];
        if (*pbVar15 != 0xff) {
          uVar6 = (uint)(local_38 < &UNK_8017e150);
          do {
            puVar5 = DAT_8017e5d8;
            iVar9 = (uint)*pbVar15 * 4;
            pcVar14 = &DAT_8017de38 + iVar9;
            cVar13 = *pcVar14 + (&DAT_8017de3a)[iVar9];
            cVar12 = (&DAT_8017de39)[iVar9] + (&DAT_8017de3b)[iVar9];
            sVar11 = (ushort)(byte)(&DAT_8017de3a)[iVar9] + sVar16;
            sVar10 = (ushort)(byte)(&DAT_8017de3b)[iVar9] + sVar4;
            uVar7 = func_0x800844e4(in_t2);
            *puVar5 = uVar7;
            *(short *)(puVar5 + 1) = sVar16;
            *(short *)((int)puVar5 + 6) = sVar4;
            *(char *)(puVar5 + 2) = *pcVar14;
            uVar2 = (&DAT_8017de39)[iVar9];
            *(undefined2 *)((int)puVar5 + 10) = 0;
            *(short *)(puVar5 + 3) = sVar11;
            *(short *)((int)puVar5 + 0xe) = sVar4;
            *(char *)(puVar5 + 4) = cVar13;
            *(undefined1 *)((int)puVar5 + 9) = uVar2;
            uVar2 = (&DAT_8017de39)[iVar9];
            *(undefined2 *)((int)puVar5 + 0x12) = 0x9e;
            *(short *)(puVar5 + 5) = sVar16;
            *(short *)((int)puVar5 + 0x16) = sVar10;
            *(undefined1 *)((int)puVar5 + 0x11) = uVar2;
            cVar3 = *pcVar14;
            *(char *)((int)puVar5 + 0x19) = cVar12;
            *(short *)(puVar5 + 7) = sVar11;
            *(short *)((int)puVar5 + 0x1e) = sVar10;
            *(char *)(puVar5 + 8) = cVar13;
            *(char *)((int)puVar5 + 0x21) = cVar12;
            *(undefined1 *)((int)puVar5 + 3) = 0;
            *(undefined2 *)((int)puVar5 + 0x1a) = 0;
            *(char *)(puVar5 + 6) = cVar3;
            puVar5[9] = &DAT_8017e55c;
            pbVar15 = pbVar15 + 1;
            _DAT_800df8b0 = func_0x80044fdc(_DAT_800df8b0,puVar5,0,sVar4,uVar6);
            DAT_8017e5d8 = DAT_8017e5d8 + 10;
            sVar16 = sVar16 + (ushort)(byte)(&DAT_8017de3a)[iVar9];
          } while (*pbVar15 != 0xff);
        }
      }
    }
    psVar17 = psVar17 + -4;
  } while (local_38 != &DAT_8017df58);
  return;
}
