/* FUN_8017d9a0
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017d9a0  body 0x8017d9a0..0x8017db8f  size 496 B
 * body sha256 5838c220b71363cb15838191116672797d38a09287c3a0991b2e7af5d644a727
 * provider record sha256 04b5a9c74ee3eccfc7f741cf52fd087dffe2dd96229637d27b1e1bbbf0a4d500
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017d9a0(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  short sVar6;
  undefined4 *puVar7;
  short *psVar8;
  int iVar9;
  char *pcVar10;
  short *psVar11;
  short sVar12;
  short sVar13;
  char cVar14;
  char cVar15;
  int iVar16;
  short local_40 [8];
  short local_30 [8];
  
  local_40[0] = 0xed;
  local_40[1] = 0xdf;
  local_40[2] = 0xd1;
  local_40[3] = 0xed;
  local_40[4] = 0xdf;
  local_40[5] = 0xd1;
  local_30[0] = 0x6c;
  local_30[1] = 0x6c;
  local_30[2] = 0x6c;
  local_30[3] = 0x83;
  local_30[4] = 0x83;
  local_30[5] = 0x83;
  func_0x80043620();
  iVar16 = 5;
  do {
    puVar7 = DAT_8017e5d8;
    if ((&DAT_8017e5dc)[iVar16] == 0xff) {
      iVar16 = iVar16 + -2;
    }
    else {
      psVar11 = local_40 + iVar16;
      psVar8 = local_30 + iVar16;
      sVar12 = *psVar11;
      sVar13 = *psVar8;
      iVar9 = (uint)(byte)(&DAT_8017e5dc)[iVar16] * 4;
      pcVar10 = &DAT_8017de38 + iVar9;
      cVar15 = *pcVar10;
      bVar2 = (&DAT_8017de3a)[iVar9];
      cVar14 = (&DAT_8017de39)[iVar9];
      bVar3 = (&DAT_8017de3b)[iVar9];
      *DAT_8017e5d8 = 0x2c58a058;
      *(short *)(puVar7 + 1) = *psVar11;
      *(short *)((int)puVar7 + 6) = *psVar8;
      *(char *)(puVar7 + 2) = *pcVar10;
      uVar4 = (&DAT_8017de39)[iVar9];
      sVar12 = (ushort)bVar2 + sVar12;
      *(undefined2 *)((int)puVar7 + 10) = 0;
      *(short *)(puVar7 + 3) = sVar12;
      *(undefined1 *)((int)puVar7 + 9) = uVar4;
      sVar6 = *psVar8;
      cVar15 = cVar15 + bVar2;
      *(char *)(puVar7 + 4) = cVar15;
      *(short *)((int)puVar7 + 0xe) = sVar6;
      uVar4 = (&DAT_8017de39)[iVar9];
      *(undefined2 *)((int)puVar7 + 0x12) = 0x9e;
      *(undefined1 *)((int)puVar7 + 0x11) = uVar4;
      sVar6 = *psVar11;
      sVar13 = (ushort)bVar3 + sVar13;
      *(short *)((int)puVar7 + 0x16) = sVar13;
      *(short *)(puVar7 + 5) = sVar6;
      cVar5 = *pcVar10;
      cVar14 = cVar14 + bVar3;
      *(char *)((int)puVar7 + 0x19) = cVar14;
      *(short *)(puVar7 + 7) = sVar12;
      *(short *)((int)puVar7 + 0x1e) = sVar13;
      *(char *)(puVar7 + 6) = cVar5;
      *(char *)(puVar7 + 8) = cVar15;
      *(char *)((int)puVar7 + 0x21) = cVar14;
      *(undefined1 *)((int)puVar7 + 3) = 0;
      puVar7[9] = &DAT_8017e55c;
      *(undefined2 *)((int)puVar7 + 0x1a) = 0;
      _DAT_800df8b4 = func_0x80044fdc(_DAT_800df8b4,puVar7,0);
      DAT_8017e5d8 = DAT_8017e5d8 + 10;
    }
    bVar1 = iVar16 != 0;
    iVar16 = iVar16 + -1;
  } while (bVar1);
  return;
}
