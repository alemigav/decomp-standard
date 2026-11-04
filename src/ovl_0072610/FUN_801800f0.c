/* FUN_801800f0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801800f0  body 0x801800f0..0x80180147  size 88 B
 * body sha256 117b89e0244cfb5f2b2c9fa3009b7687539307930e3606e68cddf00664867fea
 * provider record sha256 946b7d9a795dfae4a7cc8ec507d1a43349d264ba403d8b8e601dd568db0e5642
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Heritage AFTER dead removal. Example location: r0x80185460 : 0x80180118 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_801800f0(void)

{
  DAT_80185468 = 0;
  DAT_80185464 = 0;
  if ((_DAT_8010b6fc & 0x3f) == 0) {
    DAT_80185460 = _DAT_8010b6fc;
  }
  else {
    DAT_80185460 = (_DAT_8010b6fc + 0x40) - (_DAT_8010b6fc & 0x3f);
  }
  return;
}
