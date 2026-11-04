/* FUN_80167bd8
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80167bd8  body 0x80167bd8..0x80167c1b  size 68 B
 * body sha256 f36de3a4946cd344c96b0bc93408334b58d09802bb92d916caa547267ca541d6
 * provider record sha256 584c63012f7ecf3752a269a60d3280a4bcd5a5fbafd2da09afe7a3ba8b098f62
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167bd8(int param_1,int param_2,int param_3,undefined2 param_4)

{
  *(undefined2 *)(param_3 * 4 + *(int *)(*(int *)(param_1 + 0x234) + param_2 * 0x178 + 0x120) + 0xc)
       = param_4;
  func_0x80066288();
  return;
}
