/* FUN_80166e9c
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80166e9c  body 0x80166e9c..0x801677c7  size 2348 B
 * body sha256 be10673405743922331de6fc76ac8e40870adcff2830e7e58555deb7eb855544
 * provider record sha256 4c88b5b545bf4bb5b14f67004bd8d3ffbb1cc162953b6532060ba01d89881c59
 * callees 14 direct (14 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166e9c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  byte bVar5;
  char cVar6;
  uint *puVar7;
  short sVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 *puVar13;
  short local_30 [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = 0x1f0028;
  local_24 = 0x16ffec;
  local_20 = 0xffe2000a;
  local_1c = 0x160000;
  uVar11 = param_1[0x82];
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    func_0x80035b84(param_1);
    param_1[0x7a] = 0x7003f00;
    if ((*(ushort *)((int)param_1 + 0x2ba) & 0x200) != 0) {
      *(undefined1 *)((int)param_1 + 0x1e9) = 0x32;
      func_0x800334c8(param_1,param_2,param_3,0);
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    if ((*(ushort *)((int)param_1 + 0x2ba) & 2) != 0) {
      *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) & 0xfffd;
      *(undefined1 *)((int)param_1 + 0x207) = 1;
    }
    cVar6 = *(char *)((int)param_1 + 5);
    if (cVar6 == '\t') {
      FUN_80164f00(param_1);
      cVar6 = *(char *)((int)param_1 + 5);
    }
    if (cVar6 == '\x11') {
      FUN_80165038(param_1);
    }
    cVar6 = *(char *)((int)param_1 + 5);
    if (cVar6 == '\n') {
      FUN_80164d40(param_1);
      cVar6 = *(char *)((int)param_1 + 5);
    }
    if (cVar6 == '\v') {
      FUN_80164e20(param_1);
    }
    if (*(char *)((int)param_1 + 5) == '\x0e') {
      FUN_8016524c(param_1,1);
    }
    if ((*(byte *)((int)param_1 + 5) - 5 < 2) && (*(char *)((int)param_1 + 0x2bf) == '\0')) {
      *(undefined1 *)((int)param_1 + 0x2bf) = 1;
    }
    if (*(char *)((int)param_1 + 5) == '\x10') {
      FUN_80164d40(param_1);
    }
    *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) | 0x4000;
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar9 = func_0x8008a994(param_1,param_2,param_3,0x40);
    if (iVar9 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      param_1[0x7a] = 0xe003f00;
      *(undefined2 *)(param_1 + 0x7d) = 0;
      bVar5 = func_0x80033604();
      iVar9 = 0x17;
      iVar3 = 0;
      puVar12 = (uint *)param_1[0x8d];
      *(byte *)((int)param_1 + 0x206) = (bVar5 & 0x1f) + 8;
      puVar7 = puVar12 + 0x4a;
      do {
        if ((*(char *)((int)param_1 + 0x207) == '\0') || (3 < iVar3 - 9U)) {
          *puVar12 = *puVar12 | 0x2000;
          *(undefined2 *)(puVar7 + -1) = 0x1000;
          *(undefined2 *)((int)puVar7 + -2) = 0x1000;
          *(undefined2 *)puVar7 = 0x1000;
        }
        iVar3 = iVar3 + 1;
        puVar7 = puVar7 + 0x5e;
        iVar9 = iVar9 + -1;
        puVar12 = puVar12 + 0x5e;
      } while (iVar9 != 0);
      *(uint *)(param_1[0x8d] + 0x178) = *(uint *)(param_1[0x8d] + 0x178) & 0xffffdfff;
      *(undefined1 *)((int)param_1 + 0x207) = 0xff;
      func_0x80077d18(0xc,param_1);
    }
    func_0x80032b5c(param_1,0);
    if ((*(byte *)((int)param_1 + 0x1e9) & 0xf) == 0) {
      bVar5 = func_0x80033604();
      DAT_80167fca = '\x03' - bVar5 % 6;
      bVar5 = func_0x80033604();
      DAT_80167fcb = '\x0f' - bVar5 % 0x1e;
    }
    if (*(char *)((int)param_1 + 0x1e9) == '1') {
      func_0x80052c6c(8,0x96,5);
    }
    break;
  case 2:
    func_0x8008a994(param_1,param_2,param_3,0x40);
    if (300 < *(ushort *)((int)param_1 + 0x136)) {
      *(ushort *)((int)param_1 + 0x136) = *(ushort *)((int)param_1 + 0x136) - 6;
      *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + -6;
      *(short *)((int)param_1 + 0x12e) = *(short *)((int)param_1 + 0x12e) + -6;
      *(short *)(param_1 + 0x4b) = *(short *)(param_1 + 0x4b) + -6;
      *(short *)(param_1 + 0x56) = *(short *)(param_1 + 0x56) + -3;
      *(short *)((int)param_1 + 0x156) = *(short *)((int)param_1 + 0x156) + -3;
      *(short *)((int)param_1 + 0x14e) = *(short *)((int)param_1 + 0x14e) + -3;
      *(short *)(param_1 + 0x53) = *(short *)(param_1 + 0x53) + -3;
      *(short *)(param_1 + 0x5e) = *(short *)(param_1 + 0x5e) + -3;
      *(short *)((int)param_1 + 0x176) = *(short *)((int)param_1 + 0x176) + -3;
      *(short *)((int)param_1 + 0x16e) = *(short *)((int)param_1 + 0x16e) + -3;
      *(short *)(param_1 + 0x5b) = *(short *)(param_1 + 0x5b) + -3;
    }
    sVar8 = *(short *)(param_1 + 0x7d);
    if (sVar8 == 0x3c) {
      param_1[0x7a] = 0xf003f00;
      sVar8 = *(short *)(param_1 + 0x7d);
    }
    if (sVar8 == 0x78) {
      param_1[0x7a] = 0x10003f00;
    }
    if (0x14 < *(short *)(param_1[0x8d] + 0x126)) {
      iVar9 = 0x17;
      psVar10 = (short *)(param_1[0x8d] + 0x128);
      do {
        iVar9 = iVar9 + -1;
        if (0x14 < psVar10[-1]) {
          psVar10[-1] = psVar10[-1] + -7;
          psVar10[-2] = psVar10[-2] + -4;
          *psVar10 = *psVar10 + -4;
        }
        psVar10 = psVar10 + 0xbc;
      } while (iVar9 != 0);
    }
    uVar1 = param_1[0x8d];
    *(short *)(*(int *)(uVar1 + 0x298) + 0x10) = *(short *)(*(int *)(uVar1 + 0x298) + 0x10) + 10;
    if (*(char *)((int)param_1 + 0x206) == '\0') {
      *(undefined1 *)((int)param_1 + 0x207) = 0;
      bVar5 = func_0x80033604();
      cVar6 = (bVar5 & 0x1f) + 0xc;
    }
    else {
      cVar6 = *(char *)((int)param_1 + 0x206) + -1;
    }
    *(char *)((int)param_1 + 0x206) = cVar6;
    if (*(byte *)((int)param_1 + 0x207) != 0xff) {
      *(short *)(*(int *)(uVar1 + 0x298) + 0x10) =
           *(short *)(*(int *)(uVar1 + 0x298) + 0x10) +
           *(short *)((int)&local_28 +
                     ((int)((uint)*(byte *)((int)param_1 + 0x207) << 0x18) >> 0x17)) * -2;
      cVar6 = *(char *)((int)param_1 + 0x207) + '\x01';
      *(char *)((int)param_1 + 0x207) = cVar6;
      if ('\a' < cVar6) {
        *(undefined1 *)((int)param_1 + 0x207) = 0xff;
      }
    }
    if ((*(uint *)(uVar11 + 0x18) & 0xff0000) != 0x100000) {
      *(uint *)(uVar11 + 0x18) = *(uint *)(uVar11 + 0x18) + 0xff0100;
      *(short *)(uVar11 + 4) = *(short *)(uVar11 + 4) + 5;
      *(short *)(uVar11 + 6) = *(short *)(uVar11 + 6) + 5;
    }
    if (0x1000 < *(short *)(*(int *)(uVar1 + 0x298) + 0x10)) {
      *(undefined2 *)(*(int *)(uVar1 + 0x298) + 0x10) = 0x1000;
      *(undefined1 *)((int)param_1 + 6) = 3;
    }
    if (((int)*(short *)(param_1 + 0x7d) % 3 & 0xffffU) == 0) {
      uVar11 = *(uint *)(uVar1 + 0x1d8);
      if ((uVar11 & 0xff) != 0x40) {
        *(uint *)(uVar1 + 0x1d8) = uVar11 - 0x10001;
        uVar11 = *(uint *)(uVar1 + 0x1d8);
      }
      if ((uVar11 & 0xff00) != 0x6000) {
        *(uint *)(uVar1 + 0x1d8) = uVar11 - 0x100;
      }
      uVar11 = *(uint *)(uVar1 + 0x350);
      if ((uVar11 & 0xff) != 0x40) {
        *(uint *)(uVar1 + 0x350) = uVar11 - 0x10001;
        uVar11 = *(uint *)(uVar1 + 0x350);
      }
      if ((uVar11 & 0xff00) != 0x6000) {
        *(uint *)(uVar1 + 0x350) = uVar11 - 0x100;
      }
      uVar11 = *(uint *)(uVar1 + 0x640);
      if ((uVar11 & 0xff) != 0x40) {
        *(uint *)(uVar1 + 0x640) = uVar11 - 0x10001;
        uVar11 = *(uint *)(uVar1 + 0x640);
      }
      if ((uVar11 & 0xff00) != 0x6000) {
        *(uint *)(uVar1 + 0x640) = uVar11 - 0x100;
      }
      uVar4 = func_0x80033604();
      local_30[0] = (uVar4 & 0xff) * -8 + 0x400;
      local_30[1] = 0xff38;
      uVar4 = func_0x80033604();
      local_30[2] = (uVar4 & 0xff) * -8 + 0x400;
      uVar11 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar11 & 0xff) * 8 + 0x830 | 0x90000,(uVar2 & 0xff) << 4,uVar1 + 0x1b0,
                      local_30);
    }
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 1;
    if ((*(byte *)((int)param_1 + 0x1e9) & 7) == 0) {
      bVar5 = func_0x80033604();
      DAT_80167fca = '\x03' - bVar5 % 6;
      bVar5 = func_0x80033604();
      DAT_80167fcb = '\x0f' - bVar5 % 0x1e;
    }
    break;
  case 3:
    iVar9 = 0x17;
    puVar13 = (undefined4 *)param_1[0x8d];
    *param_1 = *param_1 | 2;
    do {
      *puVar13 = 0;
      iVar9 = iVar9 + -1;
      puVar13 = puVar13 + 0x5e;
    } while (iVar9 != 0);
    *(undefined4 *)(param_1[0x8d] + 0x178) = 1;
    iVar9 = 4 - (uint)DAT_800e1126;
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    while (iVar9 = iVar9 + -1, iVar9 * 0x10000 >> 0x10 != -1) {
      iVar3 = func_0x80031ff0(0x27);
      *(uint *)(iVar3 + 0x28) = param_1[10];
      *(uint *)(iVar3 + 0x2c) = param_1[0xb];
      *(uint *)(iVar3 + 0x30) = param_1[0xc];
      uVar4 = func_0x80033604();
      *(ushort *)(iVar3 + 0x66) = (uVar4 & 0xff) << 4;
      *(undefined2 *)(iVar3 + 0x1aa) = 3;
    }
    *(undefined1 *)((int)param_1 + 6) = 4;
    *(undefined2 *)(param_1 + 0x7d) = 500;
    DAT_80167fca = '\0';
    DAT_80167fcb = '\n';
    *(undefined2 *)((int)param_1 + 0x1f6) = *(undefined2 *)(*(int *)(param_1[0x8d] + 0x298) + 0x10);
  case 4:
    uVar11 = param_1[0x8d];
    if (*(char *)((int)param_1 + 0x206) == '\0') {
      *(undefined1 *)((int)param_1 + 0x207) = 0;
      bVar5 = func_0x80033604();
      cVar6 = (bVar5 & 0x3f) + 0x10;
    }
    else {
      cVar6 = *(char *)((int)param_1 + 0x206) + -1;
    }
    *(char *)((int)param_1 + 0x206) = cVar6;
    if (*(byte *)((int)param_1 + 0x207) != 0xff) {
      *(short *)(*(int *)(uVar11 + 0x298) + 0x10) =
           *(short *)((int)param_1 + 0x1f6) +
           *(short *)((int)&local_28 +
                     ((int)((uint)*(byte *)((int)param_1 + 0x207) << 0x18) >> 0x17)) * 3;
      cVar6 = *(char *)((int)param_1 + 0x207) + '\x01';
      *(char *)((int)param_1 + 0x207) = cVar6;
      if ('\a' < cVar6) {
        *(undefined1 *)((int)param_1 + 0x207) = 0xff;
      }
    }
    sVar8 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar8 + -1;
    if ((short)(sVar8 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 5;
      *(ushort *)((int)param_1 + 0x2ba) = *(ushort *)((int)param_1 + 0x2ba) & 0xfeff;
    }
  }
  return;
}
