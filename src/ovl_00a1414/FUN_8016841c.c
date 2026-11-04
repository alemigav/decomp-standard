/* FUN_8016841c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016841c  body 0x8016841c..0x8016871f  size 772 B
 * body sha256 79785f2bf76a6a84aa8be2e600afdf947603d81818d760b58562dc204c36e8c0
 * provider record sha256 496a8745f29c91404990595555a308c8e2e710f14717b75d710b0d5c8a169989
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016841c(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  sVar2 = DAT_80168f4c;
  sVar1 = DAT_80168f4a;
  if (DAT_80168f4e < DAT_80168f44) {
    DAT_80168f4a = -1;
  }
  if (DAT_80168f44 < DAT_80168f4e) {
    DAT_80168f4a = 1;
  }
  if (DAT_80168f4f < DAT_80168f45) {
    DAT_80168f4c = -1;
  }
  if (DAT_80168f45 < DAT_80168f4f) {
    DAT_80168f4c = 1;
  }
  if (-(int)DAT_80168f4a == (int)sVar1) {
    DAT_80168f46 = (short)(((int)DAT_80168f46 << 1) / 3);
  }
  if (-(int)DAT_80168f4c == (int)sVar2) {
    DAT_80168f48 = (short)(((int)DAT_80168f48 << 1) / 3);
  }
  if (DAT_80168f44 == DAT_80168f4e) {
    iVar3 = (int)DAT_80168f46;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_80168f44 = DAT_80168f4e;
      DAT_80168f4a = 0;
      DAT_80168f46 = 0;
    }
  }
  if (DAT_80168f45 == DAT_80168f4f) {
    iVar3 = (int)DAT_80168f48;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (iVar3 < 3) {
      DAT_80168f45 = DAT_80168f4f;
      DAT_80168f4c = 0;
      DAT_80168f48 = 0;
    }
  }
  iVar3 = (int)DAT_80168f44;
  iVar4 = (int)DAT_80168f45;
  DAT_80168f48 = DAT_80168f48 + DAT_80168f4c;
  DAT_80168f46 = DAT_80168f46 + DAT_80168f4a;
  DAT_80168f44 = DAT_80168f44 + (char)DAT_80168f46;
  DAT_80168f45 = DAT_80168f45 + (char)DAT_80168f48;
  if ('\x14' < DAT_80168f44) {
    DAT_80168f44 = '\x14';
  }
  if (DAT_80168f44 < -0x11) {
    DAT_80168f44 = -0x11;
  }
  if ('\x14' < DAT_80168f45) {
    DAT_80168f45 = '\x14';
  }
  if (DAT_80168f45 < -0x11) {
    DAT_80168f45 = -0x11;
  }
  func_0x800341f4(param_2,(DAT_80168f45 - iVar4) * 0x10000 >> 0x10,
                  (DAT_80168f44 - iVar3) * 0x10000 >> 0x10,_DAT_800eb290,0x630373b);
  return;
}
