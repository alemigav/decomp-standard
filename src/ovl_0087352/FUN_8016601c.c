/* FUN_8016601c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016601c  body 0x8016601c..0x8016608b  size 112 B
 * body sha256 7a42eddde5cb096b1fd33b3a6b02ebdd439f9689262d8278bc55b935e36b7ea9
 * provider record sha256 5f7a340eb3a9f8de4fb85cdda35088a2378ab24ed4bb0d64b4e279dcef1a7262
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016601c(int param_1)

{
  if (((*(ushort *)(param_1 + 0x2c6) & 4) != 0) && (3 < *(byte *)(param_1 + 5) - 0xb)) {
    _DAT_800e1128 = _DAT_800e1128 & 0xfffe;
    *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) & 0xfffb;
  }
  if ((*(ushort *)(param_1 + 0x2c6) & 0x80) != 0) {
    *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) & 0xff7f;
    *(undefined1 *)(param_1 + 0x2bd) = 0x78;
  }
  return;
}
