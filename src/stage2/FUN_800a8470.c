/* FUN_800a8470
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8470  body 0x800a8470..0x800a84e7  size 120 B
 * body sha256 f72676d5389f0fb0ec29a6b00c89b358fa4a7e9e2e07d78c01f06261d2e216ec
 * provider record sha256 c7258666a76b3a91ef1ab4c877b2caeb7c012e2735b9d3c283da723bcbdb3d9b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a8470(void)

{
  if (_DAT_80147fa0 != 0) {
    if (_DAT_80147fa4 == 0) {
      trap(0x1c00);
    }
    if ((_DAT_80147fa4 == -1) && (_DAT_80147fa0 * 32000 == -0x80000000)) {
      trap(0x1800);
    }
    _DAT_80147848 = (_DAT_80147fa0 * 32000) / _DAT_80147fa4 << 3;
    FUN_800a6c04();
  }
  return;
}
