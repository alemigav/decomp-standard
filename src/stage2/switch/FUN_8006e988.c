/* FUN_8006e988
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e988  body 0x8006e988..0x8006e997  size 16 B
 * body sha256 24bd9d368bb02c13139421d2a68b2d09d2922a01c5d1b296cb44364af7d6c940
 * provider record sha256 0fabfd84370071d4415785e1d583b5d107ae041da2dbc5f2d118342783659add
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e880::caseD_b(void)

{
  uint unaff_s0;
  short *unaff_s1;
  
  *unaff_s1 = (short)((int)*unaff_s1 >> (unaff_s0 & 0x1f));
  return;
}
