/* FUN_8000d9c0
 * image   boot (boot), base 0x80000480
 * address 0x8000d9c0  body 0x8000d9c0..0x8000d9d7  size 24 B
 * body sha256 687fd0effce760098d29bfd079e950578fc7939020c786bf01ba017538f405e1
 * provider record sha256 45345b35981f79d73e67be29960a7aaaa583437e4d9d398a074ba00ce6f6d9b6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_8000d9c0(void)

{
  return (_DAT_a4040010 & 0x1c) != 0;
}
