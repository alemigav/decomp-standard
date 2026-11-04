/* FUN_80167884
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80167884  body 0x80167884..0x801678c7  size 68 B
 * body sha256 cae9a1ebbf95869ea3cac433706d8c73fcd2aa805dcd076933ea262affccf0e4
 * provider record sha256 7cfa0167a794acebc75141fc21fec1cf04e1eee3583ca71266d29e9c09541fe0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167884(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = -0x7ff1eed0;
  }
  else {
    iVar1 = _DAT_800e13ec;
  }
  *(undefined1 *)(iVar1 + 4) = 3;
  *(undefined1 *)(iVar1 + 5) = 0;
  *(undefined1 *)(iVar1 + 6) = 0;
  *(undefined1 *)(iVar1 + 7) = 0;
  return;
}
