/* FUN_80163c44
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163c44  body 0x80163c44..0x80163c8f  size 76 B
 * body sha256 e1cecc1b9da54933bc37e4730bf13e5767ff85fa7ea4705df3c9cdc8ed9020f9
 * provider record sha256 9d0c3261bc2cbbae33ab827ff8993f0762b5c1f663440977f82b814c6b98568e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163c44(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80163e68,param_2);
  func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80163ed4,uVar1);
  return;
}
