/* FUN_800ac734
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac734  body 0x800ac734..0x800ac77b  size 72 B
 * body sha256 08288a25ce9f8f69b82c26818d8ac7bdd527de0171f9172fe357816601314184
 * provider record sha256 c943f8dc2aee1fa4d36e0a172e6c795c0286293f980ac54226178195be16808a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ac734(uint param_1,uint param_2,undefined1 param_3)

{
  if ((param_2 & 0xff) == 0xff) {
    *(undefined1 *)((param_1 & 0xff) + 0x8014e0c0) = param_3;
    return;
  }
  *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb1fc0) = param_3;
  return;
}
