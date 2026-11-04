/* FUN_800844cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800844cc  body 0x800844cc..0x800844e3  size 24 B
 * body sha256 932435391ed669e0921af0c86510ccd27c27b76bedab21f1eb7aea221c9d0821
 * provider record sha256 fc845b1cd41f71409f0c6443d168d7e11abbb07d1a6d569fa8eebb5fe734b8d9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800844cc(uint param_1)

{
  return (param_1 & 0xff) << 8 | (param_1 & 0xffff) >> 8;
}
