/* FUN_8006e8f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e8f4  body 0x8006e8f4..0x8006e92b  size 56 B
 * body sha256 d32761d33928ee77b9ac58ebf65968c3cbc5ec5c52392807575dff6a8619afff
 * provider record sha256 28914b6728cfdc1ebfd8a35c8db250398878c9106a7870df14a68eb6acf50a4d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e880::caseD_4(void)

{
  int unaff_s0;
  short *unaff_s1;
  
  if (unaff_s0 == 0) {
    trap(0x1c00);
  }
  if ((unaff_s0 == -1) && (*unaff_s1 == -0x80000000)) {
    trap(0x1800);
  }
  *unaff_s1 = (short)((int)*unaff_s1 % unaff_s0);
  return;
}
