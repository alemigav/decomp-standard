/* FUN_800813f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800813f0  body 0x800813f0..0x800814cb  size 220 B
 * body sha256 b5fc90e142c2dc4ae9ce9f2ff5d3a9d6dc02469ebc2742efb9e7ff18531a35ae
 * provider record sha256 0293ec57336d974d62631d91925487b80beb3a5f4a50aa91ad8adc8eb3b53a97
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800813f0(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    if (*(byte *)(param_1 + 8) < 0x10) {
      iVar2 = *(byte *)(param_1 + 8) + 0x10;
    }
    else {
      iVar2 = *(byte *)(param_1 + 8) - 0x40;
    }
    *(ushort *)(param_1 + 0x1e0) = -(ushort)(byte)(&DAT_8011b5b0)[iVar2 * 2];
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar1 = FUN_80081de8(param_1);
  if (cVar1 != '\0') {
    FUN_80083758(&DAT_800e8d00,*(undefined1 *)(param_1 + 0x267));
    *(undefined1 *)(param_1 + 5) = 6;
    *(undefined1 *)(param_1 + 6) = 0;
    if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
      *(undefined1 *)(param_1 + 5) = 7;
      *(undefined1 *)(param_1 + 6) = 2;
    }
  }
  return;
}
