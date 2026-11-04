/* FUN_8009f6d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f6d8  body 0x8009f6d8..0x8009f723  size 76 B
 * body sha256 946c46b9507c2ddd563d1b947554bf672d77593f653ed5afedb6a53f13cc6c31
 * provider record sha256 754d431a696eaa7bd508a1c498a08b3da875252f9ea0b271eab56f6e725d1e2b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009f6d8(void)

{
  DAT_801344cc = DAT_801344cc + 1;
  DAT_80184b38 = DAT_80184b38 ^ 1;
  func_0x8000ec60(*(undefined4 *)((uint)DAT_80184b38 * 4 + -0x7fe7b4d0));
  DAT_801344c8 = 3;
  DAT_801344f8 = DAT_801344f8 + 1;
  return;
}
