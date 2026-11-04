/* FUN_80171540
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x80171540  body 0x80171540..0x8017176f  size 560 B
 * body sha256 52adc87ad6164bcb0253bb2ae40406c85e127a5826fca2c0714f162e6cb9916a
 * provider record sha256 aff2078532449ccfa1fdcf271ab9dda3a3fd8ba0eacf1b8ee8340926257e8b9b
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80171540(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int local_30 [2];
  
  uVar10 = 0;
  DAT_80172378 = 0xffffffff;
  func_0x800274e4(1,0);
  uVar9 = 0;
  puVar3 = &DAT_80171ce4;
  do {
    uVar9 = uVar9 + 1;
    uVar10 = uVar10 + puVar3[1];
    puVar3 = puVar3 + 3;
  } while (uVar9 < 9);
  for (uVar9 = 0; uVar9 < uVar10; uVar9 = uVar9 + 1) {
    if (DAT_800c56f4 == '\0') {
      puVar8 = _DAT_8010b6e4;
      puVar3 = _DAT_8010b6e0;
    }
    else {
      puVar8 = _DAT_8010b6e0;
      puVar3 = _DAT_8010b6e4;
    }
    puVar3 = (undefined4 *)((int)puVar3 + _DAT_801137d8 * 2);
    uVar4 = (uint)(_DAT_801137d8 * (_DAT_801137dc + -1)) >> 2;
    uVar7 = 0;
    if (uVar4 != 0) {
      puVar6 = puVar8;
      do {
        uVar5 = puVar3[1];
        *puVar6 = *puVar3;
        puVar6[1] = uVar5;
        uVar5 = puVar3[3];
        puVar6[2] = puVar3[2];
        puVar6[3] = uVar5;
        uVar5 = puVar3[5];
        uVar7 = uVar7 + 4;
        puVar6[4] = puVar3[4];
        puVar6[5] = uVar5;
        puVar1 = puVar3 + 6;
        uVar5 = puVar3[7];
        puVar3 = puVar3 + 8;
        puVar6[6] = *puVar1;
        puVar6[7] = uVar5;
        puVar6 = puVar6 + 8;
      } while (uVar7 < uVar4);
    }
    local_30[0] = (int)puVar8 + (_DAT_801137d8 * _DAT_801137dc - _DAT_801137d8) * 2;
    iVar2 = FUN_801713b0(uVar9);
    if (iVar2 == 1) {
      FUN_80171320(local_30,&DAT_8017237c);
    }
    else if (iVar2 == 0) {
      FUN_801712bc(local_30,&DAT_8017237c);
    }
    else if (iVar2 == 2) {
      FUN_8017138c(local_30);
    }
    func_0x8004cd88(1);
    FUN_801714e0(uVar9);
  }
  _DAT_800df8b0 = func_0x800241e0(_DAT_800df8b0);
  func_0x8004cd88(1);
  return;
}
