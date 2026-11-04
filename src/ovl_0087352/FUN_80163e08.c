/* FUN_80163e08
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80163e08  body 0x80163e08..0x80164037  size 560 B
 * body sha256 a23a951f83ff76e6ab456be227f06d367e62d7d7e1c089bb9ee891938da4b7b7
 * provider record sha256 9fc18afc170b6a7f7ed8c33515f898e4efde9401c577ab9fd0f94cb4d7550e5c
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163e08(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar2;
  char cVar3;
  int iVar1;
  int iVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    if (_DAT_800e110c < 0) {
      sVar2 = _DAT_800e138e + -0xa8c;
    }
    else {
      sVar2 = _DAT_800e138e + -0xb40;
    }
    *(short *)(param_1 + 0x2c0) = sVar2;
    if ((int)sVar2 - *(int *)(param_1 + 0x2c) < 0) {
      *(undefined1 *)(param_1 + 0x2b4) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x2b4) = 1;
    }
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 100) = 0;
    *(undefined2 *)(param_1 + 0x68) = 0;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar3 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar3;
  if (cVar3 == -1) {
    func_0x80077d18(1,param_1);
    *(undefined1 *)(param_1 + 0x2b6) = 0xe;
  }
  if ((*(ushort *)(param_1 + 0x2c6) & 4) == 0) {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x180);
    if (*(short *)(param_1 + 0x1e0) < 300) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 0xc;
    }
  }
  else {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x60);
    if (*(short *)(param_1 + 0x1e0) < 300) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 4;
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  iVar5 = *(int *)(param_1 + 0x2c);
  iVar4 = *(short *)(param_1 + 0x2c0) - iVar5;
  if ((0x78 < iVar4 + 0x3cU) &&
     ((iVar1 = iVar5 + -0x3c, iVar4 < -0x3c || (iVar1 = iVar5 + 0x3c, 0x3c < iVar4)))) {
    *(int *)(param_1 + 0x2c) = iVar1;
  }
  if (*(uint *)(param_1 + 0x28c) < 900) {
    FUN_80166294(param_1,100);
  }
  if (*(uint *)(param_1 + 0x28c) < 0x28a) {
    if (((int)*(short *)(param_1 + 0x2c0) - *(int *)(param_1 + 0x2c)) + 99U < 199) {
      FUN_80165c68(param_1,0xe);
    }
  }
  else {
    func_0x80032bd8(param_1,0,0);
  }
  return;
}
