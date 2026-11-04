/* FUN_80165f44
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165f44  body 0x80165f44..0x80165fb3  size 112 B
 * body sha256 c16e30febb1aaceb3b910062148df84fc58955f13fbe51d9dc8cfce5e6e4a006
 * provider record sha256 b207452ea967a60831c2e6e92a4572882c2fcb6d1759a48d9386dc95ce6a6f56
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_80165f44(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  *(undefined1 *)(param_1 + 0x2b4) = 0;
  puVar1 = _DAT_800e13ec;
  puVar2 = &DAT_800e1130;
  if ((((_DAT_800e110c & 0x10000000) != 0) &&
      ((*(uint *)(param_1 + 0x290) & 0xc0000000) == 0x40000000)) &&
     ((*(uint *)(param_1 + 0x290) & 0x3fffffff) < *(uint *)(param_1 + 0x28c))) {
    *(undefined1 *)(param_1 + 0x2b4) = 1;
    puVar2 = puVar1;
  }
  return puVar2;
}
