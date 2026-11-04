/* FUN_80163264
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80163264  body 0x80163264..0x801634bf  size 604 B
 * body sha256 c83edb858d8234373e5d1f742e133926002c3a12d46c96389b8ea6551525ad5b
 * provider record sha256 6348d3b94d65005e4b952b5eaa0663c49e991b23d92615b4b86fb1c4b16c921c
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163264(int param_1)

{
  byte bVar3;
  int iVar1;
  short sVar2;
  ushort uVar4;
  
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(param_1 + 0x26f) & 0x7f) != 0) {
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) - 1;
    }
    if (_DAT_800e12da == 0x11) {
      bVar3 = *(byte *)(param_1 + 0x26f) | 0x80;
    }
    else {
      bVar3 = *(byte *)(param_1 + 0x26f) & 0x7f;
    }
    *(byte *)(param_1 + 0x26f) = bVar3;
    if (((((*(ushort *)(param_1 + 0x2b8) & 2) != 0) && ((_DAT_800e110c & 0x40000) != 0)) &&
        (iVar1 = func_0x8008cce4(_DAT_800e12da & 0xfff), iVar1 != 0)) &&
       (_DAT_800e110c = _DAT_800e110c & 0xfffbffff, (*(ushort *)(param_1 + 0x1aa) & 0x4000) == 0)) {
      sVar2 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,(int)*(short *)(param_1 + 0x2a),
                              (int)*(short *)(param_1 + 0x32));
      uVar4 = sVar2 - _DAT_800e1196 & 0xfff;
      if (0x800 < uVar4) {
        uVar4 = uVar4 | 0xf000;
      }
      if ((_DAT_800df914 & 0x40) != 0) {
        iVar1 = (int)(short)uVar4;
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        if (iVar1 < 300) {
          *(undefined4 *)(param_1 + 4) = 0x3000000;
          _DAT_800df914 = _DAT_800df914 & 0xffffffbf;
        }
      }
    }
    *(undefined2 *)(param_1 + 0x276) = 0;
    (*(code *)(&PTR_FUN_801665d4)[*(byte *)(param_1 + 4)])
              (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
    if ((*(ushort *)(param_1 + 0x2b8) & 4) == 0) {
      FUN_801626c4(param_1);
    }
    if (*(char *)(param_1 + 0x2d2) != '\0') {
      FUN_801631c8(param_1);
    }
    func_0x80033648(param_1);
    if (*(code **)(param_1 + 700) != (code *)0x0) {
      (**(code **)(param_1 + 700))(param_1);
    }
    if (*(code **)(param_1 + 0x2c0) != (code *)0x0) {
      (**(code **)(param_1 + 0x2c0))(param_1);
    }
    func_0x8004db5c(param_1);
    func_0x8004dcb8(param_1,0x400);
    if (*(short *)(param_1 + 0x1f2) < 20000) {
      *(undefined2 *)(param_1 + 0x274) = 1;
    }
    if (*(short *)(param_1 + 0x1f2) < 10000) {
      *(undefined2 *)(param_1 + 0x1f2) = 10000;
    }
    if ('\0' < *(char *)(param_1 + 0x2c6)) {
      *(char *)(param_1 + 0x2c6) = *(char *)(param_1 + 0x2c6) + -1;
    }
    *(short *)(param_1 + 0x2d0) = *(short *)(param_1 + 0x2d0) + 1;
  }
  return;
}
