/* FUN_80166c1c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80166c1c  body 0x80166c1c..0x8016738b  size 1904 B
 * body sha256 d7417d446a330a3a35cdb2d851f9084596b76e006ec87eb24932226472513ba4
 * provider record sha256 e4916eead36944b14918beed2ee704ef1397514d3fbefffa88ad2d5f75492648
 * callees 15 direct (15 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166c1c(int param_1)

{
  undefined1 uVar1;
  bool bVar2;
  byte bVar5;
  short sVar3;
  ushort uVar4;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  short local_50;
  short local_4e;
  short local_4c;
  undefined1 auStack_48 [48];
  
  uVar8 = *(uint *)(param_1 + 0x28c);
  if (*(char *)(param_1 + 0x2be) == '\x01') {
    FUN_8016738c(param_1);
    return;
  }
  bVar5 = *(byte *)(param_1 + 6);
  if (bVar5 != 1) {
    if (1 < bVar5) {
      if (bVar5 == 2) {
        func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                        0x10);
        func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0)
        ;
        func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                        0x100);
        iVar7 = *(int *)(param_1 + 0x234);
        local_50 = 0;
        local_4e = 0;
        local_4c = -(*(short *)(param_1 + 500) * (short)*(char *)(param_1 + 0x207)) *
                   *(short *)(param_1 + 0x1f6);
        func_0x80040e58(&local_50,auStack_48);
        func_0x80041fe0(iVar7 + 8,auStack_48);
        local_50 = 0;
        local_4e = 0;
        local_4c = *(short *)(param_1 + 500) * (short)*(char *)(param_1 + 0x207) *
                   *(short *)(param_1 + 0x1f6);
        func_0x80040e58(&local_50,auStack_48);
        func_0x80040cf4(auStack_48,iVar7 + 0x180);
        sVar3 = *(short *)(param_1 + 500) + -1;
        *(short *)(param_1 + 500) = sVar3;
        if (sVar3 == -1) {
          *(undefined1 *)(param_1 + 6) = 3;
        }
        if ((((uVar8 < 0x514) && ((DAT_800e139f & 0x80) == 0)) &&
            (*(char *)(param_1 + 0x1a2) == DAT_800e12d2)) && ((*_DAT_800e13ec & 1) == 0)) {
          if (((*(ushort *)(param_1 + 0x2b6) & 0x20) == 0) &&
             (iVar7 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                      (int)((*(ushort *)(param_1 + 0x66) + 0x100) * 0x10000) >> 0x10
                                      ,0x120), iVar7 == 0)) {
            *(undefined4 *)(param_1 + 4) = 0x1030000;
          }
          if (((*(ushort *)(param_1 + 0x2b6) & 0x40) == 0) &&
             (iVar7 = func_0x80032fac(param_1 + 0x28,&DAT_800e1158,
                                      (int)((*(ushort *)(param_1 + 0x66) - 0x100) * 0x10000) >> 0x10
                                      ,0x120), iVar7 == 0)) {
            *(undefined4 *)(param_1 + 4) = 0x1030000;
          }
        }
      }
      else if (bVar5 == 3) {
        if (*(char *)(param_1 + 5) == '\x0e') {
          FUN_80167c88(param_1);
        }
        bVar2 = false;
        iVar7 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
        if (((iVar7 == 0) && (*(uint *)(param_1 + 0x28c) < 4000)) && ((DAT_800e139f & 0x80) == 0)) {
          uVar8 = func_0x80033604();
          bVar2 = (uVar8 & 0xf) == 0;
        }
        if (bVar2) {
          *(undefined4 *)(param_1 + 4) = 0x10b0000;
          return;
        }
        uVar8 = 0;
        iVar7 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
        if (iVar7 != 0) {
          uVar8 = func_0x80033604();
          uVar8 = uVar8 & 1;
        }
        if (uVar8 != 0) {
          *(undefined4 *)(param_1 + 4) = 0x10c0000;
          return;
        }
        uVar8 = func_0x80033604();
        if ((uVar8 & 1) != 0) {
          *(undefined4 *)(param_1 + 4) = 0x1020000;
          return;
        }
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        if (*(char *)(param_1 + 0x2b4) != *(char *)(param_1 + 0x1e8)) {
          return;
        }
        *(undefined4 *)(param_1 + 4) = 0x1010100;
        bVar5 = func_0x80033604();
        *(byte *)(param_1 + 0x207) = (bVar5 & 0xf) << 1;
        *(undefined2 *)(param_1 + 500) = 0x1e;
        bVar5 = func_0x80033604();
        *(byte *)(param_1 + 0x206) = (bVar5 & 0x1f) + 0x1e;
        uVar4 = func_0x80033604();
        *(ushort *)(param_1 + 0x1f6) = (uVar4 & 0xff) + 300;
      }
      goto LAB_80167358;
    }
    if (bVar5 != 0) goto LAB_80167358;
    if ((uint)*(byte *)(param_1 + 0x2b4) != (uint)*(byte *)(param_1 + 0x1e8)) {
      *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + 0xf00;
    }
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      uVar8 = func_0x80033604();
      uVar6 = 0xb;
      if ((uVar8 & 1) == 0) {
        uVar6 = 0xc;
      }
      func_0x80077d18(uVar6,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    *(undefined1 *)(param_1 + 0x207) = 0x18;
    if (*(char *)(param_1 + 5) == '\x10') {
      if (((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) && (8 < *(byte *)(param_1 + 0x2d6))) {
        FUN_80167910(param_1);
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x800;
      }
      *(undefined1 *)(param_1 + 0x207) = 2;
      *(char *)(param_1 + 0x2d6) = *(char *)(param_1 + 0x2d6) + '\x01';
    }
    uVar1 = *(undefined1 *)(param_1 + 0x1e9);
    iVar9 = 0;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
    *(undefined1 *)(param_1 + 0x1e9) = uVar1;
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1f6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    iVar7 = (uint)*(byte *)(param_1 + 0x2bf) - (uint)(byte)(&DAT_8016e553)[*(byte *)(param_1 + 5)];
    *(char *)(param_1 + 0x2bf) = (char)iVar7;
    if ((((*(ushort *)(param_1 + 0x1aa) & 0x40) == 0) && (iVar7 * 0x1000000 < 1)) &&
       (0x50 < *(short *)(param_1 + 0x1f2))) {
      bVar5 = func_0x80033604();
      *(byte *)(param_1 + 0x2bf) = (bVar5 & 0xf) + 0x10;
    }
    if ((*(ushort *)(param_1 + 0x26c) & 0x20) != 0) {
      *(undefined2 *)(param_1 + 0x1f6) = 0xffff;
      iVar9 = 0x800;
    }
    if (*(char *)(param_1 + 5) != '\x10') {
      if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
        local_50 = 0;
        local_4e = 800;
        local_4c = 0;
        iVar9 = (uint)*(ushort *)(param_1 + 0x66) - iVar9;
        iVar7 = *(int *)(param_1 + 0x234) + 0x1b0;
      }
      else {
        iVar7 = *(int *)(param_1 + 0x234);
        local_50 = *(short *)(iVar7 + 0xbde) + *(short *)(param_1 + 0x1f6) * -100;
        local_4e = *(short *)(iVar7 + 0xbe2) + 300;
        local_4c = *(short *)(iVar7 + 0xbe6);
        iVar9 = (uint)*(ushort *)(param_1 + 0x66) - iVar9;
        iVar7 = *(int *)(param_1 + 0x234) + 0x38;
      }
      func_0x80037780(0x17d0,iVar9 * 0x10000 >> 0x10,iVar7,&local_50);
    }
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
    if (*(char *)(param_1 + 5) == '\x0e') {
      FUN_80167c88(param_1);
    }
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
  func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  *(short *)(param_1 + 0x1e4) = *(short *)(param_1 + 0x1e4) >> 1;
  func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100);
  iVar7 = *(int *)(param_1 + 0x234);
  local_50 = 0;
  local_4e = 0;
  local_4c = *(short *)(param_1 + 500) * (short)*(char *)(param_1 + 0x207) * -8 *
             *(short *)(param_1 + 0x1f6);
  func_0x80040e58(&local_50,auStack_48);
  func_0x80041fe0(iVar7 + 8,auStack_48);
  local_50 = 0;
  local_4e = 0;
  local_4c = *(short *)(param_1 + 500) * (short)*(char *)(param_1 + 0x207) *
             *(short *)(param_1 + 0x1f6) * 8;
  func_0x80040e58(&local_50,auStack_48);
  func_0x80040cf4(auStack_48,iVar7 + 0x180);
  sVar3 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar3 + 1;
  if (2 < sVar3) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 500) = 0x10;
    if (*(char *)(param_1 + 5) == '\x0e') {
      FUN_80167c88(param_1);
    }
  }
LAB_80167358:
  if (*(char *)(param_1 + 0x2b4) == *(char *)(param_1 + 0x1e8)) {
    func_0x80032b5c(param_1,0);
  }
  return;
}
