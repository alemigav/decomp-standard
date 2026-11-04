/* FUN_80162438
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162438  body 0x80162438..0x801624b7  size 128 B
 * body sha256 8a56d2f99c743440a27a5423eb5b2c9567d1cc6144fabb375680672c3e3a2a99
 * provider record sha256 2e167f04e7f09bd2a5b9ee823ef3ec985a65ac578e4ef74dd90aebea6e6e9241
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162438(int param_1)

{
  short sVar1;
  
  sVar1 = func_0x80033024(&DAT_800e1158,
                          *(int *)(param_1 + 0x234) +
                          (uint)(byte)(&DAT_80163022)[(*(ushort *)(param_1 + 0x1aa) & 1) * 7] *
                          0x178 + 0x4c,900);
  if (sVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1030000;
  }
  return;
}
