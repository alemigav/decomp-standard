/* FUN_80167ebc
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80167ebc  body 0x80167ebc..0x801686ef  size 2100 B
 * body sha256 945bfb2ff162bb1259351bdb266b129cb36588b2f70996370d844aab22d2854c
 * provider record sha256 3da53ccb44d88e005da1db4fb229ffcb4d44050377810e7632ca7e00234d2009
 * callees 14 direct (14 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167ebc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  undefined2 local_70 [8];
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined1 auStack_40 [32];
  
  local_70[0] = 0xff06;
  local_70[1] = 100;
  if (*(char *)((int)param_1 + 0x2cd) == '\x01') {
    FUN_8016ae0c();
    return;
  }
  if (*(char *)((int)param_1 + 0x2cd) == '\x02') {
LAB_80167f7c:
    FUN_8016aa90(param_1,param_2,param_3);
    return;
  }
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        uVar11 = param_1[0x8d];
        *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfffb;
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
        *(undefined2 *)(uVar11 + 0x2a) = 0xff38;
        *(undefined2 *)(uVar11 + 0x58) = 0;
        *(undefined2 *)(uVar11 + 0x5a) = 0;
        *(undefined2 *)(uVar11 + 0x5c) = 0x400;
        param_1[0xb] = (int)*(short *)((int)param_1 + 0x2ce);
        *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 1;
        if (*(char *)(param_1 + 1) == '\x03') {
          *(undefined2 *)((int)param_1 + 0x1f2) = 10;
        }
        *(undefined2 *)((int)param_1 + 0x1aa) = 0x2001;
        *(undefined2 *)((int)param_1 + 0x136) = 200;
        *(undefined2 *)(param_1 + 0x4e) = 200;
        *(undefined2 *)(param_1 + 0x4b) = 200;
        *(undefined2 *)((int)param_1 + 0x12e) = 200;
        *(undefined2 *)(param_1 + 0x4d) = 0xfea2;
        *(undefined2 *)((int)param_1 + 0x13a) = 0x15e;
        param_1[1] = 0x1000000;
        param_1[0x7a] = 0x5000f00;
        *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
        func_0x80089d54(param_1,param_2,param_3,0x100);
        return;
      }
      goto LAB_80168340;
    }
    if (bVar1 != 0) goto LAB_80168340;
    if (_DAT_800e1130 < 0) {
      *(undefined1 *)((int)param_1 + 0x2cd) = 2;
      goto LAB_80167f7c;
    }
    if (*(short *)(param_1 + 0x6a) != 0) {
      *(undefined1 *)((int)param_1 + 0x2cd) = 1;
LAB_80167fec:
      FUN_8016ae0c(param_1,param_2,param_3);
      return;
    }
    if ((_DAT_800e110c & 0x10000000) != 0) {
      *(undefined1 *)((int)param_1 + 0x2cd) = 1;
      goto LAB_80167fec;
    }
    if ((DAT_800e9012 & 8) == 0) {
      *(undefined1 *)((int)param_1 + 0x2cd) = 1;
      goto LAB_80167fec;
    }
    uVar11 = func_0x80033604();
    if (((uVar11 & 3) != 0) && (*(char *)(param_1 + 1) == '\x03')) {
      *(undefined1 *)((int)param_1 + 0x2cd) = 1;
      goto LAB_80167fec;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x76) = 0;
    *(undefined2 *)((int)param_1 + 0x1da) = 0;
    *(undefined2 *)(param_1 + 0x77) = 0;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    param_1[0x7a] = (4 - (uint)((param_1[0x9b] & 0x200000) != 0)) * 0x1000000 + 0x300;
    uVar2 = *(undefined2 *)((int)local_70 + (*(ushort *)(param_1 + 0x9b) >> 4 & 2));
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)(param_1 + 0x78) = uVar2;
    func_0x80032b5c(param_1,0);
    puVar10 = (uint *)param_1[0x8d];
    puVar10[0x4c] = 0x40;
    puVar10[0x4d] = 0x101030;
    *puVar10 = *puVar10 | 0x80;
    uVar11 = func_0x80033604();
    func_0x80037780(6000,(uVar11 & 0xff) << 4,puVar10 + 0xe,0);
    uVar11 = func_0x80033604();
    uVar7 = func_0x80033604();
    func_0x80037780(((uVar11 & 0xff) + 2000) * 2 | 0x8000000,(uVar7 & 0xff) << 4,puVar10 + 0xe,0);
    uVar11 = func_0x80033604();
    iVar6 = (uVar11 & 3) + 2;
    do {
      iVar6 = iVar6 + -1;
      uVar11 = func_0x80033604();
      uVar7 = func_0x80033604();
      func_0x80037780((uVar11 & 0xff) + 0xc00 | 0x9020000,(uVar7 & 0xff) << 4,puVar10 + 0xe,0);
    } while (iVar6 != 0);
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      uVar11 = func_0x80033604(9);
      uVar5 = 0xd;
      if ((uVar11 & 1) != 0) {
        uVar5 = 0xc;
      }
      func_0x80077d18(uVar5,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
    func_0x80077d18(9,param_1);
    *(undefined2 *)((int)param_1 + 0x2ce) = *(undefined2 *)((int)param_1 + 0x25e);
    func_0x80035b84(param_1);
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  cVar4 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar4;
  func_0x80032b5c(param_1,0);
  if (*(char *)((int)param_1 + 6) == '\x02') {
    uVar11 = param_1[0x8d];
    func_0x80040e58(param_1 + 0x76,&local_60);
    func_0x80041fe0(uVar11 + 8,&local_60);
    func_0x800416bc(&local_60,auStack_40);
    func_0x80040cf4(auStack_40,uVar11 + 0x180);
  }
  if ((*(byte *)((int)param_1 + 0x1e9) != 0) && ((*(byte *)((int)param_1 + 0x1e9) & 3) == 0)) {
    uVar8 = param_1[0x8d];
    uVar11 = func_0x80033604();
    uVar7 = func_0x80033604();
    func_0x80037780((uVar11 & 0xff) * 8 + 6000,(uVar7 & 0xff) << 4,uVar8 + 0x38,param_1 + 0x78);
  }
LAB_80168340:
  if (*(byte *)((int)param_1 + 6) < 2) {
    uVar11 = param_1[0x8d];
    if (*(byte *)((int)param_1 + 0x1e9) < 10) {
      *(undefined2 *)((int)param_1 + 0x1da) = 0;
      *(short *)(param_1 + 0x76) =
           *(short *)(param_1 + 0x76) + *(char *)((int)param_1 + 0x207) * -0x10;
      *(short *)(param_1 + 0x77) =
           *(short *)(param_1 + 0x77) + *(char *)((int)param_1 + 0x207) * 0x18;
      *(char *)((int)param_1 + 0x207) = *(char *)((int)param_1 + 0x207) + '\x01';
    }
    if (*(byte *)((int)param_1 + 0x1e9) - 0xb < 0x13) {
      *(short *)(param_1 + 0x76) = *(short *)(param_1 + 0x76) + *(char *)((int)param_1 + 0x207) * 8;
      *(short *)((int)param_1 + 0x1da) =
           *(short *)((int)param_1 + 0x1da) + *(short *)(param_1 + 0x7d) * -2;
      *(short *)(param_1 + 0x77) = *(short *)(param_1 + 0x77) + *(char *)((int)param_1 + 0x207) * -2
      ;
      *(char *)((int)param_1 + 0x207) = *(char *)((int)param_1 + 0x207) + -1;
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 1;
    }
    if (*(byte *)((int)param_1 + 0x1e9) - 0x1f < 0x13) {
      *(short *)(param_1 + 0x76) = *(short *)(param_1 + 0x76) + *(char *)((int)param_1 + 0x207) * -4
      ;
      *(short *)((int)param_1 + 0x1da) =
           *(short *)((int)param_1 + 0x1da) + *(short *)(param_1 + 0x7d) * 2;
      *(short *)(param_1 + 0x77) = *(short *)(param_1 + 0x77) + *(char *)((int)param_1 + 0x207) * -2
      ;
      *(char *)((int)param_1 + 0x207) = *(char *)((int)param_1 + 0x207) + '\x01';
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -1;
    }
    func_0x80040e58(param_1 + 0x76,&local_60);
    func_0x80041fe0(uVar11 + 8,&local_60);
    func_0x800416bc(&local_60,auStack_40);
    func_0x80040cf4(auStack_40,uVar11 + 0x180);
  }
  if ((*(char *)((int)param_1 + 0x1e9) == '\x14') && (*(char *)((int)param_1 + 6) == '\x01')) {
    uVar11 = param_1[0x8d];
    *(uint **)(uVar11 + 0x1dc) = param_1 + 0x6e;
    uVar7 = *(uint *)(uVar11 + 0x3c);
    uVar8 = *(uint *)(uVar11 + 0x40);
    uVar9 = *(uint *)(uVar11 + 0x44);
    param_1[0x6e] = *(uint *)(uVar11 + 0x38);
    param_1[0x6f] = uVar7;
    param_1[0x70] = uVar8;
    param_1[0x71] = uVar9;
    uVar7 = *(uint *)(uVar11 + 0x4c);
    uVar8 = *(uint *)(uVar11 + 0x50);
    uVar9 = *(uint *)(uVar11 + 0x54);
    param_1[0x72] = *(uint *)(uVar11 + 0x48);
    param_1[0x73] = uVar7;
    param_1[0x74] = uVar8;
    param_1[0x75] = uVar9;
    uVar7 = param_1[0x8d];
    *(undefined2 *)((int)param_1 + 0x1f6) = 10;
    *(undefined1 *)((int)param_1 + 0x206) = 2;
    param_1[0x73] = param_1[10];
    param_1[0x75] = param_1[0xc];
    uVar11 = func_0x80033604();
    func_0x80037780(0x31000,(uVar11 & 0xff) << 4,uVar7 + 0x1b0,0);
    func_0x80077d18(9,param_1);
  }
  if ((0x13 < *(byte *)((int)param_1 + 0x1e9)) && (*(char *)((int)param_1 + 6) == '\x01')) {
    uVar11 = param_1[0x8d];
    *(uint *)(uVar11 + 0x178) = *(uint *)(uVar11 + 0x178) | 0x9000;
    *(uint *)(uVar11 + 0x468) = *(uint *)(uVar11 + 0x468) | 0x9000;
    *(uint *)(uVar11 + 0x2f0) = *(uint *)(uVar11 + 0x2f0) | 0x9000;
    *(uint *)(uVar11 + 0x758) = *(uint *)(uVar11 + 0x758) | 0x9000;
    *(uint *)(uVar11 + 0x5e0) = *(uint *)(uVar11 + 0x5e0) | 0x9000;
    *(uint *)(uVar11 + 0xa48) = *(uint *)(uVar11 + 0xa48) | 0x9000;
    *(uint *)(uVar11 + 0x8d0) = *(uint *)(uVar11 + 0x8d0) | 0x9000;
    func_0x80040e58(param_1 + 0x19,param_1 + 5);
    func_0x800424ec(param_1 + 5,uVar11 + 8,&local_60);
    param_1[0x6e] = local_60;
    param_1[0x6f] = local_5c;
    param_1[0x70] = local_58;
    param_1[0x71] = local_54;
    param_1[0x72] = local_50;
    param_1[0x74] = *(int *)(uVar11 + 0x20) + (int)*(short *)((int)param_1 + 0x2ce);
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      sVar3 = *(short *)((int)param_1 + 0x1f6);
      param_1[0xb] = param_1[0xb] + (int)*(short *)((int)param_1 + 0x1f6);
      *(short *)((int)param_1 + 0x1f6) = sVar3 + 5;
      if (0x22 < *(byte *)((int)param_1 + 0x1e9)) {
        *(short *)((int)param_1 + 0x1f6) = sVar3 + 0x37;
      }
    }
    if (((*(short *)((int)param_1 + 0x2ce) + -200) - *(int *)(uVar11 + 0x20) < (int)param_1[0xb]) &&
       (*(char *)((int)param_1 + 0x206) != '\0')) {
      *(short *)((int)param_1 + 0x1f6) = -(*(short *)((int)param_1 + 0x1f6) >> 3);
      iVar6 = *(int *)(uVar11 + 0x20);
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + -1;
      param_1[0xb] = (*(short *)((int)param_1 + 0x2ce) + -300) - iVar6;
      func_0x80077d18(4);
    }
  }
  return;
}
