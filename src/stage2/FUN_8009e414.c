/* FUN_8009e414
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e414  body 0x8009e414..0x8009e47f  size 108 B
 * body sha256 62a2296c8e7db422b46b616d5c9c7cfe378033b8fe968c108825a218cf9a66d8
 * provider record sha256 a16455463406f73a573826b804bb6802e5935949d31c126e60f22f7be80ccae8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e414(void)

{
  if ((DAT_8013273a == 100) && (DAT_80119e70 == '\0')) {
    DAT_800e90f8 = 1;
    DAT_800e110c = DAT_800e110c & 0xffffffef;
    FUN_8006c070(0);
    FUN_8009f320(3);
    DAT_8013272e = 0xb;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
