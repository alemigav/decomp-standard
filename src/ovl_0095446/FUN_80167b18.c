/* FUN_80167b18
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80167b18  body 0x80167b18..0x80167e2b  size 788 B
 * body sha256 bf6f1b225220bad19239890670f5262da3ebb05205859c8e3d575b7fea03072a
 * provider record sha256 92b055a063aaf2dd8c9d611a9d0ee92caf739d99ac8deceb0f4700cf793fe581
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167b18(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  sVar2 = DAT_80167fc8;
  sVar1 = DAT_80167fc6;
  if (DAT_80167fca < DAT_80167fc0) {
    DAT_80167fc6 = -1;
  }
  if (DAT_80167fc0 < DAT_80167fca) {
    DAT_80167fc6 = 1;
  }
  if (DAT_80167fcb < DAT_80167fc1) {
    DAT_80167fc8 = -1;
  }
  if (DAT_80167fc1 < DAT_80167fcb) {
    DAT_80167fc8 = 1;
  }
  if (-(int)DAT_80167fc6 == (int)sVar1) {
    DAT_80167fc2 = (short)(((int)DAT_80167fc2 << 1) / 3);
  }
  if (-(int)DAT_80167fc8 == (int)sVar2) {
    DAT_80167fc4 = (short)(((int)DAT_80167fc4 << 1) / 3);
  }
  if (DAT_80167fc0 == DAT_80167fca) {
    iVar3 = (int)DAT_80167fc2;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_80167fc0 = DAT_80167fca;
      DAT_80167fc6 = 0;
      DAT_80167fc2 = 0;
    }
  }
  if (DAT_80167fc1 == DAT_80167fcb) {
    iVar3 = (int)DAT_80167fc4;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_80167fc1 = DAT_80167fcb;
      DAT_80167fc8 = 0;
      DAT_80167fc4 = 0;
    }
  }
  iVar3 = (int)DAT_80167fc0;
  iVar4 = (int)DAT_80167fc1;
  DAT_80167fc4 = DAT_80167fc4 + DAT_80167fc8;
  DAT_80167fc2 = DAT_80167fc2 + DAT_80167fc6;
  DAT_80167fc0 = DAT_80167fc0 + (char)DAT_80167fc2;
  DAT_80167fc1 = DAT_80167fc1 + (char)DAT_80167fc4;
  if ('\x03' < DAT_80167fc0) {
    DAT_80167fc0 = '\x03';
  }
  if (DAT_80167fc0 < -3) {
    DAT_80167fc0 = -3;
  }
  if ('\x0f' < DAT_80167fc1) {
    DAT_80167fc1 = '\x0f';
  }
  if (DAT_80167fc1 < -0xf) {
    DAT_80167fc1 = -0xf;
  }
  func_0x800341f4(param_2,(DAT_80167fc1 - iVar4) * 0x10000 >> 0x10,
                  (DAT_80167fc0 - iVar3) * 0x10000 >> 0x10,_DAT_800eb290,0x100c3034,0x35363738,
                  0x393a3b3c,0x3f92939a);
  return;
}
