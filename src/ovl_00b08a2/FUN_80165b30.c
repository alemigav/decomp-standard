/* FUN_80165b30
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80165b30  body 0x80165b30..0x80165b77  size 72 B
 * body sha256 dc355f13f9642fa0206d365dac03eefb0a5c2c123eaa786c03f4f377bdfb5829
 * provider record sha256 d98bf106730589f7a46705a3328a41e9d60a28caaa1aa4e5687962562121a196
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165b30(int param_1)

{
  (*(code *)(&PTR_FUN_801672b4)[(*(byte *)(param_1 + 5) - 1) * 9 + (uint)*(byte *)(param_1 + 0x26e)]
  )();
  return;
}
