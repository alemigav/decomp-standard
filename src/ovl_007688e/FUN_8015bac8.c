/* FUN_8015bac8
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015bac8  body 0x8015bac8..0x8015bc3b  size 372 B
 * body sha256 bb30944027aa9c6836a0301ab918e10418faacb5f128d91dfbac67c2e7cb0793
 * provider record sha256 696c554d39793e6577f09fb48b71db5477dda6fa90437123278b85ea5c461f46
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015bb60) */
/* WARNING: Removing unreachable block (ram,0x8015bbac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015bac8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar6 = _DAT_800c52d8 + 7U & 0xfffffff8;
  _DAT_800df934 = _DAT_800c52d8;
  func_0x80004cfc(0x1f94,uVar6,0,"Init tbl");
  puVar7 = (undefined4 *)(uVar6 + (uint)DAT_800e10fa * 0x6ec);
  puVar1 = (undefined4 *)&DAT_800e8930;
  puVar9 = puVar7;
  do {
    puVar8 = puVar9;
    puVar2 = puVar1;
    uVar3 = puVar8[1];
    uVar4 = puVar8[2];
    uVar5 = puVar8[3];
    *puVar2 = *puVar8;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
    puVar9 = puVar8 + 4;
    puVar1 = puVar2 + 4;
  } while (puVar9 != puVar7 + 0x1b8);
  uVar3 = puVar8[5];
  uVar4 = puVar8[6];
  puVar2[4] = *puVar9;
  puVar2[5] = uVar3;
  puVar2[6] = uVar4;
  return;
}
