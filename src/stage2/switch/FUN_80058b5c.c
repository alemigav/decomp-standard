/* FUN_80058b5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058b5c  body 0x80058b5c..0x80058be7  size 140 B
 * body sha256 2fe3c2fe717accca03a09af8bad361f92fde2310f3a3a777251ef7c5a96cffea
 * provider record sha256 4f4c0973ade6a31ba6371ba35a58adc2bbb54816ea48628cbd9e6cbb93f2997b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058894::caseD_4(void)

{
  char cVar1;
  uint *unaff_s1;
  
  *(undefined1 *)((int)unaff_s1 + 7) = 5;
  *(undefined1 *)(unaff_s1 + 0x7a) = 9;
  if (4 < (*(byte *)((int)unaff_s1 + 6) & 0xc)) {
    *(undefined1 *)(unaff_s1 + 0x7a) = 7;
  }
  *(undefined1 *)((int)unaff_s1 + 0x1e9) = 4;
  *(undefined1 *)((int)unaff_s1 + 0x1ea) = 7;
  *(byte *)((int)unaff_s1 + 0x26f) = *(byte *)((int)unaff_s1 + 0x26f) & 0x7f;
  unaff_s1[0xb] = (int)*(short *)((int)unaff_s1 + 0x25e);
  *unaff_s1 = *unaff_s1 & 0xfffffffb;
  FUN_80077f30(1);
  DAT_800e112a = DAT_800e112a | 4;
  if (*(char *)((int)unaff_s1 + 0x1e9) == '\x06') {
    FUN_80077f30(1,7);
  }
  *(char *)((int)unaff_s1 + 0x1a2) = -(char)((int)unaff_s1[0xb] / 0x708);
  if (unaff_s1[0xa0] != 0) {
    FUN_8004f634(&DAT_800e1130,unaff_s1[0xa0],(uint)*(byte *)((int)unaff_s1 + 9) << 8,0x30);
  }
  cVar1 = FUN_80089d54();
  *(char *)((int)unaff_s1 + 7) = *(char *)((int)unaff_s1 + 7) + cVar1;
  return;
}
