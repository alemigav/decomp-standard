/* FUN_800810a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800810a0  body 0x800810a0..0x800811f3  size 340 B
 * body sha256 e4e8e081ea7d5844aa3002e3edcbb3b79c284f6a05850ce0b917057b4de304f0
 * provider record sha256 4bcad1f3147e5e19ff03c566dd6951f0b149f3eaf87ac253546dc982ec578891
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800810a0(int param_1)

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
      *(undefined1 *)(param_1 + 5) = 4;
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
    *(ushort *)(param_1 + 0x1e0) = (ushort)(byte)(&DAT_8011b570)[iVar3 * 2];
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
  }
  cVar2 = FUN_80081d1c(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if (cVar2 != '\0') {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  return;
}
