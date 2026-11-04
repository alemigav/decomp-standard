/* FUN_800b3f54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3f54  body 0x800b3f54..0x800b40c3  size 368 B
 * body sha256 a72b4065560028c50721577ff9939e9c8afc9e04f079b4c243634d275911b45d
 * provider record sha256 4c593831459712d6b806a53cb18e74875035a84cf545e5d165f80def96dba389
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800b3f54(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  
  if (DAT_80136d80 != '\0') {
    if ((_DAT_8015af7c != (undefined4 *)0x0) && (DAT_80136d81 != '\0')) {
      (*_DAT_8014400c)();
    }
    if (((uint)param_1 & 0xf0000000) == 0x80000000) {
      _DAT_8015af74 = param_1;
      _DAT_8015af78 = (*_DAT_80144004)(param_2);
      DAT_80136d81 = 0;
      _DAT_8015af7c = param_1 + 1;
      _DAT_8015af80 = *param_1;
      return 1;
    }
    _DAT_8015af74 = (undefined4 *)(*_DAT_80144004)(param_1);
    _DAT_8015af78 = (int)_DAT_8015af74;
    piVar1 = (int *)(*_DAT_80144008)(4,0);
    if (piVar1 != (int *)0x0) {
      FUN_800b467c(piVar1,_DAT_8015af74,4);
      _DAT_8015af80 = *piVar1;
      (*_DAT_8014400c)();
      _DAT_8015af7c = (undefined4 *)(*_DAT_80144008)(_DAT_8015af80 << 2,0);
      if (_DAT_8015af7c != (undefined4 *)0x0) {
        FUN_800b467c(_DAT_8015af7c,(int)_DAT_8015af74 + 4,_DAT_8015af80 << 2);
        DAT_80136d81 = 1;
        return 1;
      }
    }
  }
  return 0;
}
