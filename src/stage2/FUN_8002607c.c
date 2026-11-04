/* FUN_8002607c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002607c  body 0x8002607c..0x800260cb  size 80 B
 * body sha256 17da50c4585e46c43f7d66e532540e210538a8590beb626926aaca85dd62cb47
 * provider record sha256 ad5c7c290ac687ab63eb1b06efbfe95b8baa0f9fc1177f9d8e1190f105e51ad5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002607c(int param_1)

{
  DAT_800c56e8 = param_1;
  DAT_800c4f18 = DAT_8010b6f8;
  DAT_800c4ec8 = param_1 - (int)DAT_800e8920 * DAT_801137d8 * 2;
  return;
}
