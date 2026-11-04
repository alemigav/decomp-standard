/* FUN_80162b50
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80162b50  body 0x80162b50..0x80162d47  size 504 B
 * body sha256 35773207b592ba343aba0f8bc2de646e01c90d15ba29c6b72f74cf47f58fc6e7
 * provider record sha256 6876e8be8e5793186bd30eb5f0057cc95b2b5ec93b4fe84161672123d6c42fca
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162b50(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 1) == 0) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x20);
    iVar3 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                            (int)*(short *)(param_1 + 0x262),0x338);
    if (iVar3 != 0) {
      sVar1 = *(short *)(param_1 + 0x260);
      sVar2 = *(short *)(param_1 + 0x262);
      uVar5 = 0x30;
LAB_80162c40:
      func_0x80032dbc(param_1,(int)sVar1,(int)sVar2,uVar5);
    }
  }
  else {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8);
    iVar3 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                            (int)*(short *)(param_1 + 0x262),0x338);
    if (iVar3 != 0) {
      sVar1 = *(short *)(param_1 + 0x260);
      sVar2 = *(short *)(param_1 + 0x262);
      uVar5 = 0x10;
      goto LAB_80162c40;
    }
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  if (0xf < *(byte *)(param_1 + 0x1ea)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
  }
  iVar3 = func_0x80083d2c(param_1 + 0x28,_DAT_800df940);
  if (iVar3 == 0) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 0x14;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if (iVar3 != 0) {
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
      uVar4 = func_0x80033604(param_1);
      if ((uVar4 & 1) != 0) {
        func_0x80077d18(9,param_1);
      }
      if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) goto LAB_80162d28;
    }
    if ((*(ushort *)(param_1 + 500) & 1) == 0) {
      func_0x80077d18(0xd,param_1);
    }
  }
LAB_80162d28:
  func_0x80032b5c(param_1,0);
  return;
}
