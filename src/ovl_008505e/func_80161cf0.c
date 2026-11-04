/* func_80161cf0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161dcf  size 224 B
 * body sha256 5cf46399afeeedc5c57a1d182ec2de2aae39b1c25d5e4dfb948ebb25d5347640
 * provider record sha256 3add310d48394dced37d6db5a7277dd40cde172b626ba4f02af066c79e40b4c7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int in_a0;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    if (*(char *)(in_a0 + 0x2ce) != '\0') {
      *(char *)(in_a0 + 0x2ce) = *(char *)(in_a0 + 0x2ce) + -1;
    }
    (*(code *)(&PTR_FUN_80166d08)[*(byte *)(in_a0 + 4)])();
    func_0x8004db5c();
    func_0x8004dcb8();
    if (((*(int *)(in_a0 + 0x28) == (int)*(short *)(in_a0 + 0x34)) &&
        (*(int *)(in_a0 + 0x30) == (int)*(short *)(in_a0 + 0x38))) || (*(char *)(in_a0 + 0xd) != -1)
       ) {
      *(char *)(in_a0 + 0x2cc) = *(char *)(in_a0 + 0x2cc) + '\x01';
    }
    else {
      *(undefined1 *)(in_a0 + 0x2cc) = 0;
    }
  }
  return;
}
