/* FUN_8017d81c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d81c  body 0x8017d81c..0x8017d87f  size 100 B
 * body sha256 14e9e1242139986b29e81ecde428631e4ebf3c6bcbea2b50134aea6bb7cfa541
 * provider record sha256 c8dd14951059aefcae0d232415860e39a5961956a755efbbc68b85aa4c311de0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d81c(void)

{
  int iVar1;
  
  FUN_8017bec8(3);
  iVar1 = FUN_8017bec8(1);
  if (iVar1 != 0) {
    FUN_8017bec8(8);
    FUN_8017bec8(8);
    DAT_80185818 = FUN_8017bec8(8);
  }
  FUN_8017bec8(0xe);
  FUN_8017bbe8(1);
  FUN_8017bec8(0xe);
  return;
}
