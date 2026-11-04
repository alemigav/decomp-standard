/* FUN_8009e4b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e4b8  body 0x8009e4b8..0x8009e4ef  size 56 B
 * body sha256 51855b98c1f92ae8f8119bb5706a41a48ba3a6c269244b11aa7ee8ebc2abe32a
 * provider record sha256 0af52729d53b112e63384bbf24a66e29c6e0773660bde9488362d6eec366d653
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e4b8(void)

{
  if (DAT_8013273a == 1) {
    FUN_8006c070(0);
    FUN_8009f320(0x10);
    DAT_8013272e = 0xd;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
