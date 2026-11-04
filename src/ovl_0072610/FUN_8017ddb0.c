/* FUN_8017ddb0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017ddb0  body 0x8017ddb0..0x8017df4b  size 412 B
 * body sha256 2c7960e0bc14818a6e0ba62fcf4631f2d03e02b4dd5358ba8f398caa5c22c6bf
 * provider record sha256 c767f765013996bc7972d2df627bef8278f5634e7738eae29516d460e6334770
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017ddb0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  
  iVar4 = DAT_801857a0;
  iVar3 = DAT_8018576c;
  iVar2 = DAT_80185760;
  iVar1 = DAT_80185754;
  if ((DAT_801857a0 == 3) && (DAT_801857bc != 0)) {
    DAT_801857bc = 0;
  }
  uVar5 = DAT_801857bc;
  piVar7 = &DAT_80185734;
  piVar9 = &DAT_80185710;
  piVar10 = &DAT_8018571c;
  piVar11 = &DAT_80185728;
  do {
    if (iVar3 == 3) {
      *piVar7 = *piVar11;
    }
    else {
      if (uVar5 == 0) {
        iVar6 = *piVar10;
        *piVar10 = *piVar9;
        *piVar9 = iVar6;
      }
      *piVar7 = *piVar9;
    }
    if (iVar4 == 2) {
      iVar6 = iVar2;
      if (piVar7 == &DAT_80185734) {
        iVar6 = iVar1;
      }
      *piVar7 = *piVar7 + iVar6;
    }
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
    piVar10 = piVar10 + 1;
    piVar11 = piVar11 + 1;
  } while ((int)piVar7 < -0x7fe7a8c0);
  FUN_8017df6c(param_1);
  if ((param_1 != 0) && ((DAT_801857a0 == 3 || (DAT_801857bc != 0)))) {
    if (DAT_8018576c == 3) {
      puVar8 = &DAT_80185728;
    }
    else {
      puVar8 = &DAT_8018571c;
    }
    FUN_8017b5e8(puVar8);
  }
  if (DAT_801857a0 != 3) {
    DAT_801857bc = (uint)(DAT_801857bc == 0);
  }
  return;
}
