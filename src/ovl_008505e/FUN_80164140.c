/* FUN_80164140
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164140  body 0x80164140..0x80164383  size 580 B
 * body sha256 18769b6a924e9c3d481b8bc929b0ade77776c2f5bc205069cf6906afd07b77f9
 * provider record sha256 0783beb7a4a8408295b734c34b4fd9c805404e71015fd444172fb89a4c4f136d
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164140(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 1) {
    if (_DAT_800e1322 < 0) goto LAB_801642bc;
    uVar3 = 0xdac;
    if ((_DAT_800e1134 & 0xffff0000) == 0x1020000) {
      uVar3 = 5000;
    }
    if (uVar3 < *(uint *)(param_1 + 0x28c)) {
      if ((_DAT_800e112a & 1) != 0) {
        if ((_DAT_800e1128 & 0x80) == 0) {
          *(undefined2 *)(param_1 + 6) = 0x100;
          _DAT_800e1128 = _DAT_800e1128 | 0x80;
        }
        else {
          *(undefined1 *)(param_1 + 7) = 2;
          uVar3 = func_0x80033604();
          *(ushort *)(param_1 + 500) = (ushort)(byte)(&DAT_80166c90)[uVar3 & 7];
        }
      }
      goto LAB_801642bc;
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined1 *)(param_1 + 7) = 1;
        *(undefined1 *)(param_1 + 0x2b5) = 0;
        *(undefined1 *)(param_1 + 0x2c9) = 0;
        uVar3 = func_0x80033604();
        *(uint *)(param_1 + 0x1e8) = (uVar3 & 0x3f) * 0x10000 + 0xe001f00;
        func_0x800334c8(param_1,param_2,param_3,0);
        func_0x80089d54(param_1,param_2,param_3,0x80);
      }
      goto LAB_801642bc;
    }
    if ((bVar1 != 2) ||
       (sVar2 = *(short *)(param_1 + 500), *(short *)(param_1 + 500) = sVar2 + -1, sVar2 != 1))
    goto LAB_801642bc;
  }
  *(undefined2 *)(param_1 + 6) = 0x100;
LAB_801642bc:
  uVar3 = **(uint **)(param_1 + 0x214);
  if ((uVar3 & 0x30000) != 0) {
    *(undefined1 *)(param_1 + 699) = 1;
    FUN_80166980(param_1,4,0);
    if (((uVar3 & 0x20000) != 0) && (uVar3 = func_0x80033604(), (uVar3 & 3) == 0)) {
      *(undefined1 *)(param_1 + 699) = 1;
      uVar3 = func_0x80033604();
      FUN_80166980(param_1,4,(uVar3 & 1) + 1);
    }
  }
  func_0x80033648(param_1);
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80089d54(param_1,param_2,param_3,0x80);
  func_0x80032b5c(param_1,0);
  return;
}
