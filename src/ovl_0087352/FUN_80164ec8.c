/* FUN_80164ec8
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164ec8  body 0x80164ec8..0x8016511f  size 600 B
 * body sha256 1f05b290fc4f61ef10de071579a6a3f74891f9e95d1d4c01902ac79c7e077311
 * provider record sha256 4f8e670b740d9dba9c5dd08002602163af2752e5057b372eaf88ccca8bd59814
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164ec8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    func_0x80035b84(param_1);
    func_0x80077d18(3,param_1);
    FUN_80166294(param_1,10);
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    FUN_80166100(param_1);
    uVar2 = func_0x80033604();
    FUN_801661d8(param_1,(uVar2 & 3) + 5);
    uVar1 = _DAT_800e1196;
    *(undefined2 *)(param_1 + 0x1e0) = 600;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x66) = uVar1;
  case 1:
    iVar4 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar4 != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
  case 2:
    func_0x80032b5c(param_1,0);
    iVar4 = *(short *)(param_1 + 0x25e) + -0xfa;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x14;
    if (iVar4 < *(int *)(param_1 + 0x2c)) {
      func_0x80077d18(5,param_1);
      *(undefined1 *)(param_1 + 0x2b5) = 0x10;
      *(int *)(param_1 + 0x2c) = iVar4;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined1 *)(param_1 + 6) = 3;
    }
    if ((*(uint *)(param_1 + 0x1ac) & 1) != 0) {
      func_0x80077d18(3,param_1);
      FUN_80166100(param_1);
      *(undefined2 *)(param_1 + 0x1e0) = 0x14;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined1 *)(param_1 + 6) = 4;
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
    }
    return;
  case 3:
    func_0x80032b5c(param_1,0);
    cVar3 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar3;
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
    if (cVar3 != -1) {
      return;
    }
    break;
  case 4:
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x14;
    func_0x80032b5c(param_1,0);
    iVar4 = *(short *)(param_1 + 0x25e) + -0xfa;
    if (*(int *)(param_1 + 0x2c) <= iVar4) {
      return;
    }
    FUN_80166294(param_1,0x15e);
    func_0x80077d18(5,param_1);
    *(int *)(param_1 + 0x2c) = iVar4;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    break;
  default:
    return;
  }
  FUN_80165c58(param_1,7,3);
  return;
}
