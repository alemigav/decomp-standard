/* FUN_80047b20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b20  body 0x80047b20..0x80047b3b  size 28 B
 * body sha256 0b3d203dcf200a98a1a97052409ef78769b8d6971e1208257ef0676522346d52
 * provider record sha256 48d94decf19a14328fb1b4411d14b12edcb22036efec7c76d7406f8076ad07e1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b20(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 7) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 7) = 2;
  return;
}
