/* FUN_801637e8
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x801637e8  body 0x801637e8..0x80164ac7  size 4832 B
 * body sha256 82466cf9f834d370a30696edb85bcfa3eafc1e1c579a1b12b0392f33c55d25f8
 * provider record sha256 c8f85f684ca9bb053f15036c7672334d2d2ec1b14941f7fa26bf80529d7830f3
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80163820) */
/* WARNING: Removing unreachable block (ram,0x80163824) */
/* WARNING: Removing unreachable block (ram,0x80163870) */

void FUN_801637e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar5;
  byte bVar6;
  ushort uVar4;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined **ppuVar7;
  short *psVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  uint *puVar12;
  int iVar13;
  short local_68;
  short local_66;
  short local_64;
  short local_60 [2];
  undefined4 local_5c [15];
  
  psVar8 = local_60;
  ppuVar7 = (undefined **)&DAT_80167e30;
  do {
    puVar9 = ppuVar7[1];
    puVar10 = ppuVar7[2];
    puVar11 = ppuVar7[3];
    *(undefined **)psVar8 = *ppuVar7;
    *(undefined **)(psVar8 + 2) = puVar9;
    *(undefined **)(psVar8 + 4) = puVar10;
    *(undefined **)(psVar8 + 6) = puVar11;
    ppuVar7 = ppuVar7 + 4;
    psVar8 = psVar8 + 8;
  } while (ppuVar7 != &switchD_801638c8::switchdataD_80167e70);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0xc000700;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 1;
    *(undefined2 *)(*(int *)(param_1 + 0x234) + 0x704) = 0x200;
    bVar6 = func_0x80033604();
    iVar13 = *(int *)(param_1 + 0x234);
    *(byte *)(param_1 + 0x207) = (bVar6 & 7) + 7;
    *(undefined1 *)(param_1 + 0x206) = 5;
    *(uint *)(iVar13 + 0x1318) = *(uint *)(iVar13 + 0x1318) | 0x4000;
    *(uint *)(iVar13 + 0x1490) = *(uint *)(iVar13 + 0x1490) | 0x4000;
    *(uint *)(iVar13 + 0x1608) = *(uint *)(iVar13 + 0x1608) | 0x4000;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) | 0x4000;
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x350) = 0x608060;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x640) = 0x608060;
    iVar13 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar13 + 0xd98) = 0x608060;
    *(undefined4 *)(iVar13 + 0xf10) = 0x608060;
    *(undefined4 *)(iVar13 + 0x1088) = 0x608060;
    *(undefined4 *)(iVar13 + 0x1200) = 0x608060;
    iVar13 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar13 + 0x1378) = 0x608060;
    *(undefined4 *)(iVar13 + 0x14f0) = 0x608060;
    *(undefined4 *)(iVar13 + 0x1668) = 0x608060;
    iVar13 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar13 + 0x17e0) = 0x608060;
    *(undefined4 *)(iVar13 + 0x1958) = 0x608060;
    break;
  case 1:
    cVar5 = *(char *)(param_1 + 0x207) + -1;
    *(char *)(param_1 + 0x207) = cVar5;
    if (cVar5 == -1) {
      *(undefined1 *)(param_1 + 6) = 2;
      func_0x80077d18(8,param_1);
LAB_80163ae8:
      bVar6 = func_0x80033604();
      DAT_80167fca = '\x03' - bVar6 % 6;
      bVar6 = func_0x80033604();
      DAT_80167fcb = '\x0f' - bVar6 % 0x1e;
    }
    break;
  case 2:
    iVar13 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar13 != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
      bVar6 = func_0x80033604();
      *(byte *)(param_1 + 0x207) = (bVar6 & 7) + 7;
      cVar5 = *(char *)(param_1 + 0x206) + -1;
      *(char *)(param_1 + 0x206) = cVar5;
      if (cVar5 == -1) {
        *(undefined1 *)(param_1 + 6) = 3;
        *(undefined1 *)(param_1 + 0x207) = 0x78;
        *(undefined1 *)(param_1 + 0x206) = 0;
        DAT_80167fca = '\0';
        DAT_80167fcb = '\0';
        func_0x80077d18(9,param_1);
      }
    }
    break;
  case 3:
    *(undefined1 *)(param_1 + 0x1ea) = 0x30;
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    func_0x80089d54(param_1,param_2,param_3,0x40);
    cVar5 = *(char *)(param_1 + 0x207) + -1;
    *(char *)(param_1 + 0x207) = cVar5;
    if (cVar5 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
      *(undefined4 *)(param_1 + 0x1e8) = 0xd003f00;
    }
    break;
  case 4:
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x40);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar5;
    if ((*(ushort *)(param_1 + 500) & 0x10) != 0) goto LAB_80163ae8;
    break;
  case 5:
    *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x234) + 0x298) + 0xc) = 0;
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    DAT_80167fca = '\0';
    DAT_80167fcb = '\0';
    iVar13 = *(int *)(param_1 + 0x234);
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
    *(uint *)(iVar13 + 0x1780) = *(uint *)(iVar13 + 0x1780) & 0xfffff3ff;
    *(uint *)(iVar13 + 0x18f8) = *(uint *)(iVar13 + 0x18f8) & 0xfffff3ff;
    *(uint *)(iVar13 + 0x1a70) = *(uint *)(iVar13 + 0x1a70) & 0xfffff3ff;
    *(uint *)(iVar13 + 0x1be8) = *(uint *)(iVar13 + 0x1be8) & 0xfffff3ff;
    *(uint *)(iVar13 + 0x1d60) = *(uint *)(iVar13 + 0x1d60) & 0xfffff3ff;
    *(uint *)(iVar13 + 0x1ed8) = *(uint *)(iVar13 + 0x1ed8) & 0xfffff3ff;
    *(uint *)(iVar13 + 0x2050) = *(uint *)(iVar13 + 0x2050) & 0xfffff3ff;
  }
  *(short *)(param_1 + 0x1f6) = -*(short *)(param_1 + 0x1f6);
  if (*(ushort *)(param_1 + 500) - 2 < 0xd) {
    iVar13 = *(int *)(param_1 + 0x234);
    uVar4 = func_0x80033604();
    local_68 = (uVar4 & 0xff) * -4 + 0x3f4;
    local_66 = 0xff38;
    uVar4 = func_0x80033604();
    local_64 = (uVar4 & 0xff) * -4 + 0x200;
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    iVar13 = iVar13 + 0x1b0;
    func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0 | 0x80000,(uVar2 & 0xff) << 4,iVar13,&local_68);
    uVar4 = func_0x80033604();
    local_68 = (uVar4 & 0xff) * -4 + 0x3f4;
    local_66 = -200;
    uVar4 = func_0x80033604();
    local_64 = (uVar4 & 0xff) * -4 + 0x200;
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar1 & 0xff) * 8 + 0x17d0 | 0x100000,(uVar2 & 0xff) << 4,iVar13,&local_68);
  }
  if ((1 < *(short *)(param_1 + 500)) && ((*(ushort *)(param_1 + 0x2ba) & 8) == 0)) {
    iVar13 = *(int *)(param_1 + 0x234);
    *(short *)(*(int *)(iVar13 + 0x298) + 0xc) =
         *(short *)(*(int *)(iVar13 + 0x298) + 0xc) + local_60[*(char *)(param_1 + 0x206)] * -3;
    *(byte *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + 1U & 0x1f;
    if (*(short *)(*(int *)(iVar13 + 0x298) + 0xc) < 0) {
      *(undefined2 *)(*(int *)(iVar13 + 0x298) + 0xc) = 0;
      *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x108;
    }
    func_0x80066288(param_1,iVar13 + 0x178);
    func_0x80066554(param_1,iVar13 + 0x178);
    if ((*(byte *)(param_1 + 0x206) & 1) == 0) {
      uVar4 = func_0x80033604();
      local_68 = (uVar4 & 0xff) * -4 + 0x3f4;
      local_66 = -200;
      uVar4 = func_0x80033604();
      local_64 = (uVar4 & 0xff) * -4 + 0x200;
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780(((uVar1 & 1) * 8 + 8) * 0x10000 | (uVar2 & 0xff) * 8 + 0xc18,
                      (uVar3 & 0xff) << 4,iVar13 + 0x1b0,&local_68);
    }
  }
  if (0xe6 < *(short *)(param_1 + 500)) {
    iVar13 = *(int *)(param_1 + 0x234);
    if (*(short *)(iVar13 + 0x704) < 0x1000) {
      *(ushort *)(iVar13 + 0x704) =
           *(short *)(iVar13 + 0x704) + -10 + (*(ushort *)(param_1 + 500) & 1) * 100;
      if (*(char *)(param_1 + 0x206) < '\x05') {
        uVar4 = func_0x80033604();
        local_68 = 0x40 - (uVar4 & 0x7f);
        uVar4 = func_0x80033604();
        local_66 = 0x40 - (uVar4 & 0x7f);
        uVar4 = func_0x80033604();
        local_64 = 0x40 - (uVar4 & 0x7f);
      }
      uVar1 = *(uint *)(*(int *)(param_1 + 0x234) + 0x350);
      if ((uVar1 & 0xff) != 0x80) {
        *(uint *)(*(int *)(param_1 + 0x234) + 0x350) = uVar1 + 0x10001;
        *(int *)(*(int *)(param_1 + 0x234) + 0x640) =
             *(int *)(*(int *)(param_1 + 0x234) + 0x640) + 0x10001;
      }
    }
    else {
      *(uint *)(iVar13 + 0x5e0) = *(uint *)(iVar13 + 0x5e0) & 0xfffff3ff;
    }
  }
  if (0xa0 < *(short *)(param_1 + 500)) {
    iVar13 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar13 + 0x5e0) = *(uint *)(iVar13 + 0x5e0) & 0xffffbfff;
    if (*(short *)(iVar13 + 0x414) < 0x1000) {
      *(ushort *)(iVar13 + 0x414) =
           *(short *)(iVar13 + 0x414) + 10 + (*(ushort *)(param_1 + 500) & 1) * 0x46;
      *(ushort *)(iVar13 + 0x58c) =
           *(short *)(iVar13 + 0x58c) + 10 + (*(ushort *)(param_1 + 500) & 1) * 0x46;
      uVar4 = func_0x80033604();
      local_68 = 0x40 - (uVar4 & 0x7f);
      local_66 = 0x40;
      uVar4 = func_0x80033604();
      local_64 = 0x40 - (uVar4 & 0x7f);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) << 2 | 0x81000,(uVar2 & 0xff) << 4,iVar13 + 0x328,&local_68);
      local_66 = -0x40;
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      uVar2 = ((uVar1 & 1) * 8 + 8) * 0x10000 | (uVar2 & 0xff) * 4 + 0xc18;
      uVar1 = func_0x80033604();
    }
    else {
      *(uint *)(iVar13 + 0x2f0) = *(uint *)(iVar13 + 0x2f0) & 0xfffff3ff;
      *(uint *)(iVar13 + 0x468) = *(uint *)(iVar13 + 0x468) & 0xfffff3ff;
      if ((*(ushort *)(param_1 + 500) & 7) != 0) goto LAB_801640d4;
      uVar4 = func_0x80033604();
      local_68 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_66 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_64 = 0x40 - (uVar4 & 0x7f);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      uVar2 = ((uVar1 & 1) * 8 + 8) * 0x10000 | (uVar2 & 0xff) * 4 + 0xc18;
      uVar1 = func_0x80033604();
    }
    func_0x80037780(uVar2,(uVar1 & 0xff) << 4,iVar13 + 0x328,&local_68);
  }
