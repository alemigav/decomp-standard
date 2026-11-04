/* FUN_800ac77c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac77c  body 0x800ac77c..0x800ac7cb  size 80 B
 * body sha256 3c514edb0fd8ae09791414f5e4d9295291d6f6d8d2516f62568feaff68369f0b
 * provider record sha256 b3b112d117a21aa5650719eb918c9e4f1959111b7b21499d5620081c9ac29b0f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800ac77c(uint param_1,uint param_2)

{
  if ((param_2 & 0xff) == 0xff) {
    return *(undefined1 *)((param_1 & 0xff) + 0x8014e0c0);
  }
  return *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb1fc0);
}
