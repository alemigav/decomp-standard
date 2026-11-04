/* FUN_8003a128
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a128  body 0x8003a128..0x8003a153  size 44 B
 * body sha256 933a751536c9087aa73d59ddb97047869abd2e2e15bf34319796a47be3740057
 * provider record sha256 7a4a9e77679c9ecf911d8e1f60abd1da41eb8df97899a9b167ac1e053c5ade2e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a128(void)

{
  *(short *)(DAT_800ebb94 + 4) = *(short *)(DAT_800ebb94 + 4) + 0x100;
  FUN_8003b14c();
  return;
}
