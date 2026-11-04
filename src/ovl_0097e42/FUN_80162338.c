/* FUN_80162338
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80162338  body 0x80162338..0x801625a3  size 620 B
 * body sha256 585887ff2aa0856954119f2f225aac8b8581632c4b8a28f3df93b70d9f854abc
 * provider record sha256 0505999a0587d353a1cb8e4e0bd1572da56c7cc7f65012ae7c049a068f6429cc
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162338(int param_1)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar5;
  ushort uVar6;
  uint uVar3;
  int iVar4;
  short local_10 [4];
  
  bVar1 = *(byte *)(param_1 + 6);
  *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 8;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      goto LAB_80162448;
    }
    if (bVar1 != 0) {
      return;
    }
    uVar5 = func_0x80032d14(0xffff9d90,0xfffff8f8,(int)*(short *)(param_1 + 0x32),
                            (int)*(short *)(param_1 + 0x2e));
    *(undefined2 *)(param_1 + 0x2b4) = uVar5;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  uVar3 = func_0x80033604();
  if ((uVar3 & 3) == 0) {
    if ((*(int *)(param_1 + 0x2c) < -0x708) && (uVar3 = func_0x80033604(), (uVar3 & 3) == 0)) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    return;
  }
  uVar3 = func_0x80033604();
  if ((uVar3 & 3) == 2) {
    func_0x80077d18(0,param_1);
  }
  uVar6 = func_0x80033604();
  *(ushort *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x66) + -0x400 + (uVar6 & 0xff) * 8;
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
LAB_80162448:
  if (*(short *)(param_1 + 0x1e0) < 0x8c) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 0x14;
  }
  local_10[2] = *(short *)(param_1 + 0x1e0);
  local_10[0] = 0;
  local_10[1] = 0;
  uVar3 = func_0x80032f64(param_1,(int)*(short *)(param_1 + 0x2b8),0x20);
  if ((uVar3 & 0xffff) == 0) {
    *(undefined1 *)(param_1 + 6) = 1;
  }
  iVar4 = *(ushort *)(param_1 + 0x66) + uVar3;
  *(short *)(param_1 + 0x66) = (short)iVar4;
  func_0x800837d0(iVar4 * 0x10000 >> 0x10,local_10,local_10);
  sVar2 = (short)((local_10[2] * 0x64000) / 0x113fa0);
  *(short *)(param_1 + 0x2b6) = sVar2;
  *(ushort *)(param_1 + 0x2b4) = *(short *)(param_1 + 0x2b4) + sVar2 & 0xfff;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_10[0];
  iVar4 = func_0x800408c0((int)*(short *)(param_1 + 0x2b4));
  iVar4 = iVar4 * 0x708;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xfff;
  }
  *(int *)(param_1 + 0x30) = (iVar4 >> 0xc) + -0x6270;
  iVar4 = func_0x80040968((int)*(short *)(param_1 + 0x2b4));
  iVar4 = iVar4 * -0x708;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xfff;
  }
  *(int *)(param_1 + 0x2c) = (iVar4 >> 0xc) + -0x708;
  *(undefined2 *)(param_1 + 0x1da) = 0xc00;
  *(short *)(param_1 + 0x1dc) = 0xc00 - *(short *)(param_1 + 0x2b4);
  func_0x80040e58(param_1 + 0x1d8,*(undefined4 *)(param_1 + 0x70));
  return;
}
