/* FUN_801633bc
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801633bc  body 0x801633bc..0x8016375f  size 932 B
 * body sha256 7a32c3fb70cdeba9da5b68ccc779a6f758973633fdce001990277849514b757e
 * provider record sha256 1ac8ea8081d484ea5990f991dfb85174fff2efa8156bcf6e713caeb9ea8b0a86
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801633bc(int param_1)

{
  short sVar3;
  ushort uVar4;
  undefined4 uVar1;
  ushort uVar5;
  uint uVar2;
  int iVar6;
  int iVar7;
  bool bVar8;
  short local_30 [2];
  short local_2c;
  int local_28 [2];
  int local_20;
  
  if ((DAT_800e1134 == '\x05') && (DAT_800e1135 == '\x01')) {
    return;
  }
  if (_DAT_800e1322 < 0) {
    return;
  }
  sVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  uVar4 = FUN_801621c4(param_1);
  iVar6 = (int)(short)uVar4;
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  if (((iVar6 < 0x2aa) && (*(uint *)(param_1 + 0x28c) < 2000)) && (_DAT_800e1322 < 0x47)) {
    local_2c = 0;
    local_30[0] = _DAT_800e1266 + 300;
    func_0x800837d0((int)sVar3,local_30,local_30);
    local_20 = local_2c + _DAT_800e1160;
    local_28[0] = local_30[0] + _DAT_800e1158;
    iVar6 = func_0x800667d4(local_28,0,1 << (DAT_800e12d2 & 0x1f),0x8000);
    uVar1 = 0x1060000;
    if (iVar6 != 0) goto LAB_80163740;
  }
  if ((_DAT_800e1322 < 0x33) && (*(char *)(param_1 + 0x2c9) == '\0')) {
    iVar6 = (int)(short)uVar4;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if ((iVar6 < 0x2aa) && (uVar1 = 0x1030000, *(uint *)(param_1 + 0x28c) < 0x898))
    goto LAB_80163740;
  }
  if ((*(char *)(param_1 + 0x2c6) != '\0') && (*(char *)(param_1 + 0x2c8) == '\0')) {
    iVar6 = (int)(short)uVar4;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if ((iVar6 < 0x2aa) && (uVar1 = 0x1060000, *(uint *)(param_1 + 0x28c) < 0x898))
    goto LAB_80163740;
  }
  if (_DAT_800e1322 < 0x29) {
    if ((*(char *)(param_1 + 0x2c6) == '\0') && (*(uint *)(param_1 + 0x28c) < 2000)) {
      iVar7 = (int)(short)uVar4;
      iVar6 = iVar7;
      if (iVar7 < 0) {
        iVar6 = -iVar7;
      }
      if (iVar6 < 500) {
        *(ushort *)(param_1 + 0x2c0) = *(ushort *)(param_1 + 0x2c0) | 0x20;
        uVar1 = 0x1040000;
        if (iVar7 < 1) {
          uVar1 = 0x1050000;
        }
        goto LAB_80163740;
      }
LAB_801636a4:
      func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20
                     );
    }
  }
  else if (*(char *)(param_1 + 0x2c6) == '\0') {
    bVar8 = false;
    if (*(uint *)(param_1 + 0x28c) < 0x898) {
      iVar7 = (int)(short)uVar4;
      iVar6 = iVar7;
      if (iVar7 < 0) {
        iVar6 = -iVar7;
      }
      if (iVar6 < 800) {
        if (iVar7 < 0) {
          iVar7 = -iVar7;
        }
        if ((0x23 < iVar7) || (*(uint *)(param_1 + 0x28c) < 0x640)) {
          bVar8 = true;
        }
      }
      if (bVar8) {
        if (((*(ushort *)(param_1 + 0x2c0) & 0x40) == 0) ||
           (uVar2 = func_0x80033604(), (uVar2 & 2) == 0)) {
          uVar5 = *(ushort *)(param_1 + 0x2c0) | 0x20;
        }
        else {
          uVar5 = *(ushort *)(param_1 + 0x2c0) & 0xffdf;
        }
        *(ushort *)(param_1 + 0x2c0) = uVar5;
        uVar1 = 0x1040000;
        if ((int)((uint)uVar4 << 0x10) < 1) {
          uVar1 = 0x1050000;
        }
        goto LAB_80163740;
      }
      goto LAB_801636a4;
    }
  }
  if (*(char *)(param_1 + 0x2c7) != '\0') {
    return;
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 0x300) == 0x100) {
    return;
  }
  if (*(char *)(param_1 + 5) == '\x02') {
    return;
  }
  if (_DAT_800e1322 < 0x51) {
    return;
  }
  uVar2 = func_0x80033604();
  if ((uVar2 & 0x1f) != 8) {
    return;
  }
  if (0x1f2 < *(int *)(param_1 + 0x28c) - 0xc81U) {
    return;
  }
  iVar6 = (int)(short)uVar4;
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  uVar1 = 0x1080000;
  if (199 < iVar6) {
    return;
  }
LAB_80163740:
  *(undefined4 *)(param_1 + 4) = uVar1;
  return;
}
