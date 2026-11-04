/* FUN_8002767c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002767c  body 0x8002767c..0x800276a7  size 44 B
 * body sha256 a96fc73672178740588a91469f68d3ad3b9f6f0c6072a1448ad1c223aec57624
 * provider record sha256 14fc530c3a3a75de59eac067b2da00c8209041484771fc864155561865d40241
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8002767c(int param_1)

{
  return (uint)(int)(short)(&DAT_800e9184)[param_1 * 0x16] >> 0x1f;
}
