/* FUN_80162cf8
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162cf8  body 0x80162cf8..0x80162d3b  size 68 B
 * body sha256 4d45e393875bab6a3a4169c61d9a05ee303d46b4417d103cd6e6ec86720aee9d
 * provider record sha256 dae2778a32a377501ffce830c6bbfcb384d0de349dbb68e67a8c7493a59d631c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162cf8(undefined4 param_1)

{
  char cVar1;
  
  _DAT_800e1134 = 0x2000000;
  _DAT_800e1380 = param_1;
  cVar1 = func_0x80033144(param_1,&DAT_800e1130);
  cVar1 = DAT_800e1135 + cVar1;
  _DAT_800e1135 = CONCAT12(cVar1,DAT_800e1134_1._1_2_);
  return;
}
