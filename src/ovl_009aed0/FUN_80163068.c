/* FUN_80163068
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80163068  body 0x80163068..0x801630af  size 72 B
 * body sha256 5943311edd24a3be65de66a01e16ea1d0a2712ad423cfbbf91c4a9128147ff6b
 * provider record sha256 48d225cb3dcdc56ce74319056337de6661f10f8f564dd725bd61850836ea27ae
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163068(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = param_2 * 0x178 + *(int *)(param_1 + 0x234);
  *(uint *)(iVar1 + 0x60) =
       *(uint *)(iVar1 + 0x60) & 0xff000000 | param_5 << 0x10 | param_4 << 8 | param_3;
  return;
}
