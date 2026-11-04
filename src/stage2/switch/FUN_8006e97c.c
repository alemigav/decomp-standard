/* FUN_8006e97c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e97c  body 0x8006e97c..0x8006e987  size 12 B
 * body sha256 946eeddf11e26501f6cbc45df44623314785923e04ac209c92f7dc47b7e780be
 * provider record sha256 492331fc0efbe62b42cb14e84daa9a9027ebfc85bd501617a4bad985273aa26a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e880::caseD_a(void)

{
  uint unaff_s0;
  ushort *unaff_s1;
  
  *unaff_s1 = (ushort)((int)(uint)*unaff_s1 >> (unaff_s0 & 0x1f));
  return;
}
