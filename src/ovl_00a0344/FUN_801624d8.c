/* FUN_801624d8
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801624d8  body 0x801624d8..0x801626b3  size 476 B
 * body sha256 15c3ffca9b67abc1b9ec8dd54ce47365132a345bff17e917906028d134c43f63
 * provider record sha256 ee2a4097b1599a7230ee016e18ee1ec8a3dd7f5afe33aa3912fee441e14c1a2e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801624d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar4;
  uint uVar3;
  ushort uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x250);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 6) = 1;
    uVar3 = func_0x80033604();
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = ((uVar3 & 1) + 5) * 0x1000000 + (uVar1 & 7) * 0x10000 + 0x700;
    if (*(char *)(iVar6 + 0x2b4) == '\0') {
      iVar2 = -0x7ff1eed0;
    }
    else {
      iVar2 = _DAT_800e13ec;
    }
    uVar4 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)*(short *)(iVar2 + 0x2a),(int)*(short *)(iVar2 + 0x32));
    *(undefined2 *)(param_1 + 500) = uVar4;
  case 1:
    *(short *)(param_1 + 700) = *(short *)(param_1 + 500) - *(short *)(iVar6 + 0x66);
    uVar3 = func_0x80033604();
    iVar6 = (uint)*(ushort *)(param_1 + 0x2c2) - (uVar3 & 0x1f | 0x100);
    *(short *)(param_1 + 0x2c2) = (short)iVar6;
    if (iVar6 * 0x10000 >> 0x10 < -0x3ff) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    break;
  case 2:
    if (*(char *)(iVar6 + 0x2c3) != '\0') {
      *(undefined1 *)(param_1 + 6) = 3;
      *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x80000 + 0x1000700;
    }
    break;
  case 3:
    *(short *)(param_1 + 700) = *(short *)(param_1 + 500) - *(short *)(iVar6 + 0x66);
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 0x2c2) = *(short *)(param_1 + 0x2c2) + (uVar5 & 0x1f | 0x100);
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if (-1 < *(short *)(param_1 + 0x2c2)) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  FUN_8016375c(param_1,0);
  return;
}
