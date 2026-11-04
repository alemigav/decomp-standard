/* FUN_800ac69c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac69c  body 0x800ac69c..0x800ac6e3  size 72 B
 * body sha256 7b68ba67a0822c143a99a3ae16afc62de782b1ca9802ccaf42ffb3bfc97bb547
 * provider record sha256 4f592846c2d5cde732286dcb227f7a36bc1ed1d12eb8b663ce754b4f3c2b5641
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ac69c(uint param_1,uint param_2,undefined1 param_3)

{
  if ((param_2 & 0xff) == 0xff) {
    *(undefined1 *)((param_1 & 0xff) + 0x80148c60) = param_3;
    return;
  }
  *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb7420) = param_3;
  return;
}
