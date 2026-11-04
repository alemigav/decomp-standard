/* FUN_80180070
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180070  body 0x80180070..0x801800e7  size 120 B
 * body sha256 320bb092dd78031b853cf4d8ead19627f15d01b49f1e4444b2f9d8238252b288
 * provider record sha256 ee068ce173a2428f460bbcc222ad5e1a20a854f324d3301ee625937ca78bb44d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80180070(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0x3f) != 0) {
    param_1 = param_1 + 0x40 & 0xffffff40;
  }
  if (0x25800 < param_1 + DAT_80185464) {
    DAT_80185464 = 0;
    DAT_80185468 = DAT_80185468 + 1;
  }
  iVar1 = DAT_80185464;
  DAT_80185464 = DAT_80185464 + param_1;
  return (&DAT_80185460)[DAT_80185468] + iVar1;
}
