/* FUN_8016304c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016304c  body 0x8016304c..0x80163137  size 236 B
 * body sha256 cd79a18bc69c0d80aec55c1237650761dbc23fcc89c516513c65a3bec9f24f60
 * provider record sha256 9218940085eeb12f67a7a6147adf106f4f8d91f0aa4b26acb276a0d0a84c9717
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016304c(int param_1)

{
  short sVar1;
  uint uVar2;
  
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  sVar1 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          (int)*(char *)(param_1 + 0x2bf));
  if (_DAT_800e1322 < 0) {
    sVar1 = -sVar1;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar1;
  *(undefined2 *)(param_1 + 100) =
       *(undefined2 *)(&LAB_801666e4 + (*(ushort *)(param_1 + 500) & 0xe));
  uVar2 = 0x4b;
  if ((*(byte *)(param_1 + 0x2bd) & 1) != 0) {
    uVar2 = 0x32;
  }
  *(short *)(param_1 + 0x1e0) = (short)uVar2;
  if ((**(uint **)(param_1 + 0x214) & 0x10000) == 0) {
    *(short *)(param_1 + 0x1e0) = (short)(uVar2 >> 1);
  }
  func_0x80032b5c(param_1,0);
  return;
}
