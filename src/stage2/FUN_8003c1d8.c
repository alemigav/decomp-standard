/* FUN_8003c1d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c1d8  body 0x8003c1d8..0x8003c25f  size 136 B
 * body sha256 7d393f0a7fabd8a4fcf0b1c41316b9daf58edb2bcc7ea647c88fe2aaf527f693
 * provider record sha256 efa27a39b941e3d62cbf21122d5de3b5f1b99df3636074028bd72286e4ec0c9b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c1d8(void)

{
  int iVar1;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0xfda80000;
  local_c = 0x12c0096;
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = *(short *)(DAT_800ebb94 + 0x36) + -100;
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar1 = FUN_800609e0(&local_20,(int)*(short *)(DAT_800ebb94 + 0x22),&local_10,0x2002000a);
  if (iVar1 != 0) {
    FUN_8003d144();
  }
  return;
}
