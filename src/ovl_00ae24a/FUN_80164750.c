/* FUN_80164750
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80164750  body 0x80164750..0x80165307  size 3000 B
 * body sha256 8f3b4d70253f1bc8526d0d1d127a62033a8e5d3b6cbe41803aba20304d0dca4e
 * provider record sha256 4e883d1c06763384ca58112807a23ebef369e70a5ace5e36343bb7f94f3bbcb7
 * callees 19 direct (19 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164750(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar2;
  short sVar3;
  char cVar4;
  int iVar1;
  uint uVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  bool bVar10;
  short local_58;
  short local_56;
  short local_54;
  short local_50;
  short local_4e;
  short local_4c;
  undefined1 auStack_48 [32];
  undefined1 local_28 [8];
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    local_50 = 0;
    local_4c = 0;
    local_4e = _DAT_800e1196;
    func_0x80040e58(&local_50,auStack_48);
    local_50 = 0x1000;
    local_4e = 0;
    func_0x8004276c(auStack_48,&local_50,&local_50);
    iVar9 = (int)local_50;
    bVar10 = false;
    if (((iVar9 < -0x40) && (*(byte *)(param_1 + 5) != 0x10)) && (3 < *(byte *)(param_1 + 5) - 9)) {
      iVar1 = (int)local_4c * (*(int *)(param_1 + 0x28) - (_DAT_800e1158 + -0xc6f));
      if (iVar9 == 0) {
        trap(0x1c00);
      }
      if ((iVar9 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      local_56 = -0x578;
      local_58 = *(short *)(param_1 + 0x2a) + 0xc6f;
      if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
        local_4e = -700;
      }
      if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 2) {
        local_4e = -2000;
      }
      iVar9 = iVar1 / iVar9 + (uint)_DAT_800e1162;
      local_54 = (short)iVar9;
      if (-0x5014 < iVar9 * 0x10000 >> 0x10) {
        local_54 = -0x5014;
      }
      if (local_54 < -26000) {
        local_54 = -26000;
      }
      if (*(char *)(param_1 + 5) == '\x01') {
        local_54 = *(short *)(_DAT_800e1364 + 0x107e);
      }
      uVar5 = func_0x80033604();
      uVar7 = func_0x80033604();
      func_0x80037780((uVar5 & 1) << 0x10 | (uVar7 & 0xff) * 8 + 0x1fa0,0,0x800e9028,&local_58);
      local_58 = local_58 + 500;
      uVar2 = func_0x80033604();
      local_54 = local_54 - ((uVar2 & 0xff) - 0x80);
      uVar5 = func_0x80033604();
      uVar7 = func_0x80033604();
      func_0x80037780((uVar5 & 1) << 0x10 | (uVar7 & 0xff) * 4 + 0x1fa0,0,0x800e9028,&local_58);
      if ((local_54 < -0x57e4) && (-24000 < local_54)) {
        bVar10 = true;
      }
    }
    sVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)(short)_DAT_800e1162);
    if (bVar10) {
      local_58 = *(short *)(param_1 + 0x142) + 500;
      local_56 = *(short *)(param_1 + 0x146);
      local_54 = *(short *)(param_1 + 0x14a);
      uVar5 = func_0x80033604();
      func_0x80037780((uVar5 & 0xff) * 8 + 0x1fa0,(int)sVar3,0x800e9028,&local_58);
      local_50 = local_50 + 500;
      uVar5 = func_0x80033604();
      func_0x80037780((uVar5 & 0xff) * 8 + 0x1fa0 | 0x10000,(int)sVar3,0x800e9028,&local_58);
      if (*(char *)(param_1 + 5) != '\x01') {
        func_0x80077d18(8,param_1);
      }
    }
    cVar4 = *(char *)(param_1 + 5);
    if ((cVar4 == '\t') || (cVar4 == '\x11')) {
      FUN_80163ddc(param_1);
      cVar4 = *(char *)(param_1 + 5);
    }
    if (cVar4 == '\n') {
      FUN_80163974(param_1);
    }
    cVar4 = *(char *)(param_1 + 5);
    if (cVar4 == '\v') {
      FUN_80163bbc(param_1);
      cVar4 = *(char *)(param_1 + 5);
    }
    if (cVar4 == '\x0e') {
      FUN_80163e98(param_1);
    }
    *(undefined1 *)(param_1 + 0x2c1) = 0xf0;
    if ((*(ushort *)(param_1 + 0x2c2) & 2) != 0) {
      *(undefined2 *)(param_1 + 0x1f2) = 0;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
      *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) | 4;
      if (*(char *)(param_1 + 4) == '\x01') {
        FUN_801623b0(param_1,param_2,param_3);
        return;
      }
      FUN_8016464c(param_1,param_2,param_3);
      return;
    }
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    iVar1 = 7;
    *(undefined4 *)(param_1 + 0x1e8) = 0x6001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x270) = *(ushort *)(param_1 + 0x270) | 2;
    func_0x80077d18(10,param_1);
    iVar9 = *(int *)(param_1 + 0x234);
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    do {
      iVar1 = iVar1 + -1;
      uVar5 = func_0x80033604();
      uVar7 = func_0x80033604();
      iVar6 = iVar9 + 0x38;
      iVar9 = iVar9 + 0x178;
      func_0x80037780((uVar5 & 1) << 0x10 | (uVar7 & 0xff) * 4 + 0x1fa0,
                      (int)*(short *)(param_1 + 0x66),iVar6,0);
    } while (iVar1 != 0);
    *(undefined1 *)(param_1 + 0x2b4) = 5;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    func_0x80077d18(0xd,param_1);
    func_0x80052c6c(0xfa,0xb4,0);
    func_0x80052d10(0x96,0xb4,0,0xfa);
    func_0x80052d10(10,0xb4,0xdc,0x14);
    func_0x80052d10(10,0xdc,0xb4,0x1e);
    func_0x80052d10(10,0xb4,0xdc,0x28);
    func_0x80052d10(10,0xdc,0xb4,0x32);
    func_0x80052d10(10,0xb4,0xdc,0x41);
    func_0x80052d10(10,0xdc,0xb4,0x4b);
    func_0x80052d10(10,0xb4,0xdc,0xe6);
    func_0x80052d10(10,0xdc,0xb4,0xf0);
  case 1:
    iVar9 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar9 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x7001f00;
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined2 *)(param_1 + 500) = 0xfa;
    }
    iVar9 = (int)((uint)*(byte *)(param_1 + 0x207) << 0x18) >> 0x1c;
    if (iVar9 < 3) {
      iVar1 = iVar9 * 8;
      iVar9 = (iVar9 + 1) * 8;
      iVar6 = (int)(((uint)*(ushort *)(&DAT_8016700c + iVar9) -
                    (uint)*(ushort *)(&DAT_8016700c + iVar1)) * 0x10000) >> 0x10;
      if (iVar6 < 0) {
        iVar6 = iVar6 + 0xf;
      }
      local_50 = (*(byte *)(param_1 + 0x207) & 0xf) * (short)(iVar6 >> 4);
      iVar6 = (int)(((uint)*(ushort *)(&DAT_8016700e + iVar9) -
                    (uint)*(ushort *)(&DAT_8016700e + iVar1)) * 0x10000) >> 0x10;
      if (iVar6 < 0) {
        iVar6 = iVar6 + 0xf;
      }
      local_4e = (*(byte *)(param_1 + 0x207) & 0xf) * (short)(iVar6 >> 4);
      iVar9 = (int)(((uint)*(ushort *)(&DAT_80167010 + iVar9) -
                    (uint)*(ushort *)(&DAT_80167010 + iVar1)) * 0x10000) >> 0x10;
      if (iVar9 < 0) {
        iVar9 = iVar9 + 0xf;
      }
      local_4c = (*(byte *)(param_1 + 0x207) & 0xf) * (short)(iVar9 >> 4);
      local_58 = *(ushort *)(&DAT_8016700c + iVar1) + local_50;
      local_56 = *(short *)(&DAT_8016700e + iVar1) + local_4e;
      local_54 = *(short *)(&DAT_80167010 + iVar1) + local_4c;
      iVar9 = *(int *)(param_1 + 0x234);
      uVar5 = func_0x80033604();
      uVar7 = func_0x80033604();
      func_0x80037780((uVar5 & 1) << 0x10 | (uVar7 & 0xff) * 8 + 0x1fa0,
                      (int)*(short *)(param_1 + 0x66),iVar9 + 0x328,&local_58);
      *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + '\x01';
    }
    if (*(char *)(param_1 + 0x1e9) == '<') {
      *(undefined1 *)(param_1 + 0x207) = 0;
    }
    iVar9 = 4;
    if ((*(byte *)(param_1 + 0x1e9) & 3) == 0) {
      uVar5 = 0;
      uVar7 = 0;
      do {
        iVar9 = iVar9 + -1;
        if ((((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar5 & 0x1f) & 1U) == 0) &&
           (((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar5 + 4 & 0x1f) & 1U) == 0)) {
          local_28[uVar7 & 0xff] = (char)uVar5;
          uVar7 = uVar7 + 1;
        }
        uVar5 = uVar5 + 1;
      } while (iVar9 != 0);
LAB_801650cc:
      uVar7 = uVar7 & 0xff;
      if (uVar7 != 0) {
        uVar5 = func_0x80033604();
        if (uVar7 == 0) {
          trap(0x1c00);
        }
        FUN_801667c0(local_28[(uVar5 & 0xff) % uVar7],0xe01);
        func_0x80052bd0(3,0);
        func_0x80052c6c(0xf,0xfa,0);
      }
    }
    break;
  case 2:
    iVar9 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar9 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x6001f00;
      uVar5 = func_0x80033604();
      if ((uVar5 & 3) == 0) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x8001f00;
      }
    }
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 3;
      *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) | 8;
      FUN_8016698c(0,0,0);
      FUN_8016698c(1,0,0);
      iVar9 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar9 + 0x2f0) = *(uint *)(iVar9 + 0x2f0) | 0x400;
      *(undefined2 *)(iVar9 + 0x414) = 0x1000;
      *(undefined2 *)(iVar9 + 0x416) = 0x1000;
      *(undefined2 *)(iVar9 + 0x418) = 0x1000;
      *(undefined4 *)(param_1 + 0x1e8) = 0xa001f00;
      func_0x80052c6c(5,200,0);
      func_0x80052d10(200,200,0,5);
      func_0x80052bd0(3,0);
      func_0x80052bd0(3,5);
      func_0x80052bd0(2,0xf);
      func_0x80052bd0(3,0x3c);
      func_0x80052bd0(3,0x41);
      func_0x80052bd0(2,0x4b);
      func_0x80052bd0(3,0x5a);
      func_0x80052bd0(3,0x5f);
      func_0x80052bd0(2,0x69);
      func_0x80052bd0(2,0x6e);
      func_0x80052bd0(2,0x73);
      func_0x80052bd0(1,0x78);
    }
    iVar9 = 4;
    if ((*(byte *)(param_1 + 0x1e9) & 3) != 0) {
      return;
    }
    uVar5 = 0;
    uVar7 = 0;
    do {
      iVar9 = iVar9 + -1;
      if ((((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar5 & 0x1f) & 1U) == 0) &&
         (((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar5 + 4 & 0x1f) & 1U) == 0)) {
        local_28[uVar7 & 0xff] = (char)uVar5;
        uVar7 = uVar7 + 1;
      }
      uVar5 = uVar5 + 1;
    } while (iVar9 != 0);
    goto LAB_801650cc;
  case 3:
    if ((*(ushort *)(param_1 + 500) & 1) == 0) {
      cVar4 = func_0x80089d54(param_1,param_2,param_3,0x80);
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    }
  case 4:
    uVar2 = *(short *)(param_1 + 500) + 1;
    *(ushort *)(param_1 + 500) = uVar2;
    if ((uVar2 & 1) != 0) {
      iVar9 = *(int *)(param_1 + 0x234);
      uVar5 = *(uint *)(iVar9 + 0x60);
      if ((uVar5 & 0xff) != 0x30) {
        *(uint *)(iVar9 + 0x60) = uVar5 - 1;
        uVar5 = *(uint *)(iVar9 + 0x60);
      }
      if ((uVar5 & 0xff00) != 0x3000) {
        *(uint *)(iVar9 + 0x60) = uVar5 - 0x100;
      }
      if ((*(uint *)(iVar9 + 0x60) & 0xff0000) != 0x400000) {
        *(uint *)(iVar9 + 0x60) = *(uint *)(iVar9 + 0x60) - 0x10000;
      }
      uVar5 = func_0x800844e4(*(undefined4 *)(iVar9 + 0x60));
      *(uint *)(iVar9 + 0xcc) = uVar5 | 0xff;
      iVar9 = *(int *)(param_1 + 0x234);
      uVar5 = *(uint *)(iVar9 + 0x350);
      if ((uVar5 & 0xff) != 0x30) {
        *(uint *)(iVar9 + 0x350) = uVar5 - 1;
        uVar5 = *(uint *)(iVar9 + 0x350);
      }
      if ((uVar5 & 0xff00) != 0x3000) {
        *(uint *)(iVar9 + 0x350) = uVar5 - 0x100;
      }
      if ((*(uint *)(iVar9 + 0x350) & 0xff0000) != 0x400000) {
        *(uint *)(iVar9 + 0x350) = *(uint *)(iVar9 + 0x350) - 0x10000;
      }
      uVar5 = func_0x800844e4(*(undefined4 *)(iVar9 + 0x350));
      *(uint *)(iVar9 + 0x3bc) = uVar5 | 0xff;
    }
    iVar9 = *(int *)(param_1 + 0x234);
    sVar3 = *(short *)(*(int *)(iVar9 + 0x410) + 0x14);
    sVar8 = 0x10;
    if (sVar3 < 0xc01) {
      if (sVar3 < 0x801) {
        if (0x400 < sVar3) {
          sVar8 = 0xc;
        }
      }
      else {
        sVar8 = 8;
      }
    }
    else {
      sVar8 = 4;
    }
    *(short *)(*(int *)(iVar9 + 0x410) + 0x14) = *(short *)(*(int *)(iVar9 + 0x410) + 0x14) + sVar8;
    if (0x1000 < *(short *)(*(int *)(iVar9 + 0x410) + 0x14)) {
      *(undefined1 *)(param_1 + 6) = 5;
    }
    iVar1 = *(short *)(*(int *)(iVar9 + 0x410) + 0x14) * 0xb86;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    iVar1 = 0x1194 - (iVar1 >> 0xc);
    *(int *)(iVar9 + 0x310) = iVar1;
    *(int *)(param_1 + 0x2c) = 0x1194 - iVar1;
    break;
  default:
    break;
  }
  return;
}
