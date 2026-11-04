/* FUN_800a15d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a15d0  body 0x800a15d0..0x800a1be7  size 1560 B
 * body sha256 2e9e1241aa19bef4b6a81c0862cc6a2cfe6273c2ca77c4ca1b8a62b40fdd61c1
 * provider record sha256 609335c4ebf1d145c14981b0792b9284a76d46e4dbf195d9908b5f1f3ceae908
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a15d0(uint *param_1,uint *param_2,char param_3)

{
  byte bVar1;
  undefined1 uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_40;
  uint local_3c;
  uint local_38;
  undefined2 local_34;
  undefined2 local_32;
  undefined1 local_30;
  undefined1 local_28;
  
  uVar8 = 0;
  puVar7 = (uint *)&DAT_8013bc90;
  do {
    if ((*(char *)((int)puVar7 + 0xfc1) == '\0') && (*puVar7 == (*param_1 & 0x7fffffff))) {
      uVar8 = uVar8 | *param_1 & 0x80000000;
      goto LAB_800a1644;
    }
    uVar8 = uVar8 + 1;
    puVar7 = puVar7 + 0x3fe;
  } while (uVar8 < 8);
  uVar8 = 0xffffffff;
LAB_800a1644:
  if (uVar8 == 0xffffffff) {
    return;
  }
  bVar1 = *(byte *)((int)param_1 + 0x26);
  if ((bVar1 & 4) != 0) {
    puVar7 = (uint *)(uVar8 * 0xff8 + -0x7fec33a8);
    puVar6 = param_1;
    do {
      puVar5 = puVar6;
      puVar3 = puVar7;
      uVar11 = puVar5[1];
      uVar12 = puVar5[2];
      uVar13 = puVar5[3];
      *puVar3 = *puVar5;
      puVar3[1] = uVar11;
      puVar3[2] = uVar12;
      puVar3[3] = uVar13;
      puVar6 = puVar5 + 4;
      puVar7 = puVar3 + 4;
    } while (puVar6 != param_1 + 8);
    uVar11 = puVar5[5];
    puVar3[4] = *puVar6;
    puVar3[5] = uVar11;
    iVar4 = uVar8 * 0xff8;
    *(undefined1 *)(iVar4 + -0x7fec337c) = 1;
    *(uint **)(iVar4 + -0x7fec3380) = param_2;
    *(byte *)(iVar4 + -0x7fec3382) = *(byte *)(iVar4 + -0x7fec3382) & 0xfb;
    *param_2 = *param_1 | 0x80000000;
    return;
  }
  if (param_3 == '\0') {
    if ((bVar1 & 1) == 0) {
      if ((bVar1 & 0x40) == 0) {
        uVar9 = *(undefined2 *)(param_1 + 1);
        uVar8 = *param_1;
        if (DAT_80136310 == '\0') goto LAB_800a183c;
        FUN_800a5678();
        uVar10 = 1;
      }
      else {
        uVar9 = *(undefined2 *)(param_1 + 1);
        uVar8 = *param_1;
        if (DAT_80136310 == '\0') goto LAB_800a183c;
        FUN_800a5678();
        uVar10 = 3;
      }
    }
    else {
      uVar9 = *(undefined2 *)(param_1 + 1);
      uVar8 = *param_1;
      if (DAT_80136310 == '\0') goto LAB_800a183c;
      FUN_800a5678();
      uVar10 = 2;
    }
    FUN_800a13c4(0,uVar9,uVar8,uVar10);
    FUN_800a56c0();
  }
  else if ((bVar1 & 1) == 0) {
    if ((bVar1 & 0x40) == 0) {
      FUN_800a13c4(0,*(undefined2 *)(param_1 + 1),*param_1,1);
    }
    else {
      FUN_800a13c4(0,*(undefined2 *)(param_1 + 1),*param_1,3);
    }
  }
  else {
    FUN_800a13c4(0,*(undefined2 *)(param_1 + 1),*param_1,2);
  }
LAB_800a183c:
  if (param_2 != (uint *)0x0) {
    uVar8 = 0;
    if ((*(byte *)((int)param_1 + 0x26) & 2) == 0) {
      local_40 = 4;
      if ((*(byte *)((int)param_1 + 0x26) & 8) != 0) {
        local_40 = 0x14;
      }
      if ((*(byte *)((int)param_1 + 0x26) & 0x20) != 0) {
        local_40 = local_40 | 2;
        local_34 = *(undefined2 *)(param_1 + 9);
      }
      if ((*(byte *)((int)param_1 + 0x26) & 0x10) != 0) {
        local_40 = local_40 | 1;
        local_3c = param_1[7];
        local_38 = param_1[8];
      }
      local_32 = *(undefined2 *)(param_1 + 3);
      local_30 = *(undefined1 *)(param_1 + 6);
      local_28 = 0;
      if (param_3 == '\0') {
        uVar8 = FUN_800a8bc8(*(undefined2 *)(param_1 + 5),*(undefined2 *)((int)param_1 + 0x16),
                             param_1[4],&local_40);
        *param_2 = uVar8;
        if (((uVar8 != 0xffffffff) && ((*(byte *)((int)param_1 + 0x26) & 0x80) != 0)) &&
           (DAT_80136310 != '\0')) {
          FUN_800a5678();
          FUN_800a12f8(uVar8,0,0);
          FUN_800a56c0();
        }
      }
      else {
        uVar8 = FUN_800a8cf4(*(undefined2 *)(param_1 + 5),*(undefined2 *)((int)param_1 + 0x16),
                             param_1[4],&local_40,1);
        *param_2 = uVar8;
        if ((uVar8 != 0xffffffff) && ((*(byte *)((int)param_1 + 0x26) & 0x80) != 0)) {
          FUN_800a12f8(uVar8,0,0);
        }
      }
    }
    else {
      puVar7 = (uint *)&DAT_8013bc90;
      do {
        if ((*(char *)((int)puVar7 + 0xfc1) == '\0') && (*puVar7 == (param_1[2] & 0x7fffffff))) {
          uVar8 = uVar8 | param_1[2] & 0x80000000;
          goto LAB_800a1898;
        }
        uVar8 = uVar8 + 1;
        puVar7 = puVar7 + 0x3fe;
      } while (uVar8 < 8);
      uVar8 = 0xffffffff;
LAB_800a1898:
      if (uVar8 == 0xffffffff) {
        *param_2 = 0xffffffff;
      }
      else {
        if (param_3 == '\0') {
          uVar8 = param_1[2];
          if (DAT_80136310 != '\0') {
            FUN_800a5678();
            FUN_800a1234(uVar8);
            FUN_800a56c0();
          }
          uVar2 = *(undefined1 *)(param_1 + 6);
          uVar9 = *(undefined2 *)(param_1 + 3);
          uVar8 = param_1[2];
          if (DAT_80136310 != '\0') {
            FUN_800a5678();
            FUN_800a13c4(uVar2,uVar9,uVar8,0);
            FUN_800a56c0();
          }
          if ((*(byte *)((int)param_1 + 0x26) & 0x10) != 0) {
            uVar11 = param_1[2];
            uVar12 = param_1[7];
            uVar8 = param_1[8];
            if (DAT_80136310 != '\0') {
              FUN_800a5678();
              FUN_800a12f8(uVar11,uVar12,uVar8);
              FUN_800a56c0();
            }
          }
          if ((*(byte *)((int)param_1 + 0x26) & 0x20) != 0) {
            FUN_800a1134(param_1[2],*(undefined2 *)(param_1 + 9));
          }
        }
        else {
          FUN_800a1234(param_1[2]);
          FUN_800a13c4(*(undefined1 *)(param_1 + 6),*(undefined2 *)(param_1 + 3),param_1[2],0);
          if ((*(byte *)((int)param_1 + 0x26) & 0x10) != 0) {
            FUN_800a12f8(param_1[2],param_1[7],param_1[8]);
          }
          uVar8 = 0;
          if ((*(byte *)((int)param_1 + 0x26) & 0x20) != 0) {
            puVar7 = (uint *)&DAT_8013bc90;
            do {
              if ((*(char *)((int)puVar7 + 0xfc1) == '\0') && (*puVar7 == (param_1[2] & 0x7fffffff))
                 ) {
                uVar8 = uVar8 | param_1[2] & 0x80000000;
                goto LAB_800a1948;
              }
              uVar8 = uVar8 + 1;
              puVar7 = puVar7 + 0x3fe;
            } while (uVar8 < 8);
            uVar8 = 0xffffffff;
LAB_800a1948:
            if (uVar8 != 0xffffffff) {
              if ((int)uVar8 < 0) {
                iVar4 = (uVar8 * 0x200 - (uVar8 & 0x7fffffff)) * 8;
                *(undefined2 *)(iVar4 + -0x7fec3384) = *(undefined2 *)(param_1 + 9);
                *(byte *)(iVar4 + -0x7fec3382) = *(byte *)(iVar4 + -0x7fec3382) | 0x20;
              }
              else {
                *(undefined2 *)(&DAT_8013cc52 + uVar8 * 0xff8) = *(undefined2 *)(param_1 + 9);
              }
            }
          }
        }
        *param_2 = param_1[2];
      }
    }
  }
  return;
}
