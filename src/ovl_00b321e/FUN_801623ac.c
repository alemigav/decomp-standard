/* FUN_801623ac
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801623ac  body 0x801623ac..0x801623e3  size 56 B
 * body sha256 d6f314430579122f33c93cd31ac8186c9404f42e1be333e107590f23f9e9797e
 * provider record sha256 3bcd00ceea366d85a53f634dbd652e212f1ae9f26b71bfc984b06bef09231aae
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801623ac(int param_1)

{
  if ((((*(ushort *)(param_1 + 0x1aa) & 1) == 0) && (*(char *)(param_1 + 0x2c3) != '\0')) &&
     ((*(byte *)(param_1 + 0x2bd) & 1) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1060000;
  }
  return;
}
