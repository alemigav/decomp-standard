/* FUN_8017f3b4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f3b4  body 0x8017f3b4..0x8017f42f  size 124 B
 * body sha256 853534fe98d4fe6485c2b8f0ef8cd0ecfc26e738c4b0d3793693f86f7b006a3a
 * provider record sha256 59da3f2cd4d0a27cf3e99e6d4697a504eea4d7dc322a5be07766a324525d03e4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f3b4(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = FUN_8017bbb0(6);
  if (iVar1 < 8) {
    if (iVar1 == 0) {
      DAT_80185780 = 1;
      return 0;
    }
    puVar2 = &UNK_80184b80;
  }
  else {
    iVar1 = iVar1 >> 3;
    puVar2 = &DAT_80184b70;
  }
  FUN_8017bbe8((int)(char)(puVar2 + iVar1 * 2)[1]);
  return (int)(char)puVar2[iVar1 * 2];
}
