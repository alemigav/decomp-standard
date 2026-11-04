/* FUN_801630d4
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801630d4  body 0x801630d4..0x801632bf  size 492 B
 * body sha256 819a58287cab0497fd2dceb849aad524fee5625b7dc130becb8609620b336978
 * provider record sha256 deac572f3aab6f1de56cdcc31ee31237b82bca2b6bf0b9a80680446c241c27bc
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801630d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    DAT_8016c31e = 0;
    func_0x80077d18(0,param_1);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if (DAT_8016c31e == 0) {
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x10);
    iVar2 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                            (int)*(short *)(param_1 + 0x262),0x338);
    if (iVar2 == 0) goto LAB_801631b0;
    sVar3 = *(short *)(param_1 + 0x260);
    sVar1 = *(short *)(param_1 + 0x262);
    uVar4 = 0x20;
  }
  else {
    uVar4 = 0xfffffff0;
    DAT_8016c31e = DAT_8016c31e + -1;
    sVar3 = DAT_8016c31a;
    sVar1 = DAT_8016c31c;
  }
  func_0x80032dbc(param_1,(int)sVar3,(int)sVar1,uVar4);
LAB_801631b0:
  func_0x800334c8(param_1,param_2,param_3,0);
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 10;
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
    *(undefined2 *)(param_1 + 500) = 0;
  }
  else {
    sVar3 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar3;
    if (0x5a < sVar3) {
      local_20 = *(undefined4 *)(param_1 + 0x120);
      local_1c = *(undefined4 *)(param_1 + 0x124);
      local_18 = *(undefined4 *)(param_1 + 0x128);
      func_0x800667d4(&local_20,0x6a4,1,0x500);
      if (_DAT_800e1068 != (short *)0x0) {
        DAT_8016c31e = 8;
        DAT_8016c31a = *_DAT_800e1068 + ((ushort)_DAT_800e1068[2] >> 1);
        DAT_8016c31c = _DAT_800e1068[1] + ((ushort)_DAT_800e1068[3] >> 1);
      }
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x80);
  func_0x80032b5c(param_1,0);
  return;
}
