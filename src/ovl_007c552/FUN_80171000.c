/* FUN_80171000
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x80171000  body 0x80171000..0x8017123f  size 576 B
 * body sha256 e2fb9d051189763c8968d0c441ef3c269e2a7c9ea521f6320220a01db2f16f4d
 * provider record sha256 1a56e657d63d48eda91bc9f6c24cd70baf84643070eb74d12fbbd8ba8def64f3
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x801710e8) */
/* WARNING: Removing unreachable block (ram,0x801710ec) */
/* WARNING: Removing unreachable block (ram,0x80171138) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80171000(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined1 local_20 [16];
  
  uVar13 = _DAT_800c52d8 + 7U & 0xfffffff8;
  _DAT_800df934 = _DAT_800c52d8;
  func_0x80004cfc(0x1f94,uVar13,0,"Init tbl");
  iVar5 = 0;
  puVar14 = (undefined4 *)(uVar13 + (uint)DAT_800e10fa * 0x6ec);
  puVar4 = local_20;
  do {
    puVar1 = (undefined1 *)(iVar5 + -0x7ff16fed);
    iVar5 = iVar5 + 1;
    *puVar4 = *puVar1;
    puVar4 = local_20 + iVar5;
  } while (iVar5 < 8);
  puVar8 = puVar14;
  puVar2 = (undefined4 *)&DAT_800e8930;
  do {
    puVar9 = puVar2;
    puVar7 = puVar8;
    uVar10 = puVar7[1];
    uVar11 = puVar7[2];
    uVar12 = puVar7[3];
    *puVar9 = *puVar7;
    puVar9[1] = uVar10;
    puVar9[2] = uVar11;
    puVar9[3] = uVar12;
    puVar8 = puVar7 + 4;
    puVar2 = puVar9 + 4;
  } while (puVar8 != puVar14 + 0x1b8);
  uVar10 = puVar7[5];
  uVar11 = puVar7[6];
  puVar9[4] = *puVar8;
  puVar9[5] = uVar10;
  puVar9[6] = uVar11;
  if ((_DAT_800e110c & 0x40000000) == 0) {
    DAT_800e901b = 0xff;
  }
  else {
    iVar3 = -0x7ff38950;
    iVar5 = 0;
    do {
      iVar6 = iVar5 + 1;
      *(undefined1 *)(iVar3 + 0x21963) = local_20[iVar5];
      iVar3 = iVar5 + -0x7ff3894f;
      iVar5 = iVar6;
    } while (iVar6 < 8);
  }
  return;
}
