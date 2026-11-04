/* FUN_80163bb8
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163bb8  body 0x80163bb8..0x80163c43  size 140 B
 * body sha256 32610a9861751cb952656f11dfd0a4c1bd48257ecb871d61a6d68e12f03d1fe1
 * provider record sha256 401d22331a65383b5adc8229c0668299be2f58c8c7f2e78006e56248893c5a25
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163bb8(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  iVar1 = (param_3 & 0xff) * 6;
  local_10 = 0;
  local_e = 0;
  local_c = 0;
  func_0x80037780((uint)(byte)(&DAT_80163e1c)[iVar1] << 0x18 |
                  (uint)(byte)(&DAT_80163e1d)[iVar1] << 0x10 |
                  (uint)*(ushort *)(&DAT_80163e20 + iVar1),(int)*(short *)(param_1 + 0x66),
                  *(int *)(param_1 + 0x234) + (param_2 & 0xff) * 0x178 + 0x38,&local_10);
  return;
}
