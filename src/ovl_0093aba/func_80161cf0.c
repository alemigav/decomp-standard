/* func_80161cf0
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161ddf  size 240 B
 * body sha256 e35d0861f7e783a1ea17a2d0bfd58728006518f4d2f908dced00847353d8ae44
 * provider record sha256 e43dd29d801463fe77ea7ba97e333801c13d47b0ba306ae87a3d8e859b5e0bd9
 * callees 4 direct (4 in corpus)
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
    (*(code *)(&PTR_FUN_801654a0)[*(byte *)(in_a0 + 4)])();
    *(undefined2 *)(in_a0 + 0x2b4) = *(undefined2 *)(in_a0 + 0x2b6);
    *(undefined2 *)(in_a0 + 0x2b6) = *(undefined2 *)(in_a0 + 0x2b8);
    *(undefined2 *)(in_a0 + 0x2b8) = *(undefined2 *)(in_a0 + 0x2ba);
    *(undefined2 *)(in_a0 + 0x2ba) = *(undefined2 *)(in_a0 + 700);
    *(undefined2 *)(in_a0 + 0x2ba) = *(undefined2 *)(in_a0 + 0x2c0);
    *(undefined2 *)(in_a0 + 0x2c0) = *(undefined2 *)(in_a0 + 0x2c2);
    *(undefined2 *)(in_a0 + 0x2c2) = *(undefined2 *)(in_a0 + 0x66);
    func_0x80033648();
    func_0x8004da40();
    func_0x8004dcb8();
  }
  return;
}
