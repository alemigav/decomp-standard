/* FUN_801660cc
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801660cc  body 0x801660cc..0x801662e3  size 536 B
 * body sha256 da5d6bf654df3abba379ce8ad8d8b73ea3860ee2631e877cc2775cc50281dc4f
 * provider record sha256 fb9750588cf92f51cc8173ce3ad3cbc24166e82e90dd6c1b6d0ed048efa06ce0
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801660cc(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar3;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        if (bVar1 == 3) {
          *(undefined4 *)(param_1 + 0x1e8) = 0x6080700;
          func_0x800334c8(param_1,param_2,param_3,0);
          *(undefined2 *)(param_1 + 0x2c0) = 0;
          func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x10);
          func_0x80089d54(param_1,param_2,param_3,0x200);
          *(undefined4 *)(param_1 + 4) = 0x1050100;
          *(undefined1 *)(param_1 + 0x206) = 0;
          *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x80;
          func_0x80077d18(2);
          func_0x80052c6c(8,0x50,0);
          return;
        }
        return;
      }
      func_0x800334c8(param_1,param_2,param_3,0);
      func_0x80089d54(param_1,param_2,param_3,0x100);
      func_0x80032b5c(param_1,0);
      sVar3 = *(short *)(param_1 + 500) + -1;
      *(short *)(param_1 + 500) = sVar3;
      if (sVar3 != -1) {
        return;
      }
      *(undefined1 *)(param_1 + 6) = 3;
      iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
      if (iVar2 == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x10b0000;
      *(undefined1 *)(param_1 + 0x2c2) = 4;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x15000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffd;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x16000f00;
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 500) = 0x1e;
  }
  func_0x80032b5c(param_1,0);
  return;
}
