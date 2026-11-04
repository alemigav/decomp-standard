/* FUN_8009da3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009da3c  body 0x8009da3c..0x8009dad7  size 156 B
 * body sha256 295a4861046ddaf40c5b2acfbf057a78883e1f34d4d3a8b37c0b821d08d5310e
 * provider record sha256 23995f2bbfe6cd50eeb9e24c2d7bf337b7e55b03e91ab8c08b53075e0b735b15
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009da3c(void)

{
  if (DAT_8013273a == 0x80) {
    func_0x80004a6c(1,9);
  }
  if (DAT_8013273a == 0x8a) {
    DAT_80132740 = 0x30;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x150) {
    DAT_80132740 = 0x30;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x18c) {
    FUN_8009ced8();
    DAT_80132728 = 8;
    DAT_8013273a = 0;
    DAT_8013272e = 4;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
