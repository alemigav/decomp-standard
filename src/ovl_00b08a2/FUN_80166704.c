/* FUN_80166704
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80166704  body 0x80166704..0x801667a3  size 160 B
 * body sha256 8af939cdacfc6ad16a4b1abe5e51c89879bb56b1ddf9f2fdd7f560fc21d8c68c
 * provider record sha256 3e94a8a5a60950042b0e25189c489e9b006f15d45ce91318ccb4926cf5f801f4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166704(int param_1,short param_2,int param_3,int param_4)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  
  iVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2e),
                          (int)((uint)*(ushort *)(param_1 + 0x32) * -0x10000) >> 0x10,(int)param_2,
                          param_3 * -0x10000 >> 0x10);
  uVar3 = param_4 + (iVar1 - (uint)*(ushort *)(param_1 + 100)) & 0xfff;
  if ((int)uVar3 < (param_4 << 0x10) >> 0xf) {
    *(short *)(param_1 + 100) = (short)iVar1;
  }
  else {
    sVar2 = *(ushort *)(param_1 + 100) - (short)param_4;
    *(short *)(param_1 + 100) = sVar2;
    if (uVar3 < 0x801) {
      *(short *)(param_1 + 100) = sVar2 + (short)param_4 * 2;
    }
  }
  return;
}
