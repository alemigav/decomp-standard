/* FUN_8009de04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009de04  body 0x8009de04..0x8009de4f  size 76 B
 * body sha256 158f4c4dc069df2176c2e471d130adf55d9e1c221ec1bf88884b365a05ad19e5
 * provider record sha256 d8fe72b014206b139ee97772c51a764f8888a9b3c3ec5fbdc707a717f278c03c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009de04(void)

{
  if (DAT_8013273a == 10) {
    DAT_8013272a = 3;
    DAT_8013273c = 4;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
