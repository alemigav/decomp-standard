/* FUN_8009dce4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009dce4  body 0x8009dce4..0x8009dd4f  size 108 B
 * body sha256 708eac74434a69c83c5464f196275b5f03e4be2c2bacee643b05943f66fa683b
 * provider record sha256 29ceed712a8335814802926826e3fb0ae05d610a37adc038a46671494a37f6c8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009dce4(void)

{
  if ((DAT_8013273a == 100) && (DAT_80119e70 == '\0')) {
    DAT_800e90f8 = 1;
    DAT_800e110c = DAT_800e110c & 0xffffffef;
    FUN_8006c070(0);
    FUN_8009f320(3);
    DAT_8013272e = 8;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
