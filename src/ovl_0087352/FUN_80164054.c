/* FUN_80164054
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164054  body 0x80164054..0x8016448f  size 1084 B
 * body sha256 cda1a48e0907e88e1eb459d50f6f5293ed1ed8b5bf53a385b263f5ad02b836fd
 * provider record sha256 c83b47df8358de4493ad04ca03f5ae108b45330e8cb6f22e2f6ab4e9d1fd57a5
 * callees 15 direct (15 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164054(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar4;
  int iVar2;
  short sVar3;
  byte bVar5;
  undefined1 uVar6;
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  
  if (_DAT_800e1322 < 1) {
    *(undefined1 *)(param_1 + 0x2b4) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x2b4) = 1;
  }
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    if (-1 < _DAT_800e1322) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 100) = 0;
      *(undefined2 *)(param_1 + 0x68) = 0;
      if ((*(ushort *)(param_1 + 0x2c6) & 4) != 0) {
        FUN_8016608c(8);
        FUN_8016608c(0x40);
        FUN_80165c58(0x800e1130,5,0);
        _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
        _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
        _DAT_800e1380 = param_1;
      }
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x2c0);
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x800);
      *(undefined4 *)(param_1 + 0x1e8) = 0x5000700;
      *(undefined1 *)(param_1 + 0x2b5) = 100;
      *(undefined2 *)(param_1 + 0x1e0) = 300;
      *(undefined1 *)(param_1 + 0x2b6) = 0;
      *(undefined1 *)(param_1 + 6) = 1;
      goto switchD_801640c4_caseD_1;
    }
    break;
  case 1:
switchD_801640c4_caseD_1:
    if ((*(ushort *)(param_1 + 0x2c6) & 4) == 0) {
      uVar1 = func_0x80033604(6);
      if ((uVar1 & 7) == 0) {
        FUN_801661d8(param_1,1);
      }
LAB_8016426c:
      *(undefined1 *)(param_1 + 0x2b7) = 4;
      *(undefined1 *)(param_1 + 6) = 2;
      goto switchD_801640c4_caseD_2;
    }
    func_0x80052bd0(6,0);
    func_0x80052c6c(4,0x96,1);
    local_20 = *(undefined2 *)(param_1 + 0x2a);
    local_1e = *(short *)(param_1 + 0x2e) + 500;
    local_1c = *(undefined2 *)(param_1 + 0x32);
    func_0x80037780(0x11000,(int)*(short *)(param_1 + 0x66),0x800e9028,&local_20);
    uVar1 = func_0x80033604();
    if ((uVar1 & 3) == 0) {
      FUN_801661d8(param_1,1);
    }
    func_0x80077d18(2,param_1);
    iVar2 = func_0x80059e00(5,*(undefined1 *)(param_1 + 0x2b4));
    if (iVar2 != 1) {
      if (iVar2 != 2) goto LAB_8016426c;
      FUN_8016608c(0x80);
    }
    break;
  case 2:
switchD_801640c4_caseD_2:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    iVar2 = func_0x800331b8();
    iVar2 = (*(byte *)(param_1 + 0x2b5) - 1) + iVar2 * -3;
    *(char *)(param_1 + 0x2b5) = (char)iVar2;
    if (-1 < iVar2 * 0x1000000) {
      cVar4 = *(char *)(param_1 + 0x2b7) + -1;
      *(char *)(param_1 + 0x2b7) = cVar4;
      if (cVar4 == -1) {
        *(undefined2 *)(param_1 + 0x2c0) = 0x96;
        bVar5 = func_0x80033604();
        cVar4 = (bVar5 & 7) + 2;
        *(char *)(param_1 + 0x2b6) = cVar4;
        *(char *)(param_1 + 0x2b7) = cVar4;
        *(undefined1 *)(param_1 + 6) = 3;
        return;
      }
      return;
    }
    break;
  case 3:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    iVar2 = func_0x800331b8();
    iVar2 = (*(byte *)(param_1 + 0x2b5) - 1) + iVar2 * -3;
    *(char *)(param_1 + 0x2b5) = (char)iVar2;
    if (-1 < iVar2 * 0x1000000) {
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - (int)*(short *)(param_1 + 0x2c0);
      cVar4 = *(char *)(param_1 + 0x2b6) + -1;
      *(char *)(param_1 + 0x2b6) = cVar4;
      *(short *)(param_1 + 0x2c0) = *(short *)(param_1 + 0x2c0) + -0xf;
      if (cVar4 == -1) {
        *(undefined1 *)(param_1 + 6) = 4;
        return;
      }
      return;
    }
    break;
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    iVar2 = func_0x800331b8();
    iVar2 = (*(byte *)(param_1 + 0x2b5) - 1) + iVar2 * -3;
    *(char *)(param_1 + 0x2b5) = (char)iVar2;
    if (-1 < iVar2 * 0x1000000) {
      sVar3 = *(short *)(param_1 + 0x2c0) + 0xf;
      *(short *)(param_1 + 0x2c0) = sVar3;
      cVar4 = *(char *)(param_1 + 0x2b7) + -1;
      *(char *)(param_1 + 0x2b7) = cVar4;
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)sVar3;
      if (cVar4 == -1) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x5000700;
        *(undefined1 *)(param_1 + 6) = 1;
        *(undefined1 *)(param_1 + 0x2b6) = 7;
        return;
      }
      return;
    }
    break;
  case 5:
    break;
  default:
    goto switchD_801640c4_default;
  }
  bVar5 = func_0x80033604();
  *(byte *)(param_1 + 700) = bVar5 & 0x7f;
  uVar6 = func_0x80065628();
  *(undefined1 *)(param_1 + 699) = uVar6;
  FUN_80165c68(param_1,4);
  if ((*(ushort *)(param_1 + 0x2c6) & 4) != 0) {
    FUN_80166294(param_1,0x15e);
    FUN_8016608c(0x10);
    DAT_800e1136 = 3;
  }
switchD_801640c4_default:
  return;
}
