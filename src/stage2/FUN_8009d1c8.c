/* FUN_8009d1c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d1c8  body 0x8009d1c8..0x8009d2fb  size 308 B
 * body sha256 70655cf4704eb70cbf518b89a7186f7b75759727dbcac935fdc4a533a4c9936b
 * provider record sha256 268561bad6c1278d00f5d8776f8e35c5ee9ad2220c2eab1e4df91e359354e1f0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d1c8(void)

{
  if ((DAT_8013273a & 0xf) == 0) {
    DAT_80132674 = DAT_80132674 + 0x140;
    FUN_80025f78(0,2);
  }
  if (DAT_8013273a == 0x40) {
    func_0x80004a6c(1,2);
  }
  if (DAT_8013273a == 0x4a) {
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x15d) {
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x167) {
    DAT_80132740 = 0x300;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x36b) {
    DAT_80132740 = 0x300;
    FUN_8009e8d4(0xb,0);
    FUN_8009ced8();
  }
  if (DAT_8013273a == 0x389) {
    DAT_80132740 = 0x3c;
    FUN_8009e8d4(0x1b,0);
    DAT_80132740 = 0x400;
    FUN_8009e8d4(0x47,0);
    DAT_8013272e = 3;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
