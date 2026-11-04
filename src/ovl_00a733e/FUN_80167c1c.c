/* FUN_80167c1c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80167c1c  body 0x80167c1c..0x80167c87  size 108 B
 * body sha256 ac907564db10ecb02a1761d26a968aa91235a96628f48d467aa60bc68a567511
 * provider record sha256 cfbe1d0827ad3a45089d10e33ef9e7e3c9ac852aedbcdfce840e1b0ed908d5f8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167c1c(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x2ce) != '\0') {
    _DAT_800e110c = _DAT_800e110c | 0x80000000U >> (*(byte *)(param_1 + 0x2cf) & 0x1f);
    cVar1 = *(char *)(param_1 + 0x2ce) + -1;
    *(char *)(param_1 + 0x2ce) = cVar1;
    if (cVar1 == '\0') {
      _DAT_800e110c = _DAT_800e110c & 0xfffffff3;
    }
  }
  return;
}
