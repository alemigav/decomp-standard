/* FUN_80168448
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168448  body 0x80168448..0x8016847b  size 52 B
 * body sha256 b2484d6547ad541818f0d088f0f476acbd26eb00aec31ed595f66c38f9d58479
 * provider record sha256 a777a42f84381fe59f8ed795b1df879695cef88fe966c1e657875ed76fff70d7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168448(int param_1)

{
  (**(code **)(&DAT_80168d4c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
