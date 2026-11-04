/* FUN_801624e8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801624e8  body 0x801624e8..0x80162563  size 124 B
 * body sha256 eaad6aff537a150c0271a211c24e60824eb4ff44e1e5d2f6616c3ad2dc68bfac
 * provider record sha256 fe4ecb07fa02e3affb774187f20cf2377f2f2cff7a57b78b472e27d25cc67bd6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801624e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(&DAT_801671b8 + (uint)*(byte *)(param_1 + 5) * 4))();
  (**(code **)(&DAT_801671b8 + (uint)*(byte *)(param_1 + 5) * 4))(param_1,param_2,param_3);
  return;
}
