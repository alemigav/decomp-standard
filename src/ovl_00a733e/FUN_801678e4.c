/* FUN_801678e4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801678e4  body 0x801678e4..0x80167bd7  size 756 B
 * body sha256 b9861edd46345687e253263c0f0dee3ec2fe6c944c45799ee9dc4762bed491ae
 * provider record sha256 319942cd1235a1341766e31a27901658d97546c84dcca3ae68439181e80b65f4
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801678e4(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  sVar2 = DAT_80167d68;
  sVar1 = DAT_80167d66;
  if (DAT_80167d6a < DAT_80167d60) {
    DAT_80167d66 = -1;
  }
  if (DAT_80167d60 < DAT_80167d6a) {
    DAT_80167d66 = 1;
  }
  if (DAT_80167d6b < DAT_80167d61) {
    DAT_80167d68 = -1;
  }
  if (DAT_80167d61 < DAT_80167d6b) {
    DAT_80167d68 = 1;
  }
  if (-(int)DAT_80167d66 == (int)sVar1) {
    DAT_80167d62 = (short)(((int)DAT_80167d62 << 1) / 3);
  }
  if (-(int)DAT_80167d68 == (int)sVar2) {
    DAT_80167d64 = (short)(((int)DAT_80167d64 << 1) / 3);
  }
  if (DAT_80167d60 == DAT_80167d6a) {
    iVar3 = (int)DAT_80167d62;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_80167d60 = DAT_80167d6a;
      DAT_80167d66 = 0;
      DAT_80167d62 = 0;
    }
  }
  if (DAT_80167d61 == DAT_80167d6b) {
    iVar3 = (int)DAT_80167d64;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_80167d61 = DAT_80167d6b;
      DAT_80167d68 = 0;
      DAT_80167d64 = 0;
    }
  }
  iVar3 = (int)DAT_80167d60;
  iVar4 = (int)DAT_80167d61;
  DAT_80167d64 = DAT_80167d64 + DAT_80167d68;
  DAT_80167d62 = DAT_80167d62 + DAT_80167d66;
  DAT_80167d60 = DAT_80167d60 + (char)DAT_80167d62;
  DAT_80167d61 = DAT_80167d61 + (char)DAT_80167d64;
  if ('\b' < DAT_80167d60) {
    DAT_80167d60 = '\b';
  }
  if (DAT_80167d60 < -8) {
    DAT_80167d60 = -8;
  }
  if ('\b' < DAT_80167d61) {
    DAT_80167d61 = '\b';
  }
  if (DAT_80167d61 < -8) {
    DAT_80167d61 = -8;
  }
  func_0x800341f4(param_2,(DAT_80167d61 - iVar4) * 0x10000 >> 0x10,
                  (DAT_80167d60 - iVar3) * 0x10000 >> 0x10,_DAT_800eb290);
  return;
}
