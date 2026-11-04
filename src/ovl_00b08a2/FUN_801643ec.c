/* FUN_801643ec
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801643ec  body 0x801643ec..0x80164c3b  size 2128 B
 * body sha256 46836e303a2d5fb03a1c687e7b380b8936994fa5c38fadc362b323403d06c6be
 * provider record sha256 34524b32f0e7994e60fbc435b77f909b6738e085631048bfb008ebf680f40d6b
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801643ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  short sVar4;
  uint uVar2;
  int iVar3;
  uint *puVar5;
  undefined2 local_20;
  ushort local_1e;
  short local_1c;
  
  puVar5 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    uVar2 = func_0x80033604();
    iVar3 = (uVar2 & 3) * 4;
    *(undefined2 *)(param_1 + 100) =
         *(undefined2 *)(&DAT_801671f8 + ((uint)*(byte *)(param_1 + 0x2b4) + iVar3) * 8);
    *(undefined2 *)(param_1 + 0x66) =
         *(undefined2 *)(&DAT_801671fa + ((uint)*(byte *)(param_1 + 0x2b4) + iVar3) * 8);
    uVar1 = *(undefined2 *)(&DAT_801671fc + ((uint)*(byte *)(param_1 + 0x2b4) + iVar3) * 8);
    *(undefined2 *)(param_1 + 0x1f6) = 0x40;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x68) = uVar1;
    *(undefined2 *)(puVar5 + 0x49) = 0;
    *puVar5 = *puVar5 | 1;
    func_0x80077d18(0,param_1);
    *(byte *)(_DAT_800e13f0 + 0x2c4) =
         *(byte *)(_DAT_800e13f0 + 0x2c4) & ~(byte)(1 << (*(byte *)(param_1 + 0x2b4) + 4 & 0x1f));
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    *(short *)(puVar5 + 0x49) = *(short *)(puVar5 + 0x49) + *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 8;
    if (0xc00 < *(short *)(puVar5 + 0x49)) {
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    }
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) - *(short *)(param_1 + 0x1f6);
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -4;
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    *(short *)(puVar5 + 0x49) = *(short *)(puVar5 + 0x49) + *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 0x10;
    if (0x1000 < *(short *)(puVar5 + 0x49)) {
      *(undefined2 *)(puVar5 + 0x49) = 0x1000;
      *(undefined1 *)(param_1 + 6) = 3;
      func_0x80077d18(0xf,param_1);
    }
  case 3:
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) - *(short *)(param_1 + 0x1f6);
    if (*(char *)(param_1 + 6) == '\x03') {
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -4;
    }
    FUN_80166510(param_1,*(undefined4 *)(param_1 + 0x234));
    iVar3 = *(int *)(param_1 + 0x234);
    local_20 = 0x5dc;
    local_1e = 0;
    local_1c = 0;
    func_0x8004276c(iVar3 + 0x4a0,&local_20,&local_20);
    local_1e = local_1e + *(short *)(iVar3 + 0x4ba);
    local_1c = local_1c + *(short *)(iVar3 + 0x4be);
    if ((0 < (int)((uint)local_1e << 0x10)) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if (((short)local_1e < -5000) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if ((local_1c < -27000) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if ((-0x4d58 < local_1c) && (*(char *)(param_1 + 0x206) == '\0')) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    if (((*(ushort *)(param_1 + 700) & 2) != 0) && (DAT_800e139f == 0)) {
      func_0x80059e00(0xf,1);
      uVar2 = func_0x80033144(param_1,0x800e1130);
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1134 = (~uVar2 & 1) * 0x10000 + 0x5000000;
      _DAT_800e1380 = param_1;
      func_0x80052bd0(3,0);
      func_0x80052c6c(5,0xfa,0);
    }
    break;
  case 4:
    *(undefined2 *)(param_1 + 0x1f6) = 0x40;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined1 *)(param_1 + 0x206) = 1;
    func_0x80077d18(2,param_1);
    *(undefined1 *)(param_1 + 0x2be) = 7;
    *(undefined1 *)(param_1 + 0x2bf) = 1;
  case 5:
    sVar4 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar4;
    if (sVar4 == -1) {
      *(undefined1 *)(param_1 + 6) = 6;
      *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
      *(undefined2 *)(param_1 + 500) = 8;
      *(short *)(param_1 + 0x2b6) = *(short *)(param_1 + 0x2a) + 0x2000;
      *(undefined2 *)(param_1 + 0x2b8) = *(undefined2 *)(puVar5 + 0x49);
    }
    *(short *)(puVar5 + 0x17) = *(short *)(puVar5 + 0x17) + *(short *)(param_1 + 0x1f6);
    *(short *)(puVar5 + 0x75) = *(short *)(puVar5 + 0x75) - *(short *)(param_1 + 0x1f6);
    *(short *)(puVar5 + 0xd3) = *(short *)(puVar5 + 0xd3) - *(short *)(param_1 + 0x1f6);
    *(short *)(puVar5 + 0x131) = *(short *)(puVar5 + 0x131) - (*(short *)(param_1 + 0x1f6) >> 1);
    sVar4 = *(short *)(param_1 + 0x1f6) + *(char *)(param_1 + 0x206) * -2;
    *(short *)(param_1 + 0x1f6) = sVar4;
    if (sVar4 == 0) {
      *(undefined2 *)(param_1 + 500) = 0;
    }
    FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
    iVar3 = *(int *)(param_1 + 0x234);
    if (((int)*(short *)(param_1 + 0x68) + (int)*(short *)(iVar3 + 0x5c) +
         (int)*(short *)(iVar3 + 0x1d4) + (int)*(short *)(iVar3 + 0x34c) +
         (int)*(short *)(iVar3 + 0x4c4) & 0xfffU) - 0x801 < 0x7ff) {
      *(short *)(iVar3 + 0x5c) = *(short *)(iVar3 + 0x5c) - *(short *)(param_1 + 0x1f6);
      *(short *)(iVar3 + 0x1d4) = *(short *)(iVar3 + 0x1d4) + *(short *)(param_1 + 0x1f6);
      *(short *)(iVar3 + 0x34c) = *(short *)(iVar3 + 0x34c) + *(short *)(param_1 + 0x1f6);
      *(short *)(iVar3 + 0x4c4) = *(short *)(iVar3 + 0x4c4) + (*(short *)(param_1 + 0x1f6) >> 1);
      FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
      *(undefined2 *)(param_1 + 0x1f6) = 0;
      *(undefined1 *)(param_1 + 0x206) = 0;
    }
    break;
  case 6:
    *(ushort *)(param_1 + 700) = *(ushort *)(param_1 + 700) | 1;
    *puVar5 = *puVar5 & 0xfffffbff | 0x2000;
    puVar5[0x5e] = puVar5[0x5e] & 0xfffff7ff;
    iVar3 = ((int)*(short *)(param_1 + 0x2b6) - *(int *)(param_1 + 0x28)) * 0x100;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x1fff;
    }
    *(short *)(puVar5 + 0x49) =
         (short)((uint)((iVar3 >> 0xd) * (int)*(short *)(param_1 + 0x2b8)) >> 8);
    *(undefined2 *)(param_1 + 500) = 0;
    break;
  case 7:
    if (*(short *)(param_1 + 500) < 10) {
      *(short *)(puVar5 + 0x17) = *(short *)(puVar5 + 0x17) + *(short *)(param_1 + 500) * -2;
      *(short *)(puVar5 + 0x75) = *(short *)(puVar5 + 0x75) + *(short *)(param_1 + 500) * 2;
      *(short *)(puVar5 + 0xd3) = *(short *)(puVar5 + 0xd3) + *(short *)(param_1 + 500) * 2;
      *(short *)(puVar5 + 0x131) = *(short *)(puVar5 + 0x131) + *(short *)(param_1 + 500);
      FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
    }
    if (*(ushort *)(param_1 + 500) - 6 < 0x4a) {
      uVar2 = func_0x80033604();
      *(uint *)(param_1 + 0x28) =
           *(int *)(param_1 + 0x28) + (uVar2 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
      uVar2 = func_0x80033604();
      *(uint *)(param_1 + 0x2c) =
           *(int *)(param_1 + 0x2c) + (uVar2 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
      uVar2 = func_0x80033604();
      *(uint *)(param_1 + 0x30) =
           *(int *)(param_1 + 0x30) + (uVar2 & 0xf) * ((*(ushort *)(param_1 + 500) & 1) * -2 + 1);
    }
    if (0x50 < *(short *)(param_1 + 500)) {
      *(short *)(puVar5 + 0x17) = *(short *)(puVar5 + 0x17) + 4;
      *(short *)(puVar5 + 0x75) = *(short *)(puVar5 + 0x75) + -4;
      *(short *)(puVar5 + 0xd3) = *(short *)(puVar5 + 0xd3) + -4;
      *(short *)(puVar5 + 0x131) = *(short *)(puVar5 + 0x131) + -2;
      FUN_80166598(param_1,*(undefined4 *)(param_1 + 0x234));
    }
    if (*(short *)(param_1 + 500) == 0x5a) {
      *(undefined1 *)(param_1 + 6) = 8;
    }
    iVar3 = ((int)*(short *)(param_1 + 0x2b6) - *(int *)(param_1 + 0x28)) * 0x100;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x1fff;
    }
    *(short *)(puVar5 + 0x49) =
         (short)((uint)((iVar3 >> 0xd) * (int)*(short *)(param_1 + 0x2b8)) >> 8);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
  case 8:
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
    iVar3 = ((int)*(short *)(param_1 + 0x2b6) - *(int *)(param_1 + 0x28)) * 0x100;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x1fff;
    }
    *(short *)(puVar5 + 0x49) =
         (short)((uint)((iVar3 >> 0xd) * (int)*(short *)(param_1 + 0x2b8)) >> 8);
    break;
  case 9:
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + -1;
    sVar4 = *(short *)(puVar5 + 0x49);
    *(short *)(puVar5 + 0x49) = sVar4 + 0x80;
    if (*(short *)(param_1 + 0x2b8) < (short)(sVar4 + 0x80)) {
      *(undefined2 *)(puVar5 + 0x49) = *(undefined2 *)(param_1 + 0x2b8);
      *puVar5 = *puVar5 & 0xffffdfff | 0x400;
      puVar5[0x5e] = puVar5[0x5e] | 0x800;
      *(undefined1 *)(param_1 + 6) = 10;
      *(ushort *)(param_1 + 700) = *(ushort *)(param_1 + 700) & 0xfffe;
      func_0x80077d18(0,param_1);
    }
    func_0x80089d54(param_1,param_2,param_3,0x40);
    break;
  case 10:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    *(short *)(puVar5 + 0x49) = *(short *)(puVar5 + 0x49) - *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + -1;
    if (*(short *)(puVar5 + 0x49) < 0) {
      *(undefined2 *)(puVar5 + 0x49) = 0;
      *(undefined4 *)(param_1 + 4) = 0x1000000;
    }
  }
  return;
}
