/* FUN_801627c4
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801627c4  body 0x801627c4..0x8016281f  size 92 B
 * body sha256 3b3ffdc0ea736b929bc869baf62b8e374ec91da34dcf4990f721ff9b287ae770
 * provider record sha256 290edcbbbda3d25c967f0e9caa6645620124898e7197b218328efbd6fdf83b03
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801627c4(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x207) = 1;
    *(undefined1 *)(param_1 + 0x206) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54();
  return;
}
