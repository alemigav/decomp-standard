/* FUN_8017f7dc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017f7dc  body 0x8017f7dc..0x8017f86f  size 148 B
 * body sha256 ea2074f3fa3f321e2834618f76b8facea447e11ba780049d46243ac3d5dce869
 * provider record sha256 8933ca589f6acfd9830e62ca9b1ab63c4f7b58db291f2569befb3d9dd898f427
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017f7dc(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = FUN_8017bbb0(9);
  if (iVar1 < 0x80) {
    if (iVar1 < 8) {
      if (iVar1 < 1) {
        DAT_80185780 = 1;
        return 0;
      }
      puVar2 = &UNK_80184d6c;
    }
    else {
      iVar1 = iVar1 >> 1;
      puVar2 = &DAT_80184cec;
    }
  }
  else {
    iVar1 = iVar1 >> 4;
    puVar2 = &UNK_80184cac;
  }
  FUN_8017bbe8((int)(char)(puVar2 + iVar1 * 2)[1]);
  return (int)(char)puVar2[iVar1 * 2];
}
