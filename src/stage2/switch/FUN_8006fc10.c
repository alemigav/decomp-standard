/* FUN_8006fc10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fc10  body 0x8006fc10..0x8006fc3b  size 44 B
 * body sha256 88a4b0149893b357b0cb1dd34bfb679c51a8567cbf8d06119d29c3f67e5457a0
 * provider record sha256 44e59fa0dfd87f826998abf9337c5c41af094ac1d628e6ff7b3fed54fee3ab59
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8006fb9c::caseD_4(undefined4 param_1,int param_2,int param_3)

{
  *(undefined4 **)(param_3 + 0x154) = &DAT_800e18f8 + param_2 * 0xda;
  return 1;
}
