/* FUN_800ada34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ada34  body 0x800ada34..0x800adb47  size 276 B
 * body sha256 d1ef6aba36322f29a1611db28f997b30ccb6a806659a3bbcd528e3c38dcdbbde
 * provider record sha256 2f40b9789b804d3cbe983e2b844eace017d34283cd39c7e28b404bc5f41febd8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800ada34(undefined2 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  _DAT_8014e100 = param_1;
  if (0 < _DAT_8014e16c) {
    puVar3 = (undefined4 *)&DAT_8014e170;
    uVar2 = _DAT_8014e11c;
    do {
      _DAT_8014e11c = uVar2;
      iVar1 = FUN_800ab43c(&DAT_8014e100,*puVar3,*(undefined2 *)(puVar3 + 2),0x1c,&LAB_800ae154);
      if (iVar1 != 0) {
        _DAT_8014e11c = iVar1;
        *param_2 = *(undefined4 *)(iVar1 + 0xc);
        uVar2 = *(undefined4 *)(iVar1 + 8);
        _DAT_8014e120 = iVar1 + 0xc;
        param_2[2] = 0;
        param_2[1] = uVar2;
        param_2[4] = *(undefined4 *)(iVar1 + 0x14);
        param_2[3] = *(uint *)(iVar1 + 0x10) & 0xffffff;
        param_2[5] = *(undefined4 *)(iVar1 + 0x18);
        *(undefined1 *)(param_2 + 6) = *(undefined1 *)(iVar1 + 0x10);
        return 0;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 3;
      _DAT_8014e11c = 0;
      uVar2 = 0;
    } while (iVar4 < _DAT_8014e16c);
  }
  return 0xffffffff;
}
