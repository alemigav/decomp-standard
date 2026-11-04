/* FUN_80162000
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162000  body 0x80162000..0x801620a3  size 164 B
 * body sha256 7f78abac60c4a19865fb67a95321f6e6fae73869bc8535b1e928e8ae17e37c86
 * provider record sha256 05587efb73faece104a7d4828e04fc3c52efb98518ee5942dadfd6dc6b292574
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162000(int param_1)

{
  int iVar1;
  int local_18 [2];
  int local_10;
  
  local_18[0] = (int)*(short *)(param_1 + 0x2d0);
  local_10 = (int)*(short *)(param_1 + 0x2d4);
  if (((*(ushort *)(param_1 + 0x2c8) & 0x10) == 0) &&
     (iVar1 = func_0x80036a30(param_1 + 0x28,local_18,0x30), iVar1 != 0)) {
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 0x10;
  }
  if (((*(ushort *)(param_1 + 0x2c8) & 0x20) == 0) &&
     (iVar1 = func_0x80036b2c(param_1 + 0x2c,(int)*(short *)(param_1 + 0x2d2),0x30), iVar1 != 0)) {
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 0x10;
  }
  func_0x800371a4(param_1,(uint)*(byte *)(param_1 + 0x2b4) << 10,0x20);
  return;
}
