/* FUN_80162dc0
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80162dc0  body 0x80162dc0..0x801631c3  size 1028 B
 * body sha256 bd40aef38640d28cf5c24183d63f1188ce62a8207b9e787779bad07fdc458e66
 * provider record sha256 bca6600063192b8e34afdc905cca6f88816c7392f6b105bd631a650cb7488453
 * callees 13 direct (13 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162dc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  
  if (*(char *)(param_1 + 0x2be) < '\x03') {
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) | 0x82;
  }
  if (*(char *)(param_1 + 700) < '\x02') {
    *(undefined1 *)(param_1 + 700) = 1;
  }
  bVar1 = *(byte *)(param_1 + 6);
  *(undefined1 *)(param_1 + 0x2b9) = 0xf;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 0x2b9) = 0x1e;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x4003f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar3 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x400;
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) & 0x7f;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    uVar4 = func_0x80033604();
    *(char *)(param_1 + 0x2b8) = (char)((uVar4 & 0xff) >> 1) + 'x';
  }
  func_0x80032b5c(param_1,0);
  if ((*(byte *)(param_1 + 0x1e9) - 6 < 0x18) &&
     ((func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8), 0x1194 < *(uint *)(param_1 + 0x28c)
      || (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x4c8), iVar3 != 0)))) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2b9) = 0xf;
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) & 0x7f;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x200;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,4);
  sVar6 = *(short *)(param_1 + 0x66);
  *(short *)(param_1 + 0x66) = sVar6 + -0x200;
  if (*(byte *)(param_1 + 0x1e9) - 0x36 < 0x16) {
    *(short *)(param_1 + 0x66) = sVar6;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x200;
    if (*(short *)(param_1 + 500) != 0) goto LAB_8016314c;
    bVar2 = false;
    iVar7 = *(int *)(param_1 + 0x234);
    iVar3 = func_0x80033024(iVar7 + 0x11ec,&DAT_800e1158,800);
    if (iVar3 == 0) {
      iVar3 = func_0x80033024(iVar7 + 0xefc,&DAT_800e1158,1000);
      if (iVar3 != 0) {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
    }
    if ((bVar2) && (DAT_800e139f == 0)) {
      iVar3 = func_0x80059e00(0x1e,0);
      if (iVar3 == 2) {
        _DAT_800e1134 = 0x3000000;
      }
      else {
        _DAT_800e1134 = 0x5000000;
        iVar3 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,
                                (int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32));
        if (((((iVar3 + -0x400) * 0x10000 >> 0x10) - (int)_DAT_800e1196) + 0x400U & 0xfff) < 0x800)
        {
          cVar5 = DAT_800e1135 + '\x01';
          _DAT_800e1135 = CONCAT12(cVar5,DAT_800e1134_1._1_2_);
        }
      }
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1380 = param_1;
      *(undefined2 *)(param_1 + 500) = 1;
      *(undefined2 *)(param_1 + 0x1f6) = 4;
      func_0x80052bd0(3,0);
      func_0x80052c6c(10,200,0);
      func_0x80077d18(6,param_1);
    }
  }
  if (*(short *)(param_1 + 500) == 0) {
    return;
  }
LAB_8016314c:
  sVar6 = *(short *)(param_1 + 0x1f6) + -1;
  if (*(short *)(param_1 + 0x1f6) != 0) {
    *(short *)(param_1 + 0x1f6) = sVar6;
    func_0x80037780(sVar6 * 200 + 0x818U | 0x10000,0,*(int *)(param_1 + 0x234) + 0x11d8,0);
  }
  return;
}
