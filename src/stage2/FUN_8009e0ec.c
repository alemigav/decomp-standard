/* FUN_8009e0ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e0ec  body 0x8009e0ec..0x8009e13b  size 80 B
 * body sha256 22c6ae79a97a1aec9b5ef07ca45f91558e2777316522ba3eea7040b89393b71a
 * provider record sha256 89d6fec882ad62d908cea8276718f511657b1ddc09963e5a3bd8e07187ff965d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e0ec(void)

{
  if (DAT_8013273a == 0x80) {
    func_0x80004a6c(1,0xe);
  }
  if (DAT_8013273a == 0x151) {
    FUN_8009ced8();
    DAT_80132728 = 8;
    DAT_8013273a = 0;
    DAT_8013272e = 6;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
