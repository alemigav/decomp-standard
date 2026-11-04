/* FUN_80072548
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072548  body 0x80072548..0x800725ab  size 100 B
 * body sha256 2b7ab09b1cc3c6ac1842576d33b4624be78c6ca51c5547a8e7e75f72625709cf
 * provider record sha256 39ded8a66fa9354e9bc52bac1834cacc388bb62e14ff28505465789616013dbf
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072548(int param_1)

{
  func_0x80004a6c(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),
                  *(undefined2 *)(*(int *)(param_1 + 0x1c) + 2));
  DAT_800e110c = DAT_800e110c | 0x20;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
