/* FUN_80168cd0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80168cd0  body 0x80168cd0..0x80169b87  size 3768 B
 * body sha256 3be7d15f56851ab48c8ad3f8b81179b5234b74deec4f3f5d0850028b844e098d
 * provider record sha256 810fe3ff5708812767c74432bcf34ac9222a97b00de0832e42b0720f4fad9c08
 * callees 17 direct (17 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80168cd0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  ushort uVar4;
  uint uVar1;
  uint uVar2;
  byte bVar5;
  char cVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  short *psVar11;
  short local_68 [12];
  short local_50;
  short local_4e;
  short local_4c;
  undefined1 auStack_48 [32];
  
  local_68[0] = 0x1f;
  local_68[1] = 0x28;
  local_68[2] = 0x16;
  local_68[3] = -0x14;
  local_68[4] = -0x1e;
  local_68[5] = 10;
  local_68[6] = 0x16;
  local_68[7] = 0;
  bVar5 = *(byte *)((int)param_1 + 6);
  *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x40;
  if (bVar5 != 1) {
    if (1 < bVar5) {
      if (bVar5 != 2) {
        if (bVar5 == 3) {
          *(undefined1 *)((int)param_1 + 0x1e9) = 1;
          return;
        }
        return;
      }
      DAT_8016c500 = DAT_8016c500 - 0xfeff00;
      if (0xbf0000 < (DAT_8016c500 & 0xff0000)) {
        DAT_8016c500 = DAT_8016c500 & 0xff0000ff | 0xbfbf00;
      }
      if ((DAT_8016c500 & 0xff000000) < 0x10000000) {
        DAT_8016c500 = DAT_8016c500 & 0xffffff | 0x10000000;
      }
      func_0x800341dc(param_1[0x82],DAT_8016c500);
      uVar8 = param_1[0x8d];
      if (0x80 < *(short *)(uVar8 + 0x124)) {
        *(short *)(uVar8 + 0x124) = *(short *)(uVar8 + 0x124) + -8;
        *(short *)(uVar8 + 0x126) = *(short *)(uVar8 + 0x126) + -8;
        *(short *)(uVar8 + 0x128) = *(short *)(uVar8 + 0x128) + -8;
        uVar8 = param_1[0x8d];
        *(short *)(uVar8 + 0xe5c) = *(short *)(uVar8 + 0xe5c) + -8;
        *(short *)(uVar8 + 0xe60) = *(short *)(uVar8 + 0xe60) + -8;
        *(short *)(uVar8 + 0xe5e) = *(short *)(uVar8 + 0xe5e) + -8;
        uVar8 = param_1[0x8d];
        *(short *)(uVar8 + 0x87c) = *(short *)(uVar8 + 0x87c) + -8;
        *(short *)(uVar8 + 0x880) = *(short *)(uVar8 + 0x880) + -8;
        *(short *)(uVar8 + 0x87e) = *(short *)(uVar8 + 0x87e) + -8;
        uVar8 = param_1[0x8d];
        *(short *)(uVar8 + 0x9f4) = *(short *)(uVar8 + 0x9f4) + -8;
        *(short *)(uVar8 + 0x9f8) = *(short *)(uVar8 + 0x9f8) + -8;
        *(short *)(uVar8 + 0x9f6) = *(short *)(uVar8 + 0x9f6) + -8;
        uVar8 = param_1[0x8d];
        *(short *)(uVar8 + 0xb6c) = *(short *)(uVar8 + 0xb6c) + -8;
        *(short *)(uVar8 + 0xb70) = *(short *)(uVar8 + 0xb70) + -8;
        *(short *)(uVar8 + 0xb6e) = *(short *)(uVar8 + 0xb6e) + -8;
        uVar8 = param_1[0x8d];
        *(short *)(uVar8 + 0x29c) = *(short *)(uVar8 + 0x29c) + -8;
        *(short *)(uVar8 + 0x29e) = *(short *)(uVar8 + 0x29e) + -8;
        *(short *)(uVar8 + 0x2a0) = *(short *)(uVar8 + 0x2a0) + -8;
        uVar8 = param_1[0x8d];
        *(short *)(uVar8 + 0x414) = *(short *)(uVar8 + 0x414) + -8;
        *(short *)(uVar8 + 0x418) = *(short *)(uVar8 + 0x418) + -8;
        *(short *)(uVar8 + 0x416) = *(short *)(uVar8 + 0x416) + -8;
        uVar8 = param_1[0x8d];
        *(short *)(uVar8 + 0x58c) = *(short *)(uVar8 + 0x58c) + -8;
        *(short *)(uVar8 + 0x590) = *(short *)(uVar8 + 0x590) + -8;
        *(short *)(uVar8 + 0x58e) = *(short *)(uVar8 + 0x58e) + -8;
      }
      if ((*(ushort *)((int)param_1 + 0x1f6) & 7) == 0) {
        uVar10 = param_1[0x8d];
        uVar4 = func_0x80033604();
        local_50 = (uVar4 & 0xff) * -2 + 0x39d;
        uVar4 = func_0x80033604();
        local_4e = (uVar4 & 0xff) * -2 + 0x7d;
        uVar4 = func_0x80033604();
        local_4c = (uVar4 & 0xff) * -2 + 0x7d;
        uVar8 = func_0x80033604();
        uVar1 = func_0x80033604();
        uVar2 = func_0x80033604();
        func_0x80037780((uVar8 & 1) << 0x10 | (uVar1 & 0xff) * 8 + 0x1000,(uVar2 & 0xff) << 4,
                        uVar10 + 0xee8,&local_50);
        uVar4 = func_0x80033604();
        local_50 = (uVar4 & 0xff) * -2 + 0x145;
        uVar4 = func_0x80033604();
        local_4e = (uVar4 & 0xff) * -2 + 0x7d;
        uVar4 = func_0x80033604();
        local_4c = (uVar4 & 0xff) * -2 + 0x7d;
        uVar8 = func_0x80033604();
        uVar1 = func_0x80033604();
        uVar2 = func_0x80033604();
        func_0x80037780((uVar8 & 1) << 0x10 | (uVar1 & 0xff) * 8 + 0x1000,(uVar2 & 0xff) << 4,
                        uVar10 + 0xee8,&local_50);
      }
      if ((*(short *)((int)param_1 + 0x1f6) < 0x1e) &&
         ((*(ushort *)((int)param_1 + 0x1f6) & 3) == 0)) {
        uVar10 = param_1[0x8d];
        local_50 = 200;
        uVar4 = func_0x80033604(param_1);
        local_4e = 0x16c - (uVar4 & 0xff);
        uVar4 = func_0x80033604();
        local_4c = 0x40 - (uVar4 & 0xff);
        uVar8 = func_0x80033604();
        uVar1 = func_0x80033604();
        uVar2 = func_0x80033604();
        func_0x80037780(((uVar8 & 1) + 0x10) * 0x10000 | (uVar1 & 0xff) * 4 + 0x1000,
                        (uVar2 & 0xff) << 4,uVar10 + 0x2668,&local_50);
      }
      *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + 1;
      func_0x80089d54(param_1,param_2,param_3,0x200);
      uVar8 = param_1[0x8d];
      iVar9 = uVar8 + 0xeb0;
      *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c) = *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c) + 2;
      if (*(short *)((int)param_1 + 0x27a) < 0x1000) {
        *(short *)((int)param_1 + 0x27a) = *(short *)((int)param_1 + 0x27a) + 0x10;
      }
      cVar6 = *(char *)((int)param_1 + 0x207) + -1;
      if (*(char *)((int)param_1 + 0x207) == '\0') {
        *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c) =
             *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c) +
             local_68[*(char *)((int)param_1 + 0x206)] * 2;
        cVar6 = *(char *)((int)param_1 + 0x206) + '\x01';
        *(char *)((int)param_1 + 0x206) = cVar6;
        if ('\a' < cVar6) {
          *(undefined1 *)((int)param_1 + 0x206) = 0;
          bVar5 = func_0x80033604();
          cVar6 = (bVar5 & 0x1f) + 10;
          goto LAB_80169ae8;
        }
      }
      else {
LAB_80169ae8:
        *(char *)((int)param_1 + 0x207) = cVar6;
      }
      if (0x13e8 < *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c)) {
        *(undefined1 *)((int)param_1 + 6) = 3;
        *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x800;
        FUN_8016baa0(0,5,0);
        FUN_8016baa0(1,0,4);
        FUN_8016baa0(2,7,0xfffffff9);
      }
      goto LAB_80169b48;
    }
    if (bVar5 != 0) {
      return;
    }
    uVar8 = param_1[0x8d];
    sVar3 = func_0x80032d14((int)*(short *)((int)param_1 + 0x2a),
                            (int)*(short *)((int)param_1 + 0x32),(int)_DAT_800e115a,
                            (int)_DAT_800e1162);
    psVar11 = local_68 + 8;
    local_68[8] = 0;
    local_68[10] = 0;
    local_68[9] = sVar3;
    func_0x80040e58(psVar11,auStack_48);
    local_68[8] = 200;
    local_68[9] = -200;
    local_4e = 0;
    local_4c = 0;
    local_50 = *(short *)(param_1 + 0x78) * 4 + 300;
    if ((uint)*(byte *)((int)param_1 + 0x26e) % 3 == 0) {
      local_68[8] = 0x96;
      local_68[9] = 800;
      local_4e = 700;
      local_50 = *(short *)(param_1 + 0x78) * 2 + 0x96;
    }
    func_0x8004276c(auStack_48,psVar11,psVar11);
    local_68[8] = local_68[8] + *(short *)(uVar8 + 0xefe);
    local_68[9] = local_68[9] + *(short *)(uVar8 + 0xf02);
    local_68[10] = local_68[10] + *(short *)(uVar8 + 0xf06);
    func_0x8004276c(auStack_48,&local_50,&local_50);
    local_50 = local_50 + *(short *)(uVar8 + 0xefe);
    local_4e = local_4e + *(short *)(uVar8 + 0xf02);
    local_4c = local_4c + *(short *)(uVar8 + 0xf06);
    if ((*(char *)((int)param_1 + 5) != '\x10') && (*(char *)((int)param_1 + 5) != '\f')) {
      uVar8 = func_0x80033604();
      iVar9 = (int)sVar3;
      func_0x80037780((uVar8 & 0xff) * 8 + 0x17d0 | 0x10000,iVar9,0x800e9028,psVar11);
      uVar4 = func_0x80033604();
      local_68[9] = local_68[9] - ((uVar4 & 0x3f) - 0x40);
      uVar8 = func_0x80033604();
      func_0x80037780((uVar8 & 0xff) * 8 + 0x17d0,iVar9,0x800e9028,psVar11);
      uVar8 = func_0x80033604();
      func_0x80037780((uVar8 & 0xff) * 8 + 0x17d0,iVar9,0x800e9028,&local_50);
      uVar4 = func_0x80033604();
      local_68[9] = local_68[9] - ((uVar4 & 0x3f) - 0x40);
      uVar8 = func_0x80033604();
      func_0x80037780((uVar8 & 0xff) * 8 + 0x17d0,iVar9,0x800e9028,&local_50);
      if (*(char *)((int)param_1 + 5) != '\x01') {
        func_0x80077d18(0xd,param_1);
      }
    }
    if (*(byte *)((int)param_1 + 5) - 5 < 2) {
      *(undefined1 *)(param_1 + 0xaf) = 1;
    }
    if (*(byte *)((int)param_1 + 0x26e) < 3) {
      cVar6 = *(char *)((int)param_1 + 5);
      if (cVar6 == '\t') {
        FUN_80167498(param_1);
        cVar6 = *(char *)((int)param_1 + 5);
      }
      if (cVar6 == '\x11') {
        FUN_80167628(param_1);
      }
      cVar6 = *(char *)((int)param_1 + 5);
      if (cVar6 == '\n') {
        FUN_80167228(param_1);
        cVar6 = *(char *)((int)param_1 + 5);
      }
      if (cVar6 == '\v') {
        FUN_80167360(param_1);
      }
    }
    if (*(char *)((int)param_1 + 5) == '\x0e') {
      FUN_801678c0(param_1);
    }
    if ((*(ushort *)((int)param_1 + 0x2b6) & 0x80) != 0) {
      param_1[1] = param_1[0xa6];
      FUN_8016250c(param_1,param_2,param_3);
      *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x100;
      return;
    }
    puVar7 = (uint *)param_1[0x8d];
    param_1[0x7a] = 0x11000700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x9c) = *(ushort *)(param_1 + 0x9c) | 4;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    DAT_8016c500 = 0x80808000;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x1000;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
    *param_1 = *param_1 | 2;
    *(undefined2 *)(puVar7 + 0x49) = 0x1000;
    *(undefined2 *)((int)puVar7 + 0x126) = 0x1000;
    *(undefined2 *)(puVar7 + 0x4a) = 0x1000;
    *puVar7 = *puVar7 | 0x400;
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0xd38) = *(uint *)(uVar8 + 0xd38) | 0x400;
    *(undefined2 *)(uVar8 + 0xe5c) = 0x1000;
    *(undefined2 *)(uVar8 + 0xe5e) = 0x1000;
    *(undefined2 *)(uVar8 + 0xe60) = 0x1000;
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0x758) = *(uint *)(uVar8 + 0x758) | 0x400;
    *(undefined2 *)(uVar8 + 0x87c) = 0x1000;
    *(undefined2 *)(uVar8 + 0x87e) = 0x1000;
    *(undefined2 *)(uVar8 + 0x880) = 0x1000;
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0x8d0) = *(uint *)(uVar8 + 0x8d0) | 0x400;
    *(undefined2 *)(uVar8 + 0x9f4) = 0x1000;
    *(undefined2 *)(uVar8 + 0x9f6) = 0x1000;
    *(undefined2 *)(uVar8 + 0x9f8) = 0x1000;
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0xa48) = *(uint *)(uVar8 + 0xa48) | 0x400;
    *(undefined2 *)(uVar8 + 0xb6c) = 0x1000;
    *(undefined2 *)(uVar8 + 0xb6e) = 0x1000;
    *(undefined2 *)(uVar8 + 0xb70) = 0x1000;
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0x178) = *(uint *)(uVar8 + 0x178) | 0x400;
    *(undefined2 *)(uVar8 + 0x29c) = 0x1000;
    *(undefined2 *)(uVar8 + 0x29e) = 0x1000;
    *(undefined2 *)(uVar8 + 0x2a0) = 0x1000;
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0x2f0) = *(uint *)(uVar8 + 0x2f0) | 0x400;
    *(undefined2 *)(uVar8 + 0x414) = 0x1000;
    *(undefined2 *)(uVar8 + 0x416) = 0x1000;
    *(undefined2 *)(uVar8 + 0x418) = 0x1000;
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0x468) = *(uint *)(uVar8 + 0x468) | 0x400;
    *(undefined2 *)(uVar8 + 0x58c) = 0x1000;
    *(undefined2 *)(uVar8 + 0x58e) = 0x1000;
    *(undefined2 *)(uVar8 + 0x590) = 0x1000;
  }
  if (*(byte *)((int)param_1 + 0x1e9) - 0xb < 0x4f) {
    uVar10 = param_1[0x8d];
    uVar4 = func_0x80033604();
    local_50 = (uVar4 & 0xff) * -2 + 0x39d;
    uVar4 = func_0x80033604();
    local_4e = (uVar4 & 0xff) * -2 + 0x7d;
    uVar4 = func_0x80033604();
    local_4c = (uVar4 & 0xff) * -2 + 0x7d;
    uVar8 = func_0x80033604();
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar8 & 1) << 0x10 | (uVar1 & 0xff) * 4 + 0x13e8,(uVar2 & 0xff) << 4,
                    uVar10 + 0xee8,&local_50);
    uVar4 = func_0x80033604();
    local_50 = (uVar4 & 0xff) * -2 + 0x39d;
    uVar4 = func_0x80033604();
    local_4e = (uVar4 & 0xff) * -2 + 0x7d;
    uVar4 = func_0x80033604();
    local_4c = (uVar4 & 0xff) * -2 + 0x7d;
    uVar8 = func_0x80033604();
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar8 & 1) << 0x10 | (uVar1 & 0xff) * 4 + 0xc18,(uVar2 & 0xff) << 4,
                    uVar10 + 0xee8,&local_50);
  }
  uVar1 = (uint)*(byte *)((int)param_1 + 0x1e9);
  uVar8 = uVar1 - 6;
  if ((0x5a < uVar1) && (uVar8 = uVar1 - 6, (*(byte *)((int)param_1 + 0x1e9) & 3) == 0)) {
    uVar10 = param_1[0x8d];
    uVar4 = func_0x80033604();
    local_50 = (uVar4 & 0xff) * -2 + 0x39d;
    uVar4 = func_0x80033604();
    local_4e = (uVar4 & 0xff) * -2 + 0x7d;
    uVar4 = func_0x80033604();
    local_4c = (uVar4 & 0xff) * -2 + 0x7d;
    uVar8 = func_0x80033604();
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar8 & 1) << 0x10 | (uVar1 & 0xff) * 8 + 0x1000,(uVar2 & 0xff) << 4,
                    uVar10 + 0xee8,&local_50);
    uVar4 = func_0x80033604();
    local_50 = (uVar4 & 0xff) * -2 + 0x39d;
    uVar4 = func_0x80033604();
    local_4e = (uVar4 & 0xff) * -2 + 0x7d;
    uVar4 = func_0x80033604();
    local_4c = (uVar4 & 0xff) * -2 + 0x7d;
    uVar8 = func_0x80033604();
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar8 & 1) << 0x10 | (uVar1 & 0xff) * 8 + 0x830,(uVar2 & 0xff) << 4,
                    uVar10 + 0xee8,&local_50);
    uVar1 = (uint)*(byte *)((int)param_1 + 0x1e9);
    uVar8 = uVar1 - 6;
  }
  if ((uVar8 < 0x1d) || (uVar1 - 0x3d < 0x1d)) {
    uVar10 = param_1[0x8d];
    local_50 = 300;
    uVar4 = func_0x80033604();
    local_4e = 0x19e - (uVar4 & 0xff);
    uVar4 = func_0x80033604();
    local_4c = 0x40 - (uVar4 & 0xff);
    uVar8 = func_0x80033604();
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780(((uVar8 & 1) + 0x10) * 0x10000 | (uVar1 & 0xff) * 4 + 0x17d0,(uVar2 & 0xff) << 4
                    ,uVar10 + 0x2668,&local_50);
  }
  if ((5 < *(byte *)((int)param_1 + 0x1e9)) && ((*(byte *)((int)param_1 + 0x1e9) & 3) == 0)) {
    uVar10 = param_1[0x8d];
    local_50 = 200;
    uVar4 = func_0x80033604();
    local_4e = 0x19e - (uVar4 & 0xff);
    uVar4 = func_0x80033604();
    local_4c = 0x40 - (uVar4 & 0xff);
    uVar8 = func_0x80033604();
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780(((uVar8 & 1) + 0x10) * 0x10000 | (uVar1 & 0xff) * 4 + 0x1000,(uVar2 & 0xff) << 4
                    ,uVar10 + 0x2668,&local_50);
  }
  if (*(char *)((int)param_1 + 0x1e9) == '2') {
    uVar8 = param_1[0x8d];
    *(uint *)(uVar8 + 0xeb0) = *(uint *)(uVar8 + 0xeb0) | 0x80;
    *(undefined4 *)(uVar8 + 0xfe0) = 0x30;
    *(undefined4 *)(uVar8 + 0xfe4) = 0x202020;
  }
  iVar9 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar9 != 0) {
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(undefined2 *)((int)param_1 + 0x27a) = 0x1000;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 0x207) = (bVar5 & 0x1f) + 10;
    param_1[0x7a] = 0x1c000700;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
  }
  if (*(byte *)((int)param_1 + 0x1e9) < 0x3d) {
    return;
  }
  uVar8 = param_1[0x8d];
  iVar9 = uVar8 + 0xeb0;
  *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c) = *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c) + 4;
  sVar3 = *(short *)((int)param_1 + 0x27a) + -4;
  *(short *)((int)param_1 + 0x27a) = sVar3;
  if (sVar3 < 0x800) {
    *(undefined2 *)((int)param_1 + 0x27a) = 0x800;
  }
  if (0x800 < *(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c)) {
    *(undefined2 *)(*(int *)(uVar8 + 0xfd0) + 0x1c) = 0x800;
  }
LAB_80169b48:
  func_0x80066288(param_1,iVar9);
  func_0x80066554(param_1,iVar9);
  return;
}
