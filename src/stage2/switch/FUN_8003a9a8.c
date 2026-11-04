/* FUN_8003a9a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a9a8  body 0x8003a9a8..0x8003a9c7  size 32 B
 * body sha256 97c34fef802da895ef47f15918ccc37b1a1b4004c8f2e5ae281bb0e4b11ba99a
 * provider record sha256 75f77a7609cd1312e11ee5790abfb556bad25b6ec1ed81497d8cf20d7cd86eb0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_4(void)

{
  FUN_800274f8(0x100,0,7,1);
  FUN_800275c0(0,0x1400,0x8421,0);
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  return;
}
