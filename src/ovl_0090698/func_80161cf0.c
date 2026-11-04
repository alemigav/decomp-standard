/* func_80161cf0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161e0b  size 284 B
 * body sha256 3e5cc2d818f50e03f271f842a6f94a7f2b724b1791e7a82e1167b4335569f611
 * provider record sha256 6f07309026fdd6f6f93c5953ade3a760d8caed83c36d7a3947a55fd807f5daef
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int iVar1;
  int in_a0;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    if (*(char *)(in_a0 + 0x2d9) != '\0') {
      *(char *)(in_a0 + 0x2d9) = *(char *)(in_a0 + 0x2d9) + -1;
    }
    (*(code *)(&PTR_FUN_80167d90)[*(byte *)(in_a0 + 4)])();
    *(char *)(in_a0 + 0x1a2) = (char)(-*(int *)(in_a0 + 0x2c) / 0x708);
    func_0x8004db5c();
    func_0x8004dcb8();
    FUN_801667b0();
    FUN_80167a60();
  }
  else if (*(char *)(in_a0 + 0x2db) != '\0') {
    iVar1 = func_0x80074d64(*(undefined4 *)(in_a0 + 0x28),*(undefined4 *)(in_a0 + 0x30));
    if (iVar1 + 0x46 < (int)*(short *)(in_a0 + 0x25e)) {
      *(int *)(in_a0 + 0x2c) = iVar1 + 0x46;
    }
    else {
      *(int *)(in_a0 + 0x2c) = (int)*(short *)(in_a0 + 0x25e);
    }
  }
  return;
}
