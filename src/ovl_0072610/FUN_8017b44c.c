/* FUN_8017b44c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b44c  body 0x8017b44c..0x8017b4d3  size 136 B
 * body sha256 d69e56953245036a8d1f64dc70b9d7c5f629d8a58984d5ab11491825911d5f48
 * provider record sha256 a8ae5433df35cfbc9ce828649914a10017338f3f9742c263411e8eb2a3dde22b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b44c(undefined4 param_1)

{
  if (DAT_80184b28 == 0) {
    func_0x80007320(DAT_80184b24,0x1000);
    func_0x80004ee0(param_1,DAT_80184b24,DAT_80184b20,0x1000,0,
                    "biniosim_refresh_buffer: read error.");
    DAT_80184b28 = 0x1000;
    DAT_80184b20 = DAT_80184b20 + 0x1000;
  }
  return;
}
