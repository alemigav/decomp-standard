/* FUN_80180958
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180958  body 0x80180958..0x80180a1b  size 196 B
 * body sha256 eaed021d60a1fb266b12addf0d56b0e021c0ac2e35081811779e52407cf023f7
 * provider record sha256 daabeb597efacd10023c597ed370163565615d8bddfc27819c8e54d0ee0962d3
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80180958(void)

{
  if (DAT_80185480 != -1) {
    func_0x800b431c(DAT_80185480);
    DAT_80185480 = -1;
  }
  if (DAT_80185484 != -1) {
    func_0x800b431c(DAT_80185484);
    DAT_80185484 = -1;
  }
  if (DAT_80185488 != -1) {
    FUN_801806cc(DAT_80185488);
    DAT_80185488 = -1;
  }
  if (*(short *)(_DAT_801344b0 * 0x112 + -0x7fecbaf0) == 3) {
    func_0x800b21a8();
  }
  return;
}
