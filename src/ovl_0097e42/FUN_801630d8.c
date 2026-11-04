/* FUN_801630d8
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x801630d8  body 0x801630d8..0x8016327f  size 424 B
 * body sha256 b175f16d41ab2c7f1d508e5a01da87d57cca3ad5d3cc66f108b9aeeff1f21173
 * provider record sha256 1fc1e903fe82df56cd0abe6805fb484b4a9fccad7328f040d2a9da2c25b616a1
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801630d8(int param_1)

{
  short sVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0x32;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
switchD_80163110_caseD_1:
    sVar1 = *(short *)(param_1 + 500) + 2;
    sVar3 = *(short *)(param_1 + 0x1e2) + sVar1;
    *(short *)(param_1 + 0x1e2) = sVar3;
    *(short *)(param_1 + 500) = sVar1;
    iVar4 = *(short *)(param_1 + 0x1dc) + -0xc00;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar3;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (0x10 < iVar4) {
      sVar1 = *(short *)(param_1 + 0x1dc) + -0x10;
      if (0xbff < *(short *)(param_1 + 0x1dc)) {
        sVar1 = *(short *)(param_1 + 0x1dc) + 0x10;
      }
      *(short *)(param_1 + 0x1dc) = sVar1;
      func_0x80040e58(param_1 + 0x1d8,*(undefined4 *)(param_1 + 0x70));
    }
    sVar1 = func_0x80069f1c(param_1 + 0x28,1,0x400,0);
    if (_DAT_80112710 < sVar1) {
      sVar1 = _DAT_80112712;
    }
    iVar4 = (int)sVar1;
    if ((-0x1c20 < iVar4) && (iVar4 <= *(int *)(param_1 + 0x2c))) {
      *(int *)(param_1 + 0x2c) = iVar4;
      *(undefined4 *)(iVar5 + 0x2f0) = 1;
      *(undefined4 *)(iVar5 + 0x468) = 1;
      cVar2 = *(char *)(param_1 + 6);
      *(undefined2 *)(param_1 + 0x1e2) = 0x14;
LAB_80163264:
      *(char *)(param_1 + 6) = cVar2 + '\x01';
    }
switchD_80163110_caseD_4:
    return;
  case 1:
    goto switchD_80163110_caseD_1;
  case 2:
    cVar2 = func_0x80036b84(param_1,4,0,0);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
  case 3:
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    FUN_801634c8(param_1);
    if (*(int *)(param_1 + 0x30) != (int)*(short *)(param_1 + 0x38)) {
      return;
    }
    cVar2 = *(char *)(param_1 + 6);
    goto LAB_80163264;
  default:
    goto switchD_80163110_caseD_4;
  }
}
