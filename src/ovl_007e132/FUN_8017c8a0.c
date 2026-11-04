/* FUN_8017c8a0
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c8a0  body 0x8017c8a0..0x8017c8ef  size 80 B
 * body sha256 1fdfb05eebcfa101a80ff1d13aad20c59d1a7d5ef68a09c55b039dfe211b305e
 * provider record sha256 cf47c1c8daedb397d969b48230770254b5a752dcc243b3c837a9007314a4797c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c8a0(void)

{
  int iVar1;
  
  iVar1 = _DAT_800c52dc;
  _DAT_800e1124 = 0x1f15;
  DAT_8017e8e0 = (undefined2 *)(_DAT_800c52dc + 0x47a60);
  *DAT_8017e8e0 = 0;
  *(undefined2 *)(iVar1 + 0x47a66) = 0;
  FUN_8017c9ec();
  FUN_8017ccec();
  return;
}
