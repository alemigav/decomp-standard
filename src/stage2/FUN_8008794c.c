/* FUN_8008794c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008794c  body 0x8008794c..0x8008799b  size 80 B
 * body sha256 7e71b6b0461a728dc6034362295fe102008dc6dd423c04a7c179a84cddcca467
 * provider record sha256 10c207f7f93dea977b1b5667631cf73cbd3c15790a0bf54c88731f41d055c980
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008794c(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0xd6)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0xb8) + param_3 * *(short *)(param_1 + 0xd4) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0xbc) + param_3 * *(short *)(param_1 + 0xd4) * 4;
  }
  return;
}
