/* FUN_801626c0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801626c0  body 0x801626c0..0x80162feb  size 2348 B
 * body sha256 8ed39337fcf3a8c0ecd840e805c8e3ab16cb193222d4c0c9ed51afb4e9e95a43
 * provider record sha256 865be808c8da965bebbee17778d9b65dfb1bf39f4dc80b1c57673ba11e90f102
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801626c0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  char cVar5;
  ushort uVar4;
  uint uVar1;
  byte bVar6;
  int iVar2;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0xb000f00;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)((int)param_1 + 0x1f2) = 700;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    if ((_DAT_800e10ec & 0x20) != 0) {
      *(undefined2 *)((int)param_1 + 0x1f2) = 500;
    }
    *(ushort *)(param_1 + 0x9c) = *(ushort *)(param_1 + 0x9c) | 2;
    break;
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    goto LAB_80162fc4;
  case 2:
    *(undefined2 *)(param_1 + 0x7d) = 0x96;
    *(undefined1 *)((int)param_1 + 6) = 3;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0x1000;
  case 3:
    uVar7 = param_1[0x8d];
    iVar2 = uVar7 + 0xeb0;
    *(short *)(*(int *)(uVar7 + 0xfd0) + 0xc) =
         *(short *)((int)param_1 + 0x1f6) +
         (char)(&DAT_8016c498)[*(byte *)((int)param_1 + 0x2c3)] * 3;
    if (*(short *)(param_1 + 0x7d) < 0x50) {
      uVar4 = func_0x80033604();
      *(ushort *)(*(int *)(uVar7 + 0xfd0) + 0xc) =
           *(short *)(*(int *)(uVar7 + 0xfd0) + 0xc) +
           (uVar4 & 0x3f) * ((*(ushort *)(param_1 + 0x7d) & 1) * -2 + 1);
      if ((param_1[0x7d] & 0x10000) == 0) {
        uVar8 = param_1[0x8d];
        uVar7 = func_0x80033604();
        uVar9 = func_0x80033604();
        uVar1 = func_0x80033604();
        func_0x80037780((uVar7 & 1) << 0x10 | (uVar9 & 0xff) * 4 + 0x830,(uVar1 & 0xff) << 4,
                        uVar8 + 0x1060,0);
        uVar8 = param_1[0x8d];
        iVar2 = uVar8 + 0x1608;
        uVar7 = func_0x80033604();
        uVar9 = func_0x80033604();
        uVar1 = func_0x80033604();
        func_0x80037780((uVar7 & 1) << 0x10 | (uVar9 & 0xff) * 4 + 0x830,(uVar1 & 0xff) << 4,
                        uVar8 + 0x1640,0);
      }
    }
    if (*(short *)(param_1 + 0x7d) < 0x1e) {
      if ((param_1[0x7d] & 0x10000) == 0) {
        uVar8 = param_1[0x8d];
        uVar7 = func_0x80033604();
        uVar9 = func_0x80033604();
        uVar1 = func_0x80033604();
        func_0x80037780((uVar7 & 1) << 0x10 | (uVar9 & 0xff) * 4 + 0x1000,(uVar1 & 0xff) << 4,
                        uVar8 + 0x1060,0);
        uVar8 = param_1[0x8d];
        iVar2 = uVar8 + 0x1608;
        uVar7 = func_0x80033604();
        uVar9 = func_0x80033604();
        uVar1 = func_0x80033604();
        func_0x80037780((uVar7 & 1) << 0x10 | (uVar9 & 0xff) * 4 + 0x1000,(uVar1 & 0xff) << 4,
                        uVar8 + 0x1640,0);
      }
      if (*(short *)(param_1 + 0x7d) < 0x1e) {
        uVar4 = func_0x80033604();
        *(ushort *)(*(int *)(iVar2 + 0x120) + 0xc) =
             *(short *)(*(int *)(iVar2 + 0x120) + 0xc) +
             (uVar4 & 0x3f) * ((*(ushort *)(param_1 + 0x7d) & 1) * -2 + 1);
        *(byte *)((int)param_1 + 0x2c3) = *(char *)((int)param_1 + 0x2c3) + 1U & 0x3f;
        *(short *)(*(int *)(param_1[0x8d] + 0x2750) + 0xc) =
             *(short *)((int)param_1 + 0x1f6) +
             (char)(&DAT_8016c498)[*(byte *)((int)param_1 + 0x2c3)] * 3;
        func_0x80066288(param_1);
        *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + -0x30;
      }
    }
    sVar3 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar3 + -1;
    if ((short)(sVar3 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 4;
    }
    *(byte *)((int)param_1 + 0x2c3) = *(char *)((int)param_1 + 0x2c3) + 1U & 0x3f;
    func_0x80066288(param_1,param_1[0x8d] + 0xeb0);
    break;
  case 4:
    param_1[0x7a] = 0xc000f00;
    *(undefined1 *)((int)param_1 + 6) = 5;
    *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
    *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
    *(undefined2 *)(param_1 + 0x55) = 0xfa24;
    *(undefined2 *)((int)param_1 + 0x15a) = 0x5dc;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
  case 5:
    uVar7 = param_1[0x82];
    sVar3 = *(short *)(uVar7 + 4) + 100;
    *(short *)(uVar7 + 4) = sVar3;
    if (0x8fc < sVar3) {
      *(undefined2 *)(uVar7 + 4) = 0x8fc;
    }
    sVar3 = *(short *)(uVar7 + 6) + -10;
    *(short *)(uVar7 + 6) = sVar3;
    if (sVar3 < 0x514) {
      *(undefined2 *)(uVar7 + 6) = 0x514;
    }
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x100);
    uVar7 = 0;
    uVar9 = param_1[0x8d];
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    do {
      if ((uVar7 != 10) && (uVar7 != 0x1a)) {
        *(short *)(*(int *)(uVar9 + 0x120) + 0xc) =
             *(short *)(*(int *)(uVar9 + 0x120) + 0xc) + -0x40;
        if (*(short *)(*(int *)(uVar9 + 0x120) + 0xc) < 0) {
          *(undefined2 *)(*(int *)(uVar9 + 0x120) + 0xc) = 0;
        }
        func_0x80066288(param_1,uVar9);
      }
      uVar7 = uVar7 + 1;
      uVar9 = uVar9 + 0x178;
    } while (uVar7 < 0x1b);
    if ((*(char *)((int)param_1 + 0x1e9) != '\0') && ((*(ushort *)((int)param_1 + 0x1aa) & 1) == 0))
    {
      uVar7 = param_1[0x8d];
      *(short *)(*(int *)(uVar7 + 0xfd0) + 0xc) =
           *(short *)(*(int *)(uVar7 + 0xfd0) + 0xc) - *(short *)((int)param_1 + 0x1f6);
      uVar4 = func_0x80033604();
      *(ushort *)(*(int *)(uVar7 + 0xfd0) + 0xc) =
           *(short *)(*(int *)(uVar7 + 0xfd0) + 0xc) +
           (uVar4 & 0xff) * ((*(ushort *)(param_1 + 0x7d) & 1) * -2 + 1);
      if (*(short *)(*(int *)(uVar7 + 0xfd0) + 0xc) < 0) {
        *(undefined2 *)(*(int *)(uVar7 + 0xfd0) + 0xc) = 0;
        *(undefined1 *)(param_1 + 0xb1) = 4;
        *(undefined1 *)((int)param_1 + 0x2c5) = 0;
        *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 1;
      }
      uVar7 = param_1[0x8d];
      *(short *)(*(int *)(uVar7 + 0x2750) + 0xc) =
           *(short *)(*(int *)(uVar7 + 0x2750) + 0xc) - *(short *)((int)param_1 + 0x1f6);
      if (*(short *)(*(int *)(uVar7 + 0x2750) + 0xc) < 0) {
        *(undefined2 *)(*(int *)(uVar7 + 0x2750) + 0xc) = 0;
      }
      func_0x80066288(param_1,uVar7 + 0x2630);
    }
    uVar7 = param_1[0x8d];
    *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + 2;
    uVar4 = func_0x80033604();
    sVar3 = (uVar4 & 0x3f) * ((*(ushort *)(param_1 + 0x7d) & 1) * -2 + 1);
    iVar2 = *(int *)(uVar7 + 0xfd0);
    *(short *)(iVar2 + 0xc) = *(short *)(iVar2 + 0xc) + sVar3;
    func_0x80066288(param_1,uVar7 + 0xeb0);
    uVar7 = param_1[0x8d];
    iVar2 = *(int *)(uVar7 + 0x2750);
    *(short *)(iVar2 + 0xc) = *(short *)(iVar2 + 0xc) + sVar3;
    func_0x80066288(param_1,uVar7 + 0x2630);
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 1;
    if (*(char *)((int)param_1 + 0x1e9) == 'x') {
      *(undefined1 *)(param_1 + 0xb1) = 3;
      *(undefined1 *)((int)param_1 + 0x2c5) = 0;
    }
    if (*(char *)((int)param_1 + 0x1e9) == -0x74) {
      *(undefined1 *)(param_1 + 0xb1) = 4;
      *(undefined1 *)((int)param_1 + 0x2c5) = 0;
      *param_1 = *param_1 | 0x2000;
    }
    if (((*(byte *)((int)param_1 + 0x1e9) & 1) != 0) && (*(byte *)((int)param_1 + 0x1e9) < 0x2d)) {
      uVar8 = param_1[0x8d];
      uVar7 = func_0x80033604();
      uVar9 = func_0x80033604();
      uVar1 = func_0x80033604();
      func_0x80037780((uVar7 & 1) << 0x10 | (uVar9 & 0xff) * 4 + 0x1000,(uVar1 & 0xff) << 4,
                      uVar8 + 0x1060,0);
      uVar8 = param_1[0x8d];
      uVar7 = func_0x80033604();
      uVar9 = func_0x80033604();
      uVar1 = func_0x80033604();
      func_0x80037780((uVar7 & 1) << 0x10 | (uVar9 & 0xff) * 4 + 0xc18,(uVar1 & 0xff) << 4,
                      uVar8 + 0x1640,0);
      uVar8 = param_1[0x8d];
      uVar7 = func_0x80033604();
      uVar9 = func_0x80033604();
      uVar1 = func_0x80033604();
      func_0x80037780((uVar7 & 1) << 0x10 | (uVar9 & 0xff) * 4 + 0x1000,(uVar1 & 0xff) << 4,
                      uVar8 + 0x17b8,0);
    }
    break;
  case 6:
    param_1[0x7a] = 0xa000700;
    *(undefined1 *)((int)param_1 + 6) = 7;
    *(undefined2 *)((int)param_1 + 0x1aa) = 1;
    *(undefined4 *)((*(byte *)(param_1 + 2) - 0x10) * 4 + -0x7feefac8) = 0x8010f838;
    *param_1 = *param_1 & 0xefffffff;
    *(undefined2 *)(*(int *)(param_1[0x8d] + 0x2750) + 0xc) = 0;
    *(undefined2 *)(*(int *)(param_1[0x8d] + 0xfd0) + 0xc) = 0;
  case 7:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 8;
      *(ushort *)(param_1 + 0x9c) = *(ushort *)(param_1 + 0x9c) | 8;
    }
    goto LAB_80162fc4;
  case 8:
    param_1[0x7a] = 0x5000f00;
    *(undefined1 *)((int)param_1 + 6) = 9;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    bVar6 = func_0x80033604();
    *(byte *)((int)param_1 + 0x206) = (bVar6 & 0xf) + 1;
    DAT_8016c31e = 0;
    func_0x80077d18(0,param_1);
  case 9:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      func_0x80077d18(0xb,param_1);
    }
    if ((param_1[0x9c] & 0x100000) != 0) {
      param_1[1] = 0x1030000;
      *(undefined1 *)(param_1 + 0xb1) = 5;
      *(undefined1 *)((int)param_1 + 0x2ba) = 0x5a;
      *(undefined1 *)(param_1 + 0xb6) = 0x5a;
      *(undefined1 *)((int)param_1 + 0x2c5) = 0;
      *(undefined1 *)((int)param_1 + 0x2ce) = 0;
      *(undefined2 *)(param_1 + 0x78) = 0;
      *(undefined2 *)((int)param_1 + 0x1e2) = 0;
      *(undefined2 *)(param_1 + 0x79) = 0;
      *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfd;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xefff;
      *(short *)((int)param_1 + 0x136) = *(short *)((int)param_1 + 0x136) + -0x32;
      *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + -0x32;
      *(short *)(param_1 + 0x4b) = *(short *)(param_1 + 0x4b) + -0x32;
      *(short *)((int)param_1 + 0x12e) = *(short *)((int)param_1 + 0x12e) + -0x32;
    }
LAB_80162fc4:
    func_0x80032b5c(param_1,0);
  }
  return;
}
