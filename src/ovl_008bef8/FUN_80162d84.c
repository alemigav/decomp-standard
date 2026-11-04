/* FUN_80162d84
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162d84  body 0x80162d84..0x80162dff  size 124 B
 * body sha256 f9a4d0313e0d78f10e1a7c9ab9c56f1c70f69233df29570bfe034dc4c0ac02e7
 * provider record sha256 ee6c12981338dac75abe87e61484d7a5fa9cc0ffd099710c6be9a4421b12c78e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162d84(int param_1)

{
  if ((((_DAT_800e113e != 0) && ((_DAT_800e110c & 0x10) == 0)) && (DAT_800e139f == '\0')) &&
     (((*(char *)(param_1 + 0x2c0) == '\0' && ((*(byte *)(param_1 + 0x25c) & 4) == 0)) &&
      ((*(char *)(param_1 + 0x2c2) == '\0' || (*(char *)(param_1 + 0x2c2) == '\a')))))) {
    *(undefined1 *)(param_1 + 0x2c0) = 1;
  }
  return;
}
