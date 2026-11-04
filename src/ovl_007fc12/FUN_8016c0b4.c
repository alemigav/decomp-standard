/* FUN_8016c0b4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016c0b4  body 0x8016c0b4..0x8016c12f  size 124 B
 * body sha256 617bf7529de879450aab6c0426a82aa0dff6fd40baa37800d2e8e10b60ea248c
 * provider record sha256 2677bc5d6538d19bfd15642d0a76d250f326f5ac1ed58ee637f1b9c17a6c8e61
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016c0b4(int param_1)

{
  (*(code *)(&PTR_FUN_8016e84c)[*(byte *)(param_1 + 5)])();
  if (((*(short *)(param_1 + 0x1a8) != 0) &&
      (*(int *)(*(int *)(param_1 + 0x234) + 0x50) + -500 < (int)*(short *)(param_1 + 0x1a8))) &&
     ((*(byte *)(param_1 + 0x1e9) & 0xf) == 1)) {
    FUN_8016d778(param_1);
  }
  return;
}
