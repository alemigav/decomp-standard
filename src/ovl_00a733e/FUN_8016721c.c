/* FUN_8016721c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016721c  body 0x8016721c..0x8016726b  size 80 B
 * body sha256 12478d944f777387602d351f4ff7ab9cafdf09a536197e6ce183355d1d21d29d
 * provider record sha256 d63e75d0aeaa0b9bb42d465a98903d10824a020f0ff1d3b2baa4a69107e903e7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8016721c(char param_1)

{
  DAT_80167d6b = DAT_80167d6b + param_1;
  if ('\b' < DAT_80167d6b) {
    DAT_80167d6b = 8;
    return 1;
  }
  if (DAT_80167d6b < -8) {
    DAT_80167d6b = 0xf8;
    return 0xffffffff;
  }
  return 0;
}
