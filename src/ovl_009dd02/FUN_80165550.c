/* FUN_80165550
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165550  body 0x80165550..0x801655bb  size 108 B
 * body sha256 21da2b024dcea117d48d66dcf69148a62305e7deb33ff8e5239c4fdd3176cea7
 * provider record sha256 1b4cb4a85b31d4f6239ad1206d10a716ca6e37648a0a1995080f325878fd772d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165550(int param_1)

{
  (*(code *)(&PTR_FUN_80167344)[*(byte *)(param_1 + 5) - 1])();
  func_0x800347b0(param_1,(int)(((uint)*(ushort *)(param_1 + 0x66) +
                                (uint)*(byte *)(param_1 + 0x2cd) * 0x800) * 0x10000) >> 0x10);
  func_0x80035b84(param_1);
  return;
}
