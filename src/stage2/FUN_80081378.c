/* FUN_80081378
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081378  body 0x80081378..0x800813ef  size 120 B
 * body sha256 98d9150157aedeb5770879d13e8da61f3cd027dbe4957253d5d4fd99a635a22b
 * provider record sha256 06b7a9c89d4366ea6c66fca0bb4e3131e8b15ac5655d7581187535a8d69e008d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80081378(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  return;
}
