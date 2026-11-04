/* FUN_801628a0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801628a0  body 0x801628a0..0x801629bf  size 288 B
 * body sha256 3d01112e5c227359e53eea408371bbaea6bf6cf67a0354dffac0c069246dd19d
 * provider record sha256 8d3c0a87376340559105338460a20de0ef76bcd182a0abc03719ce492659982f
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801628a0(int param_1)

{
  undefined1 uVar2;
  uint uVar1;
  
  if (-1 < _DAT_800e1322) {
    if (*(char *)(param_1 + 4) != '\a') {
      uVar2 = 1;
      if ((*(ushort *)(param_1 + 0x2c8) & 1) == 0) {
        if (*(byte *)(param_1 + 0xd) < 2) {
          *(undefined1 *)(param_1 + 0x2b5) = 2;
          return *(undefined4 *)(&DAT_800e13e8 + (uint)*(byte *)(param_1 + 0xd) * 4);
        }
        uVar1 = func_0x80036ea0(*(undefined4 *)(param_1 + 0x28c),3000,5000,7000);
        if (uVar1 == 1) {
          uVar1 = _DAT_800e1128 & 0x17;
        }
        else if (uVar1 == 0) {
          uVar1 = (uint)DAT_800e1135;
        }
        else {
          if (3 < uVar1) {
            return 0;
          }
          uVar1 = _DAT_800e1128 & 5;
        }
        uVar2 = 2;
        if (uVar1 == 0) {
          return 0;
        }
      }
      *(undefined1 *)(param_1 + 0x2b5) = uVar2;
      return 0x800e1130;
    }
    *(undefined1 *)(param_1 + 0x2b5) = 0;
  }
  return 0;
}
