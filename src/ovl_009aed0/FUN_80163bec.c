/* FUN_80163bec
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80163bec  body 0x80163bec..0x80163f37  size 844 B
 * body sha256 90c45554f18c593991fab5f5844ff3704fde91a4e84162a61a8a790d0bef7d6c
 * provider record sha256 520c528332b1cd0def24d9e0af1bc90175c98955b5bb8853f752a825c0301a64
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163bec(int param_1)

{
  byte bVar1;
  short sVar3;
  short sVar2;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  undefined4 uVar8;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      goto LAB_80163f08;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  uVar4 = DAT_8016666c._2_2_;
  *(short *)(param_1 + 0x2c8) = DAT_80166668._2_2_;
  *(undefined2 *)(param_1 + 0x2ca) = uVar4;
  uVar5 = FUN_801622f4(param_1,10,0xf,0x13,0xaa,(uint)_DAT_800e1266 * 3);
  DAT_80166670 = (int)*(short *)(param_1 + 0x2c8);
  DAT_80166674 = (int)*(short *)(param_1 + 0x2ca);
  uVar4 = DAT_80166664._2_2_;
  *(short *)(param_1 + 0x2c8) = DAT_80166660._2_2_;
  *(undefined2 *)(param_1 + 0x2ca) = uVar4;
  uVar6 = FUN_801622f4(param_1,0x10,0xf,0x13,0xaa,(uint)_DAT_800e1266 * 3);
  if (uVar5 != 0 || (uVar6 & 0x7fffffff) != 0) {
    func_0x80052bd0(5,0);
    func_0x80052d10(0x12,200,0x28,1);
    FUN_80162694(0x19);
    func_0x80077d18(5,param_1);
    *(undefined2 *)(param_1 + 0x2d0) = 0;
    *(undefined1 *)(param_1 + 0x2c6) = 0x30;
    if (_DAT_800e1322 < 0) {
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 8;
      _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
      *(undefined4 *)(param_1 + 4) = 0x1070000;
      _DAT_800e1110 = _DAT_800e1110 | 0x1000000;
      FUN_80162cf8(param_1);
    }
    else {
      if ((uVar5 & 1) == 0) {
        uVar8 = 0x10;
        sVar2 = DAT_80166660._2_2_;
        sVar3 = DAT_80166664._2_2_;
      }
      else {
        uVar8 = 10;
        sVar2 = DAT_80166668._2_2_;
        sVar3 = DAT_8016666c._2_2_;
      }
      FUN_80162d3c(param_1,(int)sVar2,(int)sVar3,uVar8);
    }
  }
  DAT_80166668 = DAT_80166670;
  DAT_8016666c = DAT_80166674;
  DAT_80166660 = (int)*(short *)(param_1 + 0x2c8);
  DAT_80166664 = (int)*(short *)(param_1 + 0x2ca);
  if (((_DAT_800e1322 < 0x51) || (2 < *(byte *)(param_1 + 0x1e9) - 10)) ||
     (*(uint *)(param_1 + 0x28c) < 0xb55)) {
    if ((*(char *)(param_1 + 0x1e9) != '\x1e') || (*(short *)(param_1 + 500) != 0)) {
      cVar7 = func_0x80036c68(param_1,4,0xf,0);
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar7;
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
      return;
    }
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  }
LAB_80163f08:
  *(undefined4 *)(param_1 + 4) = 0x1010000;
  return;
}
