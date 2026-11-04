/* FUN_8003a9c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a9c8  body 0x8003a9c8..0x8003a9e3  size 28 B
 * body sha256 eb66984bf281f5f55cce3bead0e3b6cd656c0a35423196565b065e8ea8dc4450
 * provider record sha256 36507aba5caed606dfb1dc663deb37f4364f677490dd520b8533a4e3f28607d7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_5(void)

{
  FUN_800275c0(0,0x1200,0x8421,0);
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  return;
}
