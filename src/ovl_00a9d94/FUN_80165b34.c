/* FUN_80165b34
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80165b34  body 0x80165b34..0x801660c3  size 1424 B
 * body sha256 08e7bb3133d64e92e1d92da15fb13669603209bfa7b8858feb681353ecd9d2a6
 * provider record sha256 e9ecc7b88c2395afd92f80789c4385cf0e6d9bca1cba0b2fd1c9fb61e50f6234
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165b34(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar6;
  short sVar4;
  ushort uVar5;
  int iVar3;
  byte bVar8;
  int iVar7;
  undefined4 uVar9;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x13000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x2c0) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 4;
    func_0x80052c6c(8,0x50,0xf);
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x100);
    if (*(char *)(param_1 + 0x1e9) != '\x12') {
      return;
    }
    break;
  case 2:
    cVar6 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6;
  case 3:
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
    sVar4 = *(short *)(param_1 + 0x2c0);
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x2c0) = sVar4 + 2;
    *(short *)(param_1 + 0x1e2) = (*(short *)(param_1 + 0x1e2) + 0x8c) - sVar4;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
    func_0x8004dcb8(param_1,0x400);
    iVar3 = (int)*(short *)(param_1 + 0x25e);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (int)*(short *)(param_1 + 0x1e4);
    if (iVar3 < *(int *)(param_1 + 0x2c)) {
      *(undefined1 *)(param_1 + 6) = 4;
      *(int *)(param_1 + 0x2c) = iVar3;
      *(undefined4 *)(param_1 + 0x1e8) = 0x14060800;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xff7b;
      uVar9 = 4;
      if (iVar3 == 0) {
        uVar9 = 3;
      }
      func_0x80077d18(uVar9,param_1);
      func_0x80052c6c(8,100,0);
    }
    local_20 = *(undefined4 *)(param_1 + 0x120);
    local_1c = *(undefined4 *)(param_1 + 0x124);
    local_18 = *(undefined4 *)(param_1 + 0x128);
    sVar4 = func_0x80069f1c(&local_20,0x578,0x400,0);
    if (_DAT_8011270c != 0) {
      sVar4 = _DAT_80112712;
    }
    if (sVar4 == 0) {
      *(undefined1 *)(param_1 + 0x1a2) = 0;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xffdf;
    }
    if (-0xe10 < *(int *)(param_1 + 0x2c)) {
      *(undefined1 *)(param_1 + 0x1a2) = 0;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xffdf;
    }
    goto LAB_8016608c;
  case 4:
    uVar5 = *(short *)(param_1 + 0x1e0) + *(short *)(param_1 + 500);
    *(ushort *)(param_1 + 0x1e0) = uVar5;
    if ((uVar5 & 0x8000) == (*(ushort *)(param_1 + 500) & 0x8000)) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    uVar5 = *(short *)(param_1 + 0x1e4) + *(short *)(param_1 + 0x1f6);
    *(ushort *)(param_1 + 0x1e4) = uVar5;
    if ((uVar5 & 0x8000) == (*(ushort *)(param_1 + 0x1f6) & 0x8000)) {
      *(undefined2 *)(param_1 + 0x1e4) = 0;
    }
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1030000;
      *(undefined1 *)(param_1 + 0x2cf) = 0x3c;
      *(undefined1 *)(param_1 + 0x2ba) = 0;
      if (*(char *)(param_1 + 0x2c2) == '\x05') {
        *(undefined4 *)(param_1 + 4) = 0x1040000;
      }
    }
LAB_8016608c:
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
    return;
  default:
    goto switchD_80165b74_default;
  }
  func_0x80077d18(2,param_1);
  *(undefined1 *)(param_1 + 6) = 2;
  local_28 = 0x226;
  local_26 = 0xfe70;
  local_24 = 0;
  sVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  switch(*(undefined1 *)(param_1 + 0x2c2)) {
  case 1:
    uVar2 = func_0x80033604();
    uVar1 = func_0x80033604();
    sVar4 = sVar4 + 0x200;
    goto LAB_80165cb0;
  case 2:
    uVar2 = func_0x80033604();
    uVar1 = func_0x80033604();
    sVar4 = sVar4 + 0x400 + ((ushort)((int)(uVar2 & 0xff) >> (uVar1 & 3)) & 1) * -0x800;
    break;
  case 3:
    uVar2 = func_0x80033604();
    uVar1 = func_0x80033604();
    sVar4 = sVar4 + 0xa00;
LAB_80165cb0:
    sVar4 = sVar4 + ((ushort)((int)(uVar2 & 0xff) >> (uVar1 & 3)) & 1) * -0x400;
    break;
  case 4:
    sVar4 = sVar4 + 0x800;
    break;
  case 5:
    uVar2 = func_0x80033604();
    bVar8 = DAT_8016c318 + (char)((uVar2 & 0xff) % 3) + '\x03' & 7;
    *(byte *)(param_1 + 0x207) = bVar8;
    if (7 < DAT_8016c318) {
      *(byte *)(param_1 + 0x207) = bVar8 + 8;
    }
    iVar7 = *(char *)(param_1 + 0x207) * 4;
    iVar3 = *(int *)(param_1 + 0x28) - (int)*(short *)(&DAT_8016c2d8 + iVar7);
    iVar7 = *(int *)(param_1 + 0x30) - (int)*(short *)(&DAT_8016c2da + iVar7);
    uVar2 = func_0x80040bb4(iVar3 * iVar3 + iVar7 * iVar7);
    local_26 = 0xfda8;
    local_28 = (undefined2)(uVar2 / 5);
    iVar3 = *(char *)(param_1 + 0x207) * 4;
    sVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)*(short *)(&DAT_8016c2d8 + iVar3),
                            (int)*(short *)(&DAT_8016c2da + iVar3));
  }
  FUN_8016b9c8(param_1,(int)sVar4,&local_28);
  *(short *)(param_1 + 500) =
       -(short)((uint)(((int)*(short *)(param_1 + 0x1e0) / 5) * 0x10000) >> 0x10);
  *(short *)(param_1 + 0x1f6) =
       -(short)((uint)(((int)*(short *)(param_1 + 0x1e4) / 5) * 0x10000) >> 0x10);
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x80);
  *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x80;
switchD_80165b74_default:
  return;
}
