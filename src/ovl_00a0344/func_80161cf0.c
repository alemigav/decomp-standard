/* func_80161cf0
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161dc3  size 212 B
 * body sha256 1c3291943cfdc26f04284056dc9c00be9e9ed615d530a947efd86ff4b2276502
 * provider record sha256 fa5ff53f942b8ee8abb44c328e5adbb531549d8290b45e6d2ad5780fefb7abf9
 * callees 3 direct (3 in corpus)
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
    if (*(char *)(in_a0 + 0x2be) != '\0') {
      *(char *)(in_a0 + 0x2be) = *(char *)(in_a0 + 0x2be) + -1;
    }
    (*(code *)(&PTR_FUN_80163d54)[*(byte *)(in_a0 + 4)])();
    if (((*(char *)(in_a0 + 0x2c8) == '\0') && (*(char *)(in_a0 + 0x2c6) != '\0')) &&
       (*(short *)(*(int *)(in_a0 + 0x250) + 0x2d4) != 0)) {
      FUN_80163b50();
    }
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
