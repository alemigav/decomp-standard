/* FUN_80163de0
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80163de0  body 0x80163de0..0x80164137  size 856 B
 * body sha256 81a4e01c86e55d3f8c73335c656c91f43043ec986bb2dc3f4277b6c089f80fc3
 * provider record sha256 3939e9a505baa0e1d08dadeb79fba9b0b694c2c27d9ea277513261d3f65a28be
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163de0(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  
  if ((*(uint *)(param_1 + 0x28c) < 400) && ((_DAT_800e112a & 6) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x3010100;
    *(undefined1 *)(param_1 + 0x26e) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    uVar1 = func_0x80033604();
    iVar4 = param_1 + 0x14;
    func_0x80037780(0x81fa0,(uVar1 & 0xff) << 4,iVar4,0);
    uVar1 = func_0x80033604();
    func_0x80037780(0x817d0,(uVar1 & 0xff) << 4,iVar4,0);
    uVar1 = func_0x80033604();
    func_0x80037780(0x817d0,(uVar1 & 0xff) << 4,iVar4,0);
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) * 0x10000 + 0x9000000;
    *(undefined2 *)(param_1 + 500) = 0;
    func_0x80052bd0(1,0);
    func_0x80052c6c(5,0x50,0);
  }
  else {
    switch(*(undefined1 *)(param_1 + 6)) {
    case 0:
      *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined2 *)(param_1 + 500) = 0;
    case 1:
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
      func_0x80089d54(param_1,param_2,param_3,0x100);
      func_0x80032b5c(param_1,0);
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + *(short *)(param_1 + 500) * -2;
      *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
      if (*(short *)(param_1 + 0x1e0) < 0) {
        *(undefined1 *)(param_1 + 6) = 2;
        uVar3 = func_0x80033604();
        *(ushort *)(param_1 + 500) = (uVar3 & 0x1f) + 0x1e;
        *(undefined1 *)(param_1 + 0x206) = 0;
      }
      break;
    case 2:
      *(undefined1 *)(param_1 + 0x206) = 0;
      iVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x200);
      if (iVar4 != 0) {
        *(undefined1 *)(param_1 + 0x206) = 1;
      }
      iVar4 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
      if (iVar4 == 0) {
        *(undefined1 *)(param_1 + 0x206) = 0;
      }
      if (*(char *)(param_1 + 0x206) != '\0') {
        func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x80);
      }
      func_0x80089d54(param_1,param_2,param_3,0x100);
      sVar2 = *(short *)(param_1 + 500) + -1;
      *(short *)(param_1 + 500) = sVar2;
      if (sVar2 == -1) {
        *(undefined1 *)(param_1 + 6) = 3;
        uVar1 = func_0x80033604();
        if ((uVar1 & 1) != 0) {
          *(undefined1 *)(param_1 + 5) = 1;
          *(undefined1 *)(param_1 + 6) = 0;
        }
      }
      break;
    case 3:
      *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
      *(undefined1 *)(param_1 + 6) = 4;
      uVar3 = func_0x80033604();
      *(ushort *)(param_1 + 0x1f6) = (uVar3 & 0xff) + 0x1e;
    case 4:
      func_0x80089d54(param_1,param_2,param_3,0x100);
      func_0x80032b5c(param_1,0);
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0xfffffff8);
      sVar2 = *(short *)(param_1 + 0x1e0) + 10;
      *(short *)(param_1 + 0x1e0) = sVar2;
      if (100 < sVar2) {
        *(undefined2 *)(param_1 + 0x1e0) = 100;
        *(undefined4 *)(param_1 + 4) = 0x1010000;
      }
    }
  }
  return;
}
