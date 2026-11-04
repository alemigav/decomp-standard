/* FUN_800811f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800811f4  body 0x800811f4..0x80081377  size 388 B
 * body sha256 c6f968cb752b234cab0a56c5a0355d46a3036756889d958e8c9a0859208b036f
 * provider record sha256 dd8fe92f14c0eefb530150df7a2487162414727700c307c406e78e48f072ae3e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800811f4(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      FUN_8004e774(param_1);
      cVar2 = FUN_80081de8(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220)
                          );
      if (cVar2 == '\0') {
        return;
      }
      FUN_80083758(&DAT_800e8d00,*(undefined1 *)(param_1 + 0x267));
      *(undefined1 *)(param_1 + 5) = 6;
      *(undefined1 *)(param_1 + 6) = 0;
      if ((*(ushort *)(param_1 + 0x268) & 4) == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 5) = 5;
      *(undefined1 *)(param_1 + 6) = 2;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    if (*(byte *)(param_1 + 8) < 0x10) {
      iVar3 = *(byte *)(param_1 + 8) + 0x10;
    }
    else {
      iVar3 = *(byte *)(param_1 + 8) - 0x40;
    }
    *(ushort *)(param_1 + 0x1e0) = (ushort)(byte)(&DAT_8011b670)[iVar3 * 2];
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
  }
  cVar2 = FUN_80081d1c(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if (cVar2 != '\0') {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
  }
  return;
}
