/* FUN_800752dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800752dc  body 0x800752dc..0x800755bf  size 740 B
 * body sha256 6d3e5ba1e1b80f73be0655f368855a766480761d080a4a89ea5f307da2851004
 * provider record sha256 ae2ff23f644f6dfcf97e6316e2ed2d76f38152e1b296a7169b8b59e21ca2e158
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800752dc(undefined2 param_1,ushort param_2,short param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  ushort local_58 [20];
  ushort local_30;
  
  uVar5 = DAT_8011a708;
  uVar4 = DAT_8011a704;
  uVar3 = DAT_8011a700;
  iVar9 = 0;
  local_30 = param_2;
  if (param_2 < 4) {
    uVar8 = 0;
    uVar3 = DAT_8011a708;
    uVar5 = DAT_8011a700;
    while ((DAT_8011a700 = uVar5, DAT_8011a704 = uVar4, DAT_8011a708 = uVar3, _DAT_8013a168 != 0 &&
           (uVar7 = _DAT_8013a168 - 1, 3 < *(ushort *)(uVar7 * 4 + -0x7fec5ebe)))) {
      _DAT_8013a168 = (ushort)uVar7;
      iVar6 = (uVar7 & 0xffff) * 4;
      local_58[(uint)uVar8 * 2] = *(ushort *)(iVar6 + -0x7fec5ec0);
      uVar1 = *(ushort *)(iVar6 + -0x7fec5ebe);
      local_58[(uint)uVar8 * 2 + 1] = uVar1;
      if ((uVar1 < 4) && (iVar9 == 0)) {
        if (param_3 != 0) {
          FUN_8004cd88(1);
        }
        iVar9 = func_0x800072e0();
      }
      uVar8 = uVar8 + 1;
      FUN_800a8a04();
      uVar3 = DAT_8011a708;
      uVar4 = DAT_8011a704;
      uVar5 = DAT_8011a700;
    }
    *(undefined2 *)((uint)_DAT_8013a168 * 4 + -0x7fec5ec0) = param_1;
    *(ushort *)((uint)_DAT_8013a168 * 4 + -0x7fec5ebe) = local_30;
    _DAT_8013a168 = _DAT_8013a168 + 1;
    FUN_800a86a0(uVar5,param_1,uVar4,uVar3,DAT_8011a70c);
    while (uVar8 != 0) {
      uVar8 = uVar8 - 1;
      uVar1 = local_58[(uint)uVar8 * 2];
      uVar7 = (uint)_DAT_8013a168;
      *(ushort *)(uVar7 * 4 + -0x7fec5ec0) = uVar1;
      uVar2 = local_58[(uint)uVar8 * 2 + 1];
      _DAT_8013a168 = _DAT_8013a168 + 1;
      *(ushort *)(uVar7 * 4 + -0x7fec5ebe) = uVar2;
      if ((3 < uVar2) && (iVar9 != 0)) {
        func_0x80007300(iVar9);
        iVar9 = 0;
        if (param_3 != 0) {
          FUN_8004cd88(1);
        }
      }
      FUN_800a86a0(DAT_8011a700,uVar1,DAT_8011a704,DAT_8011a708,DAT_8011a70c);
    }
    uVar7 = 0;
    if (iVar9 != 0) {
      func_0x80007300(iVar9);
      uVar7 = 0;
      if (param_3 != 0) {
        uVar7 = FUN_8004cd88(1);
      }
    }
  }
  else if (_DAT_8013a168 < 10) {
    *(undefined2 *)((uint)_DAT_8013a168 * 4 + -0x7fec5ec0) = param_1;
    *(ushort *)((uint)_DAT_8013a168 * 4 + -0x7fec5ebe) = param_2;
    _DAT_8013a168 = _DAT_8013a168 + 1;
    FUN_800a86a0(uVar3,param_1,uVar4,uVar5,DAT_8011a70c);
    uVar7 = (uint)_DAT_8013a168;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}
