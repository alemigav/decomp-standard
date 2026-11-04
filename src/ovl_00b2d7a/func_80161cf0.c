/* func_80161cf0
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161d9b  size 172 B
 * body sha256 67c3cf8c15c7ea3e4a4d7e6be73c6cb5a6d21ba7f74fd96dbdd24ab59ea8921d
 * provider record sha256 e9226486ae31ce69edd7f070ffeea8e8522d8b81d605d438685f446fb8adacad
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int in_a0;
  
  func_0x800653d0(in_a0,&DAT_800e1158,0,0);
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    (*(code *)(&PTR_FUN_801625f0)[*(byte *)(in_a0 + 4)])();
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
