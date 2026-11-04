/* FUN_8007d970
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d970  body 0x8007d970..0x8007d9df  size 112 B
 * body sha256 c9c6e77c7c07a5949d08b43a9804cfd38e531aba7ad7bc746eb0fc5e8ed70846
 * provider record sha256 9908b1bef492a54e945fa5f1d94ddc20869bacfe4520080fd1390ff40fc9598b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d970(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032e74(param_1,DAT_800e1158,DAT_800e1160,0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  else {
    FUN_80032dbc(param_1,DAT_800e1158,DAT_800e1160,0x50);
  }
  return;
}
