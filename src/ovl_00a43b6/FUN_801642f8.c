/* FUN_801642f8
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801642f8  body 0x801642f8..0x80164427  size 304 B
 * body sha256 dd190cfb8dd0a519f84d45c76ea547d90f833cf622658b6e887225783c3e31d7
 * provider record sha256 5c906ab09d1d71351d367c299981a98981952d24aee7eacc9b1e8535f5392fb9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801642f8(int param_1)

{
  short sVar2;
  undefined4 uVar1;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x28c);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x5f4);
  func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x338);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  if (*(short *)(param_1 + 0x2c0) == 0) {
    *(undefined2 *)(param_1 + 0x1aa) = 1;
    uVar1 = 0x1060000;
  }
  else if (*(short *)(param_1 + 0x1f2) < 100) {
    *(undefined2 *)(param_1 + 0x1aa) = 1;
    uVar1 = 0x1060000;
  }
  else {
    if ((sVar2 == 0) && (0x9c4 < uVar3)) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
    }
    if (DAT_800e139f != '\0') {
      return;
    }
    if (9 < *(short *)(param_1 + 500)) {
      return;
    }
    if (sVar2 != 0) {
      return;
    }
    if (0x9c3 < uVar3) {
      return;
    }
    uVar1 = 0x1040000;
    if ((_DAT_800e112a & 4) == 0) {
      return;
    }
  }
  *(undefined4 *)(param_1 + 4) = uVar1;
  return;
}
