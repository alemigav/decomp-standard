/* FUN_80164784
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80164784  body 0x80164784..0x8016489b  size 280 B
 * body sha256 f659bd2dd8ff5a2cecc4bb2606902a8bdd0d0a1485a33e01cc0f0295e1b876ee
 * provider record sha256 cd1d66d380840ea4f85218f741679f3a5bbf1b9f8683d6dd09ce5eae5fc6cd39
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164784(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
    func_0x800334c8();
    func_0x80089d54(param_1,param_2,param_3,0x100);
    iVar1 = func_0x80040bb4((5000 - _DAT_800e1158) * (5000 - _DAT_800e1158) +
                            (-0x40d8 - _DAT_800e1160) * (-0x40d8 - _DAT_800e1160));
    *(short *)(param_1 + 500) = (short)(iVar1 >> 4);
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4400;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  iVar1 = (int)*(short *)(param_1 + 0x1e0);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  iVar1 = (uint)*(ushort *)(param_1 + 500) - iVar1;
  *(short *)(param_1 + 500) = (short)iVar1;
  if (iVar1 * 0x10000 < 0) {
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  return;
}
