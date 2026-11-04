/* FUN_8008e540
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008e540  body 0x8008e540..0x8008e5f7  size 184 B
 * body sha256 cd0f2e709b3549313c7ba50110317d268b0d6a21cdbbfc42d7d04620cd2da4ac
 * provider record sha256 78848a696e22ab44a9a96ae389786bfb65e75c04651e49c44fdd667be036db54
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008e540(void)

{
  byte bVar1;
  int unaff_s2;
  int unaff_s3;
  
  bVar1 = *(byte *)(unaff_s2 + 5);
  *(byte *)(unaff_s2 + 5) = bVar1 + 1;
  if (bVar1 < 10) {
    *(char *)(unaff_s2 + 0x1e) = *(char *)(unaff_s2 + 0x1e) + *(char *)(unaff_s2 + 0x1c);
    *(char *)(unaff_s2 + 0x22) = *(char *)(unaff_s2 + 0x22) + *(char *)(unaff_s2 + 0x20);
    *(char *)(unaff_s2 + 0x1f) = *(char *)(unaff_s2 + 0x1f) + *(char *)(unaff_s2 + 0x1d);
    *(char *)(unaff_s2 + 0x23) = *(char *)(unaff_s2 + 0x23) + *(char *)(unaff_s2 + 0x21);
    FUN_800965e4(*(undefined1 *)(unaff_s3 + (uint)*(byte *)(unaff_s2 + 0xd) * 4 + 0x2181a));
  }
  else {
    if (*(char *)(unaff_s2 + 6) != '\0') {
      *(undefined1 *)(unaff_s2 + 0xc) = *(undefined1 *)(unaff_s2 + 0xd);
    }
    *(undefined1 *)(unaff_s2 + 0x23) = 0;
    *(undefined1 *)(unaff_s2 + 0x22) = 0;
    *(undefined1 *)(unaff_s2 + 0x1f) = 0;
    *(undefined1 *)(unaff_s2 + 0x1e) = 0;
    *(undefined1 *)(unaff_s2 + 0x21) = 0;
    *(undefined1 *)(unaff_s2 + 0x20) = 0;
    *(undefined1 *)(unaff_s2 + 0x1d) = 0;
    *(undefined1 *)(unaff_s2 + 0x1c) = 0;
    *(undefined1 *)(unaff_s2 + 5) = 0;
    *(undefined1 *)(unaff_s2 + 6) = 0;
    *(char *)(unaff_s2 + 4) = *(char *)(unaff_s2 + 4) + '\x01';
  }
  return;
}
