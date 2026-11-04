/* FUN_801678c8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801678c8  body 0x801678c8..0x80167937  size 112 B
 * body sha256 3d40a39d93928492fe21ea98c447a6dc34724d6ac13af992d02fb328bf33c9fd
 * provider record sha256 dc8faf9f1165ae6ab9e1697baefdfdd13c81adca2bfbc660f85bb6a5039168c4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801678c8(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x800e1130;
  *(undefined1 *)(param_1 + 0x2d3) = 0;
  uVar1 = _DAT_800e13ec;
  if ((((_DAT_800e110c & 0x10000000) != 0) &&
      ((*(uint *)(param_1 + 0x290) & 0xc0000000) == 0x40000000)) &&
     ((*(uint *)(param_1 + 0x290) & 0x3fffffff) < *(uint *)(param_1 + 0x28c))) {
    *(undefined1 *)(param_1 + 0x2d3) = 1;
    uVar2 = uVar1;
  }
  return uVar2;
}
