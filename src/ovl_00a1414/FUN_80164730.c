/* FUN_80164730
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80164730  body 0x80164730..0x8016500f  size 2272 B
 * body sha256 bd7b80ee5cb9ff7736ed3dd3226a37139bb3101cc2cf99bc05342cedff29ae69
 * provider record sha256 8611f21ecfbcda552a591d8acbad3c047e6c50129d3a6ccb2e1d1a8fac78c425
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164730(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  short sVar3;
  int iVar2;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined *puVar7;
  uint *puVar8;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  
  if (*(byte *)(param_1 + 6) < 4) {
    *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x298) + 0xc) =
         (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
    func_0x80066288();
    *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x410) + 0xc) =
         (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
    func_0x80066288(param_1);
  }
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0xe001f00;
    *(undefined2 *)(param_1 + 500) = 0x78;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    break;
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    func_0x80032b5c(param_1,0);
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined2 *)(param_1 + 500) = 0x50;
      *(undefined2 *)(param_1 + 0x1f6) = 5;
      *(undefined4 *)(param_1 + 0x1e8) = 0x12001f00;
      *(undefined1 *)(param_1 + 0x207) = 0;
      *(undefined1 *)(param_1 + 0x206) = 1;
    }
    break;
  case 2:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 3;
      *(undefined2 *)(param_1 + 500) = 0x5a;
      *(undefined2 *)(param_1 + 0x1f6) = 5;
      *(undefined4 *)(param_1 + 0x1e8) = 0xf001f00;
      *(undefined1 *)(param_1 + 0x206) = 1;
    }
    func_0x80032b5c(param_1,0);
    if (*(char *)(param_1 + 0x1e9) == 'v') {
      iVar2 = *(int *)(param_1 + 0x234);
      uVar5 = *(undefined4 *)(iVar2 + 0x1828);
      *(undefined4 *)(iVar2 + 0x1828) = *(undefined4 *)(iVar2 + 0x978);
      *(undefined4 *)(iVar2 + 0x978) = uVar5;
      uVar5 = *(undefined4 *)(iVar2 + 0x182c);
      *(undefined4 *)(iVar2 + 0x182c) = *(undefined4 *)(iVar2 + 0x97c);
      *(undefined4 *)(iVar2 + 0x97c) = uVar5;
      uVar5 = *(undefined4 *)(iVar2 + 0x1830);
      *(undefined4 *)(iVar2 + 0x1830) = *(undefined4 *)(iVar2 + 0x980);
      *(undefined4 *)(iVar2 + 0x980) = uVar5;
      uVar5 = *(undefined4 *)(iVar2 + 0x1834);
      *(undefined4 *)(iVar2 + 0x1834) = *(undefined4 *)(iVar2 + 0x984);
      *(undefined4 *)(iVar2 + 0x984) = uVar5;
      uVar1 = *(undefined2 *)(iVar2 + 0x1844);
      *(undefined2 *)(iVar2 + 0x1844) = *(undefined2 *)(iVar2 + 0x994);
      *(undefined2 *)(iVar2 + 0x994) = uVar1;
      uVar1 = *(undefined2 *)(iVar2 + 0x1846);
      *(undefined2 *)(iVar2 + 0x1846) = *(undefined2 *)(iVar2 + 0x996);
      *(undefined2 *)(iVar2 + 0x996) = uVar1;
      uVar5 = *(undefined4 *)(iVar2 + 0x184c);
      *(undefined4 *)(iVar2 + 0x184c) = *(undefined4 *)(iVar2 + 0x99c);
      *(undefined4 *)(iVar2 + 0x99c) = uVar5;
      uVar5 = *(undefined4 *)(iVar2 + 0x1848);
      *(undefined4 *)(iVar2 + 0x1848) = *(undefined4 *)(iVar2 + 0x998);
      *(undefined4 *)(iVar2 + 0x998) = uVar5;
    }
    break;
  case 3:
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
      *(undefined1 *)(param_1 + 0x2c0) = 0;
      *(undefined1 *)(param_1 + 0x2c1) = 0;
      *(undefined1 *)(param_1 + 0x2c2) = 0;
    }
    if (*(short *)(param_1 + 500) < 0x28) {
      iVar2 = *(int *)(param_1 + 0x234);
      iVar4 = *(int *)(iVar2 + 0x410);
      *(short *)(iVar4 + 0xc) =
           *(short *)(iVar4 + 0xc) + *(short *)(param_1 + 0x1f6) * (short)*(char *)(param_1 + 0x206)
      ;
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 5;
      *(char *)(param_1 + 0x206) = -*(char *)(param_1 + 0x206);
      func_0x80066288(param_1,iVar2 + 0x2f0);
    }
    break;
  case 4:
    iVar2 = 0x10;
    puVar8 = *(uint **)(param_1 + 0x234);
    *(undefined2 *)(param_1 + 0x27a) = 0x1000;
    puVar6 = puVar8 + 0x4a;
    do {
      *(short *)(puVar6 + -1) = *(short *)(puVar6 + -1) + 0x1e;
      sVar3 = *(short *)puVar6;
      *(short *)((int)puVar6 + -2) = *(short *)((int)puVar6 + -2) + 10;
      *(short *)puVar6 = sVar3 + 0x1e;
      puVar6 = puVar6 + 0x5e;
      if (0x1000 < (short)(sVar3 + 0x1e)) {
        *puVar8 = *puVar8 & 0xfffffbff;
      }
      iVar2 = iVar2 + -1;
      puVar8 = puVar8 + 0x5e;
    } while (iVar2 != 0);
    if (*(char *)(param_1 + 0x1e9) == '\x0f') {
      local_28 = 100;
      local_26 = 0;
      local_24 = 0xff38;
      iVar2 = *(int *)(param_1 + 0x234) + 0x328;
      func_0x80037780(0x1000,(int)*(short *)(param_1 + 0x66),iVar2,&local_28);
      local_26 = 0xff38;
      func_0x80037780(0x11000,(int)*(short *)(param_1 + 0x66),iVar2,&local_28);
      local_26 = 0xfe70;
      func_0x80037780(0xc18,(int)*(short *)(param_1 + 0x66),iVar2,&local_28);
      local_26 = 0xfda8;
      func_0x80037780(0x830,(int)*(short *)(param_1 + 0x66),iVar2,&local_28);
      local_26 = 200;
      func_0x80037780(0x10830,(int)*(short *)(param_1 + 0x66),iVar2,&local_28);
    }
    if (0x14 < *(byte *)(param_1 + 0x1e9)) {
      iVar2 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar2 + 0x298) + 0xc) = *(short *)(*(int *)(iVar2 + 0x298) + 0xc) + -200;
      if (*(short *)(*(int *)(iVar2 + 0x298) + 0xc) < 0) {
        *(undefined2 *)(*(int *)(iVar2 + 0x298) + 0xc) = 0;
      }
      func_0x80066288(param_1,iVar2 + 0x178);
      iVar2 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar2 + 0x410) + 0xc) = *(short *)(*(int *)(iVar2 + 0x410) + 0xc) + -200;
      if (*(short *)(*(int *)(iVar2 + 0x410) + 0xc) < 0) {
        *(undefined2 *)(*(int *)(iVar2 + 0x410) + 0xc) = 0;
      }
      func_0x80066288(param_1,iVar2 + 0x2f0);
      iVar2 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar2 + 0x700) + 0xc) = *(short *)(*(int *)(iVar2 + 0x700) + 0xc) + -200;
      *(short *)(*(int *)(iVar2 + 0x700) + 0x10) = *(short *)(*(int *)(iVar2 + 0x700) + 0x10) + 200;
      if (*(short *)(*(int *)(iVar2 + 0x700) + 0xc) < 0) {
        *(undefined2 *)(*(int *)(iVar2 + 0x700) + 0xc) = 0;
        *(undefined2 *)(*(int *)(iVar2 + 0x700) + 0x10) = 0x1000;
      }
      func_0x80066288(param_1,iVar2 + 0x5e0);
    }
    iVar2 = *(int *)(param_1 + 0x234);
    iVar4 = *(int *)(iVar2 + 0x410);
    *(short *)(iVar4 + 0xc) =
         *(short *)(iVar4 + 0xc) + *(short *)(param_1 + 0x1f6) * (short)*(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = -*(char *)(param_1 + 0x206);
    func_0x80066288(param_1,iVar2 + 0x2f0);
    iVar2 = *(int *)(param_1 + 0x234);
    *(short *)(*(int *)(iVar2 + 0x878) + 0xc) = *(short *)(*(int *)(iVar2 + 0x878) + 0xc) + -100;
    if (*(short *)(*(int *)(iVar2 + 0x878) + 0xc) < 0) {
      *(undefined2 *)(*(int *)(iVar2 + 0x878) + 0xc) = 0;
    }
    func_0x80066288(param_1,iVar2 + 0x758);
    func_0x80066554(param_1,iVar2 + 0x758);
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x13001f00;
      *(undefined1 *)(param_1 + 6) = 5;
      *(undefined2 *)(param_1 + 500) = 0x5a;
      *(undefined1 *)(param_1 + 0x207) = 10;
      *(undefined1 *)(param_1 + 0x2ba) = 0;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    }
    func_0x80032b5c(param_1,0);
    iVar2 = *(int *)(param_1 + 0x234);
    puVar7 = &DAT_80169034;
    goto LAB_80164fe4;
  case 5:
    sVar3 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar3;
    if (sVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 6;
      DAT_80168f4e = 0;
      DAT_80168f4f = 0;
      *(undefined1 *)(param_1 + 0x2c0) = 0;
      *(undefined1 *)(param_1 + 0x2c1) = 0;
      *(undefined1 *)(param_1 + 0x2c2) = 0;
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x40;
    }
    *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x298) + 0xc) =
         (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5;
    func_0x80066288(param_1);
    *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x410) + 0xc) =
         (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5;
    func_0x80066288(param_1);
    if (0 < *(short *)(param_1 + 0x1f6)) {
      iVar2 = *(int *)(param_1 + 0x234);
      iVar4 = *(int *)(iVar2 + 0x410);
      *(short *)(iVar4 + 0xc) =
           *(short *)(iVar4 + 0xc) + *(short *)(param_1 + 0x1f6) * (short)*(char *)(param_1 + 0x206)
      ;
      *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -10;
      *(char *)(param_1 + 0x206) = -*(char *)(param_1 + 0x206);
      func_0x80066288(param_1,iVar2 + 0x2f0);
    }
    if (*(short *)(param_1 + 500) < 0x46) {
      iVar2 = *(int *)(param_1 + 0x234);
      *(short *)(*(int *)(iVar2 + 0x700) + 0x10) =
           *(short *)(*(int *)(iVar2 + 0x700) + 0x10) + *(char *)(param_1 + 0x207) * -10;
      *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + '\x01';
      if (*(short *)(*(int *)(iVar2 + 0x700) + 0x10) < 0) {
        *(undefined2 *)(*(int *)(iVar2 + 0x700) + 0x10) = 0;
      }
      func_0x80066288(param_1,iVar2 + 0x5e0);
    }
    sVar3 = *(short *)(param_1 + 500);
    if (sVar3 == 0x28) {
      DAT_80168f4e = 0xf6;
      DAT_80168f4f = 0xe;
      sVar3 = *(short *)(param_1 + 500);
    }
    if (sVar3 == 10) {
      DAT_80168f4e = 0xf6;
      DAT_80168f4f = 0xf2;
    }
    break;
  case 6:
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)(param_1 + 0x1ea) = 0x1c;
    func_0x80089d54(param_1,param_2,param_3,0x80);
    if (*(char *)(param_1 + 0x1e9) == '2') {
      *(undefined1 *)(param_1 + 6) = 7;
      *(undefined4 *)(param_1 + 0x1e8) = 0x13001f00;
      *(undefined1 *)(param_1 + 0x2c0) = 0;
      *(undefined1 *)(param_1 + 0x2c1) = 0;
    }
    goto LAB_80164fbc;
  case 7:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xffbf;
    }
LAB_80164fbc:
    func_0x80032b5c(param_1,0);
    func_0x80066554(param_1,*(int *)(param_1 + 0x234) + 0x758);
    iVar2 = *(int *)(param_1 + 0x234);
    puVar7 = &DAT_80169028;
LAB_80164fe4:
    FUN_80168720(param_1,iVar2 + 0x468,puVar7);
  }
  return;
}
