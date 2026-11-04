/* FUN_80025a60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025a60  body 0x80025a60..0x80025b0b  size 172 B
 * body sha256 db9d8a3a714988731c25e5f1b68df3210c14493c13a20a53c43247d78f5df917
 * provider record sha256 2089ac72c39418c796405b70a187d2da1a9024acfaa9e832c21dfccb83f808f0
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025a60(void)

{
  DAT_800c4eba = 0x800;
  DAT_800c4ebe = 0x800;
  DAT_800c4f0a = 0x800;
  DAT_800c4f0e = 0x800;
  DAT_800c4f18 = DAT_8010b6f8;
  DAT_800c4ec2 = DAT_800c4eb4._2_2_ << 2;
  DAT_800c4ec8 = DAT_800c56e8 - (int)DAT_800e8920 * DAT_801137d8 * 2;
  DAT_800c4ec6 = DAT_800c4ec2;
  DAT_800c4f12 = DAT_800c4ec2;
  DAT_800c4f16 = DAT_800c4ec2;
  func_0x8000e210();
  func_0x8000e210(&DAT_800c4f08);
  return;
}
