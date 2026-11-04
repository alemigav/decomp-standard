/* FUN_801636d4
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801636d4  body 0x801636d4..0x80163937  size 612 B
 * body sha256 6eda69c4a11981b267f3afaddde2511126e1dd6ad73c4f74a092cf8a368532e8
 * provider record sha256 b96ab3c4bb3da1409666ff4eaae84c8ba2970df0093d2f3003a422fe34c86e31
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801636d4(int param_1)

{
  short sVar3;
  int iVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  
  sVar3 = FUN_80162544();
  if (0xaf0 < *(uint *)(param_1 + 0x28c)) {
    *(undefined2 *)(param_1 + 0x276) = 1;
  }
  if (_DAT_800e1322 < 0) {
    *(undefined4 *)(param_1 + 4) = 0x1060000;
    return;
  }
  if (0xdc < *(ushort *)(param_1 + 0x2d0)) {
    iVar1 = (int)sVar3;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if ((iVar1 < 300) && (0xdac < *(uint *)(param_1 + 0x28c))) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
      *(undefined2 *)(param_1 + 0x2d0) = 0;
      goto LAB_801638e4;
    }
  }
  if ((_DAT_800e1322 < 0) || (*(char *)(param_1 + 0x2c6) != '\0')) goto LAB_801638e4;
  uVar5 = 0x8fc;
  uVar2 = func_0x80033604();
  if ((uVar2 & 0x3f) == 1) {
    uVar5 = 0xa28;
  }
  if (_DAT_800e1322 < 0x51) {
    uVar5 = 0x76c;
  }
  if (*(uint *)(param_1 + 0x28c) < uVar5) {
    if (0x28 < _DAT_800e1322) {
      iVar4 = (int)sVar3;
      iVar1 = iVar4;
      if (iVar4 < 0) {
        iVar1 = -iVar4;
      }
      if (399 < iVar1) goto LAB_80163874;
      if ((((iVar4 <= *(char *)(param_1 + 0x2c7)) || (uVar2 = func_0x80033604(), 2 < (uVar2 & 3)))
          && (sVar3 < 0x8c)) && (uVar2 = func_0x80033604(), (uVar2 & 3) < 3)) {
        *(undefined4 *)(param_1 + 4) = 0x1020000;
        goto LAB_801638e4;
      }
    }
    *(undefined4 *)(param_1 + 4) = 0x1030000;
  }
  else {
LAB_80163874:
    uVar5 = 0x1964;
    uVar2 = func_0x80033604();
    if ((uVar2 & 0x3f) == 0x17) {
      uVar5 = 0x157c;
    }
    if ((uVar5 < *(uint *)(param_1 + 0x28c)) && (*(uint *)(param_1 + 0x28c) < 0x1d4c)) {
      iVar1 = (int)sVar3;
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if ((iVar1 < 300) && (*(char *)(param_1 + 0x2c6) == '\0')) {
        *(undefined4 *)(param_1 + 4) = 0x1040000;
        goto LAB_801638e4;
      }
    }
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
  }
LAB_801638e4:
  if (*(char *)(param_1 + 6) == '\0') {
    func_0x80036c68(param_1,1,0xf,0);
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
    *(char *)(param_1 + 0x2c7) = (char)sVar3;
  }
  else {
    *(char *)(param_1 + 0x2c7) = (char)sVar3;
  }
  return;
}
