/* FUN_800ac6e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac6e4  body 0x800ac6e4..0x800ac733  size 80 B
 * body sha256 88317640e4ad5e6f19fd379268c202d235610144077c34c550763577539d34e2
 * provider record sha256 45c547d914c123d04ec114cb9ed6650cd9f27a41860609feb1df9b6d1f66cde4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800ac6e4(uint param_1,uint param_2)

{
  if ((param_2 & 0xff) == 0xff) {
    return *(undefined1 *)((param_1 & 0xff) + 0x80148c60);
  }
  return *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb7420);
}
