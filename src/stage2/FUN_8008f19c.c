/* FUN_8008f19c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f19c  body 0x8008f19c..0x8008f1fb  size 96 B
 * body sha256 fb1fe06536d169a45ea0341ee29c2a717892fb693cdbecdc1214747e045a4fab
 * provider record sha256 167bcffc447ccc665b8757f4921c3ff80aae4ba7e638554520dfd348b18ab4f1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f19c(void)

{
  byte bVar1;
  int unaff_s2;
  
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (4 < bVar1) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  *(short *)(unaff_s2 + 0x38) = *(short *)(unaff_s2 + 0x38) + 6;
  *(short *)(unaff_s2 + 0x3a) = *(short *)(unaff_s2 + 0x3a) + 8;
  *(short *)(unaff_s2 + 0x48) = *(short *)(unaff_s2 + 0x48) + 8;
  *(short *)(unaff_s2 + 0x40) = *(short *)(unaff_s2 + 0x40) + -6;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
