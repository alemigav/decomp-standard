/* FUN_8006bd38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bd38  body 0x8006bd38..0x8006bda3  size 108 B
 * body sha256 ef12510545d8048c293a1cf3ebd7ad94e553c864d3698f35f288c81406d34bb9
 * provider record sha256 0253d17be204c78ec17cf1d0a0d7e0cff667db330ee9dd3f729fa9920c21544a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006bd38(int param_1)

{
  while (DAT_801127e0 + param_1 != 0) {
    osRecvMesg(0x8013a100,&DAT_801127f0,1);
  }
  return;
}
