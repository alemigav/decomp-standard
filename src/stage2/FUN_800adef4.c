/* FUN_800adef4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800adef4  body 0x800adef4..0x800adf53  size 96 B
 * body sha256 9aa0cf6362cb9ee1eff1a697c53e607d25fe788887810b414f6716cd90c88394
 * provider record sha256 89e324dd478b4bd4cd9b80804cff80d806efbe183aede6dda428c3fd8b75fa16
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800adef4(undefined2 param_1)

{
  undefined4 uVar1;
  
  _DAT_8014e12c = param_1;
  _DAT_8014e130 = (undefined4 *)FUN_800ab43c(0x8014e128,0x8014e1e0,_DAT_8014e1d0,8,&LAB_800ae164);
  if (_DAT_8014e130 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *_DAT_8014e130;
  }
  return uVar1;
}
