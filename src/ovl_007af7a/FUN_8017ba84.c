/* FUN_8017ba84
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017ba84  body 0x8017ba84..0x8017bb97  size 276 B
 * body sha256 d093e17082f72572cc6c95baecfa67bdd916010a9a75eef2396d9dd0ebfff57d
 * provider record sha256 65df70a448492c9ac29af6d79e54fd396cde2c7e4f57be45035b54ea7529d4d8
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017ba84(void)

{
  DAT_800e923f = DAT_8017e5cb;
  if ((DAT_8017e5bf & 0x10) != 0) {
    _DAT_800e10ec = _DAT_800e10ec | 0x1000;
  }
  if ((_DAT_800e10ec & 0x8000000) == 0) {
    if (_DAT_800df92c != 0) {
      *(undefined4 *)(_DAT_800df92c + 0x2c) = DAT_8017e5d4;
    }
    DAT_800e9182 = 2;
    _DAT_800e8cac = (ushort)DAT_8017e5ce;
    func_0x800274e4(0,0);
  }
  func_0x8004cec4(0);
  func_0x80026980(DAT_8017e5b4);
  _DAT_800e9120 = 0xffffffff;
  _DAT_800e911c = 0xffffffff;
  _DAT_8010bfa8 = _DAT_8010bfa8 >> 1;
  func_0x80026910(DAT_8017e5b8);
  func_0x80026a88();
  func_0x8004cdd4();
  return;
}
