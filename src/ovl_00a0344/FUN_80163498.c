/* FUN_80163498
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163498  body 0x80163498..0x801634d7  size 64 B
 * body sha256 a90700d1e6e76223e849a5d0db500f9ebefc9ae529a4f223b0e3ebbfcbde2012
 * provider record sha256 6d2f49888b7b248f58455d3be7e9b7dd4700987e14cd80365c9453b436896dcd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163498(int param_1)

{
  if (*(char *)(param_1 + 0x2c8) != '\0') {
    (*(code *)(&PTR_FUN_80163dd0)[*(byte *)(param_1 + 5) - 1])();
  }
  return;
}
