/* FUN_8009d7ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d7ac  body 0x8009d7ac..0x8009d7e3  size 56 B
 * body sha256 786b37e3d13092c2cabfb05a8ed9552f401a80da8f25c8ad522bc90d333aa8cc
 * provider record sha256 9caca9101253185bdf7e0f9a3f133cd39c350fad16bd203a9af3ac7578dac362
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d7ac(void)

{
  if (DAT_8013273a == 1) {
    FUN_8006c070(0);
    FUN_8009f320(0xf);
    DAT_8013272e = 9;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
