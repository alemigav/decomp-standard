/* FUN_8015b0c8
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015b0c8  body 0x8015b0c8..0x8015b233  size 364 B
 * body sha256 0dd1b432a6f6f39b9992bc7f2069aaec1c5fd1af45fa7f38703265f162ae7427
 * provider record sha256 eae41234fff94ba885c5537acbd6dbf4266297e0d2ca0b8123950618a0386a1d
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015b0c8(void)

{
  func_0x80075c9c();
  func_0x8007608c(0x11,0);
  DAT_800e9241 = '\x02';
  func_0x8004cd88(1);
  if ((_DAT_800e10ec & 2) == 0) {
    FUN_8015b234();
    FUN_8015b26c();
  }
  else {
    FUN_8015b234();
    while (DAT_800e9241 != '\0') {
      func_0x8004cd88(1);
    }
    FUN_8015b26c();
    func_0x8009f320(0);
    while ((_DAT_800e10ec & 0x200) != 0) {
      func_0x8004cd88(1);
    }
    if (DAT_800e9243 == '\x02') {
      _DAT_800e10ec = _DAT_800e10ec & 0xfffffffd;
    }
  }
  DAT_800e923f = 1;
  if ((_DAT_800e10ec & 8) == 0) {
    DAT_80160c1c = 1;
  }
  else {
    DAT_80160c1c = 3;
  }
  return;
}
