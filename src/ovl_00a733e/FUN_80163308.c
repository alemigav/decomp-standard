/* FUN_80163308
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163308  body 0x80163308..0x80163403  size 252 B
 * body sha256 ed56e6d283abb57844db70f4c218f0eeb8cd6baf15f96f9a02aa987b040d97f5
 * provider record sha256 1eea80ced59e3d0cc73d682d299b9cc3a18f8b0d3c31583644c5121d64fab16a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163308(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 6) = 1;
  if (*(char *)(param_1 + 7) == '\0') {
    iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,1);
    if (iVar1 < 0) {
      *(undefined2 *)(param_1 + 0x2b6) = 1;
    }
    else {
      *(undefined2 *)(param_1 + 0x2b6) = 0;
    }
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (ushort)(1 << (uVar2 & 0xf)) & 0x5a0;
  }
  *(int *)(param_1 + 0x1e8) = (*(short *)(param_1 + 0x2b6) + 7) * 0x1000000 + 0xf00;
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *(undefined1 *)(param_1 + 0x206) = 0;
  *(undefined1 *)(param_1 + 0x207) = 0;
  *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  *(undefined1 *)(param_1 + 0x2cd) = 0;
  return;
}
