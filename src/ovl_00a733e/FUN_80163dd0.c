/* FUN_80163dd0
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163dd0  body 0x80163dd0..0x8016410b  size 828 B
 * body sha256 e3e227d768e930a08cf22688bfd95bd0b3c2aa18921fb64293e8f6d1467fd824
 * provider record sha256 b5fd20ff9bb50d8b6858ac4997bf5fdf7b384a27fe8349fa8fdd980ee55e5bb1
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163dd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar1;
  undefined4 uVar5;
  
  switch(*(undefined1 *)(param_1 + 7)) {
  case 0:
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80032b5c(param_1,0);
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    break;
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80032b5c(param_1,0);
    if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
      *(undefined1 *)(param_1 + 7) = 2;
      *(undefined2 *)(param_1 + 0x2b6) = 0;
      iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x40);
      if (iVar1 != 0) {
        uVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
        *(undefined2 *)(param_1 + 0x2b6) = uVar2;
      }
    }
    break;
  case 2:
    uVar5 = 0xb000f00;
    uVar4 = 3;
    goto LAB_80164064;
  case 3:
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x2b6);
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80032b5c(param_1,0);
    if (((**(uint **)(param_1 + 0x214) & 0x10000) != 0) &&
       (iVar1 = FUN_8016760c(param_1,4), iVar1 != 0)) {
      if ((_DAT_800e1322 < 0x14) && (cVar3 = func_0x80033144(param_1,&DAT_800e1130), cVar3 == '\0'))
      {
        *(undefined2 *)(param_1 + 6) = 0x100;
        func_0x80077d18(4,param_1);
        return;
      }
      iVar1 = func_0x80059e00(10,0);
      if (iVar1 == 2) {
        FUN_801675ec(param_1);
      }
      else {
        uVar4 = func_0x80033144(param_1,&DAT_800e1130);
        FUN_80167598(uVar4);
      }
      func_0x80077d18(0xd,param_1);
      FUN_80167374(param_1,6,1);
    }
    if ((**(uint **)(param_1 + 0x214) & 0x20000) != 0) {
      *(undefined1 *)(param_1 + 7) = 4;
    }
    break;
  case 4:
    uVar5 = 0xc000f00;
    uVar4 = 5;
LAB_80164064:
    *(undefined1 *)(param_1 + 7) = uVar4;
    *(undefined4 *)(param_1 + 0x1e8) = uVar5;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    break;
  case 5:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 5) = 2;
      *(undefined2 *)(param_1 + 6) = 0;
      *(undefined1 *)(param_1 + 0x2b4) = 0;
      *(undefined1 *)(param_1 + 0x2b8) = 0x3c;
      func_0x80077d18(10,param_1);
      FUN_80163824(param_1);
    }
    func_0x80032b5c(param_1,0);
  }
  return;
}
