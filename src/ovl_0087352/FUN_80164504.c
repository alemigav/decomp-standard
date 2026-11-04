/* FUN_80164504
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164504  body 0x80164504..0x8016488f  size 908 B
 * body sha256 a64964a86a42d6ad273b3568aa65fbca19513c5bb2c6155ce914936ee8185cef
 * provider record sha256 e8e804eee51b16987cdf8bbfe778e3c54ec210b5d9d3eb915eb3f7c4384578b8
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164504(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  uint uVar1;
  undefined2 uVar4;
  char cVar6;
  byte bVar7;
  int iVar2;
  ushort uVar5;
  undefined4 uVar8;
  undefined4 uVar9;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    func_0x80077d18(3,param_1);
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined2 *)(param_1 + 0x2c0) = 0;
    sVar3 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,(int)*(short *)(param_1 + 0x2a),
                            (int)*(short *)(param_1 + 0x32));
    *(short *)(param_1 + 0x2c2) = sVar3 - *(short *)(param_1 + 0x66);
    *(undefined2 *)(_DAT_800df938 + 0x1e0) = 100;
    uVar1 = func_0x80033604();
    uVar4 = 200;
    if ((uVar1 & 1) == 0) {
      uVar4 = 0xff38;
    }
    *(undefined2 *)(param_1 + 0x2c4) = uVar4;
    FUN_80166100(param_1);
    uVar1 = func_0x80033604();
    FUN_801661d8(param_1,uVar1 & 1 | 2);
    *(undefined1 *)(param_1 + 0x2b5) = 3;
    *(undefined1 *)(param_1 + 0x2b6) = 3;
    *(undefined1 *)(param_1 + 6) = 1;
  case 1:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
  case 2:
    cVar6 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar6;
    if (cVar6 == -1) {
      FUN_801661d8(param_1,1);
    }
    cVar6 = *(char *)(param_1 + 0x2b6) + -1;
    *(char *)(param_1 + 0x2b6) = cVar6;
    if (cVar6 == -1) {
      FUN_801661d8(param_1,1);
    }
    sVar3 = *(short *)(param_1 + 0x2c0) + 0x14;
    *(short *)(param_1 + 0x2c0) = sVar3;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar3;
    func_0x80032b5c(_DAT_800df938,(int)*(short *)(param_1 + 0x2c2));
    if (*(short *)(param_1 + 0x2c4) < 0) {
      if (-0x800 < *(short *)(param_1 + 0x68)) {
        *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + *(short *)(param_1 + 0x2c4);
      }
    }
    else if (*(short *)(param_1 + 0x68) < 0x800) {
      *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + *(short *)(param_1 + 0x2c4);
    }
    iVar2 = *(short *)(param_1 + 0x25e) + -0xfa;
    if (iVar2 < *(int *)(param_1 + 0x2c)) {
      func_0x80077d18(5,param_1);
      *(int *)(param_1 + 0x2c) = iVar2;
      *(undefined4 *)(param_1 + 0x1e8) = 0xb000700;
      bVar7 = func_0x80033604();
      *(byte *)(param_1 + 0x2b5) = bVar7 & 0xf;
      *(undefined2 *)(param_1 + 0x68) = 0;
      if (*(short *)(param_1 + 0x1f2) < 0) {
        *(undefined1 *)(param_1 + 0x2b5) = 0xb;
        func_0x80035b84(param_1);
        *(undefined1 *)(param_1 + 6) = 5;
      }
      else {
        *(undefined1 *)(param_1 + 6) = 3;
      }
    }
    return;
  case 3:
    cVar6 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar6;
    if (cVar6 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 0x1e9) = *(char *)(param_1 + 0x1e9) + -1;
    return;
  case 4:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 == 0) {
      return;
    }
    iVar2 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                            (int)*(short *)(param_1 + 0x262),0x400);
    if (iVar2 != 0) {
      uVar8 = 1;
      uVar9 = 9;
      goto LAB_80164868;
    }
    uVar5 = func_0x80033604(param_1);
    *(ushort *)(param_1 + 500) = uVar5 & 0xf;
    uVar8 = 1;
    break;
  case 5:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    cVar6 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar6;
    if (cVar6 != -1) {
      return;
    }
    uVar8 = 7;
    break;
  default:
    return;
  }
  uVar9 = 0;
LAB_80164868:
  FUN_80165c58(param_1,uVar8,uVar9);
  return;
}
