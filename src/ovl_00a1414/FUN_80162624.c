/* FUN_80162624
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80162624  body 0x80162624..0x8016265b  size 56 B
 * body sha256 11695fa3223324ebdae56a24385887c8382a31c3c5414ed868a9da0da1e58a2b
 * provider record sha256 2b0978906b8e58398b13c3ad950f0f229519bf14094b523d677b6585bb061321
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162624(int param_1)

{
  (*(code *)(&PTR_FUN_80168f50)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
