/* FUN_800adf54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800adf54  body 0x800adf54..0x800adfb3  size 96 B
 * body sha256 7aed1748e7193937791a7bd7d215abbb21b03021dd302bbe5d40ad416240013d
 * provider record sha256 b39e84dedcb44c886ad875574a745cadd6bd8478dd868c744f28f4ef8751b754
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800adf54(undefined2 param_1)

{
  undefined4 uVar1;
  
  _DAT_8014e13c = param_1;
  _DAT_8014e140 = (undefined4 *)FUN_800ab43c(0x8014e138,0x801521f0,_DAT_801521e0,8,&LAB_800ae164);
  if (_DAT_8014e140 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *_DAT_8014e140;
  }
  return uVar1;
}
