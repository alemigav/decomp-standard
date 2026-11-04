/* FUN_80163894
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163894  body 0x80163894..0x80163ab3  size 544 B
 * body sha256 aa02d806969eedcd9841ed9a3d9ac21cf08b4edb894149ebfa56dde834f7ce17
 * provider record sha256 e55827560275e1bdc0a0f5094b3701af05525cd9916f65177efa22cb0f0f05f6
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163894(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar3;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 1) {
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80032b5c(param_1,0);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x2b6);
    if (((**(uint **)(param_1 + 0x214) & 0x70000) == 0) ||
       (iVar2 = FUN_801677b0(param_1,3), iVar2 == 0)) {
      if ((**(uint **)(param_1 + 0x214) & 0x80000) != 0) {
        *(undefined1 *)(param_1 + 7) = 2;
        *(undefined4 *)(param_1 + 0x1e8) = 0xc000f00;
        func_0x800334c8(param_1,param_2,param_3,0);
        func_0x80089d54(param_1,param_2,param_3,0x100);
      }
    }
    else {
      func_0x80077d18(0xd,param_1);
      *(undefined2 *)(param_1 + 6) = 0x100;
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      *(undefined1 *)(param_1 + 7) = 1;
      *(undefined4 *)(param_1 + 0x1e8) = 0x9000f00;
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x100);
      uVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
      *(undefined2 *)(param_1 + 0x2b6) = uVar3;
      *(undefined1 *)(param_1 + 0x2cd) = 0;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    }
  }
  else if (bVar1 == 2) {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 5) = 2;
      *(undefined2 *)(param_1 + 6) = 0;
      *(undefined1 *)(param_1 + 0x2b4) = 0;
      *(undefined1 *)(param_1 + 0x2b8) = 0x1e;
      func_0x80077d18(10,param_1);
    }
    func_0x80032b5c(param_1,0);
  }
  func_0x80033648(param_1);
  return;
}
