/* FUN_8005879c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005879c  body 0x8005879c..0x8005884f  size 100 B
 * body sha256 960c97dda3f72281960b2a1e463add8bfb5d1318deebb247a80fdb4507817f7c
 * provider record sha256 a93d03623384948f947c879b7f810421231279f621b435942baa9f22cf937f70
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8005850c::caseD_4(void)

{
  int unaff_s0;
  
  if (*(int *)(unaff_s0 + 0x280) != 0) {
    FUN_8004f634(&DAT_800e1130,*(int *)(unaff_s0 + 0x280),(uint)*(byte *)(unaff_s0 + 9) << 8,1000);
  }
  *(undefined1 *)(unaff_s0 + 5) = 0;
  *(undefined1 *)(unaff_s0 + 6) = 0;
  *(undefined1 *)(unaff_s0 + 7) = 0;
  DAT_800e110c = DAT_800e110c & 0xffffffbf;
  return;
}
