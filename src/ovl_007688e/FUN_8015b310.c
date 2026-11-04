/* FUN_8015b310
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015b310  body 0x8015b310..0x8015b487  size 376 B
 * body sha256 34578104df8072d840377550404c61e5500d7f60ca08d89b6e9d1036fec18d57
 * provider record sha256 3a2301744839c5401c02f12c43a0a6623a02faeb0f6fc556b626a10333bb5ff6
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015b310(void)

{
  func_0x80026980(0);
  func_0x800479c8(&DAT_80161520,&DAT_801614b8,0x14d7,0);
  DAT_800e923f = 1;
  DAT_800e9182 = 0;
  DAT_80160c32 = 0xffd2;
  DAT_80160c21 = 0;
  DAT_80160c22 = 0;
  DAT_80160c23 = 0;
  DAT_80160c24 = 1;
  DAT_80160c1d = 0;
  DAT_80160c1e = 0;
  DAT_80160c1f = 0;
  DAT_80160c20 = 0;
  DAT_80160c2a = 0;
  DAT_80160c28 = 0;
  DAT_80160c29 = 0;
  DAT_80160c30 = 0;
  DAT_80160c34 = 0xffffffff;
  if ((_DAT_800e10ec & 2) == 0) {
    func_0x800274e4(0,0);
    FUN_8015b26c();
    func_0x800274f8(0x200,0,7,1);
    func_0x800275c0(0,0x7c00,0,0);
    DAT_80160c2e = 0xfc00;
    DAT_80160c2c = 0x7c00;
    DAT_80160c1d = 1;
  }
  else {
    _DAT_800e10ec = _DAT_800e10ec & 0xfffffffd;
    FUN_8015b26c();
    func_0x800274f8(0x100,0,7,1);
    func_0x800275c0(0,0x7f80,0,0);
    DAT_80160c32 = 0xf0;
    DAT_80160c1d = 5;
  }
  FUN_8015e1d0();
  DAT_80160c1c = DAT_80160c1c + '\x01';
  return;
}
