/* FUN_800931dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800931dc  body 0x800931dc..0x8009325b  size 88 B
 * body sha256 71c5415323558e6341de741f3ba45046a6399a15b57cce0b7a5a207d581fdc41
 * provider record sha256 5dcd2a403137e83c4c422f6afdc64cb4e5482a8e1cf084edf3b930d6894eafb3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800931dc(void)

{
  byte bVar1;
  int unaff_s2;
  
  bVar1 = DAT_8010b294 & 0x80;
  *(undefined1 *)(unaff_s2 + 0x16) = 0;
  if (bVar1 == 0) {
    *(undefined1 *)(unaff_s2 + 2) = 1;
  }
  return;
}
