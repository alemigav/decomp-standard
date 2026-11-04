/* FUN_80162c88
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162c88  body 0x80162c88..0x80162ea7  size 544 B
 * body sha256 5f64c2e86b1c0376e56fd3acac5f6889a06be0bf8ed9f5bbf108720419bee3f7
 * provider record sha256 7d75c321880e1b9b755930227232dfe351a8227c3489cdfdfd30bc288c4f4d45
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162c88(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  short sVar6;
  uint uVar4;
  int iVar5;
  undefined4 uVar7;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 6) = 3;
        uVar4 = func_0x8006568c((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32));
        uVar2 = *(undefined2 *)(&DAT_80167d80 + (uVar4 & 0xff) * 2);
        *(undefined2 *)(param_1 + 500) = 0x2d;
        *(undefined2 *)(param_1 + 0x2b6) = uVar2;
      }
      else if (bVar1 != 3) goto LAB_80162e40;
      func_0x800334c8(param_1,param_2,param_3,0);
      bVar3 = false;
      iVar5 = FUN_80165e14(param_1,0x10);
      if (iVar5 == 0) {
        sVar6 = *(short *)(param_1 + 500);
        *(short *)(param_1 + 500) = sVar6 + -1;
        if (sVar6 == 1) {
          bVar3 = true;
        }
      }
      else {
        bVar3 = true;
      }
      if (bVar3) {
        *(undefined1 *)(param_1 + 6) = 1;
        *(undefined1 *)(param_1 + 0x2c1) = 0;
      }
      goto LAB_80162e40;
    }
    if (bVar1 != 0) goto LAB_80162e40;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined1 *)(param_1 + 0x2c0) = 0;
    *(undefined1 *)(param_1 + 0x2c1) = 0;
    *(uint *)(param_1 + 0x1e8) = (*(byte *)(param_1 + 0x2b4) + 1) * 0x1000000 + 0xf00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfe;
  }
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  uVar7 = 0x18;
  if (5000 < *(uint *)(param_1 + 0x28c)) {
    uVar7 = 0x20;
  }
  if (-1 < _DAT_800e1322) {
    sVar6 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                            (int)*(short *)(param_1 + 0x262),uVar7);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar6;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  if (0x14 < *(byte *)(param_1 + 0x2c1)) {
    *(undefined1 *)(param_1 + 6) = 2;
  }
LAB_80162e40:
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80032b5c(param_1,0);
  func_0x80033648(param_1);
  iVar5 = FUN_80162ea8(param_1);
  if (iVar5 == -1) {
    func_0x80077d18(10,param_1);
  }
  FUN_801631d4(param_1);
  FUN_80164d9c(param_1);
  return;
}
