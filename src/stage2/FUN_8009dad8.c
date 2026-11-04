/* FUN_8009dad8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009dad8  body 0x8009dad8..0x8009db4f  size 120 B
 * body sha256 4caca353fd4c524b0e03025089625a58c15681daf5b3e73f76b9051114783ca3
 * provider record sha256 e38520f2ec2f7e1451299ab2ae794859ead0e64b9003117b0fcbd22c71932b86
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009dad8(void)

{
  if (DAT_8013273a == 0x3c) {
    func_0x80004a6c(1,10);
  }
  if (DAT_8013273a == 0x46) {
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x112) {
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(0xb,0);
    DAT_8013273a = 0;
    DAT_8013272e = 5;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
