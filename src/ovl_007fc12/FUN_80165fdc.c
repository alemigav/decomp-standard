/* FUN_80165fdc
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165fdc  body 0x80165fdc..0x801661c7  size 492 B
 * body sha256 a04c25f8327e281baa3ad126d412ea3bb069f1b7e3c6e5ebd1ea1b408f603a2d
 * provider record sha256 65633f304a50905408a0c9181804cda9a2d9a966e463c1e3072fd11e9beee1f2
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165fdc(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar3;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x1b000700;
        *(undefined1 *)(param_1 + 6) = 3;
      }
      else if (bVar1 != 3) {
        return;
      }
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
      func_0x800334c8(param_1,param_2,param_3,0);
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
      }
      func_0x80032b5c(param_1,0);
      if (*(char *)(param_1 + 0x1e9) == '\x19') {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x19000700;
    *(undefined1 *)(param_1 + 6) = 1;
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
    uVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0xbe);
    *(undefined2 *)(param_1 + 500) = uVar3;
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      func_0x80077d18(10,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    *(undefined2 *)(param_1 + 0x1e0) = 0xb;
  }
  iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x140);
  if (iVar2 == 0) {
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 6) = 2;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 500);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  return;
}