LAB_801640d4:
  if (100 < *(short *)(param_1 + 500)) {
    iVar13 = *(int *)(param_1 + 0x234);
    if (*(short *)(iVar13 + 0xe5e) < 0x1000) {
      *(short *)(iVar13 + 0xe5e) =
           *(short *)(iVar13 + 0xe5e) + local_60[*(char *)(param_1 + 0x206)] * 3;
      *(short *)(iVar13 + 0xfd6) =
           *(short *)(iVar13 + 0xfd6) + local_60[*(char *)(param_1 + 0x206)] * 3;
      *(short *)(iVar13 + 0x114e) =
           *(short *)(iVar13 + 0x114e) + local_60[*(char *)(param_1 + 0x206)] * 3;
      *(short *)(iVar13 + 0x12c6) =
           *(short *)(iVar13 + 0x12c6) + local_60[*(char *)(param_1 + 0x206)] * 3;
    }
    else {
      *(uint *)(iVar13 + 0xd38) = *(uint *)(iVar13 + 0xd38) & 0xfffff3ff;
      *(uint *)(iVar13 + 0xeb0) = *(uint *)(iVar13 + 0xeb0) & 0xfffff3ff;
      *(uint *)(iVar13 + 0x1028) = *(uint *)(iVar13 + 0x1028) & 0xfffff3ff;
      *(uint *)(iVar13 + 0x11a0) = *(uint *)(iVar13 + 0x11a0) & 0xfffff3ff;
      if ((*(uint *)(iVar13 + 0xd98) & 0xff) != 0x80) {
        *(uint *)(iVar13 + 0xd98) = *(uint *)(iVar13 + 0xd98) + 0x10001;
        *(int *)(iVar13 + 0xf10) = *(int *)(iVar13 + 0xf10) + 0x10001;
        *(int *)(iVar13 + 0x1200) = *(int *)(iVar13 + 0x1200) + 0x10001;
        *(int *)(iVar13 + 0x1088) = *(int *)(iVar13 + 0x1088) + 0x10001;
      }
    }
    if ((*(char *)(param_1 + 0x206) < '\x0f') || ((*(ushort *)(param_1 + 500) & 7) == 0)) {
      uVar4 = func_0x80033604();
      local_68 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_66 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_64 = 0x40 - (uVar4 & 0x7f);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0x830 | 0x80000,(uVar2 & 0xff) << 4,iVar13 + 0xd70,
                      &local_68);
    }
  }
  if (0x3c < *(short *)(param_1 + 500)) {
    iVar13 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar13 + 0x1318) = *(uint *)(iVar13 + 0x1318) & 0xffffbfff;
    *(uint *)(iVar13 + 0x1490) = *(uint *)(iVar13 + 0x1490) & 0xffffbfff;
    *(uint *)(iVar13 + 0x1608) = *(uint *)(iVar13 + 0x1608) & 0xffffbfff;
    if (*(short *)(iVar13 + 0x143e) < 0x1000) {
      *(ushort *)(iVar13 + 0x143e) =
           *(short *)(iVar13 + 0x143e) + 0x14 + (*(ushort *)(param_1 + 500) & 1) * 0x50;
      *(ushort *)(iVar13 + 0x15b6) =
           *(short *)(iVar13 + 0x15b6) + 0x14 + (*(ushort *)(param_1 + 500) & 1) * 0x50;
      *(ushort *)(iVar13 + 0x172e) =
           *(short *)(iVar13 + 0x172e) + 0x14 + (*(ushort *)(param_1 + 500) & 1) * 0x50;
      if ((*(ushort *)(param_1 + 500) & 1) != 0) {
        uVar4 = func_0x80033604();
        local_68 = 0x40 - (uVar4 & 0x7f);
        uVar4 = func_0x80033604();
        local_66 = 0x40 - (uVar4 & 0x7f);
        uVar4 = func_0x80033604();
        local_64 = 0x40 - (uVar4 & 0x7f);
      }
    }
    else {
      *(uint *)(iVar13 + 0x1318) = *(uint *)(iVar13 + 0x1318) & 0xfffff3ff;
      *(uint *)(iVar13 + 0x1490) = *(uint *)(iVar13 + 0x1490) & 0xfffff3ff;
      *(uint *)(iVar13 + 0x1608) = *(uint *)(iVar13 + 0x1608) & 0xfffff3ff;
      if ((*(uint *)(iVar13 + 0x1378) & 0xff) != 0x80) {
        *(uint *)(iVar13 + 0x1378) = *(uint *)(iVar13 + 0x1378) + 0x10001;
        *(int *)(iVar13 + 0x14f0) = *(int *)(iVar13 + 0x14f0) + 0x10001;
        *(int *)(iVar13 + 0x1668) = *(int *)(iVar13 + 0x1668) + 0x10001;
      }
    }
    if (*(char *)(param_1 + 0x206) < '\x0f') {
      uVar4 = func_0x80033604();
      local_68 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_66 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_64 = 0x40 - (uVar4 & 0x7f);
    }
  }
  if (1 < *(short *)(param_1 + 500)) {
    iVar13 = *(int *)(param_1 + 0x234);
    if ((*(short *)(iVar13 + 0x18a6) < 0x1000) && ((*(ushort *)(param_1 + 0x2ba) & 0x10) == 0)) {
      *(short *)(iVar13 + 0x18a6) =
           *(short *)(iVar13 + 0x18a6) + local_60[*(char *)(param_1 + 0x206)] * 3;
      *(short *)(iVar13 + 0x1a1e) =
           *(short *)(iVar13 + 0x1a1e) + local_60[*(char *)(param_1 + 0x206)] * 3;
      uVar4 = func_0x80033604();
      local_68 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_66 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_64 = 0x40 - (uVar4 & 0x7f);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780(((uVar1 & 1) * 8 + 8) * 0x10000 | (uVar2 & 0xff) * 8 + 0xc18,
                      (uVar3 & 0xff) << 4,iVar13 + 0x17b8,&local_68);
    }
    else {
      *(undefined2 *)(iVar13 + 0x18a6) = 0x1000;
      *(undefined2 *)(iVar13 + 0x1a1e) = 0x1000;
      *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x10;
      if ((200 < *(short *)(param_1 + 500)) && ((*(uint *)(iVar13 + 0x17e0) & 0xff) != 0x80)) {
        *(uint *)(iVar13 + 0x17e0) = *(uint *)(iVar13 + 0x17e0) + 0x10001;
        *(int *)(iVar13 + 0x1958) = *(int *)(iVar13 + 0x1958) + 0x10001;
      }
    }
    if ((*(char *)(param_1 + 0x206) < '\x0f') || ((*(ushort *)(param_1 + 500) & 7) == 0)) {
      uVar4 = func_0x80033604();
      local_68 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_66 = 0x40 - (uVar4 & 0x7f);
      uVar4 = func_0x80033604();
      local_64 = 0x40 - (uVar4 & 0x7f);
    }
    if ((*(short *)(iVar13 + 0x18a4) < 0x1000) && ((*(ushort *)(param_1 + 0x2ba) & 0x20) == 0)) {
      *(short *)(iVar13 + 0x18a4) =
           *(short *)(iVar13 + 0x18a4) + local_60[*(char *)(param_1 + 0x206)] * 3;
      *(short *)(iVar13 + 0x1a1c) =
           *(short *)(iVar13 + 0x1a1c) + local_60[*(char *)(param_1 + 0x206)] * 3;
      *(short *)(iVar13 + 0x18a8) =
           *(short *)(iVar13 + 0x18a8) + local_60[*(char *)(param_1 + 0x206)] * 3;
      *(short *)(iVar13 + 0x1a20) =
           *(short *)(iVar13 + 0x1a20) + local_60[*(char *)(param_1 + 0x206)] * 3;
    }
    else {
      *(undefined2 *)(iVar13 + 0x18a4) = 0x1000;
      *(undefined2 *)(iVar13 + 0x1a1c) = 0x1000;
      *(undefined2 *)(iVar13 + 0x18a8) = 0x1000;
      *(undefined2 *)(iVar13 + 0x1a20) = 0x1000;
      *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x20;
      *(uint *)(iVar13 + 0x1780) = *(uint *)(iVar13 + 0x1780) & 0xfffff3ff;
      *(uint *)(iVar13 + 0x18f8) = *(uint *)(iVar13 + 0x18f8) & 0xfffff3ff;
    }
    if (1 < *(short *)(param_1 + 500)) {
      iVar13 = *(int *)(param_1 + 0x234);
      puVar12 = (uint *)(iVar13 + 0x1a70);
      if ((*(short *)(iVar13 + 0x1b96) < 0x1000) && ((*(ushort *)(param_1 + 0x2ba) & 0x40) == 0)) {
        *(short *)(iVar13 + 0x1b96) =
             *(short *)(iVar13 + 0x1b96) + local_60[*(char *)(param_1 + 0x206)] * 3;
        *(short *)(iVar13 + 0x1d0e) =
             *(short *)(iVar13 + 0x1d0e) + local_60[*(char *)(param_1 + 0x206)] * 3;
        *(short *)(iVar13 + 0x1e86) =
             *(short *)(iVar13 + 0x1e86) + local_60[*(char *)(param_1 + 0x206)] * 3;
        *(short *)(iVar13 + 0x1ffe) =
             *(short *)(iVar13 + 0x1ffe) + local_60[*(char *)(param_1 + 0x206)] * 3;
        *(short *)(iVar13 + 0x2176) =
             *(short *)(iVar13 + 0x2176) + local_60[*(char *)(param_1 + 0x206)] * 3;
        uVar4 = func_0x80033604();
        local_68 = 0x40 - (uVar4 & 0x7f);
        uVar4 = func_0x80033604();
        local_66 = 0x40 - (uVar4 & 0x7f);
        uVar4 = func_0x80033604();
        local_64 = 0x40 - (uVar4 & 0x7f);
      }
      else {
        *(undefined2 *)(iVar13 + 0x1b96) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1d0e) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1e86) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1ffe) = 0x1000;
        *(undefined2 *)(iVar13 + 0x2176) = 0x1000;
        *puVar12 = *puVar12 & 0xfffff3ff;
        *(uint *)(iVar13 + 0x1d60) = *(uint *)(iVar13 + 0x1d60) & 0xfffff3ff;
        *(uint *)(iVar13 + 0x1be8) = *(uint *)(iVar13 + 0x1be8) & 0xfffff3ff;
        *(uint *)(iVar13 + 0x2050) = *(uint *)(iVar13 + 0x2050) & 0xfffff3ff;
        *(uint *)(iVar13 + 0x1ed8) = *(uint *)(iVar13 + 0x1ed8) & 0xfffff3ff;
        *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x40;
      }
      if ((*(char *)(param_1 + 0x206) < '\x0f') || ((*(ushort *)(param_1 + 500) & 7) == 0)) {
        uVar4 = func_0x80033604();
        local_68 = 0x40 - (uVar4 & 0x7f);
        uVar4 = func_0x80033604();
        local_66 = 0x40 - (uVar4 & 0x7f);
        func_0x80033604();
      }
      if ((*(short *)(iVar13 + 0x1b94) < 0x1000) && ((*(ushort *)(param_1 + 0x2ba) & 0x80) == 0)) {
        *(ushort *)(iVar13 + 0x1b94) =
             *(short *)(iVar13 + 0x1b94) + 10 + (*(ushort *)(param_1 + 500) & 1) * 0x14;
        *(ushort *)(iVar13 + 0x1d0c) =
             *(short *)(iVar13 + 0x1d0c) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
        *(ushort *)(iVar13 + 0x1e84) =
             *(short *)(iVar13 + 0x1e84) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
        *(ushort *)(iVar13 + 0x1ffc) =
             *(short *)(iVar13 + 0x1ffc) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
        *(ushort *)(iVar13 + 0x2174) =
             *(short *)(iVar13 + 0x2174) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
        *(ushort *)(iVar13 + 0x1b98) =
             *(short *)(iVar13 + 0x1b98) + 10 + (*(ushort *)(param_1 + 500) & 1) * 0x14;
        *(ushort *)(iVar13 + 0x1d10) =
             *(short *)(iVar13 + 0x1d10) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
        *(ushort *)(iVar13 + 0x1e88) =
             *(short *)(iVar13 + 0x1e88) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
        *(ushort *)(iVar13 + 0x2000) =
             *(short *)(iVar13 + 0x2000) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
        *(ushort *)(iVar13 + 0x2178) =
             *(short *)(iVar13 + 0x2178) + 10 + (*(ushort *)(param_1 + 500) & 1) * 10;
      }
      else {
        *(undefined2 *)(iVar13 + 0x1b94) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1d0c) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1e84) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1ffc) = 0x1000;
        *(undefined2 *)(iVar13 + 0x2174) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1b98) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1d10) = 0x1000;
        *(undefined2 *)(iVar13 + 0x1e88) = 0x1000;
        *(undefined2 *)(iVar13 + 0x2000) = 0x1000;
        *(undefined2 *)(iVar13 + 0x2178) = 0x1000;
        *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x80;
        *puVar12 = *puVar12 & 0xfffff3ff;
        *(uint *)(iVar13 + 0x1d60) = *(uint *)(iVar13 + 0x1d60) & 0xfffff3ff;
        *(uint *)(iVar13 + 0x1be8) = *(uint *)(iVar13 + 0x1be8) & 0xfffff3ff;
        *(uint *)(iVar13 + 0x2050) = *(uint *)(iVar13 + 0x2050) & 0xfffff3ff;
        *(uint *)(iVar13 + 0x1ed8) = *(uint *)(iVar13 + 0x1ed8) & 0xfffff3ff;
      }
    }
  }
  return;
}
