/* FUN_80165700
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80165700  body 0x80165700..0x801663ef  size 3312 B
 * body sha256 55b5a4483df83e144e62a61186be15c195cffef24036137427ddc84df49cbd18
 * provider record sha256 2a2d9a058bde5fe772cc52d1c01d1360848e953c8662d56fdc1281971ce749c5
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165700(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  uint uVar1;
  int iVar3;
  uint *puVar4;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x13000000;
    *(undefined1 *)(param_1 + 6) = 1;
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    *(uint *)(iVar3 + 0x2f0) = *(uint *)(iVar3 + 0x2f0) | 0xc00;
    *(undefined2 *)(iVar3 + 0x414) = 0x1000;
    *(undefined2 *)(iVar3 + 0x416) = 0x1000;
    *(undefined2 *)(iVar3 + 0x418) = 0x1000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) | 0x800;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x468) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x468) | 0x4800;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) | 0x800;
    iVar3 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar3 + 0x178) = *(uint *)(iVar3 + 0x178) | 0xc00;
    *(undefined2 *)(iVar3 + 0x29c) = 0x1000;
    *(undefined2 *)(iVar3 + 0x29e) = 0x1000;
    *(undefined2 *)(iVar3 + 0x2a0) = 0x1000;
    puVar4 = *(uint **)(param_1 + 0x234);
    *(undefined2 *)(puVar4 + 0x49) = 0x1000;
    *(undefined2 *)((int)puVar4 + 0x126) = 0x1000;
    *(undefined2 *)(puVar4 + 0x4a) = 0x1000;
    *puVar4 = *puVar4 | 0x400;
    *(undefined2 *)(param_1 + 500) = 0x96;
    *(undefined1 *)(param_1 + 0x206) = 0;
  case 1:
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    break;
  case 2:
    iVar3 = *(int *)(param_1 + 0x234);
    if (*(byte *)(param_1 + 0x1e9) - 6 < 0x1d) {
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0xc) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0xc) + (*(byte *)(param_1 + 0x1e9) - 10) * -8;
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0x10) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0x10) + (*(byte *)(param_1 + 0x1e9) - 10) * 8;
    }
    if (*(byte *)(param_1 + 0x1e9) - 0x24 < 0x18) {
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0xc) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0xc) + (*(byte *)(param_1 + 0x1e9) - 0x23) * 4;
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0x10) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0x10) + (*(byte *)(param_1 + 0x1e9) - 0x23) * -4;
    }
    if (*(byte *)(param_1 + 0x1e9) - 0x3d < 0xe) {
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0xc) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0xc) + (*(byte *)(param_1 + 0x1e9) - 0x3c) * -8;
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0x10) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0x10) + (*(byte *)(param_1 + 0x1e9) - 0x3c) * 8;
    }
    if (0x4b < *(byte *)(param_1 + 0x1e9)) {
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0xc) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0xc) + (*(byte *)(param_1 + 0x1e9) - 0x4b) * 2;
      *(ushort *)(*(int *)(iVar3 + 0x410) + 0x10) =
           *(short *)(*(int *)(iVar3 + 0x410) + 0x10) + (*(byte *)(param_1 + 0x1e9) - 0x4b) * -2;
    }
    *(ushort *)(*(int *)(iVar3 + 0x410) + 0xc) =
         *(short *)(*(int *)(iVar3 + 0x410) + 0xc) +
         ((*(byte *)(param_1 + 0x1e9) & 1) * 2 + -1) * -0x3c;
    *(ushort *)(*(int *)(iVar3 + 0x410) + 0x10) =
         *(short *)(*(int *)(iVar3 + 0x410) + 0x10) +
         ((*(byte *)(param_1 + 0x1e9) & 1) * 2 + -1) * 0x3c;
    func_0x80066288(param_1);
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x14000f00;
      *(undefined1 *)(param_1 + 6) = 3;
      *(undefined1 *)(param_1 + 0x207) = 0;
      *(undefined2 *)(param_1 + 500) = 0;
    }
    goto LAB_80166278;
  case 3:
    func_0x800334c8(param_1,param_2,param_3,0);
    if (*(char *)(param_1 + 0x1e9) == '\0') {
      *(undefined1 *)(param_1 + 0x1e9) = 1;
      func_0x800334c8(param_1,param_2,param_3,0);
      *(undefined1 *)(param_1 + 0x1ea) = 0xf;
      *(char *)(param_1 + 0x1e9) = *(char *)(param_1 + 0x1e9) + -1;
    }
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80032b5c(param_1,0);
    iVar3 = *(int *)(param_1 + 0x234);
    if (*(short *)(param_1 + 500) < 0x1f) {
LAB_80165af0:
      if ((*(byte *)(param_1 + 0x207) & 1) != 0) goto LAB_80165b00;
    }
    else {
      if ((*(byte *)(param_1 + 0x207) & 1) == 0) {
        *(short *)(*(int *)(iVar3 + 0x410) + 0xc) =
             *(short *)(*(int *)(iVar3 + 0x410) + 0xc) + (*(short *)(param_1 + 500) + -0x1e) * -4;
        *(short *)(*(int *)(iVar3 + 0x410) + 0x10) =
             *(short *)(*(int *)(iVar3 + 0x410) + 0x10) + (*(short *)(param_1 + 500) + -0x1e) * 4;
        if (0x1000 < *(short *)(*(int *)(iVar3 + 0x410) + 0x10)) {
          *(undefined2 *)(*(int *)(iVar3 + 0x410) + 0x10) = 0x1000;
          *(undefined2 *)(*(int *)(iVar3 + 0x410) + 0xc) = 0;
          *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) | 1;
        }
        goto LAB_80165af0;
      }
LAB_80165b00:
      if ((*(byte *)(param_1 + 0x207) & 4) == 0) {
        *(short *)(*(int *)(iVar3 + 0x410) + 0x10) =
             *(short *)(*(int *)(iVar3 + 0x410) + 0x10) + -0x80;
        if (*(short *)(*(int *)(iVar3 + 0x410) + 0x10) < 0) {
          *(undefined2 *)(*(int *)(iVar3 + 0x410) + 0x10) = 0;
          *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) | 4;
        }
      }
    }
    *(ushort *)(*(int *)(iVar3 + 0x410) + 0xc) =
         *(short *)(*(int *)(iVar3 + 0x410) + 0xc) +
         ((*(byte *)(param_1 + 0x1e9) & 1) * 2 + -1) * 0x78;
    *(ushort *)(*(int *)(iVar3 + 0x410) + 0x10) =
         *(short *)(*(int *)(iVar3 + 0x410) + 0x10) +
         ((*(byte *)(param_1 + 0x1e9) & 1) * 2 + -1) * -0x78;
    func_0x80066288(param_1);
    if (*(short *)(param_1 + 500) == 0x29) {
      func_0x80037780(0x31fa0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x4a0,0);
    }
    if (0x2d < *(short *)(param_1 + 500)) {
      iVar3 = *(int *)(param_1 + 0x234);
      if ((*(uint *)(iVar3 + 0x468) & 0x400) != 0) {
        *(uint *)(iVar3 + 0x468) = *(uint *)(iVar3 + 0x468) & 0xffffbfff;
        sVar2 = *(short *)(iVar3 + 0x58e) + (*(short *)(param_1 + 500) + -0x2d) * 2;
        *(short *)(iVar3 + 0x58e) = sVar2;
        if (0xfff < sVar2) {
          *(uint *)(iVar3 + 0x468) = *(uint *)(iVar3 + 0x468) & 0xfffffbff;
          *(undefined4 *)(param_1 + 0x1e8) = 0x15000f00;
          *(undefined1 *)(param_1 + 6) = 4;
          *(undefined1 *)(param_1 + 0x207) = 0;
        }
      }
    }
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    break;
  case 4:
    func_0x800334c8(param_1,param_2,param_3,0);
    if (*(char *)(param_1 + 0x1e9) == '\0') {
      *(undefined1 *)(param_1 + 0x1e9) = 1;
      func_0x800334c8(param_1,param_2,param_3,0);
      *(char *)(param_1 + 0x1e9) = *(char *)(param_1 + 0x1e9) + -1;
    }
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x16000f00;
      *(undefined1 *)(param_1 + 6) = 5;
      *(undefined1 *)(param_1 + 0x207) = 0;
      *(undefined2 *)(param_1 + 500) = 0;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    }
    goto LAB_80166278;
  case 5:
    sVar2 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar2;
    if (sVar2 == 0x2e) {
      *(undefined1 *)(param_1 + 0x207) = 0;
      *(undefined1 *)(param_1 + 6) = 6;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
      DAT_801697ea = 0;
      DAT_801697eb = 0;
    }
    sVar2 = *(short *)(param_1 + 500);
    if (sVar2 == 0x14) {
      DAT_801697ea = 0xf9;
      DAT_801697eb = 0;
      sVar2 = *(short *)(param_1 + 500);
    }
    if (sVar2 == 0x1e) {
      DAT_801697ea = 0xf9;
      DAT_801697eb = 7;
    }
    iVar3 = *(int *)(param_1 + 0x234);
    if ((0 < *(short *)(param_1 + 500)) && ((*(byte *)(param_1 + 0x207) & 1) == 0)) {
      *(short *)(*(int *)(iVar3 + 0x700) + 0xc) =
           *(short *)(*(int *)(iVar3 + 0x700) + 0xc) + *(short *)(param_1 + 500) * -0x10;
      if (*(short *)(*(int *)(iVar3 + 0x700) + 0xc) < 0) {
        *(undefined2 *)(*(int *)(iVar3 + 0x700) + 0xc) = 0;
        *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) | 1;
      }
    }
    func_0x80066288(param_1,iVar3 + 0x5e0);
    break;
  case 6:
    local_20 = 0xff9c;
    local_1e = 100;
    local_1c = 0;
    iVar3 = *(int *)(param_1 + 0x234);
    if ((0xf < *(byte *)(param_1 + 0x1e9)) && ((*(uint *)(iVar3 + 0xbc0) & 0x400) != 0)) {
      sVar2 = *(short *)(iVar3 + 0xce6) + (*(byte *)(param_1 + 0x1e9) - 0xf) * 0x20;
      *(short *)(iVar3 + 0xce6) = sVar2;
      if (0xfff < sVar2) {
        *(uint *)(iVar3 + 0xbc0) = *(uint *)(iVar3 + 0xbc0) & 0xfffffbff;
      }
      *(ushort *)(iVar3 + 0xce4) =
           *(short *)(iVar3 + 0xce4) + (*(byte *)(param_1 + 0x1e9) - 0xf) * 0x20;
      *(ushort *)(iVar3 + 0xce8) =
           *(short *)(iVar3 + 0xce8) + (*(byte *)(param_1 + 0x1e9) - 0xf) * 0x20;
      if (0xfff < *(short *)(iVar3 + 0xce6)) {
        *(undefined2 *)(iVar3 + 0xce4) = 0x1000;
        *(undefined2 *)(iVar3 + 0xce8) = 0x1000;
      }
      if ((*(byte *)(param_1 + 0x1e9) & 1) != 0) {
        uVar1 = func_0x80033604();
        func_0x80037780((uVar1 & 0xff) << 3 | 0x140800,0,iVar3 + 0xbf8,&local_20);
      }
      iVar3 = *(int *)(param_1 + 0x234);
    }
    if ((0x14 < *(byte *)(param_1 + 0x1e9)) && ((*(uint *)(iVar3 + 0x8d0) & 0x400) != 0)) {
      sVar2 = *(short *)(iVar3 + 0x9f6) + (*(byte *)(param_1 + 0x1e9) - 0x14) * 0x20;
      *(short *)(iVar3 + 0x9f6) = sVar2;
      if (0xfff < sVar2) {
        *(uint *)(iVar3 + 0x8d0) = *(uint *)(iVar3 + 0x8d0) & 0xfffffbff;
      }
      *(ushort *)(iVar3 + 0x9f4) =
           *(short *)(iVar3 + 0x9f4) + (*(byte *)(param_1 + 0x1e9) - 0x14) * 0x20;
      *(ushort *)(iVar3 + 0x9f8) =
           *(short *)(iVar3 + 0x9f8) + (*(byte *)(param_1 + 0x1e9) - 0x14) * 0x20;
      if (0xfff < *(short *)(iVar3 + 0x9f6)) {
        *(undefined2 *)(iVar3 + 0x9f4) = 0x1000;
        *(undefined2 *)(iVar3 + 0x9f8) = 0x1000;
      }
      if ((*(byte *)(param_1 + 0x1e9) & 1) != 0) {
        uVar1 = func_0x80033604();
        func_0x80037780((uVar1 & 0xff) << 3 | 0x140800,0,iVar3 + 0x908,&local_20);
      }
    }
    iVar3 = *(int *)(param_1 + 0x234);
    if ((0x28 < *(byte *)(param_1 + 0x1e9)) && ((*(uint *)(iVar3 + 0xa48) & 0x400) != 0)) {
      sVar2 = *(short *)(iVar3 + 0xb6e) + (*(byte *)(param_1 + 0x1e9) - 0x28) * 0x20;
      *(short *)(iVar3 + 0xb6e) = sVar2;
      if (0xfff < sVar2) {
        *(uint *)(iVar3 + 0xa48) = *(uint *)(iVar3 + 0xa48) & 0xfffffbff;
      }
      *(ushort *)(iVar3 + 0xb6c) =
           *(short *)(iVar3 + 0xb6c) + (*(byte *)(param_1 + 0x1e9) - 0x28) * 0x20;
      *(ushort *)(iVar3 + 0xb70) =
           *(short *)(iVar3 + 0xb70) + (*(byte *)(param_1 + 0x1e9) - 0x28) * 0x20;
      if (0xfff < *(short *)(iVar3 + 0xb6e)) {
        *(undefined2 *)(iVar3 + 0xb6c) = 0x1000;
        *(undefined2 *)(iVar3 + 0xb70) = 0x1000;
      }
      if ((*(byte *)(param_1 + 0x1e9) & 1) != 0) {
        uVar1 = func_0x80033604(param_1);
        func_0x80037780((uVar1 & 0xff) << 3 | 0x140800,0,iVar3 + 0xa80,&local_20);
      }
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 6) = 7;
      *(undefined2 *)(param_1 + 500) = 0;
      *(undefined4 *)(param_1 + 0x1e8) = 0xff00;
      *(ushort *)(param_1 + 0x270) = *(ushort *)(param_1 + 0x270) | 2;
    }
    goto LAB_80166278;
  case 7:
    if (0x1e < *(short *)(param_1 + 500)) {
      func_0x80089d54(param_1,param_2,param_3,0x10);
    }
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    if ((*(ushort *)(param_1 + 0x270) & 4) != 0) {
      *(undefined1 *)(param_1 + 6) = 8;
      *(undefined2 *)(param_1 + 0x1e0) = 200;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 500) = 0;
      *(undefined4 *)(param_1 + 0x1e8) = 0xf000000;
      func_0x80089d54(param_1,param_2,param_3,0x100);
      *(uint *)(*(int *)(param_1 + 0x234) + 0x2f0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x2f0) & 0xfffff3ff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) & 0xfffff7ff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0x468) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x468) & 0xffffb7ff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) & 0xfffff7ff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0x178) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x178) & 0xfffff3ff;
      **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) & 0xfffffbff;
      func_0x80077d18(9,param_1);
    }
    break;
  case 8:
    iVar3 = *(int *)(param_1 + 0x2c) + *(short *)(param_1 + 500) * 0x1e;
    *(int *)(param_1 + 0x2c) = iVar3;
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    if (-2000 < iVar3) {
      *(undefined1 *)(param_1 + 6) = 9;
    }
    goto LAB_80166278;
  case 9:
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 6) = 10;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    }
    iVar3 = *(int *)(param_1 + 0x2c) + *(short *)(param_1 + 500) * 0x1e;
    *(int *)(param_1 + 0x2c) = iVar3;
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    if (-400 < iVar3) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    if (0xb < *(byte *)(param_1 + 0x1e9)) break;
LAB_80166278:
    func_0x80032b5c(param_1,0);
    break;
  case 10:
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 10;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  iVar3 = *(int *)(param_1 + 0x234);
  *(short *)(iVar3 + 0x414) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  *(short *)(iVar3 + 0x416) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  *(short *)(iVar3 + 0x418) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  iVar3 = *(int *)(param_1 + 0x234);
  *(short *)(iVar3 + 0x29c) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  *(short *)(iVar3 + 0x29e) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  *(short *)(iVar3 + 0x2a0) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  iVar3 = *(int *)(param_1 + 0x234);
  *(short *)(iVar3 + 0x124) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  *(short *)(iVar3 + 0x126) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  *(short *)(iVar3 + 0x128) = 0x1000 - (char)(&DAT_801697a0)[*(char *)(param_1 + 0x206)];
  *(byte *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + 1U & 0x3f;
  return;
}
