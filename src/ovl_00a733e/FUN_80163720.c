/* FUN_80163720
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163720  body 0x80163720..0x80163823  size 260 B
 * body sha256 033a46418b2add78b658e7f425dd89c61f1f74dae7fac47e64b43b16d18a7054
 * provider record sha256 5eea8056442b1e8d1f046f00db5d12a9e9f4509cd2267771ef1c47c635709a07
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163720(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar1 = 0x8260000;
    if (*(short *)(param_1 + 0x2b6) == 0) {
      uVar1 = 0x72e0000;
    }
    *(uint *)(param_1 + 0x1e8) = uVar1 | 0xf00;
    iVar2 = (int)(short)(&DAT_80167d6c)[*(short *)(param_1 + 0x2b6) * 2];
    FUN_80167374(param_1,iVar2 + 1U & 0xff,6);
    FUN_80167374(param_1,iVar2 + 2U & 0xff,6);
    FUN_80167374(param_1,iVar2 + 3U & 0xff,6);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + *(short *)(param_1 + 0x2b6) + 0x2b8) = 0x1e;
    FUN_801631d4(param_1);
    *(undefined1 *)(param_1 + 0x2c0) = 0;
  }
  return;
}
