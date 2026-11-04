/* FUN_801641a4
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801641a4  body 0x801641a4..0x8016455f  size 956 B
 * body sha256 5b4af642be2f7dbefd6bde88346c9a8a60e737ad43431a3f8e8b33a1a9bf1093
 * provider record sha256 14ceb85ffe4a1558b04adf97a888d6ca47872296c6cbd094c971bd0182eb7cf5
 * callees 17 direct (17 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801641a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0x3840000;
  local_1c = 0xff4c0000;
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      if (*(char *)(param_1 + 0x1e9) == '\v') {
        func_0x80052bd0(6,2);
        func_0x80052d10(0x1e,0xf0,0x78,1);
        func_0x80052c6c(0x32,0x78,0x1e);
        func_0x80052d10(0x14,0xff,100,0x60);
        func_0x80052d10(0x11,0xb4,0x32,0x74);
        _DAT_800e1196 = *(short *)(param_1 + 0x66) + 0x800;
        _DAT_800e1354 = *(undefined4 *)(param_1 + 0x224);
        _DAT_800e1358 = *(undefined4 *)(param_1 + 0x228);
        _DAT_800e1134 = 0x5000000;
        _DAT_800e1380 = param_1;
        func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
        FUN_80163068(param_1,8,0xd0,0x50,0x50);
        FUN_80163068(param_1,9,0xd0,0x50,0x50);
        FUN_80163068(param_1,10,0xd0,0x50,0x50);
        FUN_80163068(param_1,0xb,0xd0,0x50,0x50);
      }
      *(undefined1 *)(param_1 + 0x1e8) = 3;
      iVar3 = func_0x80036b84(param_1,3,3,0);
      if (iVar3 != 0) {
        uVar4 = 0x1060000;
        if ((*(ushort *)(param_1 + 0x2b8) & 8) == 0) {
          uVar4 = 0x1010000;
        }
        *(undefined4 *)(param_1 + 4) = uVar4;
      }
      if (*(byte *)(param_1 + 0x1e9) < 0xc) {
        FUN_801625b0(param_1,0);
        return;
      }
      func_0x8003331c(param_1,param_2,param_3,0);
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 500) = 0;
    func_0x800837d0((int)*(short *)(param_1 + 0x66),&local_20,&local_20);
    DAT_80166680 = *(int *)(param_1 + 0x28) + (int)local_20._0_2_;
    DAT_80166688 = *(int *)(param_1 + 0x30) + (int)local_1c._0_2_;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  iVar3 = FUN_801622f4(param_1,10,6,10,200,_DAT_800e1266);
  if (iVar3 != 0) {
    FUN_80162cf8(param_1);
    func_0x80052bd0(3,0);
    func_0x80052d10(0xc,0xb4,0x28,0);
    func_0x80077d18(5,param_1);
    if ((*(ushort *)(param_1 + 0x2b8) & 8) == 0) {
      FUN_80162694(10);
    }
  }
  if ((*(char *)(param_1 + 0x1e9) == '\x0f') && ((*(ushort *)(param_1 + 0x2b8) & 8) == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2c6) = 0x1e;
  }
  func_0x80036c68(param_1,9,3,0);
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  if ((*(ushort *)(param_1 + 0x2b8) & 8) != 0) {
    func_0x80036a30(&DAT_800e1158,&DAT_80166680,200);
  }
  iVar3 = *(int *)(param_1 + 0x28) - DAT_80166680;
  iVar2 = *(int *)(param_1 + 0x30) - DAT_80166688;
  func_0x80040bb4(iVar3 * iVar3 + iVar2 * iVar2);
  if ((*(char *)(param_1 + 0x1e9) == ')') && ((*(ushort *)(param_1 + 0x2b8) & 8) != 0)) {
    *(undefined1 *)(param_1 + 0x1e9) = 10;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  return;
}
