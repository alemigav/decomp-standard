/* FUN_8009db50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009db50  body 0x8009db50..0x8009dbeb  size 156 B
 * body sha256 0748b0b5f74d23cada00404802229494647f17f1167cc8ff68ff7877dc655379
 * provider record sha256 dabf6e6063a8f628aa92a5060508f95d6e14ad7cda1537e6bffd0304a5d235fa
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009db50(void)

{
  if (DAT_8013273a == 1) {
    func_0x80004a6c(1,0xb);
  }
  if (DAT_8013273a == 0xb) {
    DAT_80132740 = 0x300;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0xfd) {
    DAT_80132740 = 0x300;
    FUN_8009e8d4(0xb,0);
    FUN_80025f78(1,2,&DAT_80132660);
    FUN_8009ce40();
    DAT_8013273a = 0;
    DAT_8013272e = 6;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
