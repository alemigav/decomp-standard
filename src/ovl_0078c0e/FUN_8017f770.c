/* FUN_8017f770
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017f770  body 0x8017f770..0x8017f843  size 212 B
 * body sha256 e6fed9db0dbe3a139a1336ec7682652e96c797593e2f2327386378109c9cbc3b
 * provider record sha256 7682a9aaae02d62fdf6d246431f1bf4c5a1c21b3debf38e8a20543c972ee9c59
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017f770(void)

{
  _DAT_800e110c = _DAT_800e8b44;
  if ((_DAT_800e8b44 & 0x4000000) != 0) {
    _DAT_800e10ec = _DAT_800e10ec | 0x20;
  }
  func_0x8007604c(DAT_800e8b39);
  DAT_8012bfa2 = DAT_800e8b48;
  DAT_8012bfa0 = DAT_800e8b49;
  _DAT_800e1322 = _DAT_800e8b4a;
  DAT_800e13e6 = DAT_800e8b3f;
  _DAT_800e13e4 = _DAT_800e8b40;
  DAT_80119e73 = DAT_800e8b3c;
  DAT_80119e74 = DAT_800e8b3d;
  func_0x800750b0(1);
  DAT_800dfbe9 = DAT_800e8b39;
  DAT_800e923e = DAT_800e8b3e;
  return;
}
