/* FUN_80026040
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026040  body 0x80026040..0x8002607b  size 60 B
 * body sha256 cc3234b0ca5dd538739698313d514194d20ad1715cf828ffe6dc292663a1d012
 * provider record sha256 2277bcabbc0888192aac30854a52b65fac499277ab0103115a2f4f7ca6242986
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80026040(void)

{
  DAT_800c4f1f = 2;
  DAT_800c4ecf = 2;
  DAT_800c4f1e = 0;
  DAT_800c4ece = 0;
  FUN_80025a60();
  return;
}
