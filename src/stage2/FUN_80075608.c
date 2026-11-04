/* FUN_80075608
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075608  body 0x80075608..0x80075877  size 624 B
 * body sha256 aedaa160055056b335a6b8ed228e0676b99136f5026bc66c8dd7d8e47c312464
 * provider record sha256 c1ca466ae56e4686db3a53e14be58c8ae0fb2ca23b1ec24696a6ec139f820644
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_80075608(short param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  ushort local_50 [20];
  
  iVar6 = 0;
  uVar5 = 0;
  if (_DAT_8013a168 == 0) {
    uVar5 = 0;
  }
  else {
    do {
      uVar4 = _DAT_8013a168 - 1;
      if (*(short *)(uVar4 * 4 + -0x7fec5ebe) == param_1) break;
      _DAT_8013a168 = (ushort)uVar4;
      iVar3 = (uVar4 & 0xffff) * 4;
      local_50[(uint)uVar5 * 2] = *(ushort *)(iVar3 + -0x7fec5ec0);
      uVar1 = *(ushort *)(iVar3 + -0x7fec5ebe);
      local_50[(uint)uVar5 * 2 + 1] = uVar1;
      if ((uVar1 < 4) && (iVar6 == 0)) {
        if (param_2 != 0) {
          FUN_8004cd88(1);
        }
        iVar6 = func_0x800072e0();
      }
      uVar5 = uVar5 + 1;
      FUN_800a8a04();
    } while (_DAT_8013a168 != 0);
    if ((_DAT_8013a168 != 0) && (*(short *)((_DAT_8013a168 - 1) * 4 + -0x7fec5ebe) == param_1)) {
      FUN_800a8a04();
      _DAT_8013a168 = _DAT_8013a168 - 1;
    }
    if (_DAT_8013a168 == 0xffff) {
      _DAT_8013a168 = 0;
    }
    while (uVar5 != 0) {
      uVar5 = uVar5 - 1;
      uVar4 = (uint)_DAT_8013a168;
      uVar1 = local_50[(uint)uVar5 * 2];
      _DAT_8013a168 = _DAT_8013a168 + 1;
      *(ushort *)(uVar4 * 4 + -0x7fec5ec0) = uVar1;
      uVar2 = local_50[(uint)uVar5 * 2 + 1];
      *(ushort *)(uVar4 * 4 + -0x7fec5ebe) = uVar2;
      if ((3 < uVar2) && (iVar6 != 0)) {
        func_0x80007300(iVar6);
        iVar6 = 0;
        if (param_2 != 0) {
          FUN_8004cd88(1);
        }
      }
      FUN_800a86a0(DAT_8011a700,uVar1,DAT_8011a704,DAT_8011a708,DAT_8011a70c);
    }
    if ((iVar6 != 0) && (func_0x80007300(iVar6), param_2 != 0)) {
      FUN_8004cd88(1);
    }
    uVar5 = _DAT_8013a168;
  }
  return uVar5;
}
