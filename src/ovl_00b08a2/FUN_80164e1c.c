/* FUN_80164e1c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80164e1c  body 0x80164e1c..0x80165233  size 1048 B
 * body sha256 b0e8f4b7bd093c06a30be7fc000dc6b3eb49717ba3af06fa3c945b32c482f59e
 * provider record sha256 d5a3d6b178970c1be80094c03f3f4ec4045d02a42daa37c0a445c3223b2427e3
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164e1c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  char cVar2;
  uint *puVar3;
  
  puVar3 = (uint *)param_1[0x8d];
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    puVar3 = (uint *)param_1[0x8d];
    param_1[0x7a] = 0;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *puVar3 = *puVar3 | 1;
    *(undefined2 *)(param_1 + 0x1a) =
         *(undefined2 *)(&DAT_8016727a + (uint)*(byte *)(param_1 + 0xad) * 6);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    *(undefined2 *)(param_1 + 0x19) = 0;
    *(byte *)(_DAT_800e13f0 + 0x2c4) =
         *(byte *)(_DAT_800e13f0 + 0x2c4) | (byte)(1 << (*(byte *)(param_1 + 0xad) + 4 & 0x1f));
    func_0x80077d18(0,param_1);
    *param_1 = *param_1 | 0x100000;
  case 1:
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar1 = *(short *)(puVar3 + 0x49);
    *(short *)(puVar3 + 0x49) = sVar1 + 0x40;
    if (0xdf4 < (short)(sVar1 + 0x40)) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      sVar1 = *(short *)(&DAT_80167278 + (uint)*(byte *)(param_1 + 0xad) * 6);
      *(undefined2 *)((int)param_1 + 0x1f6) = 0;
      param_1[0x7a] = sVar1 * 0x1000000 + 0x1f00;
    }
    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + -8;
    break;
  case 2:
    sVar1 = *(short *)(puVar3 + 0x49);
    *(short *)(puVar3 + 0x49) = sVar1 + 0x40;
    if ((short)(sVar1 + 0x40) < 0x1001) {
      *(undefined1 *)((int)param_1 + 0x207) = 0;
    }
    else {
      *(undefined1 *)((int)param_1 + 6) = 3;
      *(undefined2 *)(puVar3 + 0x49) = 0x1000;
      *(undefined1 *)((int)param_1 + 0x207) = 0;
    }
  case 3:
    if (0x14 < *(byte *)((int)param_1 + 0x1e9)) {
      *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + *(short *)((int)param_1 + 0x1f6);
      *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + 8;
      if (0 < *(short *)(param_1 + 0x1a)) {
        *(undefined2 *)(param_1 + 0x1a) = 0;
      }
    }
    if ((*(byte *)((int)param_1 + 0x1e9) - 0x1a < 7) && ((param_1[0xaf] & 0x40000) != 0)) {
      if (DAT_800e139f == 0) {
        func_0x80059e00(0xf,1);
        DAT_800e139f = DAT_800e139f | 0x80;
        _DAT_800e1354 = param_1[0x89];
        _DAT_800e1358 = param_1[0x8a];
        _DAT_800e1134 = 0x5030000;
        _DAT_800e1380 = param_1;
        func_0x80077d18(3,param_1);
        *(undefined1 *)((int)param_1 + 0x207) = 1;
        func_0x80052bd0(3,0);
        func_0x80052c6c(10,0xfa,0);
      }
      if (((((param_1[0xaf] & 0x40000) != 0) && (DAT_800e139f != 0)) &&
          (*(char *)((int)param_1 + 0x207) == '\0')) && (-1 < _DAT_800e1322)) {
        func_0x80059e00(10,1);
        DAT_800e139f = DAT_800e139f | 0x80;
        _DAT_800e1354 = param_1[0x89];
        _DAT_800e1358 = param_1[0x8a];
        _DAT_800e1134 = 0x5040000;
        _DAT_800e1380 = param_1;
        func_0x80077d18(3,param_1);
        *(undefined1 *)((int)param_1 + 0x207) = 1;
        func_0x80052bd0(3,0);
        func_0x80052c6c(10,0xfa,0);
      }
    }
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    break;
  case 4:
    *(undefined1 *)((int)param_1 + 6) = 5;
    param_1[0x7a] = 0x3f00;
  case 5:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar1 = *(short *)(puVar3 + 0x49);
    *(ushort *)(puVar3 + 0x49) = sVar1 - 0x80U;
    if ((int)((uint)(ushort)(sVar1 - 0x80U) << 0x10) < 0) {
      *(undefined2 *)(puVar3 + 0x49) = 0;
      param_1[1] = 0x1000000;
      *(byte *)(_DAT_800e13f0 + 0x2c4) =
           *(byte *)(_DAT_800e13f0 + 0x2c4) & ~(byte)(1 << (*(byte *)(param_1 + 0xad) + 4 & 0x1f));
      *param_1 = *param_1 & 0xffefffff;
    }
  }
  return;
}
