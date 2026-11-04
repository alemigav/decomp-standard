/* FUN_80165444
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165444  body 0x80165444..0x801654df  size 156 B
 * body sha256 e0286d3fc07abab8cc28a72ed57b3668289d9d893691cfeacfcdd2b4c427c85c
 * provider record sha256 655b22d323ead7f6f0ee2ac338cff6c9747f45fea27424ea4bf4a9c4df77d97f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165444(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = func_0x80033604();
  FUN_80166b98(param_1,(&DAT_80167230)[uVar1 & 0xf],10);
  uVar1 = func_0x80033604();
  FUN_80166b98(param_1,(&DAT_80167230)[uVar1 & 0xf],10);
  *(undefined1 *)(param_1 + 0x2d8) = 0xf;
  FUN_80164e88(param_1,param_2,param_3);
  return;
}
