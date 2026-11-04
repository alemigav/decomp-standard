/* FUN_80162e00
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162e00  body 0x80162e00..0x80162ee3  size 228 B
 * body sha256 adc26e0f38a2224667dc057f014fd1877b0e5eb6d9df3417150c9b54fb8f7f36
 * provider record sha256 fa7f59ecef8fec6b5a99868faf38ca2abb95358173260975e604951ae38a3084
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162e00(int param_1,uint param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar3 = (param_3 & 0xff) * 6;
  sVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  iVar2 = *(int *)(param_1 + 0x234) + (param_2 & 0xff) * 0x178;
  local_18 = *(undefined2 *)(iVar2 + 0x4e);
  local_16 = *(undefined2 *)(iVar2 + 0x52);
  local_14 = *(undefined2 *)(iVar2 + 0x56);
  func_0x80037780(((byte)(&DAT_801630b0)[iVar3] & 0x7f) << 0x18 |
                  ((uint)(byte)(&DAT_801630b1)[iVar3] + (uint)*(ushort *)(&DAT_801630b2 + iVar3)) *
                  0x10000 | (uint)*(ushort *)(&DAT_801630b4 + iVar3),(int)sVar1,0x800e9028,&local_18
                 );
  return;
}
