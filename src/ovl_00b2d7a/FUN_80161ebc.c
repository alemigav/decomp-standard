/* FUN_80161ebc
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80161ebc  body 0x80161ebc..0x80161ef3  size 56 B
 * body sha256 98fc958dd9e6d26378bf6bfe708499dd37c146d4ae01a2a2878efd90bbb8eeb6
 * provider record sha256 dbe635c4719264d3f9995d458b53510a1bbfa9c72ffae0cfa4204cc41e47e892
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161ebc(int param_1)

{
  (*(code *)(&PTR_FUN_80162610)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
