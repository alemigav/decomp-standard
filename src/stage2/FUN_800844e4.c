/* FUN_800844e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800844e4  body 0x800844e4..0x8008450b  size 40 B
 * body sha256 3b357cf18a738e21b1f5442a28c857e5cb7c3e2364a507a9471c9a39242dd359
 * provider record sha256 a6db0c97810bc13207793e5e82407cb08ad02908db9290b1a9023697aa8fc2ae
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800844e4(uint param_1)

{
  return param_1 << 0x18 | (param_1 & 0xff00) << 8 | param_1 >> 8 & 0xff00 | param_1 >> 0x18;
}
