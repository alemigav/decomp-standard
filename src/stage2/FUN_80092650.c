/* FUN_80092650
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092650  body 0x80092650..0x80092697  size 72 B
 * body sha256 64accf1a784e8a98192e68eb6d7d0a923c20082802d75abd46b20f23073e5bb1
 * provider record sha256 689cba3e5a176cfbfc2b90ba739d54830f998417345bc2dc2760c7d2708bd021
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092650(void)

{
  (*(code *)(&PTR_FUN_8012fa2c)[DAT_8012bf99])();
  FUN_80097fd0();
  FUN_8009202c();
  return;
}
