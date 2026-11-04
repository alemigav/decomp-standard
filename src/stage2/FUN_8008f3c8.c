/* FUN_8008f3c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f3c8  body 0x8008f3c8..0x8008f41b  size 84 B
 * body sha256 e12e2e1584a134d474f46e8aa4f36aa5ea4a545c491eddacbe4aa15f73daf713
 * provider record sha256 d2df7d0b01696a255ce4df2dad328a9b49673e0736fa847c498abae14cb0ccdd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f3c8(void)

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
  *(short *)(unaff_s2 + 0x40) = *(short *)(unaff_s2 + 0x40) + 6;
  *(short *)(unaff_s2 + 0x3a) = *(short *)(unaff_s2 + 0x3a) + -8;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
