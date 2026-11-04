/* FUN_80168ee8
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80168ee8  body 0x80168ee8..0x801691db  size 756 B
 * body sha256 50db2cc626e13e6a30ce7459951e6e830c494d1dca86588c9561ca08d553b851
 * provider record sha256 856cc31d0c7ec9292dbcbe7a0c66e99eb378abde491bdc6edda02cc278c07a04
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80168ee8(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  sVar2 = DAT_801697e8;
  sVar1 = DAT_801697e6;
  if (DAT_801697ea < DAT_801697e0) {
    DAT_801697e6 = -1;
  }
  if (DAT_801697e0 < DAT_801697ea) {
    DAT_801697e6 = 1;
  }
  if (DAT_801697eb < DAT_801697e1) {
    DAT_801697e8 = -1;
  }
  if (DAT_801697e1 < DAT_801697eb) {
    DAT_801697e8 = 1;
  }
  if (-(int)DAT_801697e6 == (int)sVar1) {
    DAT_801697e2 = (short)(((int)DAT_801697e2 << 1) / 3);
  }
  if (-(int)DAT_801697e8 == (int)sVar2) {
    DAT_801697e4 = (short)(((int)DAT_801697e4 << 1) / 3);
  }
  if (DAT_801697e0 == DAT_801697ea) {
    iVar3 = (int)DAT_801697e2;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_801697e0 = DAT_801697ea;
      DAT_801697e6 = 0;
      DAT_801697e2 = 0;
    }
  }
  if (DAT_801697e1 == DAT_801697eb) {
    iVar3 = (int)DAT_801697e4;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_801697e1 = DAT_801697eb;
      DAT_801697e8 = 0;
      DAT_801697e4 = 0;
    }
  }
  iVar3 = (int)DAT_801697e0;
  iVar4 = (int)DAT_801697e1;
  DAT_801697e4 = DAT_801697e4 + DAT_801697e8;
  DAT_801697e2 = DAT_801697e2 + DAT_801697e6;
  DAT_801697e0 = DAT_801697e0 + (char)DAT_801697e2;
  DAT_801697e1 = DAT_801697e1 + (char)DAT_801697e4;
  if ('\b' < DAT_801697e0) {
    DAT_801697e0 = '\b';
  }
  if (DAT_801697e0 < -8) {
    DAT_801697e0 = -8;
  }
  if ('\b' < DAT_801697e1) {
    DAT_801697e1 = '\b';
  }
  if (DAT_801697e1 < -8) {
    DAT_801697e1 = -8;
  }
  func_0x800341f4(param_2,(DAT_801697e1 - iVar4) * 0x10000 >> 0x10,
                  (DAT_801697e0 - iVar3) * 0x10000 >> 0x10,_DAT_800eb290);
  return;
}
