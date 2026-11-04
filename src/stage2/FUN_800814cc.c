/* FUN_800814cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800814cc  body 0x800814cc..0x800815e3  size 280 B
 * body sha256 d082c18096bc0302c8d0b5eb39884db8eb5786e392428eb4075ed05e5cfcc3f9
 * provider record sha256 573257caf552e55f29894aff44bba12b14bd9441d6d9cf59b3a1021b714ba128
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800814cc(int param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  
  if (*(char *)(param_1 + 6) == '\0') {
    if (*(byte *)(param_1 + 8) < 0x10) {
      bVar1 = (&DAT_8011b630)[(*(byte *)(param_1 + 8) + 0x10) * 2];
      iVar2 = *(byte *)(param_1 + 8) + 0x10;
    }
    else {
      bVar1 = (&DAT_8011b630)[(*(byte *)(param_1 + 8) - 0x40) * 2];
      iVar2 = *(byte *)(param_1 + 8) - 0x40;
    }
    *(ushort *)(param_1 + 0x1e0) = -(ushort)bVar1;
    *(short *)(param_1 + 0x1e2) = (short)(-(uint)(byte)(&DAT_8011b630)[iVar2 * 2] >> 0x10);
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar3 = FUN_80081de8(param_1);
  if (cVar3 != '\0') {
    FUN_80083758(&DAT_800e8d00,*(undefined1 *)(param_1 + 0x267));
    *(undefined1 *)(param_1 + 5) = 6;
    *(undefined1 *)(param_1 + 6) = 0;
    if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
      *(undefined1 *)(param_1 + 5) = 8;
      *(undefined1 *)(param_1 + 6) = 2;
    }
  }
  return;
}
