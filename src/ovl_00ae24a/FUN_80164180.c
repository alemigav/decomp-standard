/* FUN_80164180
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80164180  body 0x80164180..0x8016464b  size 1228 B
 * body sha256 794287f3431d3baf13424d571b12d3ceab27be307753732ae4727ec25fb425cb
 * provider record sha256 f746c76fa2cae7c35597ac1b5ff5e405df0ced12137d63097a5cf3e1d15708df
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164180(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  short sVar5;
  char cVar6;
  int iVar7;
  bool bVar8;
  short local_50;
  undefined2 local_4e;
  short local_4c;
  short local_48;
  undefined2 local_46;
  short local_44;
  undefined1 auStack_40 [32];
  
  if (*(char *)(param_1 + 6) == '\0') {
    local_50 = 0;
    local_4c = 0;
    local_4e = _DAT_800e1196;
    func_0x80040e58(&local_50,auStack_40);
    local_50 = 0x1000;
    local_4e = 0;
    func_0x8004276c(auStack_40,&local_50,&local_50);
    iVar7 = (int)local_50;
    bVar8 = false;
    if (((iVar7 < -0x40) && (*(byte *)(param_1 + 5) != 0x10)) && (3 < *(byte *)(param_1 + 5) - 9)) {
      iVar1 = (int)local_4c * (*(int *)(param_1 + 0x28) - (_DAT_800e1158 + -0xc6f));
      if (iVar7 == 0) {
        trap(0x1c00);
      }
      if ((iVar7 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      local_46 = 0xfa88;
      local_48 = *(short *)(param_1 + 0x2a) + 0xc6f;
      if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) {
        local_4e = 0xfd44;
      }
      if ((uint)*(byte *)(param_1 + 0x26e) % 3 == 2) {
        local_4e = 0xf830;
      }
      iVar7 = iVar1 / iVar7 + (uint)_DAT_800e1162;
      local_44 = (short)iVar7;
      if (-0x5014 < iVar7 * 0x10000 >> 0x10) {
        local_44 = -0x5014;
      }
      if (local_44 < -26000) {
        local_44 = -26000;
      }
      if (*(char *)(param_1 + 5) == '\x01') {
        local_44 = *(short *)(_DAT_800e1364 + 0x107e);
      }
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780((uVar2 & 1) << 0x10 | (uVar3 & 0xff) * 8 + 0x1fa0,0,0x800e9028,&local_48);
      local_48 = local_48 + 500;
      uVar4 = func_0x80033604();
      local_44 = local_44 - ((uVar4 & 0xff) - 0x80);
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780((uVar2 & 1) << 0x10 | (uVar3 & 0xff) * 4 + 0x1fa0,0,0x800e9028,&local_48);
      if ((local_44 < -0x57e4) && (-24000 < local_44)) {
        bVar8 = true;
      }
    }
    sVar5 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)(short)_DAT_800e1162);
    if (bVar8) {
      local_48 = *(short *)(param_1 + 0x142) + 500;
      local_46 = *(undefined2 *)(param_1 + 0x146);
      local_44 = *(short *)(param_1 + 0x14a);
      uVar2 = func_0x80033604();
      func_0x80037780((uVar2 & 0xff) * 8 + 0x1fa0,(int)sVar5,0x800e9028,&local_48);
      local_50 = local_50 + 500;
      uVar2 = func_0x80033604();
      func_0x80037780((uVar2 & 0xff) * 8 + 0x1fa0 | 0x10000,(int)sVar5,0x800e9028,&local_48);
      if (*(char *)(param_1 + 5) != '\x01') {
        func_0x80077d18(8,param_1);
      }
    }
    cVar6 = *(char *)(param_1 + 5);
    if ((cVar6 == '\t') || (cVar6 == '\x11')) {
      FUN_80163ddc(param_1);
      cVar6 = *(char *)(param_1 + 5);
    }
    if (cVar6 == '\n') {
      FUN_80163974(param_1);
    }
    cVar6 = *(char *)(param_1 + 5);
    if (cVar6 == '\v') {
      FUN_80163bbc(param_1);
      cVar6 = *(char *)(param_1 + 5);
    }
    if (cVar6 == '\x0e') {
      FUN_80163e98(param_1);
    }
    if (10 < (byte)(&LAB_80166ff6_1)[*(byte *)(param_1 + 5)]) {
      *(undefined1 *)(param_1 + 0x2c1) = 7;
    }
    if ((*(ushort *)(param_1 + 0x2c2) & 2) == 0) {
      *(char *)(param_1 + 0x2be) =
           *(char *)(param_1 + 0x2be) + (&LAB_80166ff6_1)[*(byte *)(param_1 + 5)];
      if ((*(ushort *)(param_1 + 0x2c2) & 1) == 0) {
        *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) | 1;
        *(undefined1 *)(param_1 + 0x2bd) = 0xf;
      }
      if (*(byte *)(param_1 + 0x2be) < 0xf) {
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
        FUN_801623b0(param_1,param_2,param_3);
        return;
      }
      *(undefined1 *)(param_1 + 0x2be) = 0;
      *(undefined1 *)(param_1 + 0x2bd) = 0;
      *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) & 0xfffe;
    }
    else {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
      if (*(char *)(param_1 + 4) == '\x01') {
        FUN_801623b0(param_1,param_2,param_3);
        return;
      }
    }
  }
  FUN_8016464c(param_1,param_2,param_3);
  return;
}
