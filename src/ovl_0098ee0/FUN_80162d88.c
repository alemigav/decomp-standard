/* FUN_80162d88
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162d88  body 0x80162d88..0x8016332b  size 1444 B
 * body sha256 ccf59ea81de29303ae2cce716a26c39c8c456f4bfd4295ee004cb7c448c524d3
 * provider record sha256 52c8d26d7ef14c22c309303123c67306762d9d72919c86a384ee519f5a13af70
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162d88(uint *param_1,uint param_2,uint param_3)

{
  short sVar1;
  undefined2 uVar3;
  undefined4 uVar2;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  
  puVar7 = (uint *)param_1[0x8d];
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0xf) != 7) {
    param_2 = param_1[0x87];
    uVar4 = param_1[0x69];
    param_1[0x69] = param_2;
    param_3 = param_1[0x88];
    param_1[0x87] = uVar4;
    param_1[0x88] = param_1[0x86];
    param_1[0x86] = param_3;
  }
  _DAT_800df9b0 = FUN_80165d24;
  param_1[1] = 0x1010000;
  *(undefined2 *)(param_1 + 0xb0) = 0;
  param_1[0x7a] = 0xff000000;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x4000) != 0) {
    *(undefined *)((int)param_1 + 5) = (&DAT_80166824)[*(ushort *)((int)param_1 + 0x1aa) & 0xf];
  }
  uVar4 = (*(ushort *)((int)param_1 + 0x1aa) & 0x300) >> 8;
  if (uVar4 == 1) {
    *(ushort *)(param_1 + 0xb0) = *(ushort *)(param_1 + 0xb0) | 6;
    if ((_DAT_800e10ec & 0x20) == 0) {
      uVar3 = 0x4f1a;
    }
    else {
      uVar3 = 0x4ed4;
    }
  }
  else if (uVar4 < 2) {
    if (uVar4 != 0) goto LAB_80162f38;
    uVar3 = 0x4f1a;
  }
  else if (uVar4 == 2) {
    *(ushort *)(param_1 + 0xb0) = *(ushort *)(param_1 + 0xb0) | 0x4b;
    if ((_DAT_800e10ec & 0x20) == 0) {
      uVar3 = 0x4fe2;
    }
    else {
      uVar3 = 0x4f74;
    }
  }
  else {
    if (uVar4 != 3) goto LAB_80162f38;
    *(ushort *)(param_1 + 0xb0) = *(ushort *)(param_1 + 0xb0) | 0x1a;
    if ((_DAT_800e10ec & 0x20) == 0) {
      uVar3 = 0x4f4c;
    }
    else {
      uVar3 = 0x4efc;
    }
  }
  *(undefined2 *)((int)param_1 + 0x1f2) = uVar3;
LAB_80162f38:
  iVar5 = (_DAT_800e8ca8 + 1) * 0x100 + (int)_DAT_800e8caa;
  if (iVar5 == 0x117) {
    if ((_DAT_800e10ec & 0x20) == 0) {
      sVar1 = 300;
    }
    else {
      sVar1 = 0xf0;
    }
    *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfcff | 0x100;
  }
  if (iVar5 == 0x10d) {
    if ((_DAT_800e10ec & 0x20) == 0) {
      sVar1 = 0xdc;
    }
    else {
      sVar1 = 0xaf;
    }
    *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfcff | 0x100;
  }
  if (iVar5 == 0x507) {
    if ((_DAT_800e10ec & 0x20) == 0) {
      sVar1 = 300;
    }
    else {
      sVar1 = 0xf0;
    }
    *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfcff | 0x100;
  }
  if (iVar5 == 0x109) {
    if ((_DAT_800e10ec & 0x20) == 0) {
      sVar1 = 400;
    }
    else {
      sVar1 = 0x136;
    }
    *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfcff | 0x100;
  }
  if (iVar5 == 0x20d) {
    if ((_DAT_800e10ec & 0x20) == 0) {
      sVar1 = 300;
    }
    else {
      sVar1 = 0xf0;
    }
    *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfcff | 0x100;
  }
  if (iVar5 == 0x20c) {
    if ((_DAT_800e10ec & 0x20) == 0) {
      sVar1 = 400;
    }
    else {
      sVar1 = 0x136;
    }
    *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfcff | 0x200;
  }
  if (iVar5 == 0x602) {
    if ((_DAT_800e10ec & 0x20) == 0) {
      sVar1 = 0x15e;
    }
    else {
      sVar1 = 300;
    }
    *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfcff | 0x200;
  }
  uVar6 = 1;
  _DAT_800e1354 = param_1[0x89];
  iVar5 = -0x7ff20950;
  *param_1 = 1;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *(undefined2 *)((int)param_1 + 0x2ba) = 0;
  *(undefined2 *)(param_1 + 0xae) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  param_1[0xaf] = 0;
  *(undefined1 *)((int)param_1 + 0x2c6) = 0;
  *(undefined1 *)((int)param_1 + 0x2c7) = 0;
  *(undefined1 *)(param_1 + 0xb2) = 0;
  *(undefined1 *)((int)param_1 + 0x2c9) = 0;
  _DAT_800e1358 = param_1[0x8a];
  *(undefined1 *)((int)param_1 + 0x25d) = 9;
  uVar4 = param_1[0x8d];
  param_1[0x95] = 0x800e1130;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined2 *)(uVar4 + 0xe6c) = 0x14;
  *(undefined2 *)(uVar4 + 0xe6e) = 0x14;
  *(undefined2 *)(uVar4 + 0xe70) = 0x230;
  *(undefined2 *)(uVar4 + 0xe72) = 0x138;
  *(undefined2 *)(uVar4 + 0xe68) = 0;
  *(undefined2 *)(uVar4 + 0xe6a) = 0;
  param_1[0x7a] = 0x1000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *puVar7 = *puVar7 | 0x4000;
  param_1[0xa9] = (uint)FUN_80162d6c;
  uVar2 = entry();
  *(undefined4 *)(iVar5 + 0x284) = uVar2;
  *(undefined2 *)(param_1 + 0x4d) = 0xf95c;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x6a4;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  *(undefined2 *)(param_1 + 0x4b) = 700;
  *(undefined2 *)((int)param_1 + 0x136) = 700;
  *(undefined2 *)((int)param_1 + 0x12e) = 700;
  *(undefined2 *)(param_1 + 0x4e) = 700;
  param_1[0xa1] = uVar6;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *param_1 = *param_1 | 0x1c000000;
  func_0x800339dc(param_1 + 0x82,0,0x2ee0226,0,param_1 + 10);
  return;
}
