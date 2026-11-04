/* FUN_801623e4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801623e4  body 0x801623e4..0x80162443  size 96 B
 * body sha256 f165f54fc140342a692c6af35a99f4be7db9bee6d7aacd2970590e5413e7b8cf
 * provider record sha256 24f8e159f8f856d2481b767ecdb10309155dc937e8f8759a149723e7ac8c2c72
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801623e4(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(short *)(param_1 + 500) - 0x200;
  *(ushort *)(param_1 + 500) = uVar1;
  if ((int)((uint)uVar1 << 0x10) < 0) {
    *(undefined2 *)(param_1 + 500) = 0;
  }
  FUN_80167bd8(param_1,9,0,(int)*(short *)(param_1 + 500));
  FUN_80167bd8(param_1,6,0,(int)*(short *)(param_1 + 500));
  return;
}
