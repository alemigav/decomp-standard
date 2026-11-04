/* FUN_8016ae0c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016ae0c  body 0x8016ae0c..0x8016b1f3  size 1000 B
 * body sha256 e105ed94fa44cdd6f56f9ba0dbc2b4313e89f5f420b1f833a3d11d8c0f0ad95d
 * provider record sha256 4c1ad8b5277d64f4eee277afb978e707d7780726b0ba5f18b9303ac3d6502cb7
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016ae0c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar3;
  uint uVar1;
  ushort uVar4;
  uint uVar2;
  byte bVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte local_38 [8];
  short local_30;
  short local_2e;
  short local_2c;
  
  local_38[0] = 1;
  local_38[1] = 2;
  bVar5 = *(byte *)(param_1 + 6);
  if (bVar5 != 1) {
    if (1 < bVar5) {
      if (bVar5 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x7000000;
        return;
      }
      return;
    }
    if (bVar5 != 0) {
      return;
    }
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    uVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    *(undefined2 *)(param_1 + 500) = uVar3;
    uVar1 = func_0x80033604();
    iVar10 = (uVar1 & 3) + 1;
    if (*(char *)(param_1 + 5) == '\f') {
      cVar6 = *(char *)(*(int *)(param_1 + 0x29c) + 0x131);
      *(char *)(param_1 + 0x206) = cVar6;
      func_0x80037780(0x17d0,(int)*(short *)(param_1 + 500),
                      *(int *)(param_1 + 0x234) + cVar6 * 0x178 + 0x38,0);
    }
    else {
      iVar9 = *(int *)(param_1 + 0x234);
      local_30 = 0;
      local_2e = 0xfed4;
      local_2c = 0;
      iVar8 = iVar9 + 0x38;
      func_0x80037780(0x1fa0,(int)*(short *)(param_1 + 500),iVar8,&local_30);
      local_30 = 0;
      local_2e = -100;
      local_2c = 0;
      func_0x80037780(0x17d0,(int)*(short *)(param_1 + 500),iVar8,&local_30);
      do {
        iVar10 = iVar10 + -1;
        uVar4 = func_0x80033604();
        local_30 = (uVar4 & 0xff) * -2 + 0x100;
        uVar4 = func_0x80033604();
        local_2e = (uVar4 & 0xff) * -2 + 0x38;
        uVar4 = func_0x80033604();
        local_2c = (uVar4 & 0xff) * -2 + 0x100;
        uVar1 = func_0x80033604();
        uVar2 = func_0x80033604();
        func_0x80037780((uVar1 & 0xff) * 4 + 0x600 | 0x9020000,
                        (int)(((uint)*(ushort *)(param_1 + 500) - ((uVar2 & 0xff) * 4 + -0x200)) *
                             0x10000) >> 0x10,iVar9 + 0x38,&local_30);
      } while (iVar10 != 0);
    }
    bVar5 = func_0x80033144(param_1,&DAT_800e1130);
    *(byte *)(param_1 + 0x206) = ~bVar5 & 1;
    uVar4 = *(ushort *)(param_1 + 0x2b6) & 0xfffb;
    *(ushort *)(param_1 + 0x2b6) = uVar4;
    if (*(char *)(param_1 + 0x206) != '\0') {
      *(ushort *)(param_1 + 0x2b6) = uVar4 | 4;
    }
    bVar5 = local_38[*(char *)(param_1 + 0x206)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar5 * 0x1000000 + 0xf0f00;
    uVar1 = func_0x80033604();
    uVar7 = 0xb;
    if ((uVar1 & 1) != 0) {
      uVar7 = 0xd;
    }
    func_0x80077d18(uVar7,param_1);
    func_0x80035b84(param_1);
    *(undefined2 *)(param_1 + 0x1e0) = 400;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
  }
  if (*(char *)(param_1 + 5) != '\f') {
    bVar5 = *(byte *)(param_1 + 0x1e9);
    iVar10 = *(char *)(param_1 + 0x206) * 10;
    if (((iVar10 + 4 <= (int)(uint)bVar5) && ((int)(uint)bVar5 <= iVar10 + 0x10)) &&
       ((bVar5 & 1) != 0)) {
      iVar10 = *(int *)(param_1 + 0x234);
      local_30 = *(short *)(iVar10 + 0xbde);
      local_2e = *(short *)(iVar10 + 0xbe2) + 500;
      local_2c = *(short *)(iVar10 + 0xbe6);
      iVar10 = *(int *)(param_1 + 0x234);
      uVar1 = func_0x80033604(param_1);
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0xfd0,(uVar2 & 0xff) << 4,iVar10 + 0x38,&local_30);
    }
  }
  cVar6 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6;
  func_0x80032b5c(param_1,(int)*(char *)(param_1 + 0x206) << 0xb);
  uVar4 = *(short *)(param_1 + 0x1e0) - 0x32;
  *(ushort *)(param_1 + 0x1e0) = uVar4;
  if ((int)((uint)uVar4 << 0x10) < 0) {
    *(undefined2 *)(param_1 + 0x1e0) = 0;
  }
  if (*(short *)(param_1 + 0x1e0) == 0) {
    func_0x80033680(param_1,0,1);
  }
  return;
}
