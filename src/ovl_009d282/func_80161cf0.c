/* func_80161cf0
 * image   ovl_009d282 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161d47  size 88 B
 * body sha256 00fa2f76e4ed55249fc52b6f4ee6d94e6cee7413a1810c7fe882431d92639093
 * provider record sha256 6c414206228ac136edb64e8b6771e38f3b101915d38865948a1bdfca2019130c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void processEntry entry(void)

{
  int in_a0;
  
  if (*(char *)(in_a0 + 4) == '\0') {
    FUN_80161d48(in_a0,*(undefined4 *)(in_a0 + 0x1a4),*(undefined4 *)(in_a0 + 0x218));
  }
  else if (*(char *)(in_a0 + 4) == '\x01') {
    FUN_80161db0(in_a0,*(undefined4 *)(in_a0 + 0x1a4),*(undefined4 *)(in_a0 + 0x218));
  }
  return;
}
