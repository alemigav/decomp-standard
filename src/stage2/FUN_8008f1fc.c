/* FUN_8008f1fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f1fc  body 0x8008f1fc..0x8008f237  size 60 B
 * body sha256 15c889d75f56ec1c2008d18c03b6a955b05d84cd88717c485fbdd3780116ba1b
 * provider record sha256 d4892f27fba95aa0577cbb2365692f7a8ff24cca994b9b0a000edb21b3716872
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f1fc(void)

{
  byte bVar1;
  int unaff_s2;
  
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (6 < bVar1) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  *(short *)(unaff_s2 + 0x4e) = *(short *)(unaff_s2 + 0x4e) + -0xf;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
