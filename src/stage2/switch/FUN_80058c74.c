/* FUN_80058c74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058c74  body 0x80058c74..0x80058cdf  size 108 B
 * body sha256 53e02be6c977e2cade72dfe8920e8020d8b20b61a91b0e6ae79a3f5b46de50f3
 * provider record sha256 3d7ad569583adb520b6c45c280403d614a85c26eeeb4712648606e0e53fcc9c6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058894::caseD_6(void)

{
  int unaff_s1;
  
  DAT_800e110c = DAT_800e110c & 0xffffffbf;
  if (*(int *)(unaff_s1 + 0x280) != 0) {
    FUN_8004f634(&DAT_800e1130,*(int *)(unaff_s1 + 0x280),(uint)*(byte *)(unaff_s1 + 9) << 8,1000);
  }
  *(undefined1 *)(unaff_s1 + 5) = 0;
  *(undefined1 *)(unaff_s1 + 6) = 0;
  *(undefined1 *)(unaff_s1 + 7) = 0;
  return;
}
