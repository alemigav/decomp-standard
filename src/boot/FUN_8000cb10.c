/* FUN_8000cb10
 * image   boot (boot), base 0x80000480
 * address 0x8000cb10  body 0x8000cb10..0x8000cb57  size 72 B
 * body sha256 a0b33d430b3548aed2253973ced3c850f2dfceabc0088fe0e82ab9e214801131
 * provider record sha256 3e5bed544470852a468f0bfe0bcae2ddd7eefa387e66c3fe08223c5ec68efca5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cb10(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  _DAT_800128d0 = _DAT_800128d0 & (~param_1 | 0x401);
  FUN_80007300(uVar1);
  return;
}
