/* FUN_80165858
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165858  body 0x80165858..0x801658eb  size 148 B
 * body sha256 52dfa175d002e547d3c9d593e3e58d5c9dcdeef7f10ef11edf90deeaa913c81a
 * provider record sha256 c0a0e5030c634d09e88c74dae7525fa0e4decbd6003da145f66da9cf77461c4e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165858(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = func_0x80033604();
  *(undefined4 *)((uVar1 & 0xf) * 0x178 + *(int *)(param_1 + 0x234) + 0x60) = 0x3f2f;
  *(undefined1 *)(param_1 + 699) = 1;
  FUN_80166980(param_1,uVar1 & 0xf,9);
  *(undefined1 *)(param_1 + 5) = 1;
  FUN_80164d5c(param_1,param_2,param_3);
  return;
}
