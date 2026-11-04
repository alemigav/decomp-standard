/* FUN_80164d18
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164d18  body 0x80164d18..0x80164e0b  size 244 B
 * body sha256 6c4c383913c29aa1aac831cefc32a543caa3db5485f6d620e7a762d079fcdf66
 * provider record sha256 a1d97f6b92d97f3152b7c90919dcc0c785b98e63dca293a1e77ce6d92d012477
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164d18(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x20);
      if (*(short *)(param_1 + 0x270) == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 5) = 1;
      *(undefined2 *)(param_1 + 6) = 0;
      *(undefined1 *)(param_1 + 0x2c9) = 0;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfff;
      *(undefined1 *)(param_1 + 0x2be) = 0x2d;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 500) = 0x33;
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x10040);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x7f00;
    *(undefined1 *)(param_1 + 7) = 2;
  }
  if (*(short *)(param_1 + 500) != 0) {
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
    *(undefined1 *)(param_1 + 0x2c1) = 4;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
  }
  return;
}
