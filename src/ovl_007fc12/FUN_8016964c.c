/* FUN_8016964c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016964c  body 0x8016964c..0x801699d3  size 904 B
 * body sha256 40bb7251f1753d426f85bef6908a34dffd62e0e903810de20501a2a489613f27
 * provider record sha256 280d822964e373e5d84270c8be188d00f41e72f62ba17435c6d801094f935f8f
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016964c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  undefined2 uVar7;
  ushort uVar8;
  uint uVar4;
  char cVar9;
  uint uVar5;
  int iVar6;
  short local_28;
  short local_26;
  short local_24;
  byte local_20 [8];
  
  local_20[0] = 0x1d;
  local_20[1] = 0x1c;
  local_20[2] = 0x1e;
  local_20[3] = 0x1c;
  local_20[4] = 0x1c;
  local_20[5] = 0x1d;
  local_20[6] = 0x1c;
  local_20[7] = 0x1e;
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      uVar5 = func_0x80033604();
      if ((uVar5 & 1) != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1020000;
      }
      bVar3 = false;
      iVar6 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
      if (((iVar6 == 0) && (*(uint *)(param_1 + 0x28c) < 5000)) && ((DAT_800e139f & 0x80) == 0)) {
        uVar5 = func_0x80033604();
        bVar3 = (uVar5 & 7) == 0;
      }
      if (bVar3) {
        *(undefined4 *)(param_1 + 4) = 0x10b0000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    uVar5 = func_0x80033604();
    bVar1 = local_20[uVar5 & 7];
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x700;
    uVar7 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    *(undefined2 *)(param_1 + 500) = uVar7;
    if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
      iVar6 = *(int *)(param_1 + 0x234);
      uVar8 = func_0x80033604();
      local_28 = 0x7f - (uVar8 & 0xff);
      uVar8 = func_0x80033604();
      local_26 = 0x39f - (uVar8 & 0xff);
      uVar8 = func_0x80033604();
      local_24 = 0x7f - (uVar8 & 0xff);
      uVar5 = func_0x80033604();
      uVar4 = func_0x80033604();
      uVar5 = (uVar5 & 1) << 0x10 | (uVar4 & 0xff) * 8 + 0x17d0;
      sVar2 = *(short *)(param_1 + 500);
      iVar6 = iVar6 + 0x1b0;
    }
    else {
      iVar6 = *(int *)(param_1 + 0x234);
      uVar8 = func_0x80033604();
      local_28 = (uVar8 & 0xff) * -2 + 0x100;
      uVar8 = func_0x80033604();
      local_26 = (uVar8 & 0xff) * -4 + 0x138;
      uVar8 = func_0x80033604();
      local_24 = (uVar8 & 0xff) * -2 + 0x100;
      uVar5 = func_0x80033604();
      uVar4 = func_0x80033604();
      uVar5 = (uVar5 & 1) << 0x10 | (uVar4 & 0xff) * 8 + 7000;
      sVar2 = *(short *)(param_1 + 500);
      iVar6 = iVar6 + 0x38;
    }
    func_0x80037780(uVar5,(int)sVar2,iVar6,&local_28);
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      func_0x80077d18(0xc,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    uVar7 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    *(undefined2 *)(param_1 + 500) = uVar7;
    uVar8 = func_0x80033604();
    *(ushort *)(param_1 + 0x1e0) = (uVar8 & 0x3f) + 0x14;
    uVar8 = func_0x80033604();
    *(ushort *)(param_1 + 0x1e4) = 0x40 - (uVar8 & 0x7f);
    func_0x80032b5c(param_1,((int)*(short *)(param_1 + 500) - (int)*(short *)(param_1 + 0x66)) +
                            0x800);
    uVar8 = func_0x80033604();
    *(ushort *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) - ((uVar8 & 0x7f) - 0x40);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
  }
  cVar9 = func_0x80089d54(param_1,param_2,param_3,0x200);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar9;
  return;
}
