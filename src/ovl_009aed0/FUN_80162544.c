/* FUN_80162544
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162544  body 0x80162544..0x801625a7  size 100 B
 * body sha256 58de8f060fb898ae969f754e962b924a07566c54d5360ccb7999e08f872279c8
 * provider record sha256 9cd8184e2a36ca3f7c4d78d5f18b672f7d44b77124c897ef6de2bd5ad3f86393
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80162544(int param_1)

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
