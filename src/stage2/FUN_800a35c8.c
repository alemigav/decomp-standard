/* FUN_800a35c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a35c8  body 0x800a35c8..0x800a365f  size 152 B
 * body sha256 3f6a9723dedf9913cd055aea522a142b1664e3651793b44a9c0cc8e85573af4b
 * provider record sha256 84b9853572b4c317d84e87973d3ec889fac21e1bbf0e25f703e9c6464d4aae76
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_800a35c8(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = _DAT_80143f9c;
  puVar1 = _DAT_80143f98;
  if (_DAT_80143f9c == (int *)0x0) {
    *(undefined4 *)(*_DAT_80143f94 + 4) = 0;
    iVar3 = *_DAT_80143f94;
    _DAT_80143f98 = _DAT_80143f94;
    *puVar1 = _DAT_80143f94;
    _DAT_80143f94[1] = (int)puVar1;
    *_DAT_80143f94 = 0;
    piVar2 = _DAT_80143f94;
    _DAT_80143f94 = (int *)iVar3;
    return piVar2;
  }
  _DAT_80143f9c = (int *)*_DAT_80143f9c;
  if (_DAT_80143f9c != (int *)0x0) {
    *(undefined4 *)((int)_DAT_80143f9c + 4) = 0;
  }
  if (_DAT_80143f98 == (undefined4 *)0x0) {
    *piVar2 = (int)_DAT_80143f94;
    if (_DAT_80143f94 != (int *)0x0) {
      _DAT_80143f94[1] = (int)piVar2;
    }
    _DAT_80143f94 = piVar2;
  }
  else {
    *piVar2 = 0;
    piVar2[1] = (int)_DAT_80143f98;
    *_DAT_80143f98 = (int)piVar2;
  }
  _DAT_80143f98 = piVar2;
  return piVar2;
}
