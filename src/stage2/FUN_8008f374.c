/* FUN_8008f374
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008f374  body 0x8008f374..0x8008f3af  size 60 B
 * body sha256 e550a6ac3e2c50476cd4119708915d1ead35bcde5dbff1a4b986a357d9753f72
 * provider record sha256 57d704eed1b5a335f0aa6a6ae6f1a0a52bfc630b4327dd65ef39885694007119
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008f374(void)

{
  byte bVar1;
  int unaff_s2;
  
  bVar1 = *(char *)(unaff_s2 + 5) + 1;
  *(byte *)(unaff_s2 + 5) = bVar1;
  if (6 < bVar1) {
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  *(short *)(unaff_s2 + 0x4e) = *(short *)(unaff_s2 + 0x4e) + 0xf;
  FUN_800988a4(0);
  FUN_80096f68(0);
  return;
}
