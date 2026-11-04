/* FUN_80166ee0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166ee0  body 0x80166ee0..0x80166f43  size 100 B
 * body sha256 15f96e3fb6fedc91234a7b1242bf7328618c4aa54de366ab45553f48732c74ec
 * provider record sha256 8f77b2989b14fafcf6e8e3a1a110790a6c7a1316093e848fd0de4ed9af5f0ef7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80166ee0(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  uVar2 = sVar1 - *(short *)(param_1 + 0x66) & 0xfff;
  if (0x800 < uVar2) {
    uVar2 = uVar2 | 0xf000;
  }
  return (int)(short)uVar2;
}
