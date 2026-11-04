/* FUN_80168bcc
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80168bcc  body 0x80168bcc..0x8016905f  size 1172 B
 * body sha256 559147ea4d7dde936f569d92c06ac4cfe23e998fc9759606b3b43e2d4068a53e
 * provider record sha256 5bac5424b99ab6238135f2f618e208fe1903c00759c828590f178d0848aa55dc
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80168bcc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  byte bVar4;
  char cVar5;
  uint uVar2;
  uint uVar3;
  int iVar6;
  undefined2 uVar7;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  
  uVar7 = 0xfa;
  bVar4 = *(byte *)((int)param_1 + 6);
  if (bVar4 == 1) {
LAB_80168f10:
    func_0x800334c8(param_1,param_2,param_3,0,uVar7);
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    func_0x80032b5c(param_1,0);
    return;
  }
  if (bVar4 < 2) {
    if (bVar4 != 0) {
      return;
    }
    param_1[0x7a] = 0x1000f00;
    func_0x800334c8(param_1,param_2,param_3,0,0xfa);
    bVar4 = func_0x80033604();
    *(byte *)((int)param_1 + 0x1e9) = bVar4 & 7;
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    if (*(char *)((int)param_1 + 5) != '\f') {
      bVar4 = func_0x80033604();
      *(byte *)((int)param_1 + 0x207) = bVar4 & 1;
      if ((bVar4 & 1) != 0) {
        uVar3 = param_1[0x8d];
        uVar2 = *(uint *)(uVar3 + 0x468);
        if ((DAT_800e9012 & 8) != 0) {
          uVar2 = uVar2 | 0x4a;
        }
        *(uint *)(uVar3 + 0x468) = uVar2;
        sVar1 = *(short *)((int)param_1 + 0x66);
        *(undefined2 *)(uVar3 + 0x5a0) = 0;
        *(undefined2 *)(uVar3 + 0x59c) = 0;
        *(undefined2 *)(uVar3 + 0x59a) = 0xfff6;
        *(undefined2 *)(uVar3 + 0x59e) = 0;
        *(undefined2 *)(uVar3 + 0x5a4) = 0;
        *(undefined4 *)(uVar3 + 0x4c8) = 0x10104f;
        *(short *)(uVar3 + 0x598) = sVar1 + 0x800;
        func_0x80038e98(5,3,uVar3 + 0x4a0);
        *(undefined4 *)(param_1[0x8d] + 0x5e0) = 0;
        func_0x80077d18(2,param_1);
        uVar2 = func_0x80033604();
        if ((uVar2 & 1) != 0) {
          uVar3 = param_1[0x8d];
          uVar2 = *(uint *)(uVar3 + 0x758);
          if ((DAT_800e9012 & 8) != 0) {
            uVar2 = uVar2 | 0x4a;
          }
          iVar6 = uVar3 + 0x790;
          *(uint *)(uVar3 + 0x758) = uVar2;
          sVar1 = *(short *)((int)param_1 + 0x66);
          *(undefined2 *)(uVar3 + 0x890) = 0;
          *(undefined2 *)(uVar3 + 0x88c) = 0;
          *(undefined2 *)(uVar3 + 0x88a) = 0xfff6;
          *(undefined2 *)(uVar3 + 0x88e) = 0;
          *(undefined2 *)(uVar3 + 0x894) = 0;
          *(undefined4 *)(uVar3 + 0x7b8) = 0x10104f;
          *(short *)(uVar3 + 0x888) = sVar1 + 0x800;
          func_0x80037780(6000,0,iVar6,0);
          uVar2 = func_0x80033604();
          func_0x80037780(0x8001000,(uVar2 & 0xff) << 4,iVar6,0);
          func_0x80038e98(5,3,iVar6);
          uVar3 = param_1[0x8d];
          uVar2 = *(uint *)(uVar3 + 0x8d0);
          if ((DAT_800e9012 & 8) != 0) {
            uVar2 = uVar2 | 0x4a;
          }
          *(uint *)(uVar3 + 0x8d0) = uVar2;
          sVar1 = *(short *)((int)param_1 + 0x66);
          *(undefined2 *)(uVar3 + 0xa08) = 0;
          *(undefined2 *)(uVar3 + 0xa04) = 0;
          *(undefined2 *)(uVar3 + 0xa02) = 0xfff6;
          *(undefined2 *)(uVar3 + 0xa06) = 0;
          *(undefined2 *)(uVar3 + 0xa0c) = 0;
          *(undefined4 *)(uVar3 + 0x930) = 0x10104f;
          *(short *)(uVar3 + 0xa00) = sVar1 + 0x800;
          func_0x80037780(6000,0,uVar3 + 0x908,0);
          func_0x80038e98(5,3,uVar3 + 0x908);
          *(undefined4 *)(param_1[0x8d] + 0xa48) = 0;
        }
      }
      local_28 = 0;
      local_26 = 0;
      local_24 = 0;
      iVar6 = param_1[0x8d] + 0x4a0;
      func_0x80037780(5000,0,iVar6,&local_28);
      local_26 = 400;
      uVar2 = func_0x80033604();
      func_0x80037780(6000,(uVar2 & 0xff) << 2,iVar6,&local_28);
      local_26 = 800;
      uVar2 = func_0x80033604();
      func_0x80037780(4000,(uVar2 & 0xff) << 4,iVar6,&local_28);
      uVar2 = func_0x80033604();
      func_0x80037780(0x8001000,(uVar2 & 0xff) << 4,iVar6,0);
    }
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      func_0x80077d18(0xc,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
    func_0x80035b84(param_1);
    goto LAB_80168f10;
  }
  if (bVar4 != 2) {
    return;
  }
  if (*(char *)(param_1 + 1) == '\x03') {
    uVar2 = func_0x80033604();
    if (((uVar2 & 3) == 0) && (*(char *)((int)param_1 + 0x207) != '\0')) goto LAB_80168fb8;
    *(undefined2 *)((int)param_1 + 0x1f2) = 10;
  }
  if ((*(short *)(param_1 + 0x6a) == 0) && ((_DAT_800e110c & 0x10000000) == 0)) {
    *(undefined2 *)((int)param_1 + 0x136) = 200;
    *(undefined2 *)(param_1 + 0x4e) = 200;
    *(undefined2 *)(param_1 + 0x4b) = 200;
    *(undefined2 *)((int)param_1 + 0x12e) = 200;
    *(undefined2 *)(param_1 + 0x4d) = 0xfea2;
    *(undefined2 *)((int)param_1 + 0x13a) = 0x15e;
    *(undefined2 *)((int)param_1 + 0x1aa) = 0x2001;
    *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
    uVar2 = func_0x80033604();
    uVar3 = 0x1000000;
    if ((uVar2 & 1) == 0) {
      uVar3 = 0x1020000;
    }
    param_1[1] = uVar3;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    return;
  }
LAB_80168fb8:
  param_1[1] = 0x7000000;
  *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfffb;
  return;
}
