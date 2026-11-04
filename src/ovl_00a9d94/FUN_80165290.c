/* FUN_80165290
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80165290  body 0x80165290..0x801657ab  size 1308 B
 * body sha256 6b10f733d2f94d2c4e973940b6430111194820a1dd96e4eae26795d0073e0180
 * provider record sha256 31b8a61b38993c67da2f322023c74e3a3b8dab1d316fb0fe50f2153b11a80818
 * callees 14 direct (14 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165290(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar3;
  ushort uVar4;
  uint uVar2;
  int iVar5;
  int iVar6;
  short local_20;
  short local_1e;
  short local_1c;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
        func_0x80089d54(param_1,param_2,param_3,0x400);
        sVar3 = *(short *)(param_1 + 0x2c0);
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
        *(short *)(param_1 + 0x2c0) = sVar3 + 2;
        *(short *)(param_1 + 0x1e2) = (*(short *)(param_1 + 0x1e2) + 0x78) - sVar3;
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
        func_0x8004dcb8(param_1,0x400);
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x1e0);
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x1e4);
        if ((int)*(short *)(param_1 + 0x25e) < *(int *)(param_1 + 0x2c)) {
          *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
          *(undefined2 *)(param_1 + 0x1e2) = 0;
          *(undefined4 *)(param_1 + 4) = 0x1060000;
        }
        if (-0x5dc < *(int *)(param_1 + 0x2c)) {
          local_20 = 1000;
          local_1e = 0;
          local_1c = 0;
          iVar6 = func_0x8003307c(*(int *)(param_1 + 0x234) + 0xee8,&DAT_800e1158,2000,&local_20);
          if ((iVar6 != 0) && (DAT_800e139f == 0)) {
            sVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                                    (int)_DAT_800e115a,(int)_DAT_800e1162);
            iVar5 = (int)_DAT_800e1196;
            iVar6 = func_0x80059e00(0x1e,0);
            if (iVar6 == 2) {
              _DAT_800e1134 = 0x3000000;
              *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
            }
            else {
              _DAT_800e1134 = (((iVar5 - sVar3) + 0x400U & 0xfff) < 0x800 | 2) * 0x10000 + 0x2000000
              ;
            }
            DAT_800e139f = DAT_800e139f | 0x80;
            _DAT_800e1380 = param_1;
            *(undefined1 *)(param_1 + 0x206) = 6;
            func_0x80077d18(6,param_1);
            *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 2;
            func_0x80052bd0(8,0);
            func_0x80052c6c(0xd,0xfa,2);
          }
        }
      }
      goto LAB_80165680;
    }
    if (bVar1 != 0) goto LAB_80165680;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    if (*(short *)(param_1 + 0x2b4) ==
        *(short *)(&DAT_8016c4dc + (uint)*(byte *)(param_1 + 699) * 2)) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x10000f00;
      *(undefined1 *)(param_1 + 0x207) = 1;
    }
    *(undefined2 *)(param_1 + 0x1e0) = 400;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 0x1a2) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
  }
  if (*(byte *)(param_1 + 0x1e9) < 0xf) {
    func_0x80032ef4(param_1,(int)*(short *)(param_1 + 0x2b4),0x80);
    func_0x80032b5c(param_1,0);
    uVar4 = *(short *)(param_1 + 0x1e0) - 0x28;
    *(ushort *)(param_1 + 0x1e0) = uVar4;
    if ((int)((uint)uVar4 << 0x10) < 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
  }
  if (*(byte *)(param_1 + 0x1e9) - 0xe < 8) {
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0x14 + (uVar2 & 0x7f);
  }
  if (0x15 < *(byte *)(param_1 + 0x1e9)) {
    uVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x80);
    if (*(char *)(param_1 + 0x207) == '\0') {
LAB_80165420:
      if ((int)((uint)uVar4 << 0x10) < 0) {
        *(ushort *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + uVar4;
      }
    }
    else {
      if (0 < (int)((uint)uVar4 << 0x10)) {
        *(ushort *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + uVar4;
      }
      if (*(char *)(param_1 + 0x207) == '\0') goto LAB_80165420;
    }
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 100;
  }
  iVar6 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar6 != 0) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 0x1e2) = 100;
    *(undefined4 *)(param_1 + 0x1e8) = 0xe000300;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xffef;
  }
LAB_80165680:
  if (*(char *)(param_1 + 0x206) != '\0') {
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
    local_20 = 0x76c;
    uVar4 = func_0x80033604();
    local_1e = (uVar4 & 0xff) * -2 + 0x100;
    uVar4 = func_0x80033604();
    local_1c = (uVar4 & 0xff) * -2 + 0x100;
    iVar6 = *(int *)(param_1 + 0x234) + 0xee8;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x1000,(int)*(short *)(param_1 + 0x66),iVar6,&local_20);
    local_20 = 2000;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x11000,(int)*(short *)(param_1 + 0x66),iVar6,&local_20);
    iVar6 = _DAT_800e1364;
    uVar4 = func_0x80033604();
    local_20 = (uVar4 & 0xff) * -2 + 0x100;
    local_1e = 0xff38;
    uVar4 = func_0x80033604();
    local_1c = (uVar4 & 0xff) * -2 + 0x100;
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) << 2 | 0x1000,0,iVar6 + 0x38,&local_20);
  }
  return;
}
