/* FUN_80162dd4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162dd4  body 0x80162dd4..0x80162e2b  size 88 B
 * body sha256 3d218ca3681e83c61d7a66e1afe9735bc718b43549dc831c713ee1f6f4800aee
 * provider record sha256 697be00c514af8096c2cd40654bd4ee7dd7b56385a61647524f6f9c4c1d3d0d8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162dd4(int param_1)

{
  (*(code *)(&PTR_FUN_80166db8)[*(byte *)(param_1 + 6)])();
  FUN_801664d8(param_1);
  FUN_80166980(param_1,4,0);
  return;
}
