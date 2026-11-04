/* func_8017b410
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017b410  body 0x8017b410..0x8017b4f7  size 232 B
 * body sha256 7721e83d26ee8c82bede89634b41474f479a7dddab31a60141177625badc8454
 * provider record sha256 ce9aa13d00144cf0d3a3509915e47ab71f14939c2ec1b135f072ebce14b2ec16
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  DAT_8017e702 = 0;
  DAT_8017e704 = 0;
  DAT_8017e758 = *(char *)(_DAT_800e1380 + 8);
  if ((_DAT_800e110c & 0x10000000) == 0) {
    DAT_8017e758 = DAT_800e1138;
  }
  else if ((*(char *)(_DAT_800e13ec + 4) == '\x03') &&
          (DAT_8017e758 = '\x0f', (*(byte *)(_DAT_800e13ec + 8) & 4) == 0)) {
    DAT_8017e758 = '\x0e';
  }
  if (((DAT_800e9012 & 0xc) >> 3 == 0) || (DAT_8017e758 == '\x0f')) {
    _DAT_800e10ec = _DAT_800e10ec & 0xfffffeff;
  }
  do {
    FUN_8017b4f8();
    func_0x8004cd88(1);
  } while( true );
}
