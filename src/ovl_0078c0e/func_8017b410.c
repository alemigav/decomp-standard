/* func_8017b410
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017b410  body 0x8017b410..0x8017b4c7  size 184 B
 * body sha256 73439bc6372af4440f6967b0710f199788a580f824a5576c0d95baa5e8271402
 * provider record sha256 9da9f3b7c6e899c1da61efb662b40fa9eb04eb0b1fbfd25c0bf680331459bdb4
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  _DAT_8010bfa8 = _DAT_8010bfa8 << 1 | 1;
  DAT_80181eec = func_0x80025b0c();
  DAT_80181ef0 = _DAT_800e924c;
  func_0x8004ce90(0);
  FUN_8017cf0c();
  func_0x8004cec4(0);
  _DAT_800e9120 = 0xffffffff;
  _DAT_800e911c = 0xffffffff;
  _DAT_8010bfa8 = _DAT_8010bfa8 >> 1;
  func_0x80026980(DAT_80181eec);
  func_0x80026910(DAT_80181ef0);
  func_0x80026a88();
  func_0x8004cdd4();
  return;
}
