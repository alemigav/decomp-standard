/* FUN_80162e70
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80162e70  body 0x80162e70..0x801632cb  size 1116 B
 * body sha256 ded9f2e477b62a05c16ff818a7b5b8afe5590d6e363e5229c7076dc9ccc433d3
 * provider record sha256 8fa33cf9b59cd6780d68588c042c98c45a695c30736896aeb6cd9e0c2274bb7b
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162e70(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar3;
  ushort uVar4;
  int iVar1;
  uint uVar2;
  uint *puVar5;
  
  puVar5 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    puVar5 = *(uint **)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    *puVar5 = *puVar5 | 1;
    *(undefined2 *)(param_1 + 0x68) = 0xfdc0;
    *(undefined2 *)(param_1 + 0x66) = 0;
    *(undefined2 *)(param_1 + 100) =
         *(undefined2 *)(&DAT_801671c0 + (uint)*(byte *)(param_1 + 0x2b4) * 2);
    *(byte *)(_DAT_800e13f0 + 0x2c4) =
         *(byte *)(_DAT_800e13f0 + 0x2c4) | (byte)(1 << (*(byte *)(param_1 + 0x2b4) + 4 & 0x1f));
    func_0x80077d18(0,param_1);
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar3 = *(short *)(puVar5 + 0x49);
    *(short *)(puVar5 + 0x49) = sVar3 + 0x40;
    if (0xc00 < (short)(sVar3 + 0x40)) {
      *(undefined1 *)(param_1 + 6) = 2;
      uVar2 = func_0x80033604();
      *(char *)(param_1 + 0x207) = (char)(uVar2 & 1);
      *(uint *)(param_1 + 0x1e8) = ((uVar2 & 1) + 7) * 0x1000000 + 0x1f00;
    }
    if ((0x7e8 < *(short *)(puVar5 + 0x49)) &&
       (sVar3 = *(short *)(param_1 + 0x68) + 0x20, *(short *)(param_1 + 0x68) = sVar3, 0x20 < sVar3)
       ) {
      *(undefined2 *)(param_1 + 0x68) = 0x20;
    }
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    sVar3 = *(short *)(puVar5 + 0x49);
    *(short *)(puVar5 + 0x49) = sVar3 + 0x40;
    if (0x1000 < (short)(sVar3 + 0x40)) {
      *(undefined2 *)(puVar5 + 0x49) = 0x1000;
      *(undefined1 *)(param_1 + 6) = 3;
      uVar4 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar4 & 0xf) + 10;
    }
    iVar1 = *(char *)(param_1 + 0x207) * 4;
    if (((byte)(&DAT_801671b8)[iVar1] < *(byte *)(param_1 + 0x1e9)) &&
       (*(byte *)(param_1 + 0x1e9) < (byte)(&DAT_801671b9)[iVar1])) {
      *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + 8;
    }
    break;
  case 3:
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 6) = 4;
      *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    }
    iVar1 = *(char *)(param_1 + 0x207) * 4;
    if (((byte)(&DAT_801671b8)[iVar1] < *(byte *)(param_1 + 0x1e9)) &&
       (*(byte *)(param_1 + 0x1e9) < (byte)(&DAT_801671b9)[iVar1])) {
      *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + 8;
    }
    iVar1 = *(char *)(param_1 + 0x207) * 4;
    if (((((byte)(&DAT_801671ba)[iVar1] < *(byte *)(param_1 + 0x1e9)) &&
         (*(byte *)(param_1 + 0x1e9) < (byte)(&DAT_801671bb)[iVar1])) &&
        (*(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + 4,
        (*(ushort *)(param_1 + 700) & 4) != 0)) &&
       ((DAT_800e139f == 0 && (-1 < *(short *)(_DAT_800e13f0 + 0x1f2))))) {
      iVar1 = func_0x80059e00(0xf,0);
      if (iVar1 == 2) {
        _DAT_800e1134 = 0x3000000;
      }
      else {
        uVar2 = func_0x80033144(param_1,0x800e1130);
        _DAT_800e1134 = (~uVar2 & 1) * 0x10000 + 0x5000000;
        if (6000 < *(uint *)(param_1 + 0x28c)) {
          _DAT_800e1134 = 0x5020000;
          _DAT_800e1196 = 0xd80;
          if (*(byte *)(param_1 + 0x2b4) < 2) {
            _DAT_800e1196 = 0x280;
          }
        }
      }
      DAT_800e139f = DAT_800e139f | 0x80;
      _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
      _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
      _DAT_800e1380 = param_1;
      func_0x80077d18(3,param_1);
      func_0x80052bd0(3,0);
      func_0x80052c6c(10,0xfa,0);
    }
    break;
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    sVar3 = *(short *)(puVar5 + 0x49);
    *(ushort *)(puVar5 + 0x49) = sVar3 - 0x40U;
    if ((int)((uint)(ushort)(sVar3 - 0x40U) << 0x10) < 0) {
      *(undefined2 *)(puVar5 + 0x49) = 0;
      *(undefined4 *)(param_1 + 4) = 0x1000000;
      *(byte *)(_DAT_800e13f0 + 0x2c4) =
           *(byte *)(_DAT_800e13f0 + 0x2c4) & ~(byte)(1 << (*(byte *)(param_1 + 0x2b4) + 4 & 0x1f));
    }
  }
  return;
}
