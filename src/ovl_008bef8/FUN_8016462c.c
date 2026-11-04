/* FUN_8016462c
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x8016462c  body 0x8016462c..0x8016469f  size 116 B
 * body sha256 0007325675b428a95cabe5ee4607a95b615cb1d213a130cbd0f435c2f8d12560
 * provider record sha256 6c806c72035a28f207e7ccd5383398a0c728ec4f438bd9f5d616b45d1c8c8043
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016462c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 5) != -1) {
    *(undefined1 *)(param_1 + 5) = 0xff;
    FUN_80164624();
  }
  (*(code *)(&PTR_FUN_80166124)[*(byte *)(param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
