/* FUN_80162848
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80162848  body 0x80162848..0x80162e67  size 1568 B
 * body sha256 7ec36d0463dc8a8741e8dc18ffa88430ced739154defe79ce6c60a428ff3f469
 * provider record sha256 69335843398df08b8fdc08b839e686aee4d6198b334e1931456cf6412e0d5a4e
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162848(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  ushort uVar2;
  uint *puVar3;
  int iVar4;
  undefined2 local_20;
  short local_1e;
  short local_1c;
  
  puVar3 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    puVar3 = *(uint **)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    *puVar3 = *puVar3 | 1;
    func_0x80032dbc(param_1,*(undefined4 *)(_DAT_800e1364 + 0x4c),
                    *(undefined4 *)(_DAT_800e1364 + 0x54),0x800);
    *(undefined2 *)(param_1 + 0x68) = 0xffc0;
    *(undefined2 *)(param_1 + 0x1f6) = 0x28;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 100) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    *(short *)(puVar3 + 0x49) = *(short *)(puVar3 + 0x49) + *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 2;
    if (0xddc < *(short *)(puVar3 + 0x49)) {
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined4 *)(param_1 + 0x1e8) = 0x1003f00;
    }
    if ((0x800 < *(short *)(puVar3 + 0x49)) && (*(char *)(param_1 + 0x207) == '\0')) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x9003f00;
      *(undefined1 *)(param_1 + 0x207) = 1;
    }
    if (*(char *)(param_1 + 0x206) == '\0') {
      *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) - *(short *)(param_1 + 0x1f6);
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -1;
    }
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar1 = *(short *)(puVar3 + 0x49) + *(short *)(param_1 + 500);
    *(short *)(puVar3 + 0x49) = sVar1;
    if (0x1000 < sVar1) {
      *(undefined2 *)(puVar3 + 0x49) = 0x1000;
      *(undefined1 *)(param_1 + 6) = 3;
      uVar2 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar2 & 0xf) + 10;
    }
    if (*(char *)(param_1 + 0x206) == '\0') {
      *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) - *(short *)(param_1 + 0x1f6);
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -8;
    }
    FUN_80166510(param_1,*(undefined4 *)(param_1 + 0x234));
    iVar4 = *(int *)(param_1 + 0x234);
    local_20 = 0x5dc;
    local_1e = 0;
    local_1c = 0;
    func_0x8004276c(iVar4 + 0x4a0,&local_20,&local_20);
    local_1e = local_1e + *(short *)(iVar4 + 0x4ba);
    local_1c = local_1c + *(short *)(iVar4 + 0x4be);
    if ((-400 < local_1e) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
      uVar2 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar2 & 0xf) + 0x1e;
      *(undefined1 *)(param_1 + 0x206) = 1;
      *(undefined2 *)(param_1 + 0x1f6) = 0x40;
    }
    if (((*(ushort *)(param_1 + 700) & 2) != 0) && (DAT_800e139f == '\0')) {
      _DAT_800e1134 = 0x2020000;
      DAT_800e139f = -0x80;
      _DAT_800e1380 = param_1;
      func_0x80052bd0(3,0);
      func_0x80052c6c(10,0xfa,0);
    }
    if (local_1c < -27000) {
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x20;
    }
    if (-0x4d58 < local_1c) {
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x20;
    }
    break;
  case 3:
    if (*(char *)(param_1 + 0x206) == '\0') {
      *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) - *(short *)(param_1 + 0x1f6);
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -8;
    }
    FUN_80166510(param_1,*(undefined4 *)(param_1 + 0x234));
    iVar4 = *(int *)(param_1 + 0x234);
    local_20 = 0x5dc;
    local_1e = 0;
    local_1c = 0;
    func_0x8004276c(iVar4 + 0x4a0,&local_20,&local_20);
    local_1e = local_1e + *(short *)(iVar4 + 0x4ba);
    local_1c = local_1c + *(short *)(iVar4 + 0x4be);
    if (local_1c < -27000) {
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x20;
    }
    if (-0x4d58 < local_1c) {
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x20;
    }
    if ((-400 < local_1e) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 0x206) = 1;
      *(undefined2 *)(param_1 + 0x1f6) = 0x40;
      uVar2 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar2 & 0xf) + 0x14;
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if (((*(ushort *)(param_1 + 700) & 2) != 0) && (DAT_800e139f == '\0')) {
      _DAT_800e1134 = 0x2020000;
      DAT_800e139f = -0x80;
      _DAT_800e1380 = param_1;
      func_0x80052bd0(3,0);
      func_0x80052c6c(10,0xfa,0);
    }
    break;
  case 4:
    sVar1 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar1;
    if (sVar1 == -1) {
      *(undefined1 *)(param_1 + 6) = 5;
      *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
      *(undefined2 *)(param_1 + 500) = 8;
    }
    iVar4 = *(int *)(param_1 + 0x234);
    *(short *)(iVar4 + 0x5c) = *(short *)(iVar4 + 0x5c) + *(short *)(param_1 + 0x1f6);
    *(short *)(iVar4 + 0x1d4) = *(short *)(iVar4 + 0x1d4) - *(short *)(param_1 + 0x1f6);
    *(short *)(iVar4 + 0x34c) = *(short *)(iVar4 + 0x34c) - *(short *)(param_1 + 0x1f6);
    *(short *)(iVar4 + 0x4c4) = *(short *)(iVar4 + 0x4c4) - (*(short *)(param_1 + 0x1f6) >> 1);
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + *(char *)(param_1 + 0x206) * -2;
    FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
    iVar4 = *(int *)(param_1 + 0x234);
    if (((int)*(short *)(param_1 + 0x68) + (int)*(short *)(iVar4 + 0x5c) +
         (int)*(short *)(iVar4 + 0x1d4) + (int)*(short *)(iVar4 + 0x34c) +
         (int)*(short *)(iVar4 + 0x4c4) & 0xfffU) - 0x801 < 0x7ff) {
      *(short *)(iVar4 + 0x5c) = *(short *)(iVar4 + 0x5c) - *(short *)(param_1 + 0x1f6);
      *(short *)(iVar4 + 0x1d4) = *(short *)(iVar4 + 0x1d4) + *(short *)(param_1 + 0x1f6);
      *(short *)(iVar4 + 0x34c) = *(short *)(iVar4 + 0x34c) + *(short *)(param_1 + 0x1f6);
      *(short *)(iVar4 + 0x4c4) = *(short *)(iVar4 + 0x4c4) + (*(short *)(param_1 + 0x1f6) >> 1);
      FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
      *(undefined2 *)(param_1 + 0x1f6) = 0;
      *(undefined1 *)(param_1 + 0x206) = 0;
      *(undefined2 *)(param_1 + 500) = 5;
    }
    break;
  case 5:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    *(short *)(puVar3 + 0x49) = *(short *)(puVar3 + 0x49) - *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 8;
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + 4;
    if (*(short *)(puVar3 + 0x49) < 0) {
      *(undefined2 *)(puVar3 + 0x49) = 0;
      *(undefined4 *)(param_1 + 4) = 0x1000000;
    }
  }
  return;
}
