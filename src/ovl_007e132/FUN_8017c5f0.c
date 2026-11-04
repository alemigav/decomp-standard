/* FUN_8017c5f0
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c5f0  body 0x8017c5f0..0x8017c663  size 116 B
 * body sha256 da6488f1dd9b9f9a323cce4fb478b48500a8998b819b56fb631a4e2a421c430a
 * provider record sha256 68ae466639fa6825c947f8d41c81dd21e4ea335e0f3d8b7d19c8ef175f0b7797
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c5f0(void)

{
  DAT_8017e702 = 0;
  _DAT_800e10ec = _DAT_800e10ec & 0xbfeffeff;
  func_0x80026980(DAT_8017e900);
  func_0x80075c9c();
  func_0x8004cdd4();
  return;
}
