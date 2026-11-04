/* FUN_801645e8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801645e8  body 0x801645e8..0x8016461b  size 52 B
 * body sha256 6eabed1e609117d5a24c4760fa4bd23bbfa76a16d6a86958209e04919ac6fdc9
 * provider record sha256 bc556afe09de75f5e81bbca408779e9665582516b319aa365bba15dd72e4142a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_801645e8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_1 + 0x2c2);
  if (*(char *)(param_1 + 0x2cc) == '\0') {
    uVar2 = -uVar2;
    uVar1 = 0;
  }
  else {
    uVar1 = (uint)*(byte *)(param_1 + 0x2cc);
  }
  return uVar1 * 0x400 + (((int)(uVar2 << 0x10) >> 0x10) - ((int)(uVar2 << 0x10) >> 0x12)) & 0xfff;
}
