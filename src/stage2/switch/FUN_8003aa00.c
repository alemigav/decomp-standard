/* FUN_8003aa00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003aa00  body 0x8003aa00..0x8003aa3b  size 60 B
 * body sha256 b0818889bdc44e2dbe8dd85aa13a3d921f281d3710bf8d1093f6fabcd3e8ecb7
 * provider record sha256 7b834e1d0bc1d87656e68237de009e1361f5296056b0a8e370547608a6c49cc7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_7(void)

{
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  return;
}
