/* FUN_80071828
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071828  body 0x80071828..0x80071857  size 48 B
 * body sha256 00986383010cc3f18d8ba02eca7d57cf2b3e7ecceeb9fd520f6d1fedc3cf64de
 * provider record sha256 bc06005e5f8ca40ed8fc94d96863e1590778162db03ef2ad7f032f2c078fc838
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_800717d4::caseD_3(void)

{
  int in_a3;
  
  return *(int *)((int)&DAT_800e13f0 + ((in_a3 << 0x18) >> 0x16)) + 0x14;
}
