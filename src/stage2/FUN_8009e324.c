/* FUN_8009e324
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e324  body 0x8009e324..0x8009e413  size 240 B
 * body sha256 d3038da4c9046a2de274344533d2954514c8739dfc6656d0934a45daaa296dfc
 * provider record sha256 4cdf5e1306c8bb7a834554ddbd190997f50ede128fb558d617ef0b23dac5a8b1
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e324(void)

{
  int iVar1;
  
  if (DAT_8013273a == 1) {
    func_0x80004a6c(1,0xd);
  }
  if (DAT_8013273a == 0xb) {
    DAT_80132740 = 0x30000;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x181) {
    DAT_80132740 = 0x30000;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x253) {
    FUN_80077430(0x5a,0x18);
    DAT_80132728 = 8;
    FUN_8009ced8();
    DAT_80132729 = 0;
    DAT_8013272c = 2;
  }
  if ((0x253 < DAT_8013273a) && (iVar1 = FUN_8002767c(DAT_8013272b), iVar1 != 0)) {
    DAT_80132740 = 0;
    FUN_8009e8d4(0,1);
    DAT_80132729 = 1;
    DAT_8013272e = 10;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
