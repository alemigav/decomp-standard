/* FUN_80167990
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80167990  body 0x80167990..0x80167e23  size 1172 B
 * body sha256 08ee1e9f03d5dcb285b1500d0645a80c424fd6da684a157a774550d03eebbef5
 * provider record sha256 054b61865a8ce7d8cbfa3efe8ad3985e5ceded37931c7c8aa822559f3cc2074d
 * callees 17 direct (17 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167990(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char cVar5;
  uint uVar4;
  undefined4 uVar6;
  short sVar7;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined1 auStack_38 [32];
  
  bVar1 = *(byte *)(param_1 + 6);
  *(undefined2 *)(param_1 + 0x1f2) = 0;
  if (bVar1 == 1) goto LAB_80167ae8;
  if (1 < bVar1) {
    if (bVar1 == 2) {
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80032b5c(param_1,0);
      iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
      if (iVar3 == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x1e8) = 0x4210300;
      *(undefined1 *)(param_1 + 6) = 3;
      func_0x800334c8(param_1,param_2,param_3,0);
      uVar6 = 3;
      *(undefined1 *)(param_1 + 0x207) = 0;
    }
    else {
      if (bVar1 != 3) {
        return;
      }
      func_0x800334c8(param_1,param_2,param_3,0);
      iVar3 = func_0x80089d54(param_1,param_2,param_3,0x400);
      if (iVar3 != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1090000;
      }
      func_0x80032b5c(param_1,0);
      if ((*(char *)(param_1 + 0x1e9) == '.') && (*(char *)(param_1 + 0x207) == '\0')) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x8000300;
        *(undefined1 *)(param_1 + 0x207) = 1;
      }
      if ((**(uint **)(param_1 + 0x214) & 0x30000) == 0) {
        return;
      }
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
      if ((*(char *)(param_1 + 0x207) != '\0') &&
         (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400), iVar3 != 0)) {
        *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x80;
      }
      local_48 = 500;
      local_46 = 0x183;
      local_44 = 0;
      local_40 = 0x44c;
      local_3e = 0x183;
      local_3c = 0;
      FUN_80168cb4(param_1,auStack_38);
      bVar2 = false;
      iVar3 = func_0x8003307c(auStack_38,&DAT_800e1158,900,&local_48);
      if (iVar3 == 0) {
        iVar3 = func_0x8003307c(auStack_38,&DAT_800e1158,900,&local_40);
        if (iVar3 != 0) {
          bVar2 = true;
        }
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        return;
      }
      if (DAT_800e139f != 0) {
        return;
      }
      iVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                              (int)_DAT_800e115a,(int)_DAT_800e1162);
      sVar7 = (short)(iVar3 + -0x400);
      uVar4 = (uint)((((int)_DAT_800e1196 - ((iVar3 + -0x400) * 0x10000 >> 0x10)) + 0x400U & 0xfff)
                    < 0x800);
      if (*(char *)(param_1 + 0x207) != '\0') {
        uVar4 = uVar4 ^ 1;
        sVar7 = (short)iVar3 + -0xc00;
      }
      func_0x80059e00(0x1e,1);
      _DAT_800e1134 = (uVar4 + 4) * 0x10000 + 0x2000000;
      if (uVar4 == 0) {
        _DAT_800e1196 = sVar7 + 0x800;
      }
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      uVar6 = 6;
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1380 = param_1;
    }
    func_0x80077d18(uVar6,param_1);
    return;
  }
  if (bVar1 != 0) {
    return;
  }
  uVar4 = func_0x80033144(param_1,0x800e1130);
  *(uint *)(param_1 + 0x1e8) = (10 - (uVar4 & 0xff)) * 0x1000000 + 0x300;
  *(undefined1 *)(param_1 + 700) = 2;
  *(undefined1 *)(param_1 + 6) = 1;
  *(undefined1 *)(param_1 + 0x2bd) = 0;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x11;
  func_0x80035b84(param_1);
  if (*(byte *)(param_1 + 0x26e) < 3) {
    cVar5 = *(char *)(param_1 + 5);
    if (cVar5 == '\t') {
      FUN_801669dc(param_1);
      cVar5 = *(char *)(param_1 + 5);
    }
    if (cVar5 == '\x11') {
      FUN_80166b14(param_1);
    }
    if (*(char *)(param_1 + 5) == '\n') {
      FUN_8016676c(param_1);
    }
    cVar5 = *(char *)(param_1 + 5);
    if (cVar5 == '\v') {
      FUN_8016684c(param_1);
      goto LAB_80167ab8;
    }
  }
  else {
LAB_80167ab8:
    cVar5 = *(char *)(param_1 + 5);
  }
  if (cVar5 == '\x0e') {
    FUN_80166ca4(param_1);
  }
  if (*(byte *)(param_1 + 5) - 5 < 2) {
    *(undefined1 *)(param_1 + 0x2c3) = 1;
  }
LAB_80167ae8:
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar3 != 0) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x11000700;
    *(undefined1 *)(param_1 + 6) = 2;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  func_0x80032b5c(param_1,0);
  return;
}
