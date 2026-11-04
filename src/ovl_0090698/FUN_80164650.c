/* FUN_80164650
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164650  body 0x80164650..0x8016467f  size 48 B
 * body sha256 0e23f26272b8add19d984afa4e98203f86f5123c9ec4a9e1e7d2c0249544cd38
 * provider record sha256 057039f25beb05e75d42a73e30f630d5e91954f2e5307ae511086af2c091545e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164650(int param_1)

{
  FUN_80163868();
  *(undefined1 *)(param_1 + 5) = 2;
  *(undefined2 *)(param_1 + 6) = 0;
  return;
}
