/* FUN_8017f658
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f658  body 0x8017f658..0x8017f6bb  size 100 B
 * body sha256 de02ab9cff71d244f73abfa26d6126c5833a23633bcbf4e317c00d652c38437d
 * provider record sha256 385bc3a36c51db64a59705b0fca8d275ec066ed6ccf657c765835d3930f84e08
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f658(void)

{
  int iVar1;
  
  iVar1 = FUN_8017bbb0(3);
  if (iVar1 == 0) {
    DAT_80185780 = 1;
    iVar1 = 0;
  }
  else {
    FUN_8017bbe8((int)(char)(&DAT_80184c65)[iVar1 * 2]);
    iVar1 = (int)(char)(&DAT_80184c64)[iVar1 * 2];
  }
  return iVar1;
}
