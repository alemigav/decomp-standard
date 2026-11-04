/* FUN_8006d284
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d284  body 0x8006d284..0x8006d2c7  size 68 B
 * body sha256 ebb690d48566e6dfc92bc900f474c1e3562bcb8eb0c862cb8511eb935bcb2865
 * provider record sha256 c321249ee72a9a82faffb49ebbda4876913678b43734da26dd9f5a8a88b73f55
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d284(void)

{
  DAT_80114f28 = (DAT_80114f28 + ((DAT_80114f28 & 0x7fffffff) >> 0xf) & 0xffff) +
                 (DAT_80114f28 & 0x7fff8000) * 2;
  DAT_800e8cb2 = (short)DAT_80114f28;
  return;
}
