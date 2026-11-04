/* FUN_80050e1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80050e1c  body 0x80050e1c..0x80050eb7  size 156 B
 * body sha256 74dba6b20cd32622336f242b65bf9a73747834a3d7aff137a65c6aa44e1ecea7
 * provider record sha256 80ff196899a29c867c5e29b938cc2ca1c54a1be33c3e7d0fe7c147f5175d2213
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80050e1c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = ((uint)*(ushort *)(param_1 + 0x2a) - (uint)DAT_800e1158._2_2_) * 0x10000;
  iVar1 = iVar2 >> 0x10;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar1 < 900) {
    DAT_8010bf80 = 0;
    DAT_8010bf84 = (short)(*(short *)(param_1 + 0x32) - DAT_800e1160._2_2_) >> 0xf | 1;
  }
  else {
    DAT_8010bf84 = 0;
    DAT_8010bf80 = (ushort)(iVar2 >> 0x1f) | 1;
  }
  DAT_8010bf88 = *(undefined2 *)(param_1 + 100);
  DAT_8010bf8c = *(undefined2 *)(param_1 + 0x68);
  return;
}
