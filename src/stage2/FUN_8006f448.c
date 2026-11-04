/* FUN_8006f448
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f448  body 0x8006f448..0x8006f73f  size 760 B
 * body sha256 77037036eab4f89533685c4fd3567745b9d42ee389bab940328cdfe8840bc4d9
 * provider record sha256 aeaad1ddb38133b95fe210bd2900ee09b69c2dadee41773485054113c3fe5c75
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006f448(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  
  iVar17 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar17 + 6);
  uVar14 = (uint)*(byte *)(iVar17 + 1);
  uVar9 = *(undefined2 *)(iVar17 + 8);
  iVar10 = uVar14 * 0x368;
  puVar16 = &DAT_800e18f8 + uVar14 * 0xda;
  uVar11 = *puVar16;
  (&DAT_800e1900)[iVar10] = *(undefined1 *)(iVar17 + 2);
  (&DAT_800e1a9a)[iVar10] = uVar1;
  *(undefined2 *)(&DAT_800e1aa2 + iVar10) = uVar9;
  bVar2 = *(byte *)(iVar17 + 7);
  uVar15 = (uint)bVar2;
  if (uVar11 == 0) {
    *puVar16 = (int)(short)(*(ushort *)(iVar17 + 10) | 1);
  }
  else {
    *puVar16 = 0;
  }
  if (DAT_800e85f8 < &DAT_800e1c60 + uVar14 * 0xda) {
    DAT_800e85f8 = &DAT_800e1c60 + uVar14 * 0xda;
  }
  sVar4 = *(short *)(iVar17 + 0xc);
  sVar5 = *(short *)(iVar17 + 0xe);
  sVar6 = *(short *)(iVar17 + 0x10);
  *(int *)(&DAT_800e1928 + iVar10) = (int)*(short *)(iVar17 + 0x12);
  (&DAT_800e1908)[uVar14 * 0xda] = (int)sVar4;
  *(int *)(&DAT_800e1920 + iVar10) = (int)sVar5;
  (&DAT_800e1924)[uVar14 * 0xda] = (int)sVar6;
  if (((int)sVar4 & 0x20U) != 0) {
    *puVar16 = *puVar16 & 0xfffffffe;
  }
  uVar9 = *(undefined2 *)(iVar17 + 0x16);
  uVar7 = *(undefined2 *)(iVar17 + 0x18);
  *(undefined2 *)(&DAT_800e195c + iVar10) = *(undefined2 *)(iVar17 + 0x14);
  *(undefined2 *)(&DAT_800e195e + iVar10) = uVar9;
  *(undefined2 *)(&DAT_800e1960 + iVar10) = uVar7;
  uVar9 = *(undefined2 *)(iVar17 + 0x1c);
  uVar7 = *(undefined2 *)(iVar17 + 0x1e);
  *(undefined2 *)(&DAT_800e1a28 + iVar10) = *(undefined2 *)(iVar17 + 0x1a);
  *(undefined2 *)(&DAT_800e1a2c + iVar10) = uVar9;
  *(undefined2 *)(&DAT_800e1a2a + iVar10) = uVar7;
  uVar9 = *(undefined2 *)(iVar17 + 0x20);
  uVar7 = *(undefined2 *)(iVar17 + 0x22);
  uVar8 = *(undefined2 *)(iVar17 + 0x24);
  uVar11 = uVar15 & 0xc0;
  (&DAT_800e1ae0)[uVar14 * 0xda] = 1;
  *(undefined2 *)(&DAT_800e1a2e + iVar10) = uVar9;
  (&DAT_800e1a32)[uVar14 * 0x1b4] = uVar7;
  *(undefined2 *)(&DAT_800e1a30 + iVar10) = uVar8;
  if (uVar11 == 0x40) {
    puVar12 = (undefined4 *)&DAT_800e1144;
  }
  else if (uVar11 < 0x41) {
    if ((bVar2 & 0xc0) != 0) goto LAB_8006f650;
    puVar12 = &DAT_800e9028;
  }
  else if (uVar11 == 0x80) {
    puVar12 = (undefined4 *)((&DAT_800e13e8)[uVar15 & 0x3f] + 0x14);
  }
  else {
    if (uVar11 != 0xc0) goto LAB_8006f650;
    puVar12 = (undefined4 *)(&DAT_800e193c + (uVar15 & 0x3f) * 0x368);
  }
  (&DAT_800e1968)[uVar14 * 0xda] = puVar12;
LAB_8006f650:
  iVar13 = uVar14 * 0xb0 + *(int *)(DAT_800df92c + 0x30);
  if (*(int *)(iVar13 + 0x54) == 0) {
    *puVar16 = 0;
  }
  else {
    FUN_8004f9f0(uVar14,iVar13 + 8);
  }
  FUN_80040e58(&DAT_800e195c + iVar10,&DAT_800e190c + iVar10);
  FUN_800424ec((&DAT_800e1968)[uVar14 * 0xda],&DAT_800e190c + iVar10,&DAT_800e193c + iVar10);
  uVar1 = *(undefined1 *)(iVar17 + 4);
  uVar3 = *(undefined1 *)(iVar17 + 5);
  if ((*(byte *)(iVar17 + 3) & 0xc0) == 0) {
    (&DAT_800e1c58)[uVar14 * 0xda] = 0;
  }
  else {
    uVar11 = (uint)DAT_8010bf7e;
    iVar10 = uVar11 * 0x1c;
    (&DAT_8010bc34)[iVar10] = *(byte *)(iVar17 + 3);
    (&DAT_8010bc36)[iVar10] = uVar1;
    (&DAT_8010bc37)[iVar10] = uVar3;
    (&DAT_8010bc35)[iVar10] = 0;
    (&DAT_8010bc4c)[uVar11 * 7] = puVar16;
    (&DAT_800e1c58)[uVar14 * 0xda] = &DAT_8010bc34 + iVar10;
    DAT_8010bf7e = DAT_8010bf7e + 1;
  }
  FUN_80050eb8(puVar16);
  *(int *)(param_1 + 0x1c) = iVar17 + 0x26;
  return 1;
}
