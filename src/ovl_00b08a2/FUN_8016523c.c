/* FUN_8016523c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x8016523c  body 0x8016523c..0x80165997  size 1884 B
 * body sha256 51c8621351aebc8f5b42598a4af7cda23eb9151c8bcffba59473964f6a9fe3ed
 * provider record sha256 54dd863568845e0fb3c72557839c28b7f7cc3f0ab9c5d79ba0bd6fb0a8410af1
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016523c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  char cVar5;
  byte bVar6;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  short local_18;
  short local_16;
  short local_14;
  
  puVar9 = (uint *)param_1[0x8d];
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    puVar9 = (uint *)param_1[0x8d];
    param_1[0x7a] = 0;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *puVar9 = *puVar9 | 1;
    *(undefined2 *)(param_1 + 0x1a) = 0;
    *(undefined2 *)((int)param_1 + 0x66) = 0;
    *(undefined2 *)(param_1 + 0x19) = 0;
    *(byte *)(_DAT_800e13f0 + 0x2c4) =
         *(byte *)(_DAT_800e13f0 + 0x2c4) | (byte)(1 << (*(byte *)(param_1 + 0xad) + 4 & 0x1f));
    *param_1 = *param_1 | 2;
    puVar7 = *(uint **)((*(byte *)(param_1 + 0xad) + 7) * 4 + -0x7ff1ec18);
    *puVar7 = *puVar7 | 2;
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar1 = *(short *)(puVar9 + 0x49);
    *(short *)(puVar9 + 0x49) = sVar1 + 0x100;
    if (0x800 < (short)(sVar1 + 0x100)) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      uVar8 = func_0x80033604();
      param_1[0x7a] = ((uVar8 & 3) + 0x11) * 0x1000000 + 0x1f00;
    }
    if ((*(byte *)((int)param_1 + 0x1e9) & 1) == 0) {
      uVar4 = func_0x80033604();
      local_18 = 0x80 - (uVar4 & 0xff);
      uVar4 = func_0x80033604();
      local_16 = 0x80 - (uVar4 & 0xff);
      uVar4 = func_0x80033604();
      local_14 = 0x80 - (uVar4 & 0xff);
      uVar8 = func_0x80033604();
      uVar3 = func_0x80033604();
      uVar8 = ((uVar8 & 1) + 0x10) * 0x10000;
      uVar3 = (uVar3 & 0xff) * 8 + 0x2770;
LAB_801658b8:
      func_0x80037780(uVar8 | uVar3,(int)*(short *)((int)param_1 + 0x66),puVar9 + 0xe,&local_18);
    }
    break;
  case 2:
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x80);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    sVar1 = *(short *)(puVar9 + 0x49);
    *(short *)(puVar9 + 0x49) = sVar1 + 0x100;
    if (0x1000 < (short)(sVar1 + 0x100)) {
      *(undefined1 *)((int)param_1 + 6) = 3;
      uVar8 = func_0x80033604();
      param_1[0x7a] = ((uVar8 & 1) + 0x11) * 0x1000000 + 0x1f00;
      *(undefined1 *)((int)param_1 + 0x2b5) = 1;
      uVar4 = func_0x80033604();
      *(ushort *)(param_1 + 0x7d) = (uVar4 & 0x1f) + 100;
      *(undefined2 *)((int)param_1 + 0x1f6) = 0;
      *(undefined1 *)((int)param_1 + 0x206) = 3;
    }
    if ((*(byte *)((int)param_1 + 0x1e9) & 3) != 0) {
      return;
    }
    uVar4 = func_0x80033604();
    local_18 = 0x80 - (uVar4 & 0xff);
    uVar4 = func_0x80033604();
    local_16 = 0x80 - (uVar4 & 0xff);
    uVar4 = func_0x80033604();
    local_14 = 0x80 - (uVar4 & 0xff);
    uVar8 = func_0x80033604();
    uVar3 = func_0x80033604();
    uVar8 = (uVar8 & 1) + 0x10;
    goto LAB_801658a8;
  case 3:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar2 != 0) {
      uVar8 = func_0x80033604();
      param_1[0x7a] = ((uVar8 & 1) + 0x11) * 0x1000000 + 0x1f00;
    }
    sVar1 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar1 + -1;
    if ((short)(sVar1 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 4;
      uVar8 = func_0x80033604();
      param_1[0x7a] = ((uVar8 & 1) + 0x13) * 0x1000000 + 0x3f00;
      *(undefined1 *)((int)param_1 + 0x206) = 3;
    }
    bVar6 = *(byte *)((int)param_1 + 0x1e9) & 7;
    goto LAB_8016585c;
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    uVar4 = *(ushort *)(param_1 + 0x7d);
    param_1[0xb] = param_1[0xb] + (int)*(short *)(param_1 + 0x7d);
    iVar2 = uVar4 + 2;
    *(short *)(param_1 + 0x7d) = (short)iVar2;
    if (iVar2 * 0x10000 >> 0x10 < 0x3d) {
      if ((*(byte *)((int)param_1 + 0x1e9) & 1) == 0) {
        uVar8 = func_0x80033604();
        uVar3 = func_0x80033604();
        func_0x80037780((uVar8 & 1) << 0x10 | (uVar3 & 0xff) * 8 + 0x1fa0,
                        (int)*(short *)((int)param_1 + 0x66),puVar9 + 0xe,0);
      }
      if ((*(byte *)((int)param_1 + 0x1e9) & 7) == 0) {
        uVar4 = func_0x80033604();
        local_18 = 0x80 - (uVar4 & 0xff);
        uVar4 = func_0x80033604();
        local_16 = 0x80 - (uVar4 & 0xff);
        uVar4 = func_0x80033604();
        local_14 = 0x80 - (uVar4 & 0xff);
        uVar8 = func_0x80033604();
        uVar3 = func_0x80033604();
        func_0x80037780(((uVar8 & 1) + 0x10) * 0x10000 | (uVar3 & 0xff) * 8 + 0x1fa0,
                        (int)*(short *)((int)param_1 + 0x66),puVar9 + 0xe,&local_18);
      }
    }
    else {
      *(ushort *)(param_1 + 0x7d) = uVar4 + 0x20;
    }
    if (-0x32 < (int)param_1[0xb]) {
      param_1[0xb] = param_1[0xb] - (int)*(short *)(param_1 + 0x7d);
      *(short *)(param_1 + 0x7d) = (short)(*(short *)(param_1 + 0x7d) * -0x10000 >> 0x14);
      cVar5 = *(char *)((int)param_1 + 0x206) + -1;
      *(char *)((int)param_1 + 0x206) = cVar5;
      if (cVar5 == -1) {
        *(undefined1 *)((int)param_1 + 6) = 5;
        *(undefined2 *)(param_1 + 0x7d) = 0x96;
      }
      uVar8 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780((uVar8 & 1) << 0x10 | (uVar3 & 0xff) * 8 + 0x1fa0,
                      (int)*(short *)((int)param_1 + 0x66),puVar9 + 0xe,0);
      uVar8 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780((uVar8 & 1) << 0x10 | (uVar3 & 0xff) * 8 + 0x1fa0,
                      (int)*(short *)((int)param_1 + 0x66),puVar9 + 0x6c,0);
      uVar8 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780((uVar8 & 1) << 0x10 | (uVar3 & 0xff) * 8 + 0x1fa0,
                      (int)*(short *)((int)param_1 + 0x66),puVar9 + 0xca,0);
      func_0x80077d18(1,param_1);
      func_0x80052bd0(3,0);
      func_0x80052c6c(10,0xfa,0);
    }
    break;
  case 5:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
    if (iVar2 != 0) {
      uVar8 = func_0x80033604();
      param_1[0x7a] = ((uVar8 & 1) + 0x13) * 0x1000000 + 0x3f00;
    }
    sVar1 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar1 + -1;
    if ((short)(sVar1 + -1) == -1) {
      uVar8 = func_0x80033604();
      uVar3 = func_0x80033604();
      iVar2 = (uVar8 & 0xff) + (uVar3 & 0xff);
      *(undefined1 *)((int)param_1 + 6) = 6;
      param_1[0x7a] = (iVar2 + (int)((ulonglong)(longlong)iVar2 / 3) * -3 + 9) * 0x1000000 + 0x7f00;
    }
    if ((param_1[0x7d] & 0x30000) == 0) {
      puVar9[0x18] = puVar9[0x18] - 0x10101;
      uVar8 = func_0x800844e4();
      puVar9[0x33] = uVar8 | 0xff;
    }
    bVar6 = *(byte *)((int)param_1 + 0x1e9) & 1;
LAB_8016585c:
    if (bVar6 != 0) {
      return;
    }
    uVar4 = func_0x80033604();
    local_18 = 0x80 - (uVar4 & 0xff);
    uVar4 = func_0x80033604();
    local_16 = 0x80 - (uVar4 & 0xff);
    uVar4 = func_0x80033604();
    local_14 = 0x80 - (uVar4 & 0xff);
    uVar8 = func_0x80033604();
    uVar3 = func_0x80033604();
    uVar8 = uVar8 & 1;
LAB_801658a8:
    uVar8 = uVar8 << 0x10;
    uVar3 = (uVar3 & 0xff) * 8 + 0x1fa0;
    goto LAB_801658b8;
  case 6:
    func_0x80089d54(param_1,param_2,param_3,0x20);
    *(short *)(puVar9 + 0x49) = *(short *)(puVar9 + 0x49) + -6;
    *(short *)((int)puVar9 + 0x126) = *(short *)((int)puVar9 + 0x126) + -0x20;
    *(short *)(puVar9 + 0x4a) = *(short *)(puVar9 + 0x4a) + 0x10;
    if ((puVar9[0x18] & 0xff) != 0x20) {
      puVar9[0x18] = puVar9[0x18] - 1;
    }
    if ((puVar9[0x18] & 0xff00) != 0) {
      puVar9[0x18] = puVar9[0x18] - 0x100;
    }
    uVar8 = puVar9[0x18];
    if ((uVar8 & 0xff0000) != 0x300000) {
      puVar9[0x18] = uVar8 - 0x10000;
      uVar8 = puVar9[0x18];
    }
    uVar8 = func_0x800844e4(uVar8);
    puVar9[0x33] = uVar8 | 0xff;
    if (*(char *)((int)param_1 + 0x1ea) == '@') {
      *(undefined1 *)((int)param_1 + 6) = 7;
    }
  }
  return;
}
