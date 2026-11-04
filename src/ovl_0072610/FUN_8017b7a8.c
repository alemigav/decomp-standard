/* FUN_8017b7a8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b7a8  body 0x8017b7a8..0x8017b7e7  size 64 B
 * body sha256 55854994407ed4f7fa52952c3acfd59f9394241129670107589a50be9c2c2184
 * provider record sha256 70774af64aa8d667b3b70b8b595edc3515c84c96b78ff87af5caf9005b9a62c4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b7a8(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_80186c94;
  iVar2 = *DAT_80186c94;
  DAT_80186c94[4] = 0;
  piVar1[5] = 0;
  piVar1[3] = 0;
  piVar1[2] = iVar2 + 0x800;
  piVar1[6] = iVar2 + 0x800;
  FUN_8017bbe8(0);
  return;
}
