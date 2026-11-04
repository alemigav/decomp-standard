/* FUN_800931c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800931c8  body 0x800931c8..0x8009322f  size 56 B
 * body sha256 baa278a480e9a99de1cc0976a70c8982186327e498d74875c47da1165941c215
 * provider record sha256 dda44b3060b875e872c1ba70c17957449b263098ef29411f458060b33f88ee95
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800931c8(void)

{
  int unaff_s2;
  int unaff_s4;
  
  *(undefined1 *)(unaff_s2 + 0x16) = 0;
  *(undefined1 *)(unaff_s2 + 2) = 0;
  FUN_8009325c();
  FUN_8008c25c(0x10,0xaf,6,*(undefined1 *)(unaff_s4 + (uint)*(byte *)(unaff_s2 + 0xc) * 4 + 0x21818)
              );
  return;
}
