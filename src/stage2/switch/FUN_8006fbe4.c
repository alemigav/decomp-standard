/* FUN_8006fbe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fbe4  body 0x8006fbe4..0x8006fc0f  size 44 B
 * body sha256 642fa4a2f612ca8e1b211fc30919ae6e802509b4a9ba4daf44d2304a11b21e2d
 * provider record sha256 99cbcf429be693d55d51795a12a1ec35e51d80cdea29f09fb3bc488a6561a25e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8006fb9c::caseD_3(undefined4 param_1,int param_2,int param_3)

{
  *(undefined4 *)(param_3 + 0x154) = (&DAT_800e13e8)[param_2 + 2];
  return 1;
}
