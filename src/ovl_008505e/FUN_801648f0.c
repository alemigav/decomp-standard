/* FUN_801648f0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801648f0  body 0x801648f0..0x80164937  size 72 B
 * body sha256 b5841c905f4d2e2f97fec6114385bad37dbb7c92d02d18f0472e638c323ef719
 * provider record sha256 ab0d29889bb7f0eeea905243dd7533c51df005e2f2452d300503281223d0f85a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801648f0(int param_1)

{
  (*(code *)(&PTR_FUN_80166df0)[*(byte *)(param_1 + 6)])();
  FUN_801664d8(param_1);
  return;
}
