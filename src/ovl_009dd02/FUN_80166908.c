/* FUN_80166908
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166908  body 0x80166908..0x8016695f  size 88 B
 * body sha256 633d5beffbb3b6067757325e8add7800118b32e554cabdd519bbd85260eec4f5
 * provider record sha256 99f8459a8704e6056935d453fc7f634e763c1416723656d43b37c5a574133116
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166908(int param_1,char param_2)

{
  *(undefined1 *)(param_1 + 4) = 2;
  *(char *)(param_1 + 5) = param_2 + '\x02';
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  func_0x80052bd0(3,0);
  func_0x80052c6c(8,200,0);
  return;
}
