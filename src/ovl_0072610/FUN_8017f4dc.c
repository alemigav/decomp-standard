/* FUN_8017f4dc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f4dc  body 0x8017f4dc..0x8017f53f  size 100 B
 * body sha256 2a9f8b18f1a97b28401253c569fa8ebc8efa2d1f9c0838e362590622dc5765c3
 * provider record sha256 08319529771f1a4bf3da7e99481e1a7a8f508c7205cb02410b0f7a5ca4911b2e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f4dc(void)

{
  int iVar1;
  
  iVar1 = FUN_8017bbb0(4);
  if (iVar1 == 0) {
    DAT_80185780 = 1;
    iVar1 = 0;
  }
  else {
    FUN_8017bbe8((int)(char)(&DAT_80184bc1)[iVar1 * 2]);
    iVar1 = (int)(char)(&DAT_80184bc0)[iVar1 * 2];
  }
  return iVar1;
}
