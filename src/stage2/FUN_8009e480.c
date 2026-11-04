/* FUN_8009e480
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e480  body 0x8009e480..0x8009e4b7  size 56 B
 * body sha256 a855ddc5af0c968349b496670bee78e80c0cb56bef95989953ebdaac8621d216
 * provider record sha256 a9fa3eb2856db2a60f18da59d87d7ae585daaa9497b1586f82a191fe3c694a93
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e480(void)

{
  if ((DAT_800e10ec & 0x200) == 0) {
    FUN_8006c070(1);
    DAT_8013272e = 0xc;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
