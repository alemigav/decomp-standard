/* FUN_8005ab10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ab10  body 0x8005ab10..0x8005ab47  size 56 B
 * body sha256 69235c7687858602a100b67070c10167350579d1ecc4f6b3c8d2cef2b191b095
 * provider record sha256 5f193ea963190ca51d84538107f8dbe68e528187c42ae74363c1ce05d5f11e6b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ab10(int param_1,int param_2)

{
  if (DAT_800e1126 != '\0') {
    *(undefined1 *)(param_1 + 0x289) = 0;
    *(undefined1 *)(param_1 + 0x288) = *(undefined1 *)(*(int *)(param_2 + 4) + 1);
  }
  return;
}
