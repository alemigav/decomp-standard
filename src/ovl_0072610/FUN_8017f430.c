/* FUN_8017f430
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f430  body 0x8017f430..0x8017f4ab  size 124 B
 * body sha256 a7354dd5660ef5e9db6452230b8b91d80fa3917ba23ca5b53a0d264990c02e10
 * provider record sha256 7ebb0598a00983194fcdb03f07d9215b09c1859e699c5a4e7b35b0fa22f5b75a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f430(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = FUN_8017bbb0(6);
  if (iVar1 < 8) {
    if (iVar1 == 0) {
      DAT_80185780 = 1;
      return 0;
    }
    puVar2 = &UNK_80184bb0;
  }
  else {
    iVar1 = iVar1 >> 2;
    puVar2 = &DAT_80184b90;
  }
  FUN_8017bbe8((int)(char)(puVar2 + iVar1 * 2)[1]);
  return (int)(char)puVar2[iVar1 * 2];
}
