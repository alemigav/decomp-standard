/* FUN_8016680c
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x8016680c  body 0x8016680c..0x8016698b  size 384 B
 * body sha256 030479e4a7da5729ec630842e2ba30aa02c4f7cfcad46b47f1d64df7c7c3d711
 * provider record sha256 a0f05ee7f46d08887a92bc6bdfe77d3c71a48e99ef86693f08dd59235bb1e328
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016680c(int param_1)

{
  *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) & 0xfe;
  *(byte *)(param_1 + 0x2c0) = *(byte *)(param_1 + 0x2c0) & 0xfe;
  if (*(char *)(param_1 + 0x2c1) != '\0') {
    *(char *)(param_1 + 0x2c1) = *(char *)(param_1 + 0x2c1) + -1;
    *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) | 1;
    func_0x80052c6c(3,100,0);
    func_0x80052d10(0x14,100,0,3);
  }
  if (0x78 < *(short *)(param_1 + 0x1e0)) {
    *(byte *)(param_1 + 0x2c0) = *(byte *)(param_1 + 0x2c0) | 1;
    func_0x80052c6c(3,0x96,0);
    func_0x80052d10(0x1e,0x96,0,3);
  }
  if (0x14 < *(short *)(param_1 + 0x1e0)) {
    *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) | 1;
    func_0x80052c6c(3,100,0);
    func_0x80052d10(0x14,100,0,3);
  }
  if (*(char *)(param_1 + 0x2bf) == '\0') {
    _DAT_800e110c = _DAT_800e110c & 0xfffffff7;
  }
  else {
    _DAT_800e110c = _DAT_800e110c | 8;
  }
  if (*(char *)(param_1 + 0x2c0) == '\0') {
    _DAT_800e110c = _DAT_800e110c & 0xfffffffb;
  }
  else {
    _DAT_800e110c = _DAT_800e110c | 4;
  }
  return;
}
