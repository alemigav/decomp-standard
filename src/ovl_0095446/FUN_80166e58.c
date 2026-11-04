/* FUN_80166e58
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80166e58  body 0x80166e58..0x80166e9b  size 68 B
 * body sha256 a7080bbb0d2ba976db5e0551fe6ba8e19956ba83096682258870d320ad3d5842
 * provider record sha256 d0b00ba29ab7c414831af65448b7894146bfdbbdccb5b0bb6df48c4fd141dc29
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166e58(int param_1)

{
  if ((*(ushort *)(param_1 + 0x2ba) & 0x2000) == 0) {
    FUN_80166e9c();
  }
  else {
    *(undefined2 *)(param_1 + 0x1f2) = 0;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
    FUN_801626f4();
  }
  return;
}
