/* FUN_80163a70
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163a70  body 0x80163a70..0x80163c43  size 468 B
 * body sha256 cad89a2ad6e7f1781d6b779d5530eddb3801ae8e83002b4c7e493faa625cd896
 * provider record sha256 6a6a850cd3368686dd272de356c77d02850abbe410bc866f03a51c259f6049b0
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163a70(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  byte bVar2;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined1 *)((int)param_1 + 0x2c1) = 5;
    *(undefined1 *)((int)param_1 + 0x2c3) = 3;
    *param_1 = *param_1 | 2;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
    param_1[0x7a] = (uint)*(byte *)((int)param_1 + 0x2cd) * 0xd000000 + 0x3f00;
    _DAT_800e1128 = _DAT_800e1128 | 0x40;
    *param_1 = *param_1 & 0xfffffffb;
    _DAT_800e1354 = param_1[0x89];
    _DAT_800e1134 = 0x6000000;
    _DAT_800e1358 = param_1[0x8a];
    DAT_800e139f = DAT_800e139f | 0x80;
    _DAT_800e1130 = _DAT_800e1130 | 0x42;
    _DAT_800e1310 = 100;
    _DAT_800e1314 = 0;
    _DAT_800e1380 = param_1;
    func_0x80077d18(0xc,param_1);
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  sVar1 = func_0x80032e74(&DAT_800e1130,param_1[10],param_1[0xc],0x100);
  if (sVar1 != 0) {
    _DAT_800e1196 = _DAT_800e1196 + sVar1;
  }
  bVar2 = sVar1 == 0;
  if (param_1[0xa3] < 0x5dd) {
    bVar2 = bVar2 | 2;
  }
  else {
    sVar1 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,
                            (int)*(short *)((int)param_1 + 0x2a),
                            (int)*(short *)((int)param_1 + 0x32));
    func_0x80032b5c(&DAT_800e1130,(int)sVar1 - (int)_DAT_800e1196);
  }
  if (bVar2 == 3) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
    *(undefined1 *)((int)param_1 + 0x2c3) = 0xff;
  }
  return;
}
