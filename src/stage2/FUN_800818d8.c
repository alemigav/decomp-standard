/* FUN_800818d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800818d8  body 0x800818d8..0x8008199f  size 200 B
 * body sha256 f085662c69f1467ced0baeec6263dc744ffa8fc45b688d38cf33a0c5e7447ea7
 * provider record sha256 5246eb8e06455187ef661587ddcd67534b3009bc78e2e876d928817e15758e4a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800818d8(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar1 = FUN_80081f4c(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if (cVar1 != '\0') {
    FUN_80083758(&DAT_800e8d00,*(undefined1 *)(param_1 + 0x267));
    *(undefined1 *)(param_1 + 5) = 6;
    *(undefined1 *)(param_1 + 6) = 0;
    if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
      *(undefined1 *)(param_1 + 5) = 0x15;
      *(undefined1 *)(param_1 + 6) = 2;
    }
  }
  return;
}
