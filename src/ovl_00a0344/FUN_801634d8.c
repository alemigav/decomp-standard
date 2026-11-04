/* FUN_801634d8
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801634d8  body 0x801634d8..0x80163577  size 160 B
 * body sha256 35f4327b562349d49c6a6466370998db044086b782ce7dca2e6b0bdd82b9cc39
 * provider record sha256 22806b63796d2d13b8c8cd7119f01b7db7eab3614a45de5f401ffea17e50474d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801634d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_80163d50 < 4) {
    DAT_80163d50 = DAT_80163d50 + 1;
  }
  else {
    func_0x80083758(0x800e8d00,0x14);
  }
  *(undefined2 *)(param_1 + 0x1f2) = 1;
  *(uint *)(param_1 + 4) =
       CONCAT11(*(undefined1 *)(param_1 + 0x2c9),*(undefined1 *)(param_1 + 0x2ca)) + 0x1090000;
  FUN_8016289c(param_1,param_2,param_3);
  return;
}
