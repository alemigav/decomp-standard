/* FUN_8003a98c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a98c  body 0x8003a98c..0x8003a997  size 12 B
 * body sha256 a6c0914c912e0ec1727fa6d8a49a936dac21c1a316d553040b70203bd6bbb821
 * provider record sha256 209192fb9e69520d523149b3a142cf853f34ecc37b6b38f5a6425403b557ce4c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_2(void)

{
  FUN_800275c0(0,0x1600,0x8421,0);
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  return;
}
