/* FUN_80162444
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162444  body 0x80162444..0x80162af7  size 1716 B
 * body sha256 cb8bf09802e9cdd4d4a3f4066df7469bf2dc944e1eb0934885b9d2f5df0d451d
 * provider record sha256 730268e1f4338521c8bf45fbdc52d6a2aab6a1eeda9e0ff150bedccc0f1ffe84
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162444(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar4;
  short sVar2;
  ushort uVar3;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  switch(*(undefined1 *)(param_1 + 7)) {
  case 0:
    if (*(short *)(param_1 + 0x270) == 3) {
      *(undefined1 *)(param_1 + 7) = 1;
    }
    break;
  case 1:
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined1 *)(param_1 + 0x2c4) = 1;
    *(undefined1 *)(param_1 + 0x2c5) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000f00;
    *(undefined2 *)(param_1 + 500) = 0x1f;
    *(undefined1 *)(param_1 + 0x206) = 0;
  case 2:
    bVar4 = *(char *)(param_1 + 0x206) + 1;
    *(byte *)(param_1 + 0x206) = bVar4;
    if ((bVar4 & 1) == 0) {
      FUN_80167bd8(param_1,10,0,0xf00);
      uVar8 = 0xf00;
    }
    else {
      FUN_80167bd8(param_1,10,0,0xfff);
      uVar8 = 0xfff;
    }
    FUN_80167bd8(param_1,0x11,0,uVar8);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    sVar2 = *(short *)(param_1 + 500);
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(short *)(param_1 + 500) = sVar2 + -1;
    if (sVar2 == 1) {
      *(undefined1 *)(param_1 + 7) = 3;
    }
    break;
  case 3:
    bVar4 = *(char *)(param_1 + 0x206) + 1;
    *(byte *)(param_1 + 0x206) = bVar4;
    if ((bVar4 & 1) == 0) {
      FUN_80167bd8(param_1,10,0,0xf00);
      uVar8 = 0xf00;
    }
    else {
      FUN_80167bd8(param_1,10,0,0xfff);
      uVar8 = 0xfff;
    }
    FUN_80167bd8(param_1,0x11,0,uVar8);
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if ((**(uint **)(param_1 + 0x214) & 0x10000) == 0) break;
    *(undefined1 *)(param_1 + 7) = 4;
    goto LAB_8016267c;
  case 4:
    iVar6 = FUN_80162390(param_1,param_2,param_3,0x180);
    FUN_80167bd8(param_1,0x11,0,(int)*(short *)(param_1 + 500));
    bVar4 = *(char *)(param_1 + 0x206) + 1;
    *(byte *)(param_1 + 0x206) = bVar4;
    if ((bVar4 & 1) == 0) {
      uVar8 = 0xe00;
    }
    else {
      uVar8 = 0xfff;
    }
    FUN_80167bd8(param_1,10,0,uVar8);
    if (iVar6 != 2) break;
    *(undefined1 *)(param_1 + 7) = 5;
LAB_8016267c:
    *(undefined2 *)(param_1 + 500) = 0xfff;
    break;
  case 5:
    iVar6 = FUN_80162390(param_1,param_2,param_3,0x100);
    FUN_80167bd8(param_1,10,0,(int)*(short *)(param_1 + 500));
    if (iVar6 == 3) {
      *(undefined1 *)(param_1 + 7) = 6;
      *(undefined2 *)(param_1 + 500) = 0xfff;
      *(undefined2 *)(param_1 + 0x1f6) = 0xfff;
    }
    break;
  case 6:
    bVar4 = *(char *)(param_1 + 0x206) + 1;
    *(byte *)(param_1 + 0x206) = bVar4;
    if ((bVar4 & 1) == 0) {
      FUN_80167bd8(param_1,9,0,0xd00);
      FUN_80167bd8(param_1,6,0,0xd00);
      FUN_80167bd8(param_1,2,0,0xd00);
      FUN_80167bd8(param_1,3,0,0xd00);
      FUN_80167bd8(param_1,0x12,0,0xd00);
      uVar8 = 0xd00;
    }
    else {
      FUN_80167bd8(param_1,9,0,0xfff);
      FUN_80167bd8(param_1,6,0,0xfff);
      FUN_80167bd8(param_1,2,0,0xfff);
      FUN_80167bd8(param_1,3,0,0xfff);
      FUN_80167bd8(param_1,0x12,0,0xfff);
      uVar8 = 0xfff;
    }
    FUN_80167bd8(param_1,0x13,0,uVar8);
    sVar2 = *(short *)(param_1 + 0x1f6) + -0x100;
    *(short *)(param_1 + 0x1f6) = sVar2;
    if (sVar2 < 0) {
      *(undefined1 *)(param_1 + 7) = 7;
      *(undefined2 *)(param_1 + 0x1f6) = 0xfff;
      *(undefined2 *)(param_1 + 500) = 0xfff;
      *(undefined1 *)(param_1 + 0x207) = 4;
      FUN_80167bd8(param_1,0xb,0,0);
    }
    else {
      FUN_80167bd8(param_1,0xb,0);
    }
    break;
  case 7:
    bVar4 = *(char *)(param_1 + 0x206) + 1;
    *(byte *)(param_1 + 0x206) = bVar4;
    if ((bVar4 & 1) == 0) {
      sVar2 = *(short *)(param_1 + 0x212) + -0x1e;
    }
    else {
      sVar2 = *(short *)(param_1 + 0x212) + 0x1e;
    }
    *(short *)(param_1 + 0x212) = sVar2;
    uVar3 = *(short *)(param_1 + 0x1f6) - 0x400;
    *(ushort *)(param_1 + 0x1f6) = uVar3;
    if ((int)((uint)uVar3 << 0x10) < 0) {
      *(undefined2 *)(param_1 + 0x1f6) = 0;
    }
    FUN_80167bd8(param_1,2,0,(int)*(short *)(param_1 + 0x1f6));
    FUN_80167bd8(param_1,3,0,(int)*(short *)(param_1 + 0x1f6));
    FUN_80167bd8(param_1,0x12,0,(int)*(short *)(param_1 + 0x1f6));
    FUN_80167bd8(param_1,0x13,0,(int)*(short *)(param_1 + 0x1f6));
    FUN_801623e4(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    cVar1 = *(char *)(param_1 + 0x207);
    *(char *)(param_1 + 0x207) = cVar1 + -1;
    if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 7) = 8;
    }
    break;
  case 8:
    bVar4 = *(char *)(param_1 + 0x206) + 1;
    *(byte *)(param_1 + 0x206) = bVar4;
    sVar2 = *(short *)(param_1 + 0x212) + 0x1e;
    if ((bVar4 & 1) == 0) {
      sVar2 = *(short *)(param_1 + 0x212) + -0x1e;
    }
    *(short *)(param_1 + 0x212) = sVar2;
    FUN_801623e4(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    if ((**(uint **)(param_1 + 0x214) & 0x40000) != 0) {
      *(undefined1 *)(param_1 + 7) = 9;
    }
    break;
  case 9:
    sVar2 = *(short *)(param_1 + 0x212) + 500;
    *(short *)(param_1 + 0x212) = sVar2;
    if (0x117f < sVar2) {
      *(undefined2 *)(param_1 + 0x212) = 0x11ff;
      *(undefined1 *)(param_1 + 7) = 10;
    }
    FUN_801623e4(param_1,param_2,param_3);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    break;
  case 10:
    sVar2 = *(short *)(param_1 + 0x212) + -5;
    *(short *)(param_1 + 0x212) = sVar2;
    if (sVar2 < 0xfff) {
      *(undefined2 *)(param_1 + 0x212) = 0xfff;
    }
    FUN_801623e4(param_1,param_2,param_3);
    iVar6 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar6 != 0) {
      *(undefined1 *)(param_1 + 7) = 0xb;
      *(undefined1 *)(param_1 + 0x2c9) = 0;
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
      func_0x80077d18(0xb,param_1);
    }
    break;
  case 0xb:
    uVar7 = 0x14;
    iVar6 = 0x1d60;
    do {
      iVar5 = *(int *)(param_1 + 0x234) + iVar6;
      sVar2 = *(short *)(iVar5 + 0x126) + 0x100;
      *(short *)(iVar5 + 0x126) = sVar2;
      if (0xfff < sVar2) {
        *(undefined2 *)(iVar5 + 0x126) = 0xfff;
      }
      uVar7 = uVar7 + 1;
      iVar6 = iVar6 + 0x178;
    } while (uVar7 < 0x17);
    iVar6 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar6 != 0) {
      *(undefined1 *)(param_1 + 7) = 0xc;
      *(undefined2 *)(param_1 + 500) = 0x1e;
    }
    break;
  case 0xc:
    sVar2 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = sVar2 + -1;
    if (sVar2 == 1) {
      *(undefined2 *)(param_1 + 0x272) = 1;
      *(undefined2 *)(param_1 + 6) = 0x300;
    }
  }
  func_0x80033648(param_1);
  return;
}
