/* FUN_80163544
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80163544  body 0x80163544..0x801637a7  size 612 B
 * body sha256 6553798064eefa2a1832d521fe4a32f82f20f958df551d6e3d35d7591f849ee3
 * provider record sha256 98da8e826c62dc70f0b439c23a79f2c7ec07b0e325b2d7972a3ff1709624a164
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163544(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
    if ((*(ushort *)(param_1 + 0x2b8) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x20a0f00;
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b6) = 0xf;
  }
  func_0x80032b5c(param_1,0);
  if ((**(uint **)(param_1 + 0x214) & 0x30000) != 0) {
    bVar1 = false;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    local_28 = 500;
    local_26 = 0x183;
    local_24 = 0;
    local_20 = 1000;
    local_1e = 0x183;
    local_1c = 0;
    iVar3 = *(int *)(param_1 + 0x234) + 0x908;
    iVar2 = func_0x8003307c(iVar3,&DAT_800e1158,800,&local_28);
    if (iVar2 == 0) {
      iVar2 = func_0x8003307c(iVar3,&DAT_800e1158,800,&local_20);
      if (iVar2 != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_800e139f == 0)) {
      func_0x80059e00(0x14,1);
      DAT_800e1318 = 5;
      DAT_800e1319 = 5;
      DAT_800e131a = 3;
      _DAT_800e1310 = 0x96;
      _DAT_800e1312 = 0;
      _DAT_800e1314 = 0;
      DAT_800e138c = DAT_800e138c | 0x12;
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1134 = 0x2050100;
      _DAT_800e1380 = param_1;
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xfffe;
      func_0x80077d18(6);
      func_0x80052bd0(2,0);
      func_0x80052c6c(6,0xfa,0);
    }
  }
  return;
}
