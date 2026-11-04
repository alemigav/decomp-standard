/* FUN_8017f6bc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f6bc  body 0x8017f6bc..0x8017f79f  size 228 B
 * body sha256 51103a53eecb45d77c08fe34e6d24fd3c45b732944530ce5c5d68c6db7d94de0
 * provider record sha256 ca12c7fc5f0ad352e632d91571e5e083ccc8cfd60fd0a9fa5f0f4743f24e6037
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f6bc(void)

{
  int iVar1;
  undefined *puVar2;
  char *pcVar3;
  
  iVar1 = FUN_8017bbcc();
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = FUN_8017bbb0(9);
  if (iVar1 < 0x40) {
    if (iVar1 < 0x18) {
      if (iVar1 + -0xc < 0) {
        DAT_80185780 = 1;
        return 0;
      }
      iVar1 = (iVar1 + -0xc) * 2;
      pcVar3 = &DAT_80184c94 + iVar1;
      FUN_8017bbe8((int)(char)(&DAT_80184c95)[iVar1]);
      iVar1 = FUN_8017bbcc();
      goto joined_r0x8017f778;
    }
    iVar1 = iVar1 >> 3;
    puVar2 = &UNK_80184c84;
  }
  else {
    iVar1 = iVar1 >> 6;
    puVar2 = &DAT_80184c74;
  }
  pcVar3 = puVar2 + iVar1 * 2;
  FUN_8017bbe8((int)pcVar3[1]);
  iVar1 = FUN_8017bbcc();
joined_r0x8017f778:
  if (iVar1 == 0) {
    iVar1 = (int)*pcVar3;
  }
  else {
    iVar1 = -(int)*pcVar3;
  }
  return iVar1;
}
