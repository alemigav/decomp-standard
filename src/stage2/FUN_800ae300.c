/* FUN_800ae300
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae300  body 0x800ae300..0x800ae3cf  size 208 B
 * body sha256 3e088885963a01bcdb89a4feb3283508dd92b46cf634a4dddf922989e67f8e57
 * provider record sha256 ede10a33b54f68d908d85ed641a295d5540199537a23eeb80d7cf56d3cb10a8f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800ae300(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  piVar3 = _DAT_80158434;
  uVar5 = _DAT_80158220;
  do {
    _DAT_80158220 = uVar5;
    uVar5 = _DAT_80158220 + 1;
  } while (_DAT_80158220 == 0xffffffff);
  uVar4 = _DAT_80158220 + 1;
  piVar1 = (undefined4 *)0x0;
  uVar5 = _DAT_80158220;
  for (piVar2 = _DAT_80158430;
      (_DAT_80158220 = uVar4, piVar2 != (int *)0x0 && ((uint)piVar2[2] <= uVar5));
      piVar2 = (int *)*piVar2) {
    uVar4 = _DAT_80158220;
    if (piVar2[2] == uVar5) {
      do {
        _DAT_80158220 = uVar4;
        uVar4 = _DAT_80158220 + 1;
      } while (_DAT_80158220 == 0xffffffff);
      uVar5 = _DAT_80158220;
      _DAT_80158220 = _DAT_80158220 + 1;
    }
    else {
    }
    uVar4 = _DAT_80158220;
    piVar1 = piVar2;
  }
  if (_DAT_80158434 == (int *)0x0) {
    return 0xffffffff;
  }
  _DAT_80158434 = (int *)*_DAT_80158434;
  if (_DAT_80158434 != (int *)0x0) {
    *(undefined4 *)((int)_DAT_80158434 + 4) = 0;
  }
  if (piVar1 == (undefined4 *)0x0) {
    _DAT_80158430 = piVar3;
  }
  else {
    *piVar1 = (int)piVar3;
  }
  piVar3[1] = (int)piVar1;
  *piVar3 = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    piVar2[1] = (int)piVar3;
  }
  piVar3[2] = uVar5;
  piVar3[3] = *(int *)(param_1 + 0x60);
  *(int **)(param_1 + 0x18) = piVar3;
  return uVar5;
}
