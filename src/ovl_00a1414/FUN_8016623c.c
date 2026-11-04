/* FUN_8016623c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016623c  body 0x8016623c..0x8016665b  size 1056 B
 * body sha256 3d5ed32de800c0767c28b4e86a55b879f85be40fa813c721ab69a43ed1296db8
 * provider record sha256 13d3649538f2dde34b9dddee188181018b9fd99cf20912e5a1c8d5d4c8682082
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016623c(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  ushort uVar3;
  uint uVar1;
  char cVar4;
  int iVar5;
  short local_48;
  short local_46;
  short local_44;
  undefined1 auStack_40 [32];
  
  if (*(char *)(param_1 + 6) != '\0') goto LAB_8016662c;
  iVar5 = *(int *)(param_1 + 0x234);
  sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  local_48 = 0;
  local_44 = 0;
  local_46 = sVar2;
  func_0x80040e58(&local_48,auStack_40);
  local_48 = 100;
  uVar3 = func_0x80033604();
  local_46 = (uVar3 & 0xff) * -2 + 0x100;
  uVar3 = func_0x80033604();
  local_44 = 0x80 - (uVar3 & 0xff);
  if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
    local_48 = 100;
    uVar3 = func_0x80033604(auStack_40);
    local_46 = (uVar3 & 0xff) * -2 + 0x3bc;
  }
  func_0x8004276c(auStack_40,&local_48,&local_48);
  local_48 = local_48 + *(short *)(iVar5 + 0x1c6);
  local_46 = local_46 + *(short *)(iVar5 + 0x1ca);
  local_44 = local_44 + *(short *)(iVar5 + 0x1ce);
  if (*(char *)(param_1 + 5) != '\x10') {
    uVar1 = func_0x80033604();
    func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0 | 0x10000,(int)sVar2,0x800e9028,&local_48);
    uVar3 = func_0x80033604();
    local_46 = local_46 - ((uVar3 & 0x3f) - 0x40);
    uVar1 = func_0x80033604();
    func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0,(int)sVar2,0x800e9028,&local_48);
    if (*(char *)(param_1 + 5) != '\x01') {
      func_0x80077d18(8,param_1);
    }
  }
  *(undefined1 *)(param_1 + 700) = 1;
  *(undefined1 *)(param_1 + 0x2bd) = 0;
  if (*(byte *)(param_1 + 0x26e) < 3) {
    cVar4 = *(char *)(param_1 + 5);
    if (cVar4 == '\t') {
      FUN_801669dc(param_1);
      cVar4 = *(char *)(param_1 + 5);
    }
    if (cVar4 == '\x11') {
      FUN_80166b14(param_1);
    }
    cVar4 = *(char *)(param_1 + 5);
    if (cVar4 == '\n') {
      FUN_8016676c(param_1);
      cVar4 = *(char *)(param_1 + 5);
    }
    if (cVar4 == '\v') {
      FUN_8016684c(param_1);
    }
  }
  if ((*(char *)(param_1 + 5) == '\x10') && (*(char *)(param_1 + 0x2c8) == '\0')) {
    FUN_8016676c(param_1);
    *(undefined1 *)(param_1 + 0x2c8) = 0x2d;
  }
  if (*(byte *)(param_1 + 5) - 5 < 2) {
    *(undefined1 *)(param_1 + 0x2c3) = 1;
  }
  if (*(char *)(param_1 + 5) == '\x0e') {
    FUN_80166ca4(param_1);
  }
  if (((*(ushort *)(param_1 + 0x2b8) & 4) == 0) && (*(short *)(param_1 + 0x1f2) < 200)) {
    *(undefined1 *)(param_1 + 0x2b5) = 0x32;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 4;
  }
  if ((*(ushort *)(param_1 + 0x2b8) & 0x80) != 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
    goto LAB_8016662c;
  }
  if ((*(ushort *)(param_1 + 0x2b8) & 1) == 0) {
    if (*(byte *)(param_1 + 5) == 9) {
      cVar4 = *(char *)(param_1 + 0x2b5) + ((byte)(&DAT_8016904b)[*(byte *)(param_1 + 5)] >> 1);
      *(char *)(param_1 + 0x2b5) = cVar4;
      if (*(byte *)(param_1 + 0x26e) < 3) {
        cVar4 = cVar4 + ((byte)(&DAT_8016904b)[*(byte *)(param_1 + 5)] >> 1);
        goto LAB_801665c0;
      }
    }
    else {
      cVar4 = *(char *)(param_1 + 0x2b5) + (&DAT_8016904b)[*(byte *)(param_1 + 5)];
LAB_801665c0:
      *(char *)(param_1 + 0x2b5) = cVar4;
    }
    if ((*(ushort *)(param_1 + 0x2b8) & 2) == 0) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 2;
      *(undefined1 *)(param_1 + 0x2b4) = 0xf;
    }
  }
  if (*(byte *)(param_1 + 0x2b5) < 0xc) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
    FUN_80162624(param_1,param_2,param_3);
    return;
  }
  *(undefined1 *)(param_1 + 0x2b5) = 0;
  *(undefined1 *)(param_1 + 0x2b4) = 0;
  *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffd;
LAB_8016662c:
  FUN_8016665c(param_1,param_2,param_3);
  return;
}
