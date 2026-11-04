/* FUN_80163da0
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80163da0  body 0x80163da0..0x80163dd7  size 56 B
 * body sha256 98f997bd94ea9add7ab0c6e664ccdd6064c27ae762b994236e136061baa57c69
 * provider record sha256 bf66c41787e86077a2e04f88750ce8b2162bc164f3a90aea392b36422b956dff
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_80163da0(void)

{
  char cVar1;
  
  cVar1 = (_DAT_800df918 & 0x34f) != 0;
  if ((_DAT_800e112a & 2) != 0) {
    cVar1 = cVar1 + '\x03';
  }
  return cVar1;
}
