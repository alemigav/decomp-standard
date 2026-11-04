/* FUN_80165ec8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165ec8  body 0x80165ec8..0x80165f13  size 76 B
 * body sha256 f7278df2c9a755a328804c2c3027a55891c3351ec4d2064e8d2f132e1fad3e8a
 * provider record sha256 80172344e7eb39130288733a27ada55c6ce610c0cbfa83fd1467bf8670d302e8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ec8(int param_1)

{
  if (*(char *)(param_1 + 0x2c0) == '\0') {
    (*(code *)(&PTR_FUN_80167fd0)[*(byte *)(param_1 + 0x2be)])();
  }
  else {
    FUN_801661b8();
  }
  return;
}
