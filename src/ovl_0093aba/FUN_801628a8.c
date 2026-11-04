/* FUN_801628a8
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x801628a8  body 0x801628a8..0x80162f0b  size 1636 B
 * body sha256 4800b5df2da979a91ce1eb1f64ef159997eb4977ad6faa6a9cfe4f08eb9ef80a
 * provider record sha256 33c146205ceeaf6b8d17f1121677c5ece06c41479614aec05b554ce34b0e26f8
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801628a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uVar3;
  char cVar5;
  short sVar4;
  uint *puVar6;
  int iVar7;
  short local_58;
  short local_56;
  short local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  short local_48 [2];
  short local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [32];
  
  local_40 = 0x4040504;
  local_3c = 0x5050405;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 5;
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(_DAT_800e13f0 + 4) = 8;
      *(undefined1 *)(_DAT_800e13f0 + 5) = 0;
      *(undefined1 *)(_DAT_800e13f0 + 6) = 0;
      *(undefined1 *)(param_1 + 6) = 2;
      *(uint *)(*(int *)(param_1 + 0x234) + 0x758) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x758) & 0xffffbfff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) & 0xffffbfff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) & 0xffffbfff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) & 0xffffbfff;
      *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) =
           *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) & 0xffffbfff;
    }
    break;
  case 2:
    sVar4 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar4;
    if (sVar4 == -1) {
      uVar2 = func_0x80033604();
      uVar1 = *(undefined1 *)((int)local_48 + (uVar2 & 7) + 8);
      *(undefined1 *)(param_1 + 0x1ea) = 7;
      *(undefined1 *)(param_1 + 0x1e8) = uVar1;
      uVar3 = func_0x80033604();
      *(ushort *)(param_1 + 500) = uVar3 & 7 | 8;
      func_0x80037780(0x107d0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x618,0);
    }
    func_0x80089d54(param_1,param_2,param_3,0x200);
    local_58 = 0;
    local_56 = -400;
    local_54 = -200;
    iVar7 = *(int *)(_DAT_800e13f0 + 0x234);
    goto LAB_80162c50;
  case 3:
    *(uint *)(*(int *)(param_1 + 0x234) + 0x758) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x758) | 0x4000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) | 0x4000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xa48) | 0x4000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) | 0x4000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xd38) | 0x4000;
    *(undefined1 *)(param_1 + 6) = 4;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    func_0x80089d54(param_1,param_2,param_3,0x200);
    break;
  case 5:
    iVar7 = 10;
    puVar6 = *(uint **)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 6) = 6;
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    do {
      iVar7 = iVar7 + -1;
      *puVar6 = *puVar6 & 0xffffbfff;
      puVar6 = puVar6 + 0x5e;
    } while (iVar7 != 0);
    func_0x80037780(0x20fa0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,0);
  case 6:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar7 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar7 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xe000700;
      *(undefined1 *)(param_1 + 6) = 8;
    }
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + *(short *)(param_1 + 0x1e0);
    local_58 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + *(short *)(param_1 + 0x1e2);
    goto LAB_80162c38;
  case 7:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    local_58 = *(short *)(param_1 + 500);
LAB_80162c38:
    local_58 = local_58 + 100;
    local_56 = *(short *)(param_1 + 0x1f6);
    local_54 = -100;
    iVar7 = *(int *)(_DAT_800e13f0 + 0x234);
LAB_80162c50:
    func_0x8004276c(iVar7 + 0x38,&local_58,&local_58);
    *(int *)(param_1 + 0x28) = (int)local_58 + *(int *)(*(int *)(_DAT_800e13f0 + 0x234) + 0x4c);
    *(int *)(param_1 + 0x2c) = (int)local_56 + *(int *)(*(int *)(_DAT_800e13f0 + 0x234) + 0x50);
    *(int *)(param_1 + 0x30) = (int)local_54 + *(int *)(*(int *)(_DAT_800e13f0 + 0x234) + 0x54);
    *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(_DAT_800e13f0 + 0x66);
    break;
  case 8:
    *(undefined2 *)(param_1 + 0x1e2) = 100;
    *(undefined2 *)(param_1 + 0x1e0) = 300;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 6) = 9;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000700;
    iVar7 = *(int *)(param_1 + 0x234) + 0x38;
    func_0x80037780(0x10fa0,(int)*(short *)(param_1 + 0x66),iVar7,0);
    func_0x80037780(5000,(int)*(short *)(param_1 + 0x66),iVar7,0);
  case 9:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    func_0x80032bd8(param_1,0,0);
    *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + *(short *)(param_1 + 500) * 0xf;
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    if ((int)*(short *)(param_1 + 0x25e) < *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined1 *)(param_1 + 6) = 10;
    }
    break;
  case 10:
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    *(undefined1 *)(param_1 + 6) = 0xb;
    *(undefined2 *)(param_1 + 0x1e0) = 0x50;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar3 & 0x1f) + 0x14;
  case 0xb:
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x270),(int)*(short *)(param_1 + 0x272),0x10);
    if (*(short *)(param_1 + 0x1e0) < 0x3c) {
      *(undefined2 *)(param_1 + 0x1e0) = 0x3c;
    }
    if (0x96 < *(short *)(param_1 + 0x1e0)) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -0x1e;
    }
    cVar5 = *(char *)(param_1 + 0x206) + -1;
    *(char *)(param_1 + 0x206) = cVar5;
    if (cVar5 == -1) {
      *(undefined1 *)(param_1 + 0x206) = 10;
      *(undefined1 *)(param_1 + 0x207) = 5;
    }
    if (*(char *)(param_1 + 0x207) < *(char *)(param_1 + 0x206)) {
      sVar4 = *(short *)(param_1 + 0x1e0) + *(char *)(param_1 + 0x206) * 4;
    }
    else {
      sVar4 = *(short *)(param_1 + 0x1e0) + -0x28;
    }
    *(short *)(param_1 + 0x1e0) = sVar4;
    func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    local_50 = 0;
    local_4e = *(undefined2 *)(param_1 + 0x2b4);
    local_4c = 0;
    func_0x80040e58(&local_50,auStack_38);
    local_50 = *(undefined2 *)(param_1 + 0x1e0);
    local_4e = 0;
    local_4c = 0;
    func_0x8004276c(auStack_38,&local_50,local_48);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_48[0];
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_44;
  }
  return;
}
