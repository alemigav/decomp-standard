/* FUN_800532b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800532b4  body 0x800532b4..0x8005360b  size 856 B
 * body sha256 cb6abd2cc2ab7344a91cf04a32a1fdddeb29edccca5cf45423267d827351b858
 * provider record sha256 140eb14ddd89332d3ebb12e85207645bec8bbffddf5800e1b8c9a35bb0c41b93
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800532b4(void)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  
  iVar2 = DAT_8010d940;
  FUN_80052bbc(0xf000,0xa02);
  bVar1 = false;
  if (DAT_800e10ec < 0) {
    if ((DAT_800df90c & 0x1000) != 0) {
      *(char *)(iVar2 + 3) = *(char *)(iVar2 + 3) + -1;
      bVar1 = true;
      if (*(short *)(iVar2 + 2) == 0x901) {
        *(undefined1 *)(iVar2 + 3) = 0;
      }
      if (*(char *)(iVar2 + 3) < '\0') {
        *(undefined1 *)(iVar2 + 3) = 2;
      }
    }
    if ((DAT_800df90c & 0x4000) != 0) {
      bVar1 = true;
      cVar3 = *(char *)(iVar2 + 3) + '\x01';
      *(char *)(iVar2 + 3) = cVar3;
      if ('\x02' < cVar3) {
        *(undefined1 *)(iVar2 + 3) = 0;
      }
    }
    if ((DAT_800df90c & 0x8000) != 0) {
      bVar4 = *(char *)(iVar2 + 2) - 1;
      *(byte *)(iVar2 + 2) = bVar4;
      bVar1 = true;
      if ((int)((uint)bVar4 << 0x18) < 0) {
        *(undefined1 *)(iVar2 + 2) = 9;
      }
    }
    if ((DAT_800df90c & 0x2000) != 0) {
      bVar1 = true;
      cVar3 = *(char *)(iVar2 + 2) + '\x01';
      *(char *)(iVar2 + 2) = cVar3;
      if ('\t' < cVar3) {
        *(undefined1 *)(iVar2 + 2) = 0;
      }
    }
    if (bVar1) {
      FUN_80077adc(0x2100000,0);
    }
  }
  cVar3 = *(char *)(iVar2 + 0x2da) + *(char *)(iVar2 + 0x2db);
  *(char *)(iVar2 + 0x2da) = cVar3;
  if ((cVar3 == '`') || (cVar3 == '@')) {
    *(char *)(iVar2 + 0x2db) = -*(char *)(iVar2 + 0x2db);
  }
  *(undefined2 *)(iVar2 + 0x314) = 0x18;
  *(short *)(iVar2 + 0x310) = *(char *)(iVar2 + 2) * 0x18 + 0x34;
  *(short *)(iVar2 + 0x312) = *(char *)(iVar2 + 3) * 0x18 + 0x9a;
  *(char *)(iVar2 + 0x318) = *(char *)(iVar2 + 2) * '\x18' + '\x04';
  *(byte *)(iVar2 + 0x319) = (*(char *)(iVar2 + 3) * '\x18' + '*') - *(byte *)(iVar2 + 0x2de);
  *(undefined1 *)(iVar2 + 0x31e) = *(undefined1 *)(iVar2 + 0x2da);
  *(ushort *)(iVar2 + 0x316) = 0x17 - (ushort)*(byte *)(iVar2 + 0x2de);
  if ((*(char *)(iVar2 + 2) == '\t') && ('\0' < *(char *)(iVar2 + 3))) {
    *(undefined2 *)(iVar2 + 0x312) = 0xb2;
    *(byte *)(iVar2 + 0x319) = 'B' - *(byte *)(iVar2 + 0x2de);
    *(ushort *)(iVar2 + 0x316) = 0x2f - (ushort)*(byte *)(iVar2 + 0x2de);
  }
  *(undefined1 *)(iVar2 + 0x2de) = 0;
  if ((DAT_800df918 & 0x1000) == 0) {
    *(undefined1 *)(iVar2 + 0x2d9) = 0;
  }
  else {
    FUN_80077adc(0x2090000,0);
    cVar3 = *(char *)(iVar2 + 2) + *(char *)(iVar2 + 3) * '\n';
    *(char *)(iVar2 + 0x2d9) = cVar3;
    if (cVar3 == '\t') {
      *(undefined1 *)(iVar2 + 0x2d9) = 0x1e;
    }
    if (*(byte *)(iVar2 + 0x2d9) < 9) {
      *(byte *)(iVar2 + 0x2d9) = *(byte *)(iVar2 + 0x2d9) + 1;
    }
    if (*(char *)(iVar2 + 0x2d9) == '\x13') {
      *(undefined1 *)(iVar2 + 0x2d9) = 0x1d;
    }
    if (0x13 < *(byte *)(iVar2 + 0x2d9)) {
      *(byte *)(iVar2 + 0x2d9) = *(byte *)(iVar2 + 0x2d9) - 1;
    }
    *(undefined1 *)(iVar2 + 0x2d5) = 0x10;
  }
  if ((DAT_800df918 & 0x2000) != 0) {
    *(undefined1 *)(iVar2 + 0x2d9) = 1;
  }
  return *(undefined1 *)(iVar2 + 0x2d9);
}
