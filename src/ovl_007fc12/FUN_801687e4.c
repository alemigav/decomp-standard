/* FUN_801687e4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x801687e4  body 0x801687e4..0x80168bcb  size 1000 B
 * body sha256 e8c25b8ebd26276e4a8fbb210c6ca9dabe33fdacde2c9008f97b855dba991251
 * provider record sha256 f5f6f95485560e22fbdab2d986a47239320e93bc675513811df5e8c59f93dd35
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801687e4(int param_1)

{
  undefined2 uVar1;
  short sVar3;
  byte bVar4;
  char cVar5;
  uint uVar2;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  short local_18;
  undefined2 local_16;
  short local_14;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    iVar7 = *(int *)(param_1 + 0x29c);
    *(undefined1 *)(param_1 + 0x206) = *(undefined1 *)(iVar7 + 0x131);
    if ((*(char *)(iVar7 + 0x131) == '\x03') || (*(char *)(iVar7 + 0x131) == '\x06')) {
      *(undefined1 *)(param_1 + 0x26e) = 3;
      return;
    }
    uVar1 = *(undefined2 *)(iVar7 + 0x132);
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = uVar1;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + 0xf00;
    **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) & 0xffffffbf;
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      uVar2 = func_0x80033604();
      uVar6 = 0xd;
      if ((uVar2 & 1) != 0) {
        uVar6 = 0xc;
      }
      func_0x80077d18(uVar6,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    *(undefined2 *)(param_1 + 0x1e0) = 300;
    *(undefined1 *)(param_1 + 0x207) = 0x32;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    sVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    cVar5 = *(char *)(param_1 + 0x206);
    iVar7 = *(int *)(param_1 + 0x234);
    uVar2 = func_0x80033604();
    func_0x80037780((uVar2 & 0xff) * 8 + 6000,(int)sVar3,iVar7 + cVar5 * 0x178 + 0x38,0);
  case 1:
    local_18 = 0;
    local_16 = *(undefined2 *)(param_1 + 500);
    local_14 = 0;
    func_0x80040e58(&local_18,&local_38);
    func_0x8004276c(&local_38,param_1 + 0x1e0,&local_18);
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100)
    ;
    sVar3 = *(short *)(param_1 + 0x1f6);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_18;
    *(short *)(param_1 + 0x1f6) = sVar3 + *(char *)(param_1 + 0x207);
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - sVar3;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_14;
    if (*(short *)(param_1 + 0x1e0) < 0) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    break;
  case 2:
    iVar7 = *(int *)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 6) = 3;
    bVar4 = func_0x80033604();
    *(byte *)(param_1 + 0x207) = (bVar4 & 0x3f) + 0x1e;
    uVar1 = *(undefined2 *)(iVar7 + 0x22);
    *(undefined2 *)(param_1 + 500) = 0x1000;
    *(undefined2 *)(param_1 + 0x1f6) = uVar1;
  case 3:
    cVar5 = *(char *)(param_1 + 0x207) + -1;
    *(char *)(param_1 + 0x207) = cVar5;
    if (cVar5 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100)
    ;
    iVar7 = *(int *)(param_1 + 0x234);
    local_38 = *(undefined4 *)(iVar7 + 8);
    local_34 = *(undefined4 *)(iVar7 + 0xc);
    local_30 = *(undefined4 *)(iVar7 + 0x10);
    local_2c = *(undefined4 *)(iVar7 + 0x14);
    local_28 = *(undefined4 *)(iVar7 + 0x18);
    local_24 = *(undefined4 *)(iVar7 + 0x1c);
    local_20 = *(undefined4 *)(iVar7 + 0x20);
    local_1c = *(undefined4 *)(iVar7 + 0x24);
    func_0x80089c3c(&DAT_800e9028,&local_38,iVar7 + 8,(int)*(short *)(param_1 + 500));
    *(int *)(iVar7 + 0x20) = (int)*(short *)(param_1 + 0x1f6);
    if (0x400 < *(short *)(param_1 + 500)) {
      *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -0x200;
    }
    break;
  case 4:
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined1 *)(param_1 + 0x207) = 0x14;
  case 5:
    cVar5 = *(char *)(param_1 + 0x207) + -1;
    *(char *)(param_1 + 0x207) = cVar5;
    if (cVar5 == -1) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100)
    ;
    iVar7 = *(int *)(param_1 + 0x234);
    local_38 = *(undefined4 *)(iVar7 + 8);
    local_34 = *(undefined4 *)(iVar7 + 0xc);
    local_30 = *(undefined4 *)(iVar7 + 0x10);
    local_2c = *(undefined4 *)(iVar7 + 0x14);
    local_28 = *(undefined4 *)(iVar7 + 0x18);
    local_24 = *(undefined4 *)(iVar7 + 0x1c);
    local_20 = *(undefined4 *)(iVar7 + 0x20);
    local_1c = *(undefined4 *)(iVar7 + 0x24);
    func_0x80089c3c(&DAT_800e9028,&local_38,iVar7 + 8,(int)*(short *)(param_1 + 500));
    *(int *)(iVar7 + 0x20) = (int)*(short *)(param_1 + 0x1f6);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 0x99;
    break;
  case 6:
    **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) & 0xffffffbf;
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
    }
  }
  return;
}
