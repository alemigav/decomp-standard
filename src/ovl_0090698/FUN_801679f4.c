/* FUN_801679f4
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801679f4  body 0x801679f4..0x80167a5f  size 108 B
 * body sha256 7c44a7e056416b71df2568794fff0914eeda10acc2b78fcb74a2fd16d245ff20
 * provider record sha256 de0e5f2dbb58b0afcf6dcf7fc22362bb0adccee84c71daf85cc164cb0c4bf5b5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_801679f4(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)*(short *)(param_1 + 0x1a8);
  iVar1 = (int)*(short *)(param_1 + 0x25e);
  if (iVar2 < iVar1) {
    if (iVar2 <= *(int *)(param_1 + 0x2c) + param_2) {
      *(int *)(param_1 + 0x2c) = iVar2 + param_4;
      *(undefined1 *)(param_1 + 0x2d6) = 0xff;
      return 0xffffffff;
    }
  }
  else if (iVar1 <= *(int *)(param_1 + 0x2c) + param_2) {
    *(int *)(param_1 + 0x2c) = iVar1 + param_3;
    *(undefined1 *)(param_1 + 0x2d6) = 1;
    return 1;
  }
  return 0;
}
