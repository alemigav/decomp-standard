/* FUN_800a3374
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a3374  body 0x800a3374..0x800a34b7  size 324 B
 * body sha256 8cf5d8cda4c8a1bc5751dba62b8726379fc9ae526ebfa811532e56409f48f43e
 * provider record sha256 6bf46176526494aa1c81c3d6a92381355c1967b20264253747d2c9163c3095b5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800a3374(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = _DAT_80143f88;
  piVar5 = _DAT_80143f84;
  while( true ) {
    if (piVar5 == (int *)0x0) {
      piVar5 = _DAT_80143f84;
      if (_DAT_80143f88 == (int *)0x0) {
        while ((piVar6 = piVar5, piVar6 != (int *)0x0 && (*(short *)(piVar6 + 4) != 0))) {
          piVar5 = (int *)*piVar6;
        }
      }
      else {
        _DAT_80143f88 = (int *)*_DAT_80143f88;
        if (_DAT_80143f88 != (int *)0x0) {
          _DAT_80143f88[1] = 0;
        }
        if (_DAT_80143f84 != (int *)0x0) {
          _DAT_80143f84[1] = (int)piVar6;
        }
        piVar5 = _DAT_80143f84;
        _DAT_80143f84 = piVar6;
        *piVar6 = (int)piVar5;
      }
      uVar1 = _DAT_80143fdc;
      *(undefined2 *)(piVar6 + 4) = 2;
      piVar6[3] = param_1;
      _DAT_80143fd0 = _DAT_80143fd0 + 0xc;
      _DAT_80143fdc = FUN_80135cb0(uVar1);
      iVar2 = _DAT_80143fec;
      uVar4 = (uint)_DAT_80143fcc;
      puVar3 = (undefined4 *)(uVar4 * 0xc + _DAT_80143fec);
      puVar3[1] = param_1;
      *puVar3 = 0x100;
      _DAT_80143fcc = _DAT_80143fcc + 1;
      *(int *)(uVar4 * 0xc + iVar2 + 8) = piVar6[2];
      return piVar6[2];
    }
    if (piVar5[3] == param_1) break;
    piVar5 = (int *)*piVar5;
  }
  *(undefined2 *)(piVar5 + 4) = 2;
  return piVar5[2];
}
