/* func_80161cf0
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161db7  size 200 B
 * body sha256 8d5b984afdb773c54d219f8a12abca463c2c4c43e6ea177f51d7e17c9e8dc157
 * provider record sha256 d5a581481395b74325e62d4bb2818c9882e961ffda08f49751aaa93c26e7551a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int *in_a0;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)((int)in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)((int)in_a0 + 0x26f) = *(byte *)((int)in_a0 + 0x26f) - 1;
    }
    (*(code *)(&PTR_FUN_80162d10)[*(byte *)(in_a0 + 1)])();
    *(char *)((int)in_a0 + 0x1a2) = (char)(-in_a0[0xb] / 0x708);
    if (*in_a0 != 0) {
      func_0x8004db5c();
      func_0x8004dcb8();
    }
  }
  return;
}
