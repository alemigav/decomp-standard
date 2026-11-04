/* FUN_80169c68
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80169c68  body 0x80169c68..0x8016a12b  size 1220 B
 * body sha256 43fe6d5f437d17b0b022c64d4ad1e4c43b2c7324c47856e23ede594a16fcc8d7
 * provider record sha256 10345d5f96e947345cc714ca9e02e3f37c717c2e82d0f68779ec001bd1080458
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80169c68(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  byte bVar5;
  ushort uVar4;
  char cVar6;
  uint uVar2;
  uint uVar3;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte local_28 [8];
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  
  local_28[0] = 1;
  local_28[1] = 2;
  bVar5 = *(byte *)((int)param_1 + 6);
  if (bVar5 != 1) {
    if (1 < bVar5) {
      if (bVar5 != 2) {
        return;
      }
      param_1[1] = 0x7000000;
      uVar2 = func_0x80033604();
      if ((uVar2 & 3) != 0) {
        return;
      }
      if ((*(ushort *)((int)param_1 + 0x2b6) & 4) != 0) {
        return;
      }
      if (*(short *)(param_1 + 0x6a) != 0) {
        return;
      }
      if (*(char *)((int)param_1 + 0x207) != '\0') {
        return;
      }
      if ((_DAT_800e110c & 0x10000000) != 0) {
        return;
      }
      *(undefined2 *)((int)param_1 + 0x136) = 200;
      *(undefined2 *)(param_1 + 0x4e) = 200;
      *(undefined2 *)(param_1 + 0x4b) = 200;
      *(undefined2 *)((int)param_1 + 0x12e) = 200;
      *(undefined2 *)(param_1 + 0x4d) = 0xfea2;
      *(undefined2 *)((int)param_1 + 0x13a) = 0x15e;
      *(undefined2 *)((int)param_1 + 0x1aa) = 0x2001;
      *(undefined2 *)((int)param_1 + 0x1f2) = 1;
      *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
      uVar2 = func_0x80033604();
      uVar3 = 0x1020000;
      if ((uVar2 & 7) == 0) {
        uVar3 = 0x1000000;
      }
      param_1[1] = uVar3;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      return;
    }
    if (bVar5 != 0) {
      return;
    }
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 0x206) = bVar5 & 1;
    if ((*(ushort *)((int)param_1 + 0x2b6) & 0x2000) != 0) {
      *(undefined1 *)((int)param_1 + 0x206) = 0;
    }
    uVar4 = *(ushort *)((int)param_1 + 0x2b6) & 0xfffb;
    *(ushort *)((int)param_1 + 0x2b6) = uVar4;
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(ushort *)((int)param_1 + 0x2b6) = uVar4 | 4;
    }
    bVar5 = local_28[*(char *)((int)param_1 + 0x206)];
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 1;
    param_1[0x7a] = (uint)bVar5 * 0x1000000 + *(char *)((int)param_1 + 0x206) * 0xa0000 + 0xf00;
    if ((uint)*(byte *)((int)param_1 + 0x26e) % 3 == 0) {
      uVar7 = 0x17d0;
      local_20 = 0;
      local_1e = 800;
      local_1c = 0;
      sVar1 = *(short *)((int)param_1 + 0x66);
      iVar8 = param_1[0x8d] + 0x1b0;
    }
    else {
      uVar2 = param_1[0x8d];
      local_20 = *(undefined2 *)(uVar2 + 0xbde);
      uVar7 = 0x1fa0;
      local_1e = *(short *)(uVar2 + 0xbe2) + 300;
      local_1c = *(undefined2 *)(uVar2 + 0xbe6);
      sVar1 = *(short *)((int)param_1 + 0x66);
      iVar8 = param_1[0x8d] + 0x38;
    }
    func_0x80037780(uVar7,(int)sVar1,iVar8,&local_20);
    uVar2 = func_0x80033604();
    uVar7 = 0xb;
    if ((uVar2 & 1) != 0) {
      uVar7 = 0xd;
    }
    func_0x80077d18(uVar7,param_1);
    func_0x80035b84(param_1);
    cVar6 = *(char *)((int)param_1 + 5);
    if ((cVar6 == '\n') && ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0)) {
      FUN_80167910(param_1);
      cVar6 = *(char *)((int)param_1 + 5);
    }
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    if (cVar6 == '\v') {
      FUN_80167abc(param_1);
      uVar2 = func_0x80033604();
      if ((uVar2 & 1) != 0) {
        uVar2 = param_1[0x8d];
        *(uint *)(uVar2 + 0xbc0) = *(uint *)(uVar2 + 0xbc0) | 0x10;
        *(undefined2 *)(uVar2 + 0xcf6) = 0x801e;
        *(undefined2 *)(uVar2 + 0xcf0) = 0;
        *(undefined2 *)(uVar2 + 0xcf2) = 0;
        *(undefined1 *)(uVar2 + 0xcf4) = 10;
        *(undefined1 *)(uVar2 + 0xcf5) = 10;
        *(undefined4 *)(uVar2 + 0xc20) = 0x304040;
        func_0x80037780(0x40f0fa0,(int)*(short *)((int)param_1 + 0x66),uVar2 + 0xbf8,0);
        *(undefined1 *)((int)param_1 + 0x207) = 1;
      }
    }
    cVar6 = *(char *)((int)param_1 + 5);
    if ((cVar6 == '\t') || (cVar6 == '\x11')) {
      if ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0) {
        FUN_80167ba4(param_1);
      }
      cVar6 = *(char *)((int)param_1 + 5);
    }
    if (cVar6 == '\x0e') {
      FUN_80167c88(param_1);
    }
    if ((*(char *)((int)param_1 + 5) == '\x10') && ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0)
       ) {
      FUN_80167910(param_1);
    }
    *(undefined2 *)(param_1 + 0x78) = 0xb;
  }
  if ((uint)*(byte *)((int)param_1 + 0x26e) % 3 != 0) {
    bVar5 = *(byte *)((int)param_1 + 0x1e9);
    iVar8 = *(char *)((int)param_1 + 0x206) * 10;
    if (((iVar8 + 4 <= (int)(uint)bVar5) && ((int)(uint)bVar5 <= iVar8 + 0x10)) &&
       ((bVar5 & 1) != 0)) {
      uVar2 = param_1[0x8d];
      local_20 = *(undefined2 *)(uVar2 + 0xbde);
      local_1e = *(short *)(uVar2 + 0xbe2) + 500;
      local_1c = *(undefined2 *)(uVar2 + 0xbe6);
      uVar9 = param_1[0x8d];
      uVar2 = func_0x80033604(param_1);
      uVar3 = func_0x80033604();
      func_0x80037780((uVar2 & 0xff) * 8 + 0xfd0,(uVar3 & 0xff) << 4,uVar9 + 0x38,&local_20);
    }
  }
  cVar6 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar6;
  if (*(char *)((int)param_1 + 0x1ea) == '\0') {
    func_0x80033680(param_1,0,1);
  }
  return;
}
