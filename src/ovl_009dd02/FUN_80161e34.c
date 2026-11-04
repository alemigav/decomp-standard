/* FUN_80161e34
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80161e34  body 0x80161e34..0x8016234b  size 1304 B
 * body sha256 43747e08a0470489c3a02bd251b7472761d313683c6b98dc5a38a359b4741fdb
 * provider record sha256 b2cc483bae00bd3d1004e4da1067900ef1d40c9504e913ec16d7bee77cee9d2c
 * callees 6 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161e34(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined2 uVar6;
  ushort uVar5;
  int iVar3;
  undefined1 uVar7;
  int iVar4;
  uint *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  short sVar11;
  byte bVar12;
  byte bVar13;
  byte *pbVar14;
  
  bVar12 = 0;
  bVar13 = (&DAT_80167260)[*(ushort *)((int)param_1 + 0x1aa) & 0xf];
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  param_1[1] = (uint)bVar13 * 0x10000 + 0x1000000;
  uVar2 = 0;
  do {
    param_1[uVar2 + 0xad] = 0;
    bVar12 = bVar12 + 1;
    uVar2 = (uint)bVar12;
  } while (bVar12 < 0xc);
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  if ((_DAT_800e10ec & 0x20) == 0) {
    sVar11 = 0x32;
    uVar2 = func_0x80033604();
    uVar6 = *(undefined2 *)(&DAT_80167190 + (uVar2 & 0xf) * 2);
  }
  else {
    sVar11 = 0x14;
    uVar2 = func_0x80033604();
    uVar6 = *(undefined2 *)(&DAT_801671b0 + (uVar2 & 0xf) * 2);
  }
  *(undefined2 *)((int)param_1 + 0x1f2) = uVar6;
  uVar5 = func_0x80033604();
  *(ushort *)((int)param_1 + 0x1f2) = *(short *)((int)param_1 + 0x1f2) + (uVar5 & 3);
  iVar3 = func_0x800837ac(0x800e8ce0,0xa4);
  if (iVar3 != 0) {
    *(short *)((int)param_1 + 0x1f2) = *(short *)((int)param_1 + 0x1f2) - sVar11;
  }
  *(undefined1 *)((int)param_1 + 0x1ed) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ef) = 0xd;
  *(short *)(param_1 + 0xb1) = *(short *)((int)param_1 + 0x1f2) >> 1;
  uVar2 = param_1[0x8d];
  param_1[0x94] = (uint)&DAT_800e1130;
  *(undefined1 *)((int)param_1 + 0x25d) = 9;
  bVar13 = 0;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *param_1 = *param_1 | 0xc000000;
  *(undefined2 *)(uVar2 + 0xe6c) = 0xc;
  *(undefined2 *)(uVar2 + 0xe70) = 0x200;
  *(undefined2 *)(uVar2 + 0xe68) = 0;
  *(undefined2 *)(uVar2 + 0xe6a) = 0;
  *(undefined2 *)(uVar2 + 0xe6e) = 0;
  *(undefined2 *)(uVar2 + 0xe72) = 0;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x136) = 700;
  *(undefined2 *)(param_1 + 0x4e) = 600;
  *(undefined2 *)(param_1 + 0x4c) = 800;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(undefined2 *)(param_1 + 0x4b) = 800;
  *(undefined2 *)((int)param_1 + 0x12e) = 800;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  uVar2 = 0;
  while( true ) {
    puVar8 = (uint *)(param_1[0x8d] + uVar2 * 0x178);
    bVar13 = bVar13 + 1;
    *puVar8 = *puVar8 | 0x8000;
    if (0x19 < bVar13) break;
    uVar2 = (uint)bVar13;
  }
  uVar7 = func_0x80036ed8(param_1,param_1 + 0xb4,0x2e,1);
  *(undefined1 *)((int)param_1 + 0x2b5) = uVar7;
  *(undefined1 *)((int)param_1 + 0x2bf) = 0x5a;
  uVar2 = func_0x80033604();
  pbVar14 = &DAT_80167220 + (uVar2 & 3) * 4;
  uVar2 = func_0x80033604();
  bVar13 = 0;
  while( true ) {
    if ((*(ushort *)((int)param_1 + 0x1aa) & 0x10) == 0) {
      bVar1 = bVar13 < 4;
    }
    else {
      bVar1 = bVar13 < 3;
    }
    if (!bVar1) break;
    bVar12 = *pbVar14;
    pbVar14 = pbVar14 + 1;
    iVar3 = (uint)bVar12 * 8;
    iVar4 = func_0x80031ff0(0x2f);
    if (iVar4 != 0) {
      *(ushort *)(iVar4 + 0x1aa) = (byte)(&DAT_801671e0)[iVar3] + 1;
      *(undefined *)(iVar4 + 0x2b5) = (&DAT_801671e1)[iVar3];
      *(undefined2 *)(iVar4 + 0x2b6) = *(undefined2 *)(&DAT_801671e2 + iVar3);
      *(undefined2 *)(iVar4 + 0x2b8) = *(undefined2 *)(&DAT_801671e4 + iVar3);
      uVar6 = *(undefined2 *)(&DAT_801671e6 + iVar3);
      *(uint **)(iVar4 + 0x250) = param_1;
      *(undefined2 *)(iVar4 + 0x2ba) = uVar6;
      uVar7 = *(undefined1 *)((int)param_1 + 0x1a2);
      *(bool *)(iVar4 + 0x2bf) = (uint)bVar13 == (uVar2 & 3);
      *(byte *)(iVar4 + 0x2b4) = bVar13;
      *(undefined1 *)(iVar4 + 0x1a2) = uVar7;
      *(byte *)((int)param_1 + 0x2c2) =
           *(byte *)((int)param_1 + 0x2c2) | (byte)(1 << (bVar13 & 0x1f));
      func_0x800339dc(iVar4 + 0x208,0,0x320190,0,iVar4 + 0x28);
    }
    bVar13 = bVar13 + 1;
  }
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xff0f;
  if (*(char *)(param_1 + 2) == '.') {
    _DAT_800df9c0 = FUN_80165e28;
    _DAT_800dfac0 = FUN_8016624c;
  }
  else {
    _DAT_800df9ec = FUN_80165e28;
    _DAT_800dfaec = FUN_8016624c;
  }
  uVar5 = *(ushort *)((int)param_1 + 0x1aa);
  if (uVar5 == 6) {
    *param_1 = *param_1 & 0xe7ffffff;
    func_0x800339dc(param_1 + 0x82,0xfd440000,0x7080384,0,param_1 + 10);
    *(undefined2 *)(param_1 + 0x4c) = 100;
    *(undefined2 *)((int)param_1 + 0x132) = 0xfed4;
    *(undefined2 *)((int)param_1 + 0x136) = 1000;
    *(undefined2 *)(param_1 + 0x4e) = 500;
  }
  else {
    if (((uVar5 < 6) || (0x6005 < uVar5)) || (uVar5 < 0x6004)) {
      param_1[0x7a] = 0;
      func_0x80089d54(param_1,param_2,param_3,0x40);
      uVar9 = 0xfe70;
      uVar10 = 0x3e80898;
      uVar2 = param_1[0x8d];
    }
    else {
      param_1[0x7a] = 0xc5a0000;
      func_0x80089d54(param_1,param_2,param_3,0x40);
      uVar9 = 0xfe0c;
      uVar10 = 0x3840708;
      uVar2 = param_1[0x8d];
      *param_1 = *param_1 | 0x408;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    }
    func_0x800339dc(param_1 + 0x82,uVar9,uVar10,0,uVar2 + 0xefc);
  }
  *param_1 = *param_1 | 0x800000;
  return;
}
