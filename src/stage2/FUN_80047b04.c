/* FUN_80047b04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b04  body 0x80047b04..0x80047b1f  size 28 B
 * body sha256 0ac7526d2f11702f06226d1f811c217f63c7a34783848339cd8611657fbcbc12
 * provider record sha256 6b2744b46b0e9394bc5b1aef46fe59607550a3d53efbd4a5fdef26e4667bde2f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b04(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 3) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 3) = 2;
  return;
}
