/* FUN_801631dc
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x801631dc  body 0x801631dc..0x801634eb  size 784 B
 * body sha256 15cdfbddd6fe52d279b434cf9b3a74a231566200b28418e7841b280658a93295
 * provider record sha256 879f0662ed258d95b20f73fb92b2a3475683da3e4a6094f71d139b05fbdeb492
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801631dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar4;
  uint uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar5;
  undefined2 uVar6;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000700;
    *(undefined2 *)(param_1 + 0x1e0) = 0x32;
    *(undefined2 *)(param_1 + 0x1e2) = 0x78;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
  case 1:
    cVar4 = *(char *)(param_1 + 0x2b5) + -1;
    *(char *)(param_1 + 0x2b5) = cVar4;
    if (cVar4 == -1) {
      uVar1 = func_0x80033604();
      if ((uVar1 & 1) != 0) {
        func_0x80077d18(1,param_1);
      }
      *(undefined1 *)(param_1 + 0x2b5) = 0xf;
    }
    uVar6 = *(undefined2 *)(param_1 + 0x2e);
    func_0x80032bd8(param_1,0,0);
    if (-300 < *(int *)(param_1 + 0x2c) - (*(short *)(param_1 + 0x25e) + -0xfa)) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    func_0x80089d54(param_1,param_2,param_3,0x200,uVar6);
    return;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0xa000700;
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) != 0) {
      func_0x80077d18(1,param_1);
    }
    *(undefined2 *)(param_1 + 0x1e0) = 0x32;
    *(undefined2 *)(param_1 + 0x1e2) = 0xf;
    *(undefined1 *)(param_1 + 0x2b5) = 0xf;
    *(undefined1 *)(param_1 + 0x2b4) = 3;
    *(undefined1 *)(param_1 + 6) = 5;
    break;
  case 3:
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) != 0) {
      func_0x80077d18(1,param_1);
    }
    *(undefined1 *)(param_1 + 0x2b5) = 5;
    *(undefined1 *)(param_1 + 0x2b4) = 4;
    *(undefined1 *)(param_1 + 6) = 5;
    break;
  case 4:
    *(undefined2 *)(param_1 + 0x1e0) = 10;
    *(undefined1 *)(param_1 + 0x2b5) = 0xff;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined1 *)(param_1 + 6) = 5;
    *(int *)(param_1 + 0x2c) = *(short *)(param_1 + 0x25e) + -0xfa;
    break;
  case 5:
    break;
  case 6:
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x60);
    func_0x80032bd8(param_1,0,0);
    *(int *)(param_1 + 0x2c) = *(short *)(param_1 + 0x25e) + -0xfa;
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 != 0) {
      if ((_DAT_800e1322 < 0) && (*(char *)(param_1 + 0x2bd) < '\x01')) {
        uVar5 = 0;
      }
      else {
        uVar3 = func_0x80033604();
        *(ushort *)(param_1 + 500) = (uVar3 & 0xff) << 1;
        uVar5 = 2;
      }
      FUN_80165c68(param_1,uVar5);
    }
  default:
    goto switchD_8016321c_default;
  }
  cVar4 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar4;
  if (cVar4 == '\0') {
    *(undefined1 *)(param_1 + 6) = *(undefined1 *)(param_1 + 0x2b4);
  }
  uVar6 = *(undefined2 *)(param_1 + 0x2e);
  func_0x80032bd8(param_1,0,0);
  iVar2 = *(short *)(param_1 + 0x25e) + -0xfa;
  if (iVar2 < *(int *)(param_1 + 0x2c)) {
    *(int *)(param_1 + 0x2c) = iVar2;
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200,uVar6);
  if (iVar2 != 0) {
    *(undefined2 *)(param_1 + 0x1e0) = 10;
    *(undefined1 *)(param_1 + 6) = 6;
    *(undefined4 *)(param_1 + 0x1e8) = 0x8000700;
  }
switchD_8016321c_default:
  return;
}
