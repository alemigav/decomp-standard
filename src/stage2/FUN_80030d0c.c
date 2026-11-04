/* FUN_80030d0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030d0c  body 0x80030d0c..0x80030d67  size 92 B
 * body sha256 ecfa8bcefd2f6b7f99bd9f1e6a8a0612c5f6f26684f1841c7395d145690901d5
 * provider record sha256 91ba6b12ae040ceb412cd5651fa1ddafd7b31503a5aefdcc9440c03d01510c76
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80030d0c(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_80030b8c(param_1,iVar1);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  FUN_8002fc94(param_1,*(undefined4 *)(param_1 + 4),0x50);
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_8002fcec();
  return;
}
