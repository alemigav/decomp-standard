/* FUN_8006bf48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bf48  body 0x8006bf48..0x8006bfc3  size 124 B
 * body sha256 543148b06798ed738bcebed23cecb375b69e78ce1d7b903e4d92ba6d19e94168
 * provider record sha256 bcff722255d72039cebdaa4e1a920a7ec245dbc74624e2a2dcb42bc53b3d825d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006bf48(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x800072e0();
  if (DAT_80112969 == '\x02') {
    if ((~_DAT_80139e60 & 0x80) == 0) {
      _DAT_80139e60 = _DAT_80139e60 | 0x100;
    }
    else {
      DAT_80112969 = '\x03';
    }
    FUN_8006bebc(param_1);
  }
  func_0x80007300(uVar1);
  return;
}
