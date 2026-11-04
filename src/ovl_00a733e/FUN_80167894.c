/* FUN_80167894
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80167894  body 0x80167894..0x801678e3  size 80 B
 * body sha256 e6e4cf4afb7230c9f79cbeb3d13c2b160fb6890123942cf57839f18202c52531
 * provider record sha256 8251ee19014fb6dc325d3ae2d85493d0b8137a8d6bc216115a4212b2b0087ca9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167894(int param_1,int param_2,undefined4 param_3)

{
  func_0x800667d4(*(int *)(param_1 + 0x234) + param_2 * 0x178 + 0x4c,param_3,
                  1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x400);
  return;
}
