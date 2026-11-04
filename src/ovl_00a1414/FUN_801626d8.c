/* FUN_801626d8
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x801626d8  body 0x801626d8..0x80162753  size 124 B
 * body sha256 107cca630c2f31484ce2c9ad3429a8145df8866a9c7e6c1f8b30c1ff0e847471
 * provider record sha256 2b1d6ab2570a23c8c4828d59d89598ffc063dd2c0abff4d45025e91e1e480446
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801626d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(&DAT_80168fd8 + (uint)*(byte *)(param_1 + 5) * 4))();
  (**(code **)(&DAT_80168fd8 + (uint)*(byte *)(param_1 + 5) * 4))(param_1,param_2,param_3);
  return;
}
