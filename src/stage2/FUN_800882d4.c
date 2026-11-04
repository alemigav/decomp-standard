/* FUN_800882d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800882d4  body 0x800882d4..0x80088333  size 96 B
 * body sha256 00d72c08c66f2e1f137bf40e52600003490fc89142b6ac455457151b78d0747f
 * provider record sha256 43c53493d6fdfb69c77caf1debeaefbafd292e1ec930451d8fb6f561aba5a9d1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800882d4(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc;
  *(undefined **)(&DAT_8012a0c4 + iVar1) = &DAT_8012a03c;
  *(int *)(&DAT_8012a0c0 + iVar1) = param_1;
  *(undefined4 *)(&DAT_8012a0c8 + iVar1) = 0;
  *(undefined4 *)(&DAT_8012a040 + param_1 * 8) = 2;
  *(undefined **)(&UNK_8012a044 + param_1 * 8) = &DAT_8012a0c0 + iVar1;
  FUN_800879a0();
  return;
}
