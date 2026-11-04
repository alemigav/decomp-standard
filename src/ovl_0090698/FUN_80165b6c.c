/* FUN_80165b6c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165b6c  body 0x80165b6c..0x80165bd7  size 108 B
 * body sha256 a71445a61d317cd1bdbcf3eee762d264fb917ae97b2feaa9cdafdc9b9776d6e0
 * provider record sha256 63107c48639d588710b3287c53f4513646b7b7ee945bc8f7ebf92352fe7337cc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165b6c(uint *param_1)

{
  func_0x80089d54();
  if ((*(uint *)param_1[0x85] & 0x80000) != 0) {
    param_1[1] = 0x7000000;
    *param_1 = *param_1 & 0xe3ffffff;
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      *(undefined2 *)((int)param_1 + 0x1f2) = 1;
      *(undefined1 *)(param_1 + 0xb0) = 1;
    }
  }
  return;
}
