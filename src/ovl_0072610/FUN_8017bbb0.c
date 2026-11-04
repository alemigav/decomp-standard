/* FUN_8017bbb0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017bbb0  body 0x8017bbb0..0x8017bbcb  size 28 B
 * body sha256 7009c58cd1d280f87afe47691a48448b7186c6b5bd6fc1d8c26bf268879e7fcb
 * provider record sha256 029da5f2d7cdccec5e67b84192fbf8f08f0feb10965257f4c366450d59407c00
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017bbb0(int param_1)

{
  return *(uint *)(DAT_80186c94 + 0xc) >> (0x20U - param_1 & 0x1f);
}
