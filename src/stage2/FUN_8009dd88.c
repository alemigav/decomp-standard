/* FUN_8009dd88
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009dd88  body 0x8009dd88..0x8009ddbf  size 56 B
 * body sha256 b5d173abb78d540ff83fc959e5e3cd551b96f57e99794aa6ce018b4fdf22b532
 * provider record sha256 796c2e4c8c98f8903c089a751093693ed79acf7ef71a7bf9c12f871793e37941
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009dd88(void)

{
  if (DAT_8013273a == 1) {
    FUN_8006c070(0);
    FUN_8009f320(0x10);
    DAT_8013272e = 10;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
