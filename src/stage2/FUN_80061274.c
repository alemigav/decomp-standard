/* FUN_80061274
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061274  body 0x80061274..0x800612a7  size 52 B
 * body sha256 ebb3a4c5091a5304ce34b1502a72afba91b4f5b6c2de6f96148186cea958789e
 * provider record sha256 7f7849347de87604e378ffdd82b7b7d3eb884f0ed81c75e337f8b6feb161cc14
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80061274(int param_1)

{
  (*(code *)(&PTR_FUN_80111100)[*(byte *)(param_1 + 6)])();
  return;
}
