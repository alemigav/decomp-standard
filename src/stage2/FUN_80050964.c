/* FUN_80050964
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80050964  body 0x80050964..0x80050e1b  size 1208 B
 * body sha256 f06a8137073ea43b5730191c1be1313d15c53fda262dca7b39d42ccc460c212f
 * provider record sha256 9c85800c6fdf49167d8883157639f67b088c07381aac6c40267c6334f3ef1cf9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80050964(int param_1)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  
  sVar3 = DAT_8010bf84;
  sVar2 = DAT_8010bf80;
  switch(*(undefined1 *)(param_1 + 4)) {
  case 0:
    goto switchD_80050994_caseD_0;
  case 1:
    _DAT_80139bca = 0;
    _DAT_80139bc2 = 0xd;
    _DAT_80139bc0 = 0xd;
    _DAT_80139bc4 = 0;
    _DAT_80139bc6 = 8;
    _DAT_80139bd2 = 0;
    _DAT_80139bc8 = 0;
    DAT_80139bd8 = '\0';
    *(undefined1 *)(param_1 + 4) = 2;
    *(undefined1 *)(param_1 + 5) = 0;
  case 2:
    sVar2 = DAT_8010bf84;
    _DAT_80139bd4 = DAT_8010bf80;
    iVar6 = (int)_DAT_80139bc0;
    iVar7 = (int)DAT_8010bf84;
    bVar1 = (short)_DAT_80139bca < 0x400;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar6 * DAT_8010bf80;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + iVar6 * iVar7;
    uVar4 = (uint)_DAT_80139bca;
    if (bVar1) {
      _DAT_80139bca = (ushort)(uVar4 + _DAT_80139bc4);
      if (0x400 < (int)((uVar4 + _DAT_80139bc4) * 0x10000) >> 0x10) {
        _DAT_80139bc4 = (_DAT_80139bc4 + 0x400) - _DAT_80139bca;
      }
      _DAT_80139bd0 = _DAT_80139bc4 * -sVar2;
      _DAT_80139bd4 = _DAT_80139bc4 * _DAT_80139bd4;
    }
    else {
      _DAT_80139bd4 = 0;
      _DAT_80139bd0 = 0;
    }
    _DAT_80139bc4 = _DAT_80139bc4 + _DAT_80139bc6;
    _DAT_80139bc0 = _DAT_80139bc0 + _DAT_80139bc2;
    bVar5 = *(char *)(param_1 + 5) + 1;
    *(byte *)(param_1 + 5) = bVar5;
    if (bVar5 < 0xd) {
      *(int *)(param_1 + 0x2c) =
           *(int *)(param_1 + 0x2c) + (((int)_DAT_80139bc0 / 3) * 0x10000 >> 0x10);
    }
    else {
      iVar6 = (int)_DAT_80139bc8;
      _DAT_80139bc2 = 0;
      _DAT_80139bc8 = _DAT_80139bc8 + 0xa0;
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + iVar6;
      if (*(char *)(param_1 + 5) == '\r') {
        _DAT_80139bcc = FUN_80069f1c(param_1 + 0x120,0x1c2,0x4000,0);
        iVar6 = (int)_DAT_80139bcc;
        *(undefined2 *)(param_1 + 0x34) = *(undefined2 *)(param_1 + 0x2a);
        *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(param_1 + 0x32);
        *(char *)(param_1 + 0x1a2) = -(char)(iVar6 / 0x708);
      }
      if (((DAT_80139bd8 == '\0') && (*(short *)(param_1 + 0x1a8) != 0)) &&
         ((int)*(short *)(param_1 + 0x1a8) < *(int *)(param_1 + 0x2c))) {
        DAT_80139bd8 = '\x01';
      }
      if ((int)_DAT_80139bcc < *(int *)(param_1 + 0x2c)) {
        *(int *)(param_1 + 0x2c) = (int)_DAT_80139bcc;
        *(undefined1 *)(param_1 + 4) = 3;
      }
    }
    break;
  case 3:
    iVar7 = (int)DAT_8010bf80;
    iVar6 = (int)DAT_8010bf84;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -0x1e;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar7 * 0x14;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + iVar6 * 0x14;
    _DAT_80139bd0 = sVar3 * -0x1e;
    _DAT_80139bd4 = sVar2 * 0x1e;
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    break;
  case 4:
    iVar7 = (int)DAT_8010bf80;
    iVar6 = (int)DAT_8010bf84;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0x1e;
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar7 * 0x14;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + iVar6 * 0x14;
    _DAT_80139bd0 = sVar3 * 0x1e;
    _DAT_80139bd4 = sVar2 * -0x1e;
    *(undefined1 *)(param_1 + 4) = 0;
  }
  FUN_800838c0(param_1 + 0x28,param_1 + 100,param_1 + 0x14,&DAT_80139bd0);
switchD_80050994_caseD_0:
  return;
}
