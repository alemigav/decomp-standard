/* FUN_8009d978
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d978  body 0x8009d978..0x8009da3b  size 196 B
 * body sha256 b406aed112c008680277f3fc4291d988a48aa0c29520d1951f307a89630e734a
 * provider record sha256 1a79043f257380f19d52a82e2204ebef0533b780ebfb07463c6aaad7e6a89a35
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d978(void)

{
  if (DAT_8013273a == 1) {
    func_0x80004a6c(1,7);
  }
  if (DAT_8013273a == 0xb) {
    DAT_80132740 = 0xc;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0xbe) {
    func_0x80004a6c(1,8);
  }
  if (DAT_8013273a == 0x184) {
    DAT_80132740 = 0xc;
    FUN_8009e8d4(0xb,0);
    FUN_80025f78(0,2,&DAT_80132628);
    FUN_80025f78(1,2,&DAT_80132644);
    FUN_8009ce40();
    DAT_8013273a = 0;
    DAT_8013272e = 3;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
