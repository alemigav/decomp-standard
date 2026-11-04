/* FUN_80166d2c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80166d2c  body 0x80166d2c..0x801671db  size 1200 B
 * body sha256 b7642d628d98f014f77e67b35776a49a7d57cffab560f22243898a55d3a63aab
 * provider record sha256 796d264b73e71d5d77c7ccb69a92068e1a7e8d6d8d8ce78be9f70fd80f9e2ab6
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166d2c(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  char cVar6;
  int iVar3;
  int iVar4;
  short sVar5;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar2 = func_0x80033604();
    if (DAT_8016c2d0 == 0) {
      trap(0x1c00);
    }
    *(undefined1 *)(param_1 + 0x206) = (&DAT_8016c2d4)[(uVar2 & 0xff) % (uint)DAT_8016c2d0];
  }
  sVar5 = (&DAT_8016c2b0)[*(char *)(param_1 + 0x206) * 2];
  sVar1 = (&DAT_8016c2b2)[*(char *)(param_1 + 0x206) * 2];
  *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x2c0) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined1 *)(param_1 + 0x2d7) = 0;
    *(undefined2 *)(param_1 + 0x2d4) = 0;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffd;
    func_0x80052c6c(8,0x50,0xf);
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80032dbc(param_1,(int)sVar5,(int)sVar1,0x10);
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if (*(char *)(param_1 + 0x1e9) == '\x13') {
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined2 *)(param_1 + 0x1e2) = 0xfbb4;
      *(undefined1 *)(param_1 + 0x207) = 0x12;
      if (*(char *)(param_1 + 5) == '\x11') {
        *(undefined2 *)(param_1 + 0x1e2) = 0xfce0;
        *(undefined1 *)(param_1 + 0x207) = 0x10;
      }
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 500) = 0;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 4;
      func_0x80032dbc(param_1,(int)sVar5,(int)sVar1,0x20);
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x80;
      func_0x80077d18(2,param_1);
    }
    break;
  case 2:
    func_0x80032dbc(param_1,(int)sVar5,(int)sVar1,0x40);
    cVar6 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x1e2) = (*(short *)(param_1 + 0x1e2) + 0x78) - *(short *)(param_1 + 0x2c0)
    ;
    *(short *)(param_1 + 0x2c0) = *(short *)(param_1 + 0x2c0) + 2;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000f00;
    *(undefined1 *)(param_1 + 6) = 4;
  case 4:
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    if ((*(ushort *)(param_1 + 0x2b6) & 0x10) != 0) {
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    }
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x1e2) = (*(short *)(param_1 + 0x1e2) + 0x78) - *(short *)(param_1 + 0x2c0)
    ;
    *(short *)(param_1 + 0x2c0) = *(short *)(param_1 + 0x2c0) + 2;
    if ((0 < *(short *)(param_1 + 0x1e2)) && ((*(ushort *)(param_1 + 0x2b6) & 0x10) == 0)) {
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x10;
      *(undefined4 *)(param_1 + 0x1e8) = 0xe000f00;
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
    func_0x8004dcb8(param_1,0x400);
    iVar3 = (int)*(short *)(param_1 + 0x25e);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x1e4);
    if (iVar3 < *(int *)(param_1 + 0x2c)) {
      *(undefined4 *)(param_1 + 4) = 0x1060000;
      *(int *)(param_1 + 0x2c) = iVar3;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      if (iVar3 == -0xe10) {
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x20;
      }
      func_0x80052c6c(8,100,0);
    }
    if (*(int *)(param_1 + 0x2c) < -0xed8) {
      *(undefined1 *)(param_1 + 0x1a2) = 2;
    }
    if (-0xe10 < *(int *)(param_1 + 0x2c)) {
      *(undefined1 *)(param_1 + 0x1a2) = 0;
    }
  }
  if (*(char *)(param_1 + 0x207) != '\0') {
    iVar3 = (int)sVar5 - *(int *)(param_1 + 0x28);
    iVar4 = (int)sVar1 - *(int *)(param_1 + 0x30);
    uVar2 = func_0x80040bb4(iVar3 * iVar3 + iVar4 * iVar4);
    if ((int)*(char *)(param_1 + 0x207) == 0) {
      trap(0x1c00);
    }
    local_30 = (undefined2)(uVar2 / (uint)(int)*(char *)(param_1 + 0x207));
    local_2e = *(undefined2 *)(param_1 + 0x1e2);
    local_2c = 0;
    sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)sVar5,(int)sVar1);
    FUN_8016b9c8(param_1,(int)sVar5,&local_30);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
    *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
  }
  return;
}
