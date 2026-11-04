/* FUN_80058be8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058be8  body 0x80058be8..0x80058c73  size 140 B
 * body sha256 54460aa2a6e3f9aa8465d87a81a20c19a3cef3be6b456bdf2dd10b00828a1962
 * provider record sha256 2495b316786de48596597c3bb7853119b0e2787ccc032fd9881695562004b51c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058894::caseD_5(void)

{
  char cVar1;
  int unaff_s1;
  
  if (*(char *)(unaff_s1 + 0x1e9) == '\x06') {
    FUN_80077f30(1,7);
  }
  *(char *)(unaff_s1 + 0x1a2) = -(char)(*(int *)(unaff_s1 + 0x2c) / 0x708);
  if (*(int *)(unaff_s1 + 0x280) != 0) {
    FUN_8004f634(&DAT_800e1130,*(int *)(unaff_s1 + 0x280),(uint)*(byte *)(unaff_s1 + 9) << 8,0x30);
  }
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s1 + 7) = *(char *)(unaff_s1 + 7) + cVar1;
  return;
}
