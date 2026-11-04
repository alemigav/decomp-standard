/* FUN_80165018
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80165018  body 0x80165018..0x801658db  size 2244 B
 * body sha256 82d5d39f4671416b099f7fe4f06c1f3cfd29ae99faeca3fed7afa9980761c3aa
 * provider record sha256 6f3f3dcf80791ed025a2e4b5db021af8aa96c4bbf969665a6d4c1f9afc4850ac
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165018(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  char cVar4;
  short sVar3;
  int iVar2;
  int iVar5;
  uint *puVar6;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    iVar5 = 0x10;
    iVar2 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0x14000000;
    *(undefined1 *)(param_1 + 0x206) = 0x3c;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x2b4) = 0;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined2 *)(iVar2 + 0x1b8c) = 0;
    *(undefined1 *)(iVar2 + 0x1b81) = 0;
    puVar6 = *(uint **)(param_1 + 0x234);
    do {
      iVar5 = iVar5 + -1;
      *puVar6 = *puVar6 | 0x4000;
      puVar6 = puVar6 + 0x5e;
    } while (iVar5 != 0);
    *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x758) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x758) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xeb0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xeb0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1028) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1028) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x11a0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x11a0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1318) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1318) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1490) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1490) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1608) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1608) & 0xffffbfff;
    iVar2 = *(int *)(param_1 + 0x234);
    *(undefined2 *)(*(int *)(iVar2 + 0x700) + 0xc) = 0;
    *(undefined2 *)(*(int *)(iVar2 + 0x700) + 0x10) = 0x1000;
    func_0x80066288(param_1);
  case 1:
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(short *)(param_1 + 0x1e0) = (short)((int)((uint)*(byte *)(param_1 + 0x206) << 0x18) >> 0x1a);
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined1 *)(param_1 + 0x207) = 1;
    }
    break;
  case 2:
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x100);
    iVar2 = *(int *)(param_1 + 0x234);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    *(short *)(iVar2 + 0x1a20) = *(short *)(iVar2 + 0x1a20) + 0x199;
    *(short *)(*(int *)(iVar2 + 0x1a18) + 0xc) = *(char *)(param_1 + 0x207) * -0x1000 + 0x1000;
    *(short *)(*(int *)(iVar2 + 0x1a18) + 0x10) = (short)*(char *)(param_1 + 0x207) << 0xc;
    func_0x80066288(param_1);
    *(byte *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + 1U & 1;
    break;
  case 3:
    *(undefined2 *)(param_1 + 500) = 0x2d;
    *(undefined1 *)(param_1 + 6) = 4;
    *(undefined2 *)(param_1 + 0x1f6) = 0x80;
    *(undefined1 *)(param_1 + 0x206) = 6;
    *(undefined2 *)(param_1 + 500) = 0;
  case 4:
    iVar2 = *(int *)(param_1 + 0x234);
    iVar5 = *(int *)(iVar2 + 0x1a18);
    *(short *)(iVar5 + 0xc) = *(short *)(iVar5 + 0xc) - *(short *)(param_1 + 0x1f6);
    func_0x80066288(param_1,iVar2 + 0x18f8);
    cVar4 = *(char *)(param_1 + 0x206) + -1;
    *(char *)(param_1 + 0x206) = cVar4;
    if (cVar4 == -1) {
      *(undefined1 *)(param_1 + 0x206) = 6;
      *(short *)(param_1 + 0x1f6) = -*(short *)(param_1 + 0x1f6);
    }
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 5;
      *(undefined2 *)(param_1 + 500) = 0;
    }
    break;
  case 5:
    iVar2 = *(int *)(param_1 + 0x234);
    if (*(short *)(param_1 + 500) < 0x10) {
      *(short *)(*(int *)(iVar2 + 0x1a18) + 0xc) =
           *(short *)(*(int *)(iVar2 + 0x1a18) + 0xc) + 0x100;
      func_0x80066288(param_1,iVar2 + 0x18f8);
      *(short *)(iVar2 + 0x1a20) = *(short *)(iVar2 + 0x1a20) + -0x14;
    }
    else {
      *(short *)(iVar2 + 0x1a20) = *(short *)(iVar2 + 0x1a20) + 0x14;
      *(short *)(*(int *)(iVar2 + 0x1a18) + 0xc) =
           *(short *)(*(int *)(iVar2 + 0x1a18) + 0xc) + -0x200;
      func_0x80066288(param_1,iVar2 + 0x18f8);
    }
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      iVar2 = *(int *)(param_1 + 0x234);
      *(undefined1 *)(param_1 + 6) = 6;
      *(undefined2 *)(param_1 + 500) = 0x1e;
      *(undefined2 *)(param_1 + 0x1f6) = 0;
      *(undefined1 *)(param_1 + 0x2b4) = 1;
      *(undefined1 *)(param_1 + 0x2b5) = 0;
      *(undefined2 *)(iVar2 + 0x1b8c) = 0;
      *(undefined1 *)(iVar2 + 0x1b81) = 0;
    }
    break;
  case 6:
    iVar2 = *(int *)(param_1 + 0x234);
    *(short *)(*(int *)(iVar2 + 0x1a18) + 0x10) =
         *(short *)(*(int *)(iVar2 + 0x1a18) + 0x10) + 0x100;
    func_0x80066288(param_1,iVar2 + 0x18f8);
    *(short *)(iVar2 + 0x1950) = *(short *)(iVar2 + 0x1950) + *(short *)(param_1 + 0x1f6);
    sVar3 = *(short *)(param_1 + 0x1f6);
    *(short *)(param_1 + 0x1f6) = sVar3 + 3;
    if (*(short *)(param_1 + 500) < 5) {
      *(short *)(param_1 + 0x1f6) = sVar3 + -3;
    }
    func_0x80040e58(iVar2 + 0x1950,iVar2 + 0x1900);
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      iVar2 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar2 + 0x18f8) = *(uint *)(iVar2 + 0x18f8) | 0x8040;
      *(undefined2 *)(iVar2 + 0x1950) = 600;
      *(undefined2 *)(iVar2 + 0x1952) = 0;
      *(undefined2 *)(iVar2 + 0x1954) = 0x400;
      func_0x80040e58(iVar2 + 0x1950,iVar2 + 0x1900);
      func_0x80041fe0(iVar2 + 0x1930,iVar2 + 0x1900);
      *(undefined4 *)(iVar2 + 0x1944) = 0xffffcabd;
      *(undefined4 *)(iVar2 + 0x194c) = 0xffffbbb0;
      *(undefined1 *)(param_1 + 0x207) = 1;
      if (*(char *)(_DAT_800e13f0 + 8) == 'D') {
        *(undefined4 *)(iVar2 + 0x1944) = 0xffffae46;
        *(undefined4 *)(iVar2 + 0x194c) = 0xffff9e44;
        *(undefined1 *)(param_1 + 0x207) = 0;
      }
      *(undefined1 *)(param_1 + 6) = 7;
      *(undefined2 *)(param_1 + 500) = 0x1e;
      *(undefined1 *)(param_1 + 0x206) = 3;
      *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
      if (*(char *)(param_1 + 0x207) != '\0') {
        *(int *)(iVar2 + 0x1948) = *(int *)(iVar2 + 0x1948) + -2000;
      }
    }
    break;
  case 7:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    iVar5 = *(int *)(param_1 + 0x234);
    *(undefined2 *)(iVar5 + 0x1950) = *(undefined2 *)(param_1 + 0x1f6);
    *(undefined2 *)(iVar5 + 0x1952) = 0;
    *(undefined2 *)(iVar5 + 0x1954) = 0;
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -2;
    func_0x80040e58(iVar5 + 0x1950,iVar5 + 0x1900);
    func_0x80040cf4(iVar5 + 0x1900,iVar5 + 0x1930);
    iVar2 = 0;
    *(int *)(iVar5 + 0x1948) = *(int *)(iVar5 + 0x1948) + (int)*(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 9;
    if (*(char *)(param_1 + 0x207) != '\0') {
      iVar2 = 0x96;
    }
    if (iVar2 < *(int *)(iVar5 + 0x1948)) {
      *(int *)(iVar5 + 0x1948) = iVar2;
      cVar4 = *(char *)(param_1 + 0x206) + -1;
      *(char *)(param_1 + 0x206) = cVar4;
      *(short *)(param_1 + 500) = -(*(short *)(param_1 + 500) >> 3);
      if (cVar4 == -1) {
        *(undefined1 *)(param_1 + 6) = 8;
        *(undefined2 *)(param_1 + 500) = 8;
        *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
        *(undefined1 *)(param_1 + 0x207) = 0;
        *(undefined1 *)(param_1 + 0x206) = 0;
      }
      *(short *)(*(int *)(iVar5 + 0x1a18) + 0x10) =
           *(short *)(*(int *)(iVar5 + 0x1a18) + 0x10) + -0x100;
    }
    *(short *)(*(int *)(iVar5 + 0x1a18) + 0x10) =
         *(short *)(*(int *)(iVar5 + 0x1a18) + 0x10) + -0x100;
    func_0x80066288(param_1,iVar5 + 0x18f8);
    *(undefined2 *)(param_1 + 0x1e0) = 0xffec;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    goto LAB_8016575c;
  case 8:
    iVar2 = *(int *)(param_1 + 0x234);
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 9;
      *(undefined2 *)(param_1 + 500) = 8;
    }
    iVar5 = *(int *)(iVar2 + 0x1a18);
    *(short *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + 0x40;
    func_0x80066288(param_1,iVar2 + 0x18f8);
    uVar1 = *(ushort *)(param_1 + 0x270);
    goto joined_r0x801656bc;
  case 9:
    iVar2 = *(int *)(param_1 + 0x234);
    iVar5 = *(int *)(iVar2 + 0x1a18);
    *(short *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + -0x40;
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 8;
      *(undefined2 *)(param_1 + 500) = 8;
    }
    func_0x80066288(param_1,iVar2 + 0x18f8);
    uVar1 = *(ushort *)(param_1 + 0x270);
joined_r0x801656bc:
    if ((uVar1 & 2) != 0) {
      iVar2 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar2 + 0x700) + 0x10) =
           *(short *)(*(int *)(iVar2 + 0x700) + 0x10) + *(char *)(param_1 + 0x207) * -10;
      if (*(char *)(param_1 + 0x207) < 'Z') {
        *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + '\x01';
      }
      if (*(short *)(*(int *)(iVar2 + 0x700) + 0x10) < 0) {
        *(undefined2 *)(*(int *)(iVar2 + 0x700) + 0x10) = 0;
      }
      func_0x80066288(param_1,iVar2 + 0x5e0);
    }
    if ((*(ushort *)(param_1 + 0x270) & 4) != 0) {
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x80);
LAB_8016575c:
      func_0x80032b5c(param_1,0);
    }
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x20) != 0) {
    DAT_80168f4e = 0xf6;
    DAT_80168f4f = 0xe;
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x40) != 0) {
    DAT_80168f4e = 0xf6;
    DAT_80168f4f = 0xf2;
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x80) != 0) {
    DAT_80168f4e = 0;
    DAT_80168f4f = 0;
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x100) != 0) {
    iVar2 = *(int *)(param_1 + 0x234);
    *(short *)(*(int *)(iVar2 + 0x700) + 0x10) =
         *(short *)(*(int *)(iVar2 + 0x700) + 0x10) + *(char *)(param_1 + 0x206) * 10;
    if (*(char *)(param_1 + 0x206) < 'Z') {
      *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + '\x01';
    }
    if (0x1000 < *(short *)(*(int *)(iVar2 + 0x700) + 0x10)) {
      *(undefined2 *)(*(int *)(iVar2 + 0x700) + 0x10) = 0x1000;
    }
    func_0x80066288(param_1,iVar2 + 0x5e0);
  }
  FUN_801658dc(param_1,*(int *)(param_1 + 0x234) + 0x1a70);
  *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x298) + 0xc) =
       (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
  func_0x80066288(param_1);
  *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x410) + 0xc) =
       (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
  func_0x80066288();
  return;
}
