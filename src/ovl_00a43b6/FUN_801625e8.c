/* FUN_801625e8
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801625e8  body 0x801625e8..0x80162663  size 124 B
 * body sha256 ad0bb1c426e1d069c9b5760361fadc3f813509900299f37be82f7b819d5bc676
 * provider record sha256 bd3405965d9f20e402d45009f2da04c1a272767f63ae1cc939f9dd65c4e4ccd1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801625e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_801697fc)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80169824)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
