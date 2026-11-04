/* FUN_800837ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800837ac  body 0x800837ac..0x800837cf  size 36 B
 * body sha256 8e8abf4b4968d76d5cbed6aca664cd4da3d6861514f50ee19d3af6a808e3a0b3
 * provider record sha256 ccd039d5f2be41ffd5341d83b0946809e38a4f91c1990161fea2e1aae860cb63
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800837ac(int param_1,uint param_2)

{
  return *(uint *)((param_2 >> 5) * 4 + param_1) & 0x80000000U >> (param_2 & 0x1f);
}
