/* FUN_8016535c
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x8016535c  body 0x8016535c..0x8016538f  size 52 B
 * body sha256 5a4190e66826ab3ed747592ea7305bf3d6f1fc73443f6c294a36e6f6486f4634
 * provider record sha256 bdd07bcb2395c4c184c169d19321f517c59d2bedc8681362c0afc305fc310827
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016535c(int param_1)

{
  (**(code **)(&DAT_8016554c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
