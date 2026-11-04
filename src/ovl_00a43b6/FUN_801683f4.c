/* FUN_801683f4
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801683f4  body 0x801683f4..0x8016895b  size 1384 B
 * body sha256 054527c430e381abdd86aecca2c0315ddf8f048788144942430c9135678016ba
 * provider record sha256 b6879f2479c44c98df54e768e7e89675f8351e72e4c4293af729a66c6fffb907
 * callees 15 direct (15 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801683f4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar4;
  ushort uVar5;
  uint uVar2;
  int iVar3;
  char cVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_50 [32];
  short local_30;
  ushort local_2e;
  short local_2c;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  uVar7 = param_1[0x82];
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      if (*(char *)(uVar7 + 0x18) != '\x10') {
        *(char *)(uVar7 + 0x18) = *(char *)(uVar7 + 0x18) + -1;
        *(char *)(uVar7 + 0x40) = *(char *)(uVar7 + 0x40) + -1;
      }
      if ((*(uint *)(uVar7 + 0x40) & 1) != 0) {
        *(int *)(uVar7 + 0x18) = *(int *)(uVar7 + 0x18) + 0x10100;
        *(int *)(uVar7 + 0x40) = *(int *)(uVar7 + 0x40) + 0x10100;
        *(undefined1 *)(uVar7 + 0x1b) = 1;
      }
      if (*(short *)(param_1 + 0x7d) == 0) {
        return;
      }
      *(short *)(uVar7 + 4) = *(short *)(uVar7 + 4) + 5;
      *(short *)(uVar7 + 6) = *(short *)(uVar7 + 6) + 5;
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -1;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    uVar7 = param_1[0x8d];
    uVar4 = func_0x80032d14((int)*(short *)((int)param_1 + 0x2a),
                            (int)*(short *)((int)param_1 + 0x32),(int)_DAT_800e115a,
                            (int)_DAT_800e1162);
    uVar4 = uVar4 & 0xff;
    local_30 = 0;
    local_2c = 0;
    local_2e = uVar4;
    func_0x80040e58(&local_30,auStack_50);
    local_30 = 100;
    local_2e = 0;
    if ((uint)*(byte *)((int)param_1 + 0x26e) % 3 == 0) {
      local_2e = 700;
    }
    func_0x8004276c(auStack_50,&local_30,&local_30);
    local_30 = local_30 + *(short *)(uVar7 + 0x1c6);
    local_2e = local_2e + *(short *)(uVar7 + 0x1ca);
    local_2c = local_2c + *(short *)(uVar7 + 0x1ce);
    if (*(char *)((int)param_1 + 5) != '\x10') {
      uVar7 = func_0x80033604();
      func_0x80037780((uVar7 & 0xff) * 8 + 0x17d0 | 0x10000,uVar4,0x800e9028,&local_30);
      uVar5 = func_0x80033604();
      local_2e = local_2e - ((uVar5 & 0x3f) - 0x40);
      uVar7 = func_0x80033604();
      func_0x80037780((uVar7 & 0xff) * 8 + 0x17d0,uVar4,0x800e9028,&local_30);
    }
    if (*(byte *)((int)param_1 + 5) - 5 < 2) {
      *(undefined1 *)((int)param_1 + 0x2c5) = 1;
    }
    if (*(byte *)((int)param_1 + 0x26e) < 3) {
      cVar6 = *(char *)((int)param_1 + 5);
      if (cVar6 == '\t') {
        FUN_801674ec(param_1);
        cVar6 = *(char *)((int)param_1 + 5);
      }
      if (cVar6 == '\x11') {
        FUN_8016767c(param_1);
      }
      cVar6 = *(char *)((int)param_1 + 5);
      if (cVar6 == '\n') {
        FUN_8016724c(param_1);
        cVar6 = *(char *)((int)param_1 + 5);
      }
      if (cVar6 == '\v') {
        FUN_801673b4(param_1);
      }
    }
    cVar6 = *(char *)((int)param_1 + 5);
    if (cVar6 == '\x0e') {
      FUN_8016780c(param_1);
      cVar6 = *(char *)((int)param_1 + 5);
    }
    if (cVar6 == '\x10') {
      FUN_8016724c(param_1);
    }
    if ((param_1[0xae] & 0x1000000) == 0) {
      *(undefined2 *)((int)param_1 + 0x1f2) = 10;
      param_1[1] = param_1[0xa6];
      return;
    }
    param_1[0x7a] = 0xa000300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0xaf) = 2;
    *(undefined1 *)((int)param_1 + 0x2bd) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) | 0x11;
    func_0x80035b84(param_1);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
  }
  if (*(byte *)((int)param_1 + 0x1e9) < 0xf) {
    uVar8 = param_1[0x8d];
    uVar7 = func_0x80033604();
    local_30 = 0x40 - (short)((uVar7 & 0xff) >> 1);
    local_2e = 0;
    uVar7 = func_0x80033604();
    local_2c = 0x40 - (short)((uVar7 & 0xff) >> 1);
    uVar7 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar7 & 1) << 0x10 | 0xc00,(uVar2 & 0xff) << 4,uVar8 + 0x4a0,&local_30);
  }
  if (*(byte *)((int)param_1 + 0x1e9) - 0x51 < 0x1c) {
    if (*(byte *)((int)param_1 + 0x1e9) == 0x51) {
      func_0x80077d18(9,param_1);
    }
    uVar8 = param_1[0x8d];
    uVar7 = func_0x80033604();
    local_30 = 0x40 - (short)((uVar7 & 0xff) >> 1);
    local_2e = 0xff38;
    uVar7 = func_0x80033604();
    local_2c = 0x40 - (short)((uVar7 & 0xff) >> 1);
    uVar7 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar7 & 1) << 0x10 | 0xc00,(uVar2 & 0xff) << 4,uVar8 + 0x4a0,&local_30);
    uVar8 = param_1[0x8d];
    uVar4 = func_0x80033604();
    local_30 = (uVar4 & 0xff) * -2 + 0x100;
    uVar4 = func_0x80033604();
    local_2e = (uVar4 & 0xff) * -4 + 0xd4;
    uVar4 = func_0x80033604();
    local_2c = (uVar4 & 0xff) * -2 + 0x100;
    uVar7 = func_0x80033604();
    uVar2 = func_0x80033604();
    func_0x80037780((uVar7 & 1) << 0x10 | 0x17b8,(uVar2 & 0xff) << 4,uVar8 + 0x328,&local_30);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar3 != 0) {
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 0x7d) = 0xd2;
    *(undefined1 *)(param_1 + 0xaf) = 0;
    *(undefined1 *)((int)param_1 + 0x2bd) = 0;
    *(ushort *)(param_1 + 0xae) = *(ushort *)(param_1 + 0xae) & 0xffdf;
    *param_1 = *param_1 | 2;
  }
  func_0x80032b5c(param_1,0);
  return;
}
