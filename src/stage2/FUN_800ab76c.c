/* FUN_800ab76c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab76c  body 0x800ab76c..0x800ab7a7  size 60 B
 * body sha256 6a23152dd82f9dd04f46a06e570cb865dcd942c27a8757af5c93fd8622bd31d6
 * provider record sha256 e8e604baf91460f9a225f44de8d2f6c51695e77871e9babb264453dd2d2fd771
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab76c(void)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5358();
    FUN_800aaf84();
    DAT_80136310 = '\0';
  }
  return;
}
