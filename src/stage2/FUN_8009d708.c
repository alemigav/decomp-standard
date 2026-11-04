/* FUN_8009d708
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d708  body 0x8009d708..0x8009d773  size 108 B
 * body sha256 d2b33e85ea50d43cee725203e1f36b8d0470175affd25710ef3908a80734b15e
 * provider record sha256 bfbdb2333693d5f78c2ee4ace959df8406862cde80813877d75beb2be6cf224d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d708(void)

{
  if ((DAT_8013273a == 100) && (DAT_80119e70 == '\0')) {
    DAT_800e90f8 = 1;
    DAT_800e110c = DAT_800e110c & 0xffffffef;
    FUN_8006c070(0);
    FUN_8009f320(3);
    DAT_8013272e = 7;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
