/* FUN_80165e14
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165e14  body 0x80165e14..0x80165e8f  size 124 B
 * body sha256 914da8e1b040a3522e4461faacca7b13e4e649c509c279c8daba7dd61c942b48
 * provider record sha256 4f875a53d8d87f9cd95b5961aafb1345e23ef985f6b2b1594f6a90eff348e71a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80165e14(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (uint)*(ushort *)(param_1 + 0x2b6) - (*(ushort *)(param_1 + 0x66) & 0xfff);
  iVar1 = iVar3 * 0x10000 >> 0x10;
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = -iVar1;
  }
  if (iVar2 < param_2) {
    return 1;
  }
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (0x7ff < iVar1) {
    iVar3 = -iVar3;
  }
  if (iVar3 << 0x10 < 1) {
    param_2 = -param_2;
  }
  *(ushort *)(param_1 + 0x66) = *(ushort *)(param_1 + 0x66) + param_2;
  return 0;
}
