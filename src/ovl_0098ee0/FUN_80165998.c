/* FUN_80165998
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165998  body 0x80165998..0x80165a1f  size 136 B
 * body sha256 f114faa21643935ccfbc9c97e47dd628c0a9e598f1e5f0b6e8003239dd7c7343
 * provider record sha256 c3d7e87aa6d15a9674954a24378f6b67455f7272b4252e62c25c3756668cd9e8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165998(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    *(char *)(param_1 + 0x2c5) = *(char *)(param_1 + 5);
    FUN_801623c8();
    *(undefined1 *)(param_1 + 5) = 0xff;
    FUN_8016592c(param_1);
  }
  (*(code *)(&PTR_FUN_801668dc)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
