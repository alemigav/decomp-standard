/* FUN_8004d138
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d138  body 0x8004d138..0x8004d177  size 64 B
 * body sha256 a4f322e9d98d67681c6d7c5179753af61170e37490618c6aed98dac725a7a04e
 * provider record sha256 14c25a05835d69104514c6ca30b717856599c0c131cb2e4051b828ed5fdf2544
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004d138(undefined4 param_1,uint param_2)

{
  if ((param_2 < 5) && ((0 >> (param_2 & 0x1f) & 1U) != 0)) {
    return (&DAT_8010b6c0)[param_2];
  }
  return 0;
}
