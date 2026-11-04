/* FUN_80163a24
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163a24  body 0x80163a24..0x80163a6f  size 76 B
 * body sha256 46611981917e0cd9d2297e4b0412fd8c309fa4cc115ea6471e7a6f1b7ea7a9a5
 * provider record sha256 c0867f17fb7e684183ca712f65bfb8ff7399023dd547f2459580dce906e89d07
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163a24(int param_1)

{
  (*(code *)(&PTR_FUN_801672c4)[*(byte *)(param_1 + 6)])();
  *(undefined1 *)(param_1 + 0x2d6) = 1;
  *(undefined1 *)(param_1 + 0x2d7) = 1;
  return;
}
